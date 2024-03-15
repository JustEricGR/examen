#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define SIZE 200

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


int citire(int *a)
{
    int i=0;
    while(1)
    {
        
        if((scanf("%d",&a[i]))!=1)break;
        i++;
    }
    return i;

}

void citire1(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        if((scanf("%d",&a[i]))!=1)break;
    }

}


void afisareVect(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        afisare32(v[i]);
    }printf("\n");
}



void inserare(int *a,int size)
{
    int b[size],i=0,j=0;
    citire1(a,size);
    for(i=0;i<size;i++)
    {
        if(nrBiti(a[i])%2==0)
        {
            b[j]=a[i];
            j++;
        }
        

    }
    afisareVect(b,j);
}

int main(void)
{
    int v[SIZE];
    
    
    int size=citire(v);
    afisareVect(v,size);
    inserare(v,size);
    
}