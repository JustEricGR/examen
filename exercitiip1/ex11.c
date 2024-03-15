#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*char *modif(char *nr)
{
    char *rez=NULL;
    rez=(char*)malloc(strlen(nr)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);

    }
    char aux[4]="";
    int adder=0;
    int n=0;
    strcpy(rez,"");

    for(int i=0;i<strlen(nr);i++)
    {
        sscanf(aux,"%c",&nr[i]);

        printf("%s",aux);
        sprintf(rez,"%s",aux);
        for(int j=i;j<i+3;j++)
        {
            sprintf(aux,"%o",nr[j]);
        }
        puts(aux);
        //n=strtol(aux,NULL,10);
        printf("%d\n",n);
        //sprintf(aux,"%c",nr[i]);
        //aux[i+adder]=nr[i];
        //if(i%3==0)
        strcat(rez,aux);

    }
    while(sscanf(aux,"%s",nr)==1)
    {
        strcpy(aux,nr);
        strcat(rez,aux);

    }
    //rez[strlen(nr)+1]=0;
    return rez;
}*/

/*void modif(int n)
{
    char caract[4]="";
    snprintf(caract,sizeof(caract),"%o",n);
    int ascii=strtol(caract,NULL,8);
    printf("%c",(char)ascii);

}

int main(void)
{
    char v[100]="";
    if(fgets(v,100,stdin)!=NULL)
    {
        
        puts(modif(v));
    }

    int nr1=0,nr2=0,nr3=0;
    while(scanf("%o%o%o",&nr1,&nr2,&nr3)==3)
    {
        modif(nr1);
        modif(nr2);
        modif(nr3);
    }


}*/

void convertesteBaza8LaASCII(int numar) {
    char caractere[4];  // Un număr în baza 8 are maxim 3 cifre + terminatorul null

    // Transformă numărul din baza 8 în șir de caractere
    sprintf(caractere, "%o", numar);

    // Converteste șirul de caractere la un întreg
    puts(caractere);
    int ascii = strtol(caractere, NULL, 8);

    // Afișează caracterul ASCII corespunzător
    putchar (ascii);
}

int main() {
    FILE *file = fopen("numere.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Nu s-a putut deschide fisierul.\n");
        return 1;
    }

    int numar1, numar2, numar3;

    // Citeste perechile de 3 numere din fisier
    while (scanf("%o%o%o", &numar1, &numar2, &numar3) == 3) {
        // Convertește fiecare număr în caracter ASCII și afișează rezultatul
        convertesteBaza8LaASCII(numar1);
        convertesteBaza8LaASCII(numar2);
        convertesteBaza8LaASCII(numar3);
    }

    fclose(file);

    return 0;
}