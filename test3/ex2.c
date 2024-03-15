#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void adaugare(char *source,char *dest)
{
    FILE *fin=NULL;
    FILE *fout=NULL;
    if((fin=fopen(source,"r"))==NULL)
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

    char c=0;
    int nr=0,suma=0;
    while((c=fgetc(fin))!=EOF)
    {
        if(isdigit(c))
        {
            nr=c-'0'+(nr*10);
        }
        else
        {
            suma+=nr;
            nr=0;
        }
    }
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }
    fprintf(fout,"%d ",suma);

    if((fin=fopen(source,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier");
        perror(NULL);
        exit(-1);
    }

    while((c=fgetc(fin))!=EOF)
    {
        if(!isdigit(c))
        {
            fputc(c,fout);
        }
    }

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }

    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere2");
        perror(NULL);
        exit(-1);
    }

}

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("Nr insuficient de argumente\n");
        exit(-1);
    }
    adaugare(argv[1],argv[2]);
}