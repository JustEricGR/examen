#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CHUNK 20


typedef struct{
    int a;
    int b;
    int c;
    int delta;
    float x1;
    float x2;
    
}Ecuatie;

/*int citire(Ecuatie *v,const char *f)
{
    int i=0;
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin,"%d.%d.%d",&v[i].a,&v[i].b,&v[i].c)==3)
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
    
}*/

Ecuatie *citire(int *size,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    int index=0,curent_size=CHUNK;
    Ecuatie n={0,0,0,0,0};
    Ecuatie *v=NULL;
    v=(Ecuatie*)malloc(curent_size*sizeof(Ecuatie));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    while(fscanf(fin,"%d.%d.%d",&n.a,&n.b,&n.c)==3)
    {
        v[index++]=n;
        if(index==curent_size)
        {
            curent_size+=CHUNK;
            v=(Ecuatie*)realloc(v,curent_size*sizeof(Ecuatie));
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

void grupare(Ecuatie *v,int size,const char *f)
{
    Ecuatie *rez=NULL;
    rez=(Ecuatie*)malloc(size*sizeof(Ecuatie));
    if(!rez)
    {
        printf("Eroare la alocare3\n");
        perror(NULL);
        exit(-1);
    }

    FILE *fout=NULL;
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        
        v[i].delta=0;
        v[i].x1=0;
        v[i].x2=0;
        rez[i].a=v[i].a;
        rez[i].b=v[i].b;
        rez[i].c=v[i].c;
        
        
        //rez[i]=v[i];
        v[i].delta=pow(v[i].b,2)-4*v[i].a*v[i].c;
        rez[i].delta=v[i].delta;
        if(v[i].delta<0)
        {
            fprintf(fout,"Pt coeficientii %d,%d,%d solutia e complexa.\n",rez[i].a,rez[i].b,rez[i].c);
        }
        else if(rez[i].delta==0)
        {
            v[i].x1=v[i].x2=(float)(-v[i].b/2*v[i].a);
            rez[i].x1=v[i].x1;
            rez[i].x2=v[i].x2;
            fprintf(fout,"Pt coeficientii %d,%d,%d solutia este:%.4f si %.4f iar distanta pana la 0 e:%d\n",rez[i].a,rez[i].b,rez[i].c,rez[i].x1,rez[i].x2,abs(rez[i].x1));
        }
        else
        {
            v[i].x1=(float)((-v[i].b-sqrt(v[i].delta))/2*v[i].a);
            v[i].x1=(float)((-v[i].b+sqrt(v[i].delta))/2*v[i].a);
            rez[i].x1=v[i].x1;
            rez[i].x2=v[i].x2;
            fprintf(fout,"Pt coeficientii %d,%d,%d solutia este:%.4f si %.4f, prima distanta:%d si a doua:%d\n",rez[i].a,rez[i].b,rez[i].c,rez[i].x1,rez[i].x2,abs(rez[i].x1),abs(v[i].x2));
        }

    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere1\n");
        perror(NULL);
        exit(-1);
    }
    free(rez);

}

int main(int argc,char **argv)
{
    /*if (argc != 3) 
    {
        printf("Mod de utilizare: %s fisier_intrare fisier_iesire\n", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    Ecuatie *v=NULL;
    int size=0;
    v=citire(&size,argv[1]);
    grupare(v,size,argv[2]);
    free(v);
}

