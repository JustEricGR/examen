#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000

typedef struct{
    int min;
    int sec;
    int msec;
}Timp;

int citire(Timp *v,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    int i=0;
    while(fscanf(fin,"%d:%d:%d",&v[i].min,&v[i].sec,&v[i].msec)==3)
    {
        i++;
    }
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    return i;
}

/*Timp rapid(Timp *v,int size,const char *f)
{
    FILE *fout;
    if((fout=fopen(f,"wa"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }

    Timp fast;
    fast.min=v[0].min;
    fast.sec=v[0].sec;
    fast.msec=v[0].msec;
    for(int i=0;i<size;i++)
    {
        if(v[i].min<fast.min)
        {
            fast=v[i];
        }
        if(v[i].min==fast.min && v[i].sec<fast.sec)
        {
            fast=v[i];
        }
        if(v[i].min==fast.min && v[i].sec==fast.sec && v[i].msec<fast.msec)
        {
            fast=v[i];
        }
    }
    fprintf(fout,"Cel mai bun timp:%d:%d:%d",fast.min,fast.sec,fast.msec);
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    return fast;
}*/

Timp rapid(Timp *v,int size)
{
    Timp fast;
    fast.min=v[0].min;
    fast.sec=v[0].sec;
    fast.msec=v[0].msec;
    for(int i=0;i<size;i++)
    {
        if(v[i].min<fast.min)
        {
            fast=v[i];
        }
        if(v[i].min==fast.min && v[i].sec<fast.sec)
        {
            fast=v[i];
        }
        if(v[i].min==fast.min && v[i].sec==fast.sec && v[i].msec<fast.msec)
        {
            fast=v[i];
        }
    }
    
    return fast;
}

void diferenta(Timp *v,int size,const char *f)
{
    FILE *fout;
    if((fout=fopen(f,"wa"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    
    Timp fast;
    fast.msec=0;
    fast.sec=0;
    fast.min=0;
    Timp *rez=NULL;
    rez=(Timp*)malloc(size*sizeof(Timp));
    if(!rez)
    {
        printf("Eroare la alocare2\n");
        perror(NULL);
        exit(-1);
    }
    fast=rapid(v,size);
    for(int i=0;i<size;i++)
    {
        
        rez[i].min=0;
        rez[i].sec=0;
        rez[i].msec=0;
        if(fast.msec==v[i].msec && fast.sec==v[i].sec && fast.min==v[i].min)continue;
        if(fast.msec>v[i].msec || fast.sec>v[i].sec || fast.min>v[i].min)
        {
            int ordin=0;
            if(fast.msec>v[i].msec)
            {
                v[i].msec+=10;
                rez[i].msec=v[i].msec-fast.msec;
                ordin++;            
            }
            v[i].sec-=ordin;
            ordin=0;
            if(fast.sec>v[i].sec)
            {
                
                v[i].sec+=10;
                rez[i].sec=v[i].sec-fast.sec;
                ordin++;
            }
            rez[i].min=v[i].min-fast.min-ordin;
        }
        else
        {
            rez[i].msec=v[i].msec-fast.msec;
            rez[i].sec=v[i].sec-fast.sec;
            rez[i].min=v[i].min-fast.min;
        }
    }
    fprintf(fout,"Cel mai bun timp:%d:%d:%d\n",fast.min,fast.sec,fast.msec);

    for(int i=0;i<size;i++)
    {
        fprintf(fout,"+%d:%d:%d\n",rez[i].min,rez[i].sec,rez[i].msec);
    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    free(rez);    

}

int main(int argc,char **argv)
{
    if(argc!=3)
    {
        printf("Argumente insuficiente\n");
        perror(NULL);
        exit(-1);
    }

    Timp *v=NULL;
    v=(Timp*)malloc(SIZE*sizeof(Timp));
    if(!v)
    {
        printf("Eroare la alocare1\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(v,argv[1]);
    v=(Timp*)realloc(v,size*sizeof(Timp));
    diferenta(v,size,argv[2]);
    free(v);
}