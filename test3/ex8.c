#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void afisare32(uint32_t n)
{
    uint32_t m=0;
    m=1<<31;
    for(int i=0;i<32;i++)
    {
        if((n&m)!=0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        m>>=1;
    }printf("\n");
}

void transform(const char *src, const char *dest)
{
    FILE *fin=NULL;
    FILE *fout=NULL;
    

    int v=0;
    if((fin=fopen(src,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    if((fout=fopen(dest,"w"))==NULL)
    {
        printf("Eroare la deschidere2\n");
        perror(NULL);
        exit(-1);
    }

    while((fscanf(fin,"%X",&v))==1)
    {
        fprintf(fout,"%b \n",v);
        v=0;
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

int main(void)
{
    transform("numere8.txt","rezultate8.txt");
}