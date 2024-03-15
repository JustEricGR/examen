#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define CHUNK 50000


uint16_t *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    int index=0,nr=0,curent_size=CHUNK;
    uint16_t *v=NULL;
    v=(uint16_t*)malloc(curent_size*sizeof(uint16_t));
    if(!v)
    {
        printf("Eroare la alocare1\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin,"%d",&nr)==1)
    {
        v[index++]=nr;
        if(index==curent_size)
        {
            curent_size+=CHUNK;
            v=(uint16_t*)realloc(v,curent_size*sizeof(uint16_t));
            if(!v)
            {
                printf("Eroare la alocare1\n");
                perror(NULL);
                exit(-1);
            }
        }
    }
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }
    *size=index;
    return v;
}

char *afisare16 (uint16_t nr)
{
  uint16_t mask = 1; // 0b1000000000000000
  mask<<=15;
  uint8_t i = 0;
  char *aux=NULL;
  aux=(char*)malloc(17*sizeof(char));
  aux[17]='\0';
  strcpy(aux,"");
  char aux1[2]="";
  for (i = 15; i >=0; i--)
    {
      if ((nr & mask) == 0)
        {
          sprintf (aux1,"%c",'0');
          strcat(aux,aux1);
        }
      else
        {
          sprintf (aux1,"%c",'1');
          strcat(aux,aux1);
        }
      mask = mask >> 1; // mask >>= 1;
    }
    return aux;
    free(aux);
  
}

void complement(uint16_t *v,int size,int p,int n,const char *f)
{
    FILE *fout=NULL;
    if((fout=fopen(f,"wa"))==NULL)
    {
        printf("Eroare la deschidere out\n");
        perror(NULL);
        exit(-1);
    }
    uint16_t *rez=NULL;
    rez=(uint16_t*)malloc(size*sizeof(uint16_t));
    for(int j=0;j<size;j++)
    {
        int index=0;

        for(int i=0;i<16;i++)
        {
            if(i<p || i>n+p-1)
            {
                rez[j]|=v[j];
            }
            else
            {
                rez[j]|=v[j]^(1<<(p+index));
                index++;
            }
        }
        fputs(afisare16(v[j]),fout);
        fputs(afisare16(rez[j]),fout);
    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    free(rez);
    
}



/*void afisare(uint16_t *v,int size)
{
    for(int i=0;i<size;i++)
    {
        afisare16(v[i]);
        afisare16(complement(v[i],size,3,5));
    }
}*/



int main(int argc,char **argv)
{
    uint16_t *v=NULL;
    int size=0;
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    complement(v,size,3,5,argv[2]);
    return 0;
}