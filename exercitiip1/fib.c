#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CHUNK 20

char *fib(int n)
{
    char *rez=NULL;
    rez=(char*)malloc(CHUNK*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int a=0,b=1;
    int cnt=4;
    strcpy(rez,"");
    char aux[2]="";
    sprintf(aux,"%d",a);
    strcat(rez,aux);
    strcat(rez," ");
    sprintf(aux,"%d",b);
    strcat(rez,aux);
    strcat(rez," ");
    int c=a+b;
    int index=1;
    for(int i=2;i<n;i++)
    {
        sprintf(aux,"%d",c);
        strcat(rez,aux);
        strcat(rez," ");
        a=b;
        b=c;
        c=a+b;
        cnt+=4;
        if(cnt>=CHUNK)
        {
            index++;
            rez=(char*)realloc(rez,index*CHUNK*sizeof(char));
            if(!rez)
            {
                printf("Eroare la alocare\n");
                perror(NULL);
                exit(-1);
            }
        }
    }
    return rez;
    //free(rez);
}

int main(int argc,char **argv)
{
    /*if(argc!=2)
    {
        printf("Numar incorect de argumente\n");
        perror(NULL);
        exit(-1);
    }*/
    int n=0;
    sscanf(argv[1],"%d",&n);
    char *rez=fib(n);
    puts(rez);
    free(rez);

}