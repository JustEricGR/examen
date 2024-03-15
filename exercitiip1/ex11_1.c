#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *conversion(char *prop)
{
    char *rez=NULL;
    rez=(char*)malloc((strlen(prop)+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,"");
    char aux[3]="",aux1[3]="";
    aux1[3]='\0';
    for(int i=0;i<strlen(prop);i+=3)
    {
        char aux2[3]="";
        strncpy(aux2,prop+i,3);
        if(sscanf(aux2,"%c%c%c",&aux[0],&aux[1],&aux[2])==3)
        {
        int n=0;
        n=strtol(aux,NULL,8);
        sprintf(aux1,"%c",n);
        strcat(rez,aux1);
        }
        
    }
    
    rez[strlen(prop)]='\0';
    return rez;
    free(rez);
}

int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)==NULL)
    {
        printf("Eroare la citire\n");
        perror(NULL);
        exit(-1);
    }
    char *rez=NULL;
    rez=(char*)malloc(((strlen(v))/3+1)*sizeof(char));
    rez=conversion(v);

    puts(rez);
    free(rez);
    return 0;
}