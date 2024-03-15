#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *conversie(char *prop)
{
    char *rez=NULL;
    rez=(char*)malloc((strlen(prop)/2+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,"");
    char aux[3]="",aux1[3]="",aux2[3]="";
    aux[3]='\0';

    for(int i=0;i<strlen(prop);i+=2)
    {
        if(isspace(prop[i]))continue;
        strncpy(aux,prop+i,2);
        if((sscanf(aux,"%c%c",&aux1[0],&aux1[1]))==2)
        {
            int n=0;
            n=strtol(aux1,NULL,16);
            sprintf(aux2,"%c",n);
            strcat(rez,aux2);
        }
    }

    /*while((sscanf(prop,"%c%c"),&aux[0],&aux[1])==2)
    {
        int n=0;
        n=strtol(aux,NULL,16);
        sprintf(aux1,"%d",n);
        strcat(rez,aux1);

    }*/
    return rez;
    free(rez);
}


int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)!=NULL)
    {
        puts(conversie(v));
    }


}