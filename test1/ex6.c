#include<stdio.h>
#include<stdint.h>

void afisare16(uint16_t n)
{
    uint16_t m=0;
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
    printf("\n");
}

void afisare(uint16_t nr,int n,int p)
{
    
    for(int i=0;i<16;i++)
    {
        if(i>=p&&n!=0)
        {
            nr=nr^(1<<i);
            n--;
        }
    }
    afisare16(nr);

}

int main(void)
{
    int nr=0,p=0,n=0;
    scanf("%d %d %d ",&nr,&p,&n);
    afisare16(nr);
    afisare(nr,p,n);
}