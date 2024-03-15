#include<stdio.h>
#include<stdint.h>
#define MAX 100

int citire(int *a)
{
    int i=0;
    while(1)
    {
        
        if((scanf("%d",a+i))!=1)break;
        i++;
    }
    return i;

}

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

void afisare16(uint16_t n)
{
    uint32_t m=0;
    m=1<<15;
    for(int i=0;i<16;i++)
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


void nrmax(int *v,int *size)
{
    uint32_t max=0,i=0,indice=0;
    uint32_t rez=0;
    for(i=0;i<*size;i++)
    {
        if((*(v+i)>max)&&(*(v+i)%2)!=0)
        {
            max=*(v+i);
            indice=i;
        }
    }
    rez=max<<16|indice;
    afisare32(indice);
    afisare32(max);
    afisare32(rez);

}

int main(void)
{
    int v[MAX];
    int size=citire(v);
    nrmax(v,&size);
}

