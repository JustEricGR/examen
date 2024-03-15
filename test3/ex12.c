#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void alfabetic(char *v)
{
    char aux=0;
    for(int i=0;i<strlen(v)-1;i++)
    {
        for(int j=i+1;j<strlen(v);j++)
        {
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
                
            }
        }
    }
}

char *comun(const char *s1,const char *s2)
{
    char *c=NULL;

    int min=0,k=0;
    if(strlen(s1)<strlen(s2))
        min=strlen(s1);
    else
        min=strlen(s2);

    c=(char*)malloc((min+1)*sizeof(char));
    if(!c)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(int i=0;i<strlen(s1);i++)
    {
        for(int j=0;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j])
            {
                c[k]=s1[i];
                k++;
                break;
            }
        }
        

    }
    c[k+1]='\0';
    c=(char*)realloc(c,(k+1)*sizeof(char));
    if(!c)
    {
        printf("Eroare la realocare\n");
        perror(NULL);
        exit(-1);
    }
    alfabetic(c);
    return c;
    free(c);
}

int main(void)
{
    char v[100]="",v1[100]="";
    char *v2=NULL;

    if((fgets(v,100,stdin)!=NULL)&&(fgets(v1,100,stdin)!=NULL))
    {
        v2=comun(v,v1);
        printf("%s\n",v2);
    }
    return 0;
}

