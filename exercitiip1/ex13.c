#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *modif1(char *sir)
{
    char *rez=NULL;
    
    int len=strlen(sir);
    rez=(char*)malloc((len+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,sir);
    for(int i=0;i<len;i++)
    {
        
        if(rez[i]=='a' || rez[i]=='e' || rez[i]=='i' || rez[i]=='o' || rez[i]=='u')
        {
            for(int j=i+1;j<len;j++)
            {
                rez[j-1]=rez[j];
                
            }      
            len--;      
            i--;
            
        }
        if(rez[i]=='\n')rez[i]=0;
        
        
    }
    return rez;
    free(rez);
}

char *modif2(char *sir)
{
    char *rez=NULL;
    
    int len=strlen(sir);
    rez=(char*)malloc((len+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,sir);
    for(int i=0;i<len;i++)
    {
        if(islower(rez[i]))
        {
            rez[i]=toupper(rez[i]);
        }
        if(rez[i]=='\n')rez[i]=0;
    }
    return rez;
    free(rez);
}

char *modif3(char *sir)
{
    char *rez=NULL;
    int pozitie=0;
    int count=0;
    int len=strlen(sir);
    rez=(char*)malloc((len+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,sir);
    int j=0;
    for(int i=0;i<len;i++)
    {
        j=i;
        if(isdigit(rez[i]))
        {
            pozitie=i;
            while(isdigit(rez[j]))
            {
                count++;
                j++;
            }
            if(count>1)
            {
                for(int k=pozitie;k<len;k++)
                {
                    rez[k-count]=rez[k];
                }
                i-=count;
                len-=count;
            }
        }
        if(rez[i]=='\n')rez[i]=0;
    }
    return rez;
    free(rez);

}

int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)==NULL)
    {
        printf("Nu s a putut citi\n");
        perror(NULL);
        exit(-1);
    }
    puts(modif1(v));
    puts(modif2(v));
    puts(modif3(v));
}