#include<stdio.h>
#include<stdint.h>

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

int minim(int min,int a)
{
    if(min>a)min=a;
    return min;
}

int medie(int suma,int numere)
{
    return suma/numere;
}

int main(void)
{
    int n=0,suma=0,nrcif=0,min=0;
    scanf("%d",&n);
    min=n;
    while(n!=0)
    {
        suma+=n;
        nrcif++;
        min=minim(min,n);
        scanf("%d",&n);
        
    }
    int media=medie(suma,nrcif);
    printf("Media:%d\n",media);
    printf("Minimul:%d\n",min);

    afisare16(media);
    printf("\n");
    afisare16(min);
    printf("\n");
    //uint16_t rez1=media,rez2=min;

    uint32_t rezultat=0;
    /*rezultat=media;
    rezultat<<=16;
    rezultat|=min;*/
    rezultat=(media<<16)|min;
    afisare32(rezultat);
    
    printf("\n");
}