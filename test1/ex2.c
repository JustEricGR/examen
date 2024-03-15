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

void afisare8(uint8_t n)
{
    uint32_t m=0;
    m=1<<7;
    for(int i=0;i<8;i++)
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

uint8_t inversare(uint8_t n)
{
    uint8_t n1=0x0F,n2=0xF0;
    n1&=n;
    n2&=n;
    uint8_t rez=(n1<<4)|(n2>>4);
    return rez;
}

uint32_t ex2(uint32_t n)
{
    uint32_t final=0;
    final|=inversare(n);
    for(int i=8;i<32;i+=8)
    {
        final|=inversare(n<<(i-1));
    }
    
    return final;
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    afisare8(n);
    printf("\n");
    afisare32(n);
    printf("\n");
    afisare32(ex2(n));
    printf("\n");
}