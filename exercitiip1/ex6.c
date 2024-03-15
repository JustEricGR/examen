#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

char *modificare()
{
    char aux[17]="";
    char prop[1000]="";
    char *rez=NULL;
    if(fgets(prop,1000,stdin)==NULL)
    {
        printf("Nu se poate citi\n");
        perror(NULL);
        exit(-1);
    }
    
    rez=(char*)malloc((strlen(prop)+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    
    int nr=0,cnt=16,index=0;
    for(int i=0;i<strlen(prop);i++)
    {
        if(isdigit(prop[i]))
        {
            nr=prop[i]-'0';
            index++;
            cnt*=index;
            rez=(char*)realloc(rez,(strlen(prop)+cnt+1)*sizeof(char));
            sprintf(aux,"%016b",nr);
            strcat(rez,aux);
            
        }
        
        //if(!isdigit(prop[i]))
        else
        {
            rez = (char *)realloc(rez, (strlen(rez) + 2) * sizeof(char));
            if(!rez)
            {
                printf("Eroare la realocare\n");
                perror(NULL);
                exit(-1);
            }
            rez[strlen(rez)]=prop[i];
            rez[strlen(rez)+1]=0;
        }
        
        

    }
    if(!rez)
    {
        printf("Eroare la realocare\n");
        perror(NULL);
        exit(-1);
    }
    //rez=(char*)realloc(rez,len*sizeof(char));
    
    return rez;
    


}


int main(void)
{
    
    char *v=NULL;
    v=modificare();
    printf("%s",v);
}

/*#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *modificare()
{
    char aux[18] = "";
    char prop[1000] = "";
    char *rez = NULL;
    int cnt = 16;
    int index = 0;

    printf("Introduceti ceva: \n");

    if (fgets(prop, 1000, stdin) == NULL)
    {
        printf("Nu se poate citi\n");
        perror(NULL);
        exit(-1);
    }

    rez = (char *)malloc(1); // Alocare inițială, va fi realocată ulterior

    if (!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    int nr = 0;

    for (int i = 0; i < strlen(prop); i++)
    {
        if (isdigit(prop[i]))
        {
            nr = prop[i] - '0' + nr * 10;
            index++;
            cnt *= index;
            rez = (char *)realloc(rez, (strlen(rez) + cnt + 1) * sizeof(char));
            sprintf(aux, "%016b", nr);
            strcat(rez, aux);
        }

        

        //if (!isdigit(prop[i]))
        else
        {
            rez = (char *)realloc(rez, (strlen(rez) + 2) * sizeof(char));
            rez[strlen(rez)] = prop[i];
            rez[strlen(rez) + 1] = '\0';
        }

        if (!rez)
        {
            printf("Eroare la realocare\n");
            perror(NULL);
            exit(-1);
        }
    }

    return rez;
}

int main(void)
{

    char *v = NULL;
    v = modificare();
    printf("%s", v);

    // Eliberarea memoriei alocate pentru rezultat
    free(v);

    return 0;
}*/
