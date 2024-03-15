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
    }
}

void compunere(uint8_t a,uint8_t b)
{
    uint32_t rezultat=0;
    uint16_t m1=a+b;
    //rezultat=m1<<16;
    uint16_t m2=0;
    if(a<b)
    {
        m2=b-a;
    }
    else
    {
        m2=a-b;
    }
    rezultat=(m1<<16)|m2;
    afisare32(rezultat);
}

int main(void)
{
    int a=0,b=0;
    scanf("%d",&a);
    scanf("%d",&b);
    afisare16(a);
    printf("\n");
    afisare16(b);
    printf("\n");
    compunere(a,b);
    printf("\n");
}