#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000000

typedef struct{
    int nr;
    int nrap;
}Numar;

Numar *numere;
int nrNum=0;

int citire(int *v,const char *file)
{
    FILE *f=NULL;
    /*int *v1=NULL;
    v1=(int*)malloc(CHUNK*sizeof(int));
    if(!v1)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    v1=v;
    int cnt=1;*/
    if((f=fopen(file,"r"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    int i=0;
    while(fscanf(f,"%d",&v[i])==1)
    {
        i++;
        
    }
    
    return i;
    fclose(f);
}

Numar *numarare(int *nr,int cif,int size)
{
    Numar *rez=(Numar*)malloc(size*sizeof(Numar));
    for(int i=0;i<size;i++)
    {
        rez[i].nrap=0;
        rez[i].nr=nr[i];
        while(nr[i]!=0)
        {
            if((nr[i]%10)==cif)
            {
                rez[i].nrap++;

            }
            nr[i]/=10;
        }
    }
    return rez;
    free(rez);
    
}

void sortare(Numar *v,int size)
{
    Numar aux;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(v[j].nrap>v[i].nrap)
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void afisare(Numar *v,int size,const char *file)
{
    FILE *f=NULL;
    if((f=fopen(file,"w"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        fprintf(f,"%d : %d\n",v[i].nr,v[i].nrap);
    }
}

int main(int argc,char **argv)
{
    if (argc != 3) 
    {
        printf("Mod de utilizare: %s fisier_intrare fisier_iesire\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int *v=NULL;
    v=(int *)malloc(SIZE*sizeof(int));
    if(!v)
    {
        printf("Problema la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(v,argv[1]);
    v=realloc(v,size*sizeof(int));
    //Numar *n=numarare(v,9,size);
    sortare(numarare(v,9,size),size);
    afisare(numarare(v,9,size),size,argv[2]);
    //free(n);
    free(v);
    
}

