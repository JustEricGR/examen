#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

/*void histogramaLitere(const char *f)
{ 
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    unsigned int litereMici[26] = {0}, counter = 0, i = 0;
    char c = 0;
    while((c = fgetc(fin)) != EOF)
    {
        if(isalpha(c))
        {
            litereMici[c - 'a']++;
            counter++;
        }
    }
    for(i=0;i<26;i++)
    {
        printf("%c - %.2f%%\n", i + 'a', (float)litereMici[i] / counter * 100);
    }
    // printf("%d\n", counter);
}*/

void histograma(const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    unsigned int lit[26]={0},counter=0,i=0;
    char c=0;
    while((c=fgetc(fin))!=EOF)
    {
        if(isalpha(c))
        {
            lit[c-'a']++;
            counter++;
        }
        
    }

    for(i=0;i<26;i++)
    {
        printf("%c - %.2f%%\n",'a'+i,(float)lit[i]/counter*100);
    }


}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("Prea putine argumente\n");
        perror(NULL);
        exit(-1);

    }
    histograma(argv[1]);
}