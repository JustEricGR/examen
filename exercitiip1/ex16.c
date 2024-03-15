#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


void citire(uint16_t *v,int size)
{
    for(int i=0;i<size;i++)
    {
        if(scanf("%hd",&v[i])!=1)break;
    }
}

void afisare16 (uint16_t nr)
{
  uint16_t mask = 0x8000; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 16; i++)
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

void set_bits(uint16_t *v,int size,int n,int p)
{
    uint16_t *rez=NULL;
    
    rez=(uint16_t*)malloc(size*sizeof(uint16_t));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int j=0;j<size;j++)
    {
        uint16_t mask = ((1 << p) - 1) << n; // Construim masca pentru biții ce trebuie setați sau resetați
        rez[j]=v[j] | mask;  // Setăm biții cu 1
        afisare16(rez[j]);

        rez[j]=v[j] & ~mask;  // Resetăm biții cu 0
        afisare16(v[j]);
        
    }
}

int main(void)
{
    int size=0,n=0,p=0;
    scanf("%d",&size);
    scanf("%d",&n);
    scanf("%d",&p);
    uint16_t v[size];
    citire(v,size);
    
    set_bits(v,size,n,p);
}