#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 20

/*void schimbare()
{
    char c=0;
    int nr=0;
    //char *sir=NULL;
    while((c=getchar())!=EOF)
    {
        if(isdigit(c))
        {
            nr=c-'0'+nr*10;
        }
    }

}*/

void adaugare()
{
    char line[100]="";
    int len=0;
    if(fgets(line,100,stdin)==NULL)
    {
        printf("Eroare la citire");
        exit(-1);
    }

    len=strlen(line);
    char *prop=NULL;
    prop=(char*)malloc(len*sizeof(char));
    if(!prop)
    {
        printf("Eroare la alocare\n");
        exit(-1);
    }
    int cnt=0;

    for(int i=0;i<len;i++)
    {
        if(isdigit(line[i])&&isdigit(line[i+1]))
        {
            cnt++;
            len++;
            for(int j=len;j>=i+1;j--)
            {
                line[j]=line[j-1];

            }
            
            line[i++]='$';
        }
    }

    line[strlen(line)]=0;
    prop=(char*)realloc(prop,(cnt+len+1)*sizeof(char));
    prop=line;
    printf("%s",prop);
    free(prop);
}

int main(void)
{
    adaugare();
}