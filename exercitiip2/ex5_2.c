#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


char *inlocuire(char *prop)
{
    char *rez=NULL;
    rez=(char*)malloc((strlen(prop)+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    int counter=0,j=0;
    while(prop[j])
    {
        if(isdigit(prop[j]))
        {
            counter++;
            while(isdigit(prop[j]))
            {
                j++;
            }
        }
        else
            j++;

    }
    printf("%d\n",counter);

    strcpy(rez,"");
    rez=(char*)realloc(rez,(strlen(prop)+8*counter+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la realocare\n");
        perror(NULL);
        exit(-1);
    }
    int i=0;
    char aux[9]="";
    while(prop[i])
    {
        int nr=0;
        if(isdigit(prop[i]))
        {
            while(isdigit(prop[i]))
            {
                nr=prop[i]-'0'+nr*10;
                i++;
            }
            sprintf(aux,"%08b",nr);
            strcat(rez,aux);
        }
        else
        {
            sprintf(aux,"%c",prop[i]);
            strcat(rez,aux);
            i++;
        }
    }
    //memset(aux,0,sizeof(aux));
    rez[strlen(prop)+counter*8+1]='\0';
    return rez;
    //free(rez);
}

int main(void)
{
    
    char v[200]="";
    if(fgets(v,200,stdin)!=NULL)
    {
        char *rez=NULL;
        rez=inlocuire(v);
        puts(rez);
        free(rez);
    }
    return 0;
}