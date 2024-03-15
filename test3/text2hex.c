#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *fct(char *v)
{
    char aux[3]="";
    char *rez=NULL;
    rez=(char*)malloc((2*strlen(v)+1)*sizeof(char));
    int i=0;
    strcpy(rez,"");
    for(i=0;i<strlen(v);i++)
    {
        sprintf(aux,"%02X",v[i]);
        strcat(rez,aux);
        
    }
    return rez;
}

int main(void)
{
    char v[100]="";
    char *v1=NULL;
    if(fgets(v,100,stdin)!=NULL)
    {
        v1=fct(v);
        printf("%s\n",v1);
    }
    free(v1);
    return 0;
}

