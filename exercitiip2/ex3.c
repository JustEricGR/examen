#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 10000000

typedef struct{
    int real;
    float fractionar;
}Numar;

int citire(float *v,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    
    int i=0;
    while(1)
    {
        if(fscanf(fin,"%g",&v[i])!=1)break;
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

/*void sortare(float *v,int size)
{
    float aux=0;
    float *rez=(float*)malloc(size*sizeof(float));
    if(!rez)
    {
        printf("Eroare la alocare2\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        rez[i]=v[i];
        for(int j=i+1;j<size;j++)
        {
            rez[j]=v[j];
            if(rez[i]>rez[j])
            {
                aux=rez[i];
                rez[i]=rez[j];
                rez[j]=aux;
            }
        }
    }
    free(rez);
}*/

void sortare(float *v,int size)
{
    float aux=0;
    
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



void despartire(float *v,int size,const char *f)
{
    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    Numar *rez=(Numar*)malloc(size*sizeof(Numar));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    
    sortare(v,size);
    for(int i=0;i<size;i++)
    {
        rez[i].real=floor(v[i]);
        rez[i].fractionar=v[i]-floor(v[i]);
        fprintf(fout,"%g=%d+%.04f\n",v[i],rez[i].real,rez[i].fractionar);
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
    float *valori=NULL;
    valori=(float*)malloc(SIZE*sizeof(float));
    if(!valori)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(valori,argv[1]);
    valori =(float*) realloc(valori, size*sizeof(float));
    
    despartire(valori,size,argv[2]);
    
    free(valori);
}

