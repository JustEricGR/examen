#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10000

typedef struct{
    char en[50];
    char ro[50];
}Dict;

int citire(Dict *v,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }

    int i=0;
    while(fscanf(fin,"%49s = %49s",v[i].en,v[i].ro)==2)
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

void afisare(Dict *v,int size,const char *f)
{
    FILE *fout;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Nu s a putut deschide\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        fprintf(fout,"%s = %s \n",v[i].en,v[i].ro);
    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }

}

void ordine_alf(char *how,Dict *v,int size,const char *f)
{
    
    Dict aux;
    if(!strcasecmp(how,"engleza"))
    {
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(v[i].en[0]>v[j].en[0])
                {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }
    else if(!strcasecmp(how,"romana"))
    {
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(v[i].ro[0]>v[j].ro[0])
                {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }
    else
        printf("Nu s a selectat nicio metoda de ordonare\n");

    if(!strcasecmp(how,"romana") || !strcasecmp(how,"engleza"))
    {
        afisare(v,size,f);
    }

    
}

void get(char *cautare,Dict *v,int size)
{
    Dict rez;
    int contor=0;
    for(int i=0;i<size;i++)
    {
        if(!strcasecmp(cautare,v[i].en))
        {
            contor++;
            strcpy(rez.en,v[i].en);
            strcpy(rez.ro,v[i].ro);
        }
        
    }
    if(contor)
        printf("%s = %s \n",rez.en,rez.ro);
    else
        printf("Nu s a gasit\n");
}



int main(int argc, char **argv)
{
    if(argc!=5)
    {
        printf("Numar incorect de argumente\n");
        perror(NULL);
        exit(-1);
    }
    Dict *v=NULL;
    v=(Dict*)malloc(SIZE*sizeof(Dict));
    if(!v)
    {
        printf("Eroare la alocare in main\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(v,argv[1]);
    get(argv[3],v,size);
    ordine_alf(argv[4],v,size,argv[2]);
    free(v);
    return 0;
}

