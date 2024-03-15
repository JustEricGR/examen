#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 50000

int *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la citire\n");
        perror(NULL);
        exit(-1);
    }
    int *v=NULL;
    int n=0,index=0,curent_size=CHUNK;
    v=(int*)malloc(curent_size*sizeof(int));
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
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }
    *size=index;
    return v;
}


/*int *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    int n=0,index=0;
    int curent_size=CHUNK;
    int *v=NULL;
    v=(int*)malloc(curent_size*sizeof(int));
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
    *size=index;
    return v;
}*/

void sortare2(int *v,int size)
{
    int aux=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void sortare1(int *v,int size)
{
    int aux=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(v[i]<v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void afisare(int *v,int size,const char *f)
{
    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        fprintf(fout,"%d ",v[i]);
    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }
}

int main(int argc,char **argv)
{
    if(argc!=4)
    {
        printf("Numar incorect de argumente\n");
        perror(NULL);
    }
    int *v=NULL;
    int size=0;
    
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    int contor=0;
    if(strcasecmp(argv[3],"crescator"))contor=0;
    else if(strcasecmp(argv[3],"descrescator")) contor++;
    else contor+=2;
    switch(contor)
    {
        case 0:
        {
            sortare1(v,size);
            afisare(v,size,argv[2]);
            break;
        }
        case 1:
        {
            sortare2(v,size);
            afisare(v,size,argv[2]);
            break;
        }
        default:
        {
            afisare(v,size,argv[2]);
            break;
        }
    }
    free(v);
}

