#include<stdio.h>
#include<stdint.h>

int main()
{
    int n=0,par=0,nrcif=0;
    scanf("%d",&n);
    
      
    while(n!=0)
    {
        nrcif++;
        if((n%10)%2==0)par++;
        n/=10;


    }
    uint8_t rez=0;
    rez=(nrcif<<4)|par;

    

    printf("Numarul de cifre:%d\n",nrcif);
    printf("Numarul de cifre pare:%d\n",par);
    printf("Nr rezultat:0X%X\n",rez);
}