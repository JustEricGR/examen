#include<stdio.h>
#include<stdint.h>

void afisare32 (uint32_t nr)
{
  uint32_t mask = 0x80000000; 
  int i = 0;
  for (i = 0; i < 32; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
    printf ("\n");
}

int paritate (uint32_t nr)
{
  uint32_t mask = 0x80000000; 
  int i = 0;
  int par=0;
  for (i = 0; i < 32; i++)
    {
        if ((nr & mask) == 0)
            {
            par++;
            }
        
        mask = mask >> 1; // mask >>= 1;
    }
    if(par%2==0)
        return 0;
    else
        return 1;

}

uint32_t schimbare (uint32_t nr,int n)
{
    uint32_t mask = 0xFFFFFFFF; 
    int rez1=0,rez2=0;
    if(n>0&&n<25)
    {
        if (((nr<<(n-1)) & mask) == 0)
        {
            rez1=0;
        }
        else
        {
            rez1=1;
        }

        if (((nr<<(n+1)) & mask) == 0)
        {
            rez2=0;
        }
        else
        {
            rez2=1;
        }
    }
    if(rez1==rez2)
    {
        nr|=1<<n;

    }
    else
    {
        nr&=paritate(nr)<<n;
    }
    return nr;
    
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    int index=0;
    scanf("%d",&index);
    afisare32(n);
    
    afisare32(schimbare(n,index));
    printf("%016X\n",schimbare(n,index));
}