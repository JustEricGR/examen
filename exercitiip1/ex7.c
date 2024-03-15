#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CHUNK 100


char *fibo(int n)
{
    char *s=NULL;
    s=(char*)malloc(CHUNK*sizeof(char));
    if(!s)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    //strcpy(s,"");
    char aux[2]="";
    int a=0,b=1;
    int cnt=4,index=1;
    sprintf(aux,"%d",a);
    strcat(s,aux);
    strcat(s," ");
    sprintf(aux,"%d",b);
    strcat(s,aux);
    strcat(s," ");
    int c=a+b;
    for(int i=2;i<n;i++)
    {
        sprintf(aux,"%d",c);
        strcat(s,aux);
        strcat(s," ");
        a=b;
        b=c;
        c=a+b;
        cnt+=5;
        if(cnt>=CHUNK)
        {
            index++;
            s=(char*)realloc(s,index*CHUNK*sizeof(char));
            if(!s)
            {
                printf("Eroare la realocare\n");
                perror(NULL);
                exit(-1);
            }
        }
    }
    //s[cnt+1]=0;
    return s;

}

int main(void)
{
    int n=0;
    scanf("%d",&n);
    char *s=NULL;
    s=fibo(n);
    puts(s);
    free(s);
}