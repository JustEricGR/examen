#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define SIZE 1000000

int citire(int *v,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        exit(-1);
    }
    int i=0;
    /*int *v1=(int*)malloc(SIZE*sizeof(int));
    if(!v1)
    {
        printf("Eroare la alocare");
        exit(-1);
    }
    v=v1;*/

    while(1)
    {
        
        if((fscanf(fin,"%d",&v[i]))!=1)break;
        i++;
    }
    return i;
    fclose(fin);

}



int nrBiti(int n)
{
    int par=0;
        uint32_t m=0;
        m=1<<31;
        for(int i=0;i<32;i++)
        {
            if((n&m)!=0)
            {
                
                par++;
            }
            
            m>>=1;
        }
        return par;
}

void afisareVect(const char *fisier,int *v,int size)
{
    FILE *f=NULL;
    if((f=fopen(fisier,"w"))==NULL)
    {
        printf("Eroare la deschidere");
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        fprintf(f,"%d ",v[i]);
    }
    fclose(f);
}

void compunere(int *a,int size)
{
    int b[size],j=0;
    for(int i=0;i<size;i++)
    {
        if(nrBiti(a[i])%2==0)
        {
            b[j]=a[i];
            j++;
        }
    }
    afisareVect("rezultat.txt",b,j);
    

}

int main(void)
{
    int v[SIZE];
    int size=citire(v,"nr.txt.1");
    compunere(v,size);
    

}