#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define CHUNK 100


/*int citire(char *v const char *src)
{
    char *temp=NULL;
    int i=0,cnt=0;
    temp=(char*)malloc(CHUNK*sizeof(char));
    if(!temp)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    FILE *fin=NULL;
    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier");
        perror(NULL);
        exit(-1);
    }

    while(1)
    {
        if(fscanf(fin,"%c",v[i])!=1)break;
        temp[i]=v[i];
        i++;
        if(i>=CHUNK)
        {
            cnt++;
            temp=(char*)realloc(temp,cnt*CHUNK*sizeof(char));
        }
    }
    return i;

}*/



void *modificare(const char *src,const char *dest)
{
    FILE *fin=NULL;
    FILE *fout=NULL;

    //char *linie=NULL;

    int s=0,nr=0;
    char c=0;

    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier");
        perror(NULL);
        exit(-1);
    }

    if((fout=fopen(dest,"w"))==NULL)
    {
        printf("Eroare la deschidere fisier");
        perror(NULL);
        exit(-1);
    }

    while((c=fgetc(fin))!=EOF)
    {
        if(isdigit(c))
        {
            nr=c-'0'+(nr*10);
        }
        else
        {
            s+=nr;
            nr=0;
        }
    }

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }
    fprintf(fout,"%d ",s);

    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier");
        perror(NULL);
        exit(-1);
    }

    while((c=fgetc(fin))!=EOF)
    {
        if(!isdigit(c))
        fputc(c,fout);
    }

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }

    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }


}

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        printf("argumente insuficiente");
        exit(-1);
    }

    modificare(argv[1],argv[2]);
}