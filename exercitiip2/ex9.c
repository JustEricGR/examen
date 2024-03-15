#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *parola(int size)
{
    int n=0;
    
    srand(time(NULL));
    char *rez=NULL;
    char aux[2]="";
    rez=(char*)malloc((size+1)*sizeof(char));
    strcpy(rez,"");
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        //char c=0;
        n=(rand()%94)+33;
        sprintf(aux,"%c",n);
        strcat(rez,aux);
    }
    rez[size]='\0';
    return rez;
    //free(rez);

}

int main(int argc, char **argv)
{
    /*if(argc!=3)
    {
        printf("Nr incorect de argumente\n");
        perror(NULL);
        exit(-1);
    }*/
    FILE *fout=NULL;
    if((fout=fopen(argv[1],"w"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    int lungime=0;
    sscanf(argv[2],"%d",&lungime);
    char *rez=(char*)malloc((lungime+1)*sizeof(char));
    rez=parola(lungime);
    fputs(rez,fout);
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    free(rez);
}