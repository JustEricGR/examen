#include<stdio.h>
#define SIZE 100

int citire(int *a)
{
    int i=0;
    while(1)
    {
        
        if((scanf("%d",a+i))!=1)break;
        i++;
    }
    return i;

}

int eliminare(int *v,int size)
{
    int i=0,j=0;
    for(i=0;i<size;i++)
    {
        if(*(v+i)%3==0)
        {
            size--;
            for(j=i;j<size;j++)
            {
                *(v+j)=*(v+j+1);
            }
            i--;
            
        }
    }
    return size;

}

void afisare(int *v,int *size)
{
    for(int i=0;i<*size;i++)
    {
        printf("%d ",*(v+i));
    }printf("\n");
}


int main(void)
{
    int v[SIZE];
    int size=citire(v);
    size=eliminare(v,size);
    afisare(v,&size);


}