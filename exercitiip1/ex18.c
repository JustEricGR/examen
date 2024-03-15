#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define CHUNK 50000


uint16_t *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    int n=0,index=0,curent_size=CHUNK;
    uint16_t *v=NULL;
    v=(uint16_t*)malloc(curent_size*sizeof(uint16_t));
    if(!v)
    {
        printf("Eoare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin,"%d",&n)==1)
    {
        v[index++]=n;
        if(index==curent_size)
        {
            curent_size+=CHUNK;
            v=(uint16_t*)realloc(v,curent_size*sizeof(uint16_t));
            if(!v)
            {
                printf("Eroare la realocare\n");
                perror(NULL);
                exit(-1);
            }
        }
    }
    
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    *size=index;
    return v;
}



char *afisare16 (uint16_t nr)
{
    uint16_t mask = 0x8000; // 0b1000000000000000
    uint8_t i = 0;
    //char aux[2]="";
    //char rez[17]="";
    char *rez=NULL;
    rez=(char*)malloc(17*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare3\n");
        perror(NULL);
        exit(-1);
    }
    rez[16]='\0';
    //char aux1[17]="";
    for (i = 0; i < 16; i++)
        {
            char c=0;
            if ((nr & mask) == 0)
            {
                
                c='0';
                rez[i]=c;
            }
            else
            {
                
                c='1';
                rez[i]=c;
            }
            
            
            mask = mask >> 1; // mask >>= 1;
        }
    //printf ("\n");
    return rez;
    //free(rez);
}

void afisare(uint16_t *v,int size,int p,int n,const char *f)
{
    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    uint16_t rez[size];
    memset(rez,0,size);
    for(int j=0;j<size;j++)
    {
        int index=0;
        for(int i=0;i<16;i++)
        {
            if(i<=p || i>n+p)
            {
                rez[j]|=v[j];
            }
            else
            {
                rez[j]|=v[j]|(1<<(p+index-1));
                index++;
            }
        }
        fprintf(fout,"%s   %s\n",afisare16(v[j]),afisare16(rez[j]));
        //fprintf(fout,"%s\n",afisare16(rez[j]));
    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
}


int main(int argc, char **argv)
{
    int size=0;
    uint16_t *v=NULL;
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    afisare(v,size,3,5,argv[2]);
    free(v);
}