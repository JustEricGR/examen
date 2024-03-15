#include<stdio.h>
#include<stdlib.h>
#define CHUNK 50000

int *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    int n=0,index=0,curent_size=CHUNK;
    int *v=NULL;
    v=(int *)malloc(curent_size*sizeof(int));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin,"%d",&n)==1)
    {
        v[index++]=n;
        if(index==curent_size)
        {
            curent_size+=CHUNK;
            v=(int*)realloc(v,curent_size*sizeof(int));
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
        printf("Eroare la inchidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    *size=index;
    return v;
}

int main(int argc, char **argv)
{
    int size=0;
    int *v=NULL;
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    free(v);
}