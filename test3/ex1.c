#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *cifru(char *prop,int cheie)
{
    int i=0;
    char *temp=(char*)malloc((strlen(prop)+1)*sizeof(char));
    if(!temp)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(i=0;i<strlen(prop);i++)
    {
        if(!isalpha(prop[i]))
        {
            temp[i]=prop[i];
            continue;
        }
        temp[i]=prop[i]+cheie;
        
    }
    temp[i+1]=0;
    return temp;
    free(temp);
}

int main(void)
{
    char propozitie[1000];
    int n=0;
    fgets(propozitie,1000,stdin);
    scanf("%d",&n);    
    printf("%s\n",cifru(propozitie,n));
    return 0;
}