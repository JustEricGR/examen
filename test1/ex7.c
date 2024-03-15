#include<stdio.h>
#include<stdint.h>


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
    }
}


void afisare64(uint64_t n)
{
    uint64_t m=0;
    m=(uint64_t)1<<63;
    for(int i=0;i<64;i++)
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

uint64_t combinare(int n)
{
    uint64_t rez=0;
    int i=0,cifra=0;
    while(n!=0)
    {
        cifra=n%10;
        rez|=cifra<<(4*i);
        n/=10;
        i++;

    }
    return rez;
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    afisare64(combinare(n));
}