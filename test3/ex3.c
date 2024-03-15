#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char *modificare(char *sir)
{
    char aux[7]="";
    
    int cnt=0,len=0,adder=0;
    for(int i=0;i<strlen(sir);i++)
    {
        if(isalpha(sir[i])==0)
        {
            cnt++;
        }
        
    }
    len=strlen(sir);
    char *temp=(char*)malloc((len+5*cnt+1)*sizeof(char));

    if(!temp)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }


    for(int i=0;i<len;i++)
    {
        if(isalpha(sir[i]))
        {
            temp[i+adder]=sir[i];
        }
        else
        {
            temp[i+adder]='\0';
            sprintf(aux,"[0X%X]",sir[i]);
            strcat(temp,aux);
            adder+=5;

        }
    }
    return temp;
}

int main(void)
{
    char v[100];
    char *v2=NULL;
    if(fgets(v,100,stdin)!=NULL)
    {
        if(v[strlen(v)-1]=='\n')
        {
            v[strlen(v)-1]='\0';
        }
        v2=modificare(v);
    }
    printf("%s\n",v2);
    free(v2);
}
