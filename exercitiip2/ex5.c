/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *schimbare(char *prop)
{
    char *rez=NULL;
    int len=0;
    
    rez=(char*)malloc((strlen(prop)+1)*sizeof(char));
    rez[0]='\0';
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int i=0;
    while(prop[i])
    {

        
        if(isdigit(prop[i]))
        {
            int nr=0;
            len=0;
            while(isdigit(prop[i]))
            {
                nr=prop[i]-'0'+nr*10;
                i++;
                len++;
                
            }
            printf("%d\n",nr);
            char *aux = (char *)malloc(strlen(rez) + 3); 
            if (!aux)
            {
                printf("Eroare la alocare\n");
                perror(NULL);
                free(rez);
                exit(-1);
            }
            sprintf(aux,"%s%X",rez,nr);
            free(rez);
            rez=aux;

            i+=len;
        }
        else
        {
            char *aux=(char*)malloc(strlen(rez)+2);
            if (!aux)
            {
                printf("Eroare la alocare\n");
                perror(NULL);
                free(rez);
                exit(-1);
            }
            sprintf(aux,"%s%c",rez,prop[i]);
            free(rez);
            
            i++;
        }


    }
    if(rez[strlen(prop)-1]=='\n')rez[strlen(prop)-1]=0;
    rez[strlen(prop)]=0;
    return rez;
}

int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)==NULL)
    {
        printf("Eroare la citire\n");
        perror(NULL);
        exit(-1);
    }
    puts(schimbare(v));

}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *schimbare(char *prop)
{
    char *rez = (char *)malloc(1); // Inițializare cu șirul vid
    if (!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    rez[0] = '\0';

    int i = 0, len;

    while (prop[i])
    {
        if (isdigit(prop[i]))
        {
            int nr = 0;
            len = 0;

            while (isdigit(prop[i]))
            {
                nr = prop[i] - '0' + nr * 10;
                i++;
                len++;
            }

            printf("%d\n", nr);

            // Realocare dinamică a șirului rez pentru a adăuga caracterele
            char *aux = (char *)malloc(strlen(rez) + 3); // +3 pentru nr, terminator și spațiul pentru aux
            if (!aux)
            {
                printf("Eroare la alocare\n");
                perror(NULL);
                free(rez);
                exit(-1);
            }

            sprintf(aux, "%s%X", rez, nr);
            free(rez); // Eliberarea vechiului șir
            rez = aux; // Actualizarea la noul șir
        }
        else
        {
            char *aux = (char *)malloc(strlen(rez) + 2); // +2 pentru caracterul curent și terminator
            if (!aux)
            {
                printf("Eroare la alocare\n");
                perror(NULL);
                free(rez);
                exit(-1);
            }

            sprintf(aux, "%s%c", rez, prop[i]);
            free(rez);
            rez = aux;
            i++;
        }
    }

    if (rez[strlen(rez) - 1] == '\n')
        rez[strlen(rez) - 1] = '\0';

    return rez;
}

int main(void)
{
    char v[100] = "";

    if (fgets(v, 100, stdin) == NULL)
    {
        printf("Eroare la citire\n");
        perror(NULL);
        exit(-1);
    }

    char *result = schimbare(v);
    puts(result);

    free(result);
    return 0;
}
