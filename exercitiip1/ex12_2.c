#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *conv(char *prop)
{
    char *rez=NULL;
    rez=(char*)malloc((strlen(prop)/2+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int len=0;
    strcpy(rez,"");
    char aux[3]="",aux1[3]="";
    for(int i=0;i<strlen(prop);i+=2)
    {
        int n=0;
        strncpy(aux1,prop+i,2);
        if(isspace(prop[i]))break;
        if(sscanf(aux1,"%2X",&n)==1)
        {
            sprintf(aux,"%c",n);
            strcat(rez,aux);
            len++;
        }
    }
    rez[len+1]='\0';
    return rez;
    free(rez);
}

int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)!=NULL)
    {
        puts(conv(v));
    }
    return 0;
}