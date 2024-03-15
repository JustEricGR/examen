#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdint.h>
#define maxim 500000

void citire(uint16_t *v,int size)
{
    srand(time(NULL));
    for(int i=0;i<size;i++)
    {
        v[i]=rand()%maxim;
    }
}

char *afisare16 (uint16_t nr)
{
    //char s[18]="";
    char *s=(char*)malloc(18*sizeof(char));
    strcpy(s,"");
    char aux[2]="";
  uint16_t mask = 0x8000; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 16; i++)
    {
      if ((nr & mask) == 0)
        {
          sprintf (aux,"%c",'0');
          strcat(s,aux);
        }
      else
        {
          sprintf (aux,"%c",'1');
          strcat(s,aux);
        }
      mask = mask >> 1; // mask >>= 1;
    }
  s[17]=0;
  return s;
}

void afisare(uint16_t *v,int size)
{
    char *c=NULL;
    for(int i=0;i<size;i++)
    {
        c=afisare16(v[i]);
        printf("%s ",c);
        free(c);
    }printf("\n");
}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    uint16_t v[n];
    citire(v,n);
    afisare(v,n);
    
    

}