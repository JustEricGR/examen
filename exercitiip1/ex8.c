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



void complement(uint16_t *v,int p,int n,int size)
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
        int index=0;
        for(int i=0;i<16;i++)
        {
            if(i<p || i>p+n)
            {
                rez[j]|=v[j];
            }
            else
            {
                rez[j]|=v[j]^(1<<(n+index));
                index++;

            }
        }
        afisare16(v[j]);
        afisare16(rez[j]);
    }
    free(rez);

    

}

int main(void)
{
    int size=0;     
    scanf("%d",&size);
    uint16_t v[size];
    int p=0;
    scanf("%d",&p);
    int n=0;
    scanf("%d",&n);    
    citire(v,size);
    
    complement(v,p,n,size);
    
}