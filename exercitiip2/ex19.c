#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void conversion(int *v,int size,const char *f)
{
        printf("fisierul s a creat\n");

    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
        printf("fisierul s a creat\n");

    char *rez=NULL;
    rez=(char *)malloc(size*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,"");
    char aux[5]="";
        printf("fisierul s a creat\n");

    for(int i=0;i<size;i++)
    {
        if(v[i]>=32 && v[i]<=126)
        {
            sprintf(aux,"%c ",v[i]);
            strcat(rez,aux);

        }
        else if(v[i]<32)
        {
            v[i]=126-v[i];
            sprintf(aux,"%c ",v[i]);
            strcat(rez,aux);
        }
        else
        {
            if(v[i]>300)
            {
                v[i]=399-v[i]+32;
                sprintf(aux,"%c ",v[i]);
                strcat(rez,aux);
            }
            else if(v[i]>200 && v[i]<300)
            {
                v[i]=299-v[i]+32;
                sprintf(aux,"%c ",v[i]);
                strcat(rez,aux);
            }
            //if(v[i]<200 && v[i]>126)
            else
            {
                v[i]=v[i]-126+32;
                sprintf(aux,"%c ",v[i]);
                strcat(rez,aux);
            }
        }

    }
    fputs(rez,fout);
        printf("fisierul s a creat\n");

    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    free(rez);

}

int main(int argc, char **argv)
{
    int size=0;
    int *v=NULL;
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    conversion(v,size,argv[2]);
    free(v);
}