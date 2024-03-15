#include<stdio.h>
#include<stdint.h>

int anlunazi(uint32_t n,int p)
{
    uint8_t ziua=n&0x0F,luna=(n>>4)&0xF;
    uint32_t an=n>>8;
    switch(p)
    {

        case 0:
        {
            return ziua;
            break;
        }
        case 1:
        {
            return luna;
            break;
        }
        case 2:
        {
            return an;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }

}

int main(void)
{
    int n=0,p=0;
    scanf("%d",&n);
    scanf("%d",&p);
    printf("%d\n",anlunazi(n,p));

    return 0;
}