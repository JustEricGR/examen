#include<stdio.h>
#include<stdlib.h>

char *concat(char *s1,char *s2)
{
    int len1=0,len2=0;
    while(s1[len1]!='\0')
    {
        len1++;
    }
    while(s2[len2]!='\0')
    {
        len2++;
    }

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
    char *rez=NULL;
    rez=(char*)malloc((len1+len2+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
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
    rez[len1+len2]='\0';
    return rez;
    free(rez);
}

int main(void)
{
    char s1[100]="",s2[100]="";
    if((fgets(s1,100,stdin)!=NULL)&&(fgets(s2,100,stdin)))
    {
        puts(concat(s1,s2));
    }
    return 0;
}