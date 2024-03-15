#include<stdio.h>
#include<stdlib.h>
#define SIZE 100000

typedef struct{
    int zi;
    int luna;
    int an;
    float euro;
}Curs;

int citire(Curs *v,const char *f)
{
    int i=0;
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }

    while(fscanf(fin,"%d.%d.%d;%g",&v[i].zi,&v[i].luna,&v[i].an,&v[i].euro)==4)
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

void grupare(Curs *v,int size,const char *f)
{
    FILE *fout=NULL;
    Curs *rez=NULL;
    rez=(Curs*)malloc(size*sizeof(Curs));
    if(!rez)
    {
        printf("Eroare la alocare3\n");
        perror(NULL);
        exit(-1);
    }
    if((fout=fopen(f,"w"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        rez[i].zi=v[i].zi;
        rez[i].luna=v[i].luna;
        rez[i].an=v[i].an;
        rez[i].euro=v[i].euro;
        fprintf(fout,"In data de %d.%d.%d cursul a fost %.4f\n",rez[i].zi,rez[i].luna,rez[i].an,rez[i].euro);

    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere2\n");
        perror(NULL);
        exit(-1);
    }
    
    free(rez);
}

void get(char *argument,Curs *v,int size)
{

    Curs c;
    c.zi=0;
    c.luna=0;
    c.an=0;
    c.euro=0;
    
    if(sscanf(argument,"%d.%d.%d",&c.zi,&c.luna,&c.an)!=3)
    {
        printf("Data incorecta\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        if(c.zi==v[i].zi && c.luna==v[i].luna && c.an==v[i].an)
        {
            c.euro=v[i].euro;
        }
    }
    printf("%d.%d.%d;%.4f\n",c.zi,c.luna,c.an,c.euro);

}

int main(int argc,char **argv)
{
    if (argc != 4) 
    {
        printf("Mod de utilizare: %s fisier_intrare fisier_iesire\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    Curs *v=NULL;
    v=(Curs*)malloc(SIZE*sizeof(Curs));
    if(!v)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int size=citire(v,argv[1]);
    grupare(v,size,argv[2]);
    get(argv[3],v,size);
    //v=(Curs*)realloc(v,size*sizeof(Curs));
    free(v);
    return 0;
}

