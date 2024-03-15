#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void adunare(char *a, char *b)
{
    int len1=strlen(a);
    int len2=strlen(b);
    int len=0;
    char aux1[4]="", aux2[4]="";
    aux1[4]='\0';
    aux2[4]='\0';
    if(len1>len2)
        len=len1;
    else
        len=len2;
    char *rez=NULL;
    char aux[5]="";
    aux[4]='\0';
    rez=(char*)malloc((len+1)*sizeof(char));
    strcpy(rez,"");
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int ordin=0;
    for(int i=len-1;i>=0;i-=3)
    {
        int x=0,y=0;
        snprintf(aux1,4,"%s",a+i-1);
        snprintf(aux2,4,"%s",b+i-1);
        x=strtol(aux1,NULL,10);
        y=strtol(aux2,NULL,10);
        int z=0;
        if(x/100==0 && y/100==0)
        {
            if((x+y)>100)
            {
                z=100-(x+y);
                ordin++;
            }
            else
            {
                z=x+y;
            }
            sprintf(aux,"%4d",z);
            strcat(rez+i-2,aux);
        }
        /*printf("%d\n",x);
        printf("%d\n",y);*/
        if(x/1000==0 && y/1000==0)
        {
            if((x+y+ordin)>100)
            {
                z=1000-(x+y+ordin);
                ordin++;
            }
            else
            {
                z=x+y+ordin;
            }
            sprintf(aux,"%4d",z);
            strcat(rez+i-3,aux);
        }
        /*sprintf(aux,"%d",z);
        strcat(rez+i-1,aux);*/
    }
    puts(rez);
    free(rez);
}

int main(int argc, char **argv)
{
    /*if(argc!=3)
    {
        printf("Numar incorect de argumente\n");
        perror(NULL);
        exit(-1);
    }*/
    
    adunare(argv[1],argv[2]);
}