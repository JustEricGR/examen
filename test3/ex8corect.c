#include<stdio.h>
#include<stdlib.h>
#define CHUNK 20


void modif(const char *src,const char *dest,int n)
{
    char *rez=NULL;
    FILE *fin=NULL;
    FILE *fout=NULL;
    

    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier1\n");
        perror(NULL);
        exit(-1);
    }

    if((fout=fopen(dest,"w"))==NULL)
    {
        printf("Eroare la deschidere fisier2\n");
        perror(NULL);
        exit(-1);
    }

    rez=(char*)malloc(CHUNK*sizeof(char));
    if(!rez)
    {
        printf("Eroare la realocare\n");
        perror(NULL);
        exit(-1);
    }
    char c=0;
    int i=0,cnt=0;
    while((c=fgetc(fin))!=EOF)
    {
        
        if(i%n==0)
        {
            fputc(c,fout);
        }
        i++;
        if(i>=CHUNK)
        {
        cnt++;
        rez=(char*)realloc(rez,cnt*CHUNK*sizeof(char));
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
        printf("Eroare la inchidere1");
        perror(NULL);
        exit(-1);
    }

    free(rez);
}

int main(void)
{
    
    modif("cuvcorect8.txt","rezultatcorect8.txt",3);
    return 0;
}