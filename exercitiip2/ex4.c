#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000000

typedef struct{
    int x;
    int y;
}Puncte;

int citire(Puncte *v,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    
    int i=0;
    while(fscanf(fin,"%d.%d",&v[i].x,&v[i].y)==2)
    {
        i++;
    }
    
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }
    return i;

}

void afisare(Puncte *v,int size,const char *f)
{
    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    Puncte *rez=NULL;
    rez=(Puncte*)malloc(size*sizeof(Puncte));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        rez[i].x=v[i].x;
        rez[i].y=v[i].y;
        fprintf(fout,"x:%d , y:%d\n",rez[i].x,rez[i].y);
    }
    fclose(fout);
    free(rez);

}

int main(int argc,char **argv)
{
    if (argc != 3) 
    {
        printf("Mod de utilizare: %s fisier_intrare fisier_iesire\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    Puncte *v=NULL;
    v=(Puncte*)malloc(SIZE*sizeof(Puncte));
    if(!v)
    {
        printf("Problema la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(v,argv[1]);
    //v=(Puncte*)realloc(v,size*sizeof(Puncte));
    afisare(v,size,argv[2]);
    free(v);
}