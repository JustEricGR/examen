#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void histo(const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    unsigned int lit[26]={0};
    int i=0,counter=0;
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
        printf("%c - %.4f%%\n",'a'+i,(float)lit[i]/counter*100);
    }
    fclose(fin);
}

int main(int argc,char **argv)
{
    histo(argv[1]);
}