#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500

int special(int nr)
{
    int s=1;
    for(int i=2;i<=nr/2;i++)
    {
        if(nr%i==0)
        {
            s+=i;
        }

    }
    if(s>nr)
        return 1;
    else
        return 0;
}

int citire(int *v)
{
    int size=0;
    while(1)
    {
        scanf("%d",&v[size]);
        if(v[size]==0)
            break;
        size++;
    }
    return size;
}

void sortare(int *v,int size)
{
    int aux=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void afisare(int *v,int size)
{
    //sortare(v,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

void adaugare(int *a,int *b,int size1,int size2)
{
    int *rez=NULL;
    int cnt=0;
    
    rez=(int *)malloc((size1+size2)*sizeof(int));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size1;i++)
    {
        if(special(a[i])==1)
        {
            rez[cnt]=a[i];
            cnt++;
        }
    }

    for(int i=0;i<size2;i++)
    {
        if(special(b[i])==1)
        {
            for(int j=0;j<cnt;j++)
            {
                if(rez[j]!=b[i])
                {
                    rez[cnt]=b[i];
                    cnt++;
                    break;
                }
                else
                    break;
            }
            
        }
    }
    printf("Dimensiune:%d\n",cnt);
    rez=(int*)realloc(rez,cnt*sizeof(int));
    if(!rez)
    {
        printf("Problema la realocare\n");
        perror(NULL);
        exit(-1);
    }
    sortare(rez,cnt);
    afisare(rez,cnt);
    free(rez);

}

int main(void)
{
    int a[MAX],b[MAX];
    //int *c=NULL;
    int sizea=0,sizeb=0;
    sizea=citire(a);
    sizeb=citire(b);
    /*if(sizea>sizeb)
        size=sizea;
    else
        size=sizeb;*/

    afisare(a,sizea);
    afisare(b,sizeb);
    adaugare(a,b,sizea,sizeb);
    //afisare(c,size);
    
}