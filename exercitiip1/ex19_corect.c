#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define CHUNK 20

/*int citire(int &size)
{
    int index=0,n=0,curent_size=CHUNK;
    int *v=NULL;
    v=(int*)malloc(curent_size*sizeof(int));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    srand(time(NULL));
    for(int i=0;i<size;i++)
    {
        n=(rand()%(126-32+1))+32;
        v[index++]=n;

    }
}*/

int *citire(int size)
{
    int *v=NULL;
    v=(int*)malloc(size*sizeof(int));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    srand(time(NULL));
    for(int i=0;i<size;i++)
    {
        
        v[i]=(rand()%(126-32+1))+32;

    }
    return v;
}

void afisare(int *v,int size)
{
    char *rez=NULL;
    rez=(char*)malloc(size*3*sizeof(char));
    char aux[4]="";
    strcpy(rez,"");
    for(int i=0;i<size;i++)
    {
        sprintf(aux,"%c ",v[i]);
        strcat(rez,aux);
    }
    rez[strlen(rez)]='\0';
    puts(rez);
    free(rez);
}

int main(void)
{
    int size=0;
    scanf("%d",&size);
    int *v=NULL;
    v=citire(size);
    afisare(v,size);
    free(v);
}