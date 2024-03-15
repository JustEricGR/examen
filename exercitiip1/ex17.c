#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char line[300];
    int nrvoc;
}Linie;

Linie **linii;
int nrLinii=0;

void eliberare()
{
    for(int i=0;i<nrLinii;i++)free(linii[i]);
    free(linii);
    
}

void adaugare(char *linie_noua)
{
    Linie *linie=(Linie*)malloc(sizeof(Linie));
    if(!linie)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(linie->line,linie_noua);
    linie->nrvoc=0;
    for(int i=0;i<strlen(linie_noua);i++)
    {
        if(linie_noua[i]=='a' || linie_noua[i]=='e' || linie_noua[i]=='i' || linie_noua[i]=='o' || linie_noua[i]=='u')
        {
            linie->nrvoc++;
        }
        if(!isalnum(linie_noua[i]))continue;
    }
    Linie **p=(Linie**)realloc(linii,(nrLinii+1)*sizeof(Linie*));
    if(!p)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        eliberare();
        exit(-1);
    }
    linii=p;
    linii[nrLinii]=linie;
    nrLinii++;
}

void sortare(Linie **linii)
{
    Linie *aux;
    for(int i=0;i<nrLinii;i++)
    {
        for(int j=i+1;j<nrLinii;j++)
        {
            if(linii[j]->nrvoc>linii[i]->nrvoc)
            {
                aux=linii[i];
                linii[i]=linii[j];
                linii[j]=aux;
            }
        }
    }
}

int main(int argc, char **argv)
{
    FILE *fin=NULL;
    FILE *fout=NULL;

    if (argc != 3) 
    {
    printf("Mod de utilizare: %s fisier_intrare fisier_iesire\n", argv[0]);
    exit(EXIT_FAILURE);
    }

    if((fin=fopen(argv[1],"r"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }

    if((fout=fopen(argv[2],"w"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }

    char linie[300]="";
    while(fgets(linie,300,fin)!=NULL)
    {
        if(strlen(linie)<=1)continue;
        adaugare(linie);
    }
    sortare(linii);

    for(int i=0;i<nrLinii;i++)
    {
        fprintf(fout,"%d - %s",linii[i]->nrvoc,linii[i]->line);
    }
    fclose(fin);
    fclose(fout);
    eliberare();

}