#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 20

typedef struct{
    char en[50];
    char ro[50];
}Dict;

Dict *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }

    int index=0,curent_size=CHUNK;
    Dict *v=NULL;
    v=(Dict*)malloc(curent_size*sizeof(Dict));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    Dict n={"",""};
    char line[200]="";
    while(fgets(line,200,fin)!=NULL)
    {
        sscanf(line,"%49[^=]=%49s",n.en,n.ro);
        v[index++]=n;
        if(index==curent_size)
        {
            curent_size+=CHUNK;
            v=(Dict*)realloc(v,curent_size*sizeof(Dict));
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

void get(char *cuvant,Dict *v,int size)
{
    int counter=0;
    Dict rez={"",""};
    for(int i=0;i<size;i++)
    {
        if(!strncasecmp(cuvant,v[i].en,strlen(cuvant)))
        {
            strcpy(rez.en,v[i].en);
            strcpy(rez.ro,v[i].ro);
            counter++;

            //printf("%s = %s\n",v[i].en,v[i].ro);
        }
        /*else
        {
            printf("Nu s a gasit\n");
        }*/
        
    }
    if(counter)printf("%s=%s\n",rez.en,rez.ro);
        else printf("Nu s a gasit\n");
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
        fprintf(fout,"%s = %s\n",v[i].en,v[i].ro);
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
    Dict *v=NULL;
    int size=0;
    v=citire(&size,argv[1]);
    printf("size:%d\n",size);
    afisare(v,size,argv[2]);
    get(argv[3],v,size);
}