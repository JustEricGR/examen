#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char **linii=NULL;
int nrLinii=0;

void eliberare()
{
    for(int i=0;i<nrLinii;i++)free(linii[i]);
    free(linii);
}

void adaugare(char *linie)
{
    char *linieNoua=NULL;
    linieNoua=(char*)malloc((strlen(linie)+1)*sizeof(char));
    if(!linieNoua)
    {
        printf("Eroare la alocare");
        perror(NULL);
        exit(-1);
    }
    strcpy(linieNoua,linie);
    char **p=(char**)realloc(linii,(nrLinii+1)*sizeof(char*));
    if(!p)
    {
        printf("Eroare la alocare");
        perror(NULL);
        eliberare();
        exit(-1);
    }
    linii=p;
    linii[nrLinii]=linieNoua;
    nrLinii++;
}

void mare(const char *src,const char *dest)
{
    FILE *fin=NULL;
    FILE *fout=NULL;

    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        eliberare();
        exit(-1);
    }

    if((fout=fopen(dest,"w"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        eliberare();
        exit(-1);
    }

    char linie[1000]="";

    while((fgets(linie,1000,fin))!=NULL)
    {
        if(strlen(linie)<1)continue;
        int i=0;
        while(linie[i])
        {
            if(isalpha(linie[i]))
            {
                linie[i]=toupper(linie[i]);

            }
            i++;

        }
        adaugare(linie);
    }
    for(int i=0;i<nrLinii;i++)
        fputs(linii[i],fout);
    eliberare();
}

int main(int argc,char **argv)
{
    if(argc!=3)
    {
        printf("prea putine argumente\n");
        perror(NULL);
        exit(-1);
    }
    mare(argv[1],argv[2]);
    return 0;
}