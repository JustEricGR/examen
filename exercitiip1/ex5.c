#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

typedef struct{
    uint8_t zi_sapt;
    uint8_t zi;
    uint8_t luna;
    uint16_t an;
}DATA;

void adaugare()
{
    DATA data;
    char zi[9]="";
    char luna[11]="";
    scanf("%hhd, %hhd/%hhd/%hd",&data.zi_sapt,&data.zi,&data.luna,&data.an);

    switch(data.zi_sapt)
    {
        case 1:
        {
            strcpy(zi,"luni");
            break;
        }
        case 2:
            strcpy(zi, "marti");
            break;
        case 3:
            strcpy(zi, "miercuri");
            break;
        case 4:
            strcpy(zi, "joi");
            break;
        case 5:
            strcpy(zi, "vineri");
            break;
        case 6:
            strcpy(zi, "sambata");
            break;
        case 7:
            strcpy(zi, "duminica");
            break;
    }

    switch(data.luna)
    {
        case 1:
            strcpy(luna, "ianuarie");
            break;
        case 2:
            strcpy(luna, "februarie");
            break;
        case 3:
            strcpy(luna, "martie");
            break;
        case 4:
            strcpy(luna, "aprilie");
            break;
        case 5:
            strcpy(luna, "mai");
            break;
        case 6:
            strcpy(luna, "iunie");
            break;
        case 7:
            strcpy(luna, "iulie");
            break;
        case 8:
            strcpy(luna, "august");
            break;
        case 9:
            strcpy(luna, "septembrie");
            break;
        case 10:
            strcpy(luna, "octombrie");
            break;
        case 11:
            strcpy(luna, "noiembrie");
            break;
        case 12:
            strcpy(luna, "decembrie");
            break;
    }

    char *p=NULL;
    p=(char*)malloc(sizeof(DATA));
    if(!p)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(p,zi);
    sprintf(p,"%d",data.zi);
    strcat(p,zi);
    strcat(p,", ");
    
    strcat(p," ");
    strcat(p, luna);
    strcat(p, " ");
    sprintf(zi, "%d", data.an);
    strcat(p, zi);
    puts(p);
}

int main(void)
{
    
    adaugare();
}

