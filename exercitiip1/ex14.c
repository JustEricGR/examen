#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *mystrcat(char *s1,char *s2)
{
    char *rez=NULL;
    rez=(char*)malloc(sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int len1=0,len2=0,adder=0;
    while(s1[len1]!='\0')
    {
        len1++;
    }

    while(s2[len2]!='\0')
    {
        len2++;
    }
    rez=(char*)realloc(rez,(len1+len2+1)*sizeof(char));

    if(s1[len1-1]=='\n')
    {
        s1[len1-1]='\0';
        len1--;
    }

    if(s2[len2-1]=='\n')
    {
        s2[len2-1]='\0';
        len2--;
    }

    for(int i=0;i<len1+len2;i++)
    {
        if(i<len1)
        {
            rez[i]=s1[i];
        }
        else
        {
            rez[i]=s2[i-len1];
        }
    }
    
    
    printf("%d\n",len1);
    printf("%d\n",len2);
    return rez;
}

int main(void)
{
    char *rez=NULL;
    char a[100]="",b[100]="";
    if((fgets(a,100,stdin)!=NULL)&&fgets(b,100,stdin)!=NULL)
    {
        rez=mystrcat(a,b);
        puts(rez);
        free(rez);
    }
}