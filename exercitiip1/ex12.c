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
    char aux[2]="",aux1[2]="";
    aux1[2]='\0';
    for(int i=0;i<strlen(prop);i+=2)
    {
        char aux2[2]="";
        strncpy(aux2,prop+i,2);
        if(sscanf(aux2,"%c%c",&aux[0],&aux[1])==2)
        {
            int n=0;
            n=strtol(aux,NULL,16);
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
        printf("Nu s a putut citi\n");
        perror(NULL);
        exit(-1);
    }
    char *rez=NULL;
    rez=(char*)malloc((strlen(v)/2+1)*sizeof(char));
    rez=conversion(v);
    puts(rez);
    free(rez);
}

