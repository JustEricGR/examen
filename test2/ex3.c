#include<stdio.h>
#define SIZE 20

void citire(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        if((scanf("%d",&a[i]))!=1)break;
    }

}

void afisare(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

void inserare(int *v,int size)
{
    int v1[SIZE],j=0;
    for(int i=0;i<size;i++)
    {
        if((v[i]%2!=0)&&(i%2==0))
        {
            v1[j]=v[i];
            j++;
        }
    }
    afisare(v1,j);
    
}




int main(void)
{
    int n=0;
    int v[SIZE];
    scanf("%d",&n);
    citire(v,n);
    afisare(v,n);
    inserare(v,n);
}