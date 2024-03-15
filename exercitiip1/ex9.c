#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*char *adunare(char *a, char *b)
{
    int len=0;
    char *rez=NULL;
    char aux[3]="";
    int nr1=0,nr2=0,ordin=0;
    if(strlen(a)>strlen(b))
        len=strlen(a);
    else
        len=strlen(b);
    rez=(char*)malloc((len+1)*sizeof(char));
    if(!rez)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    strcpy(rez,"");
    for(int i=0;i<len;i++)
    {
        if(isdigit(a[i])&&isdigit(b[i]))
        {
            nr1=a[i]-'0';
            nr2=b[i]-'0';
            if((nr1+nr2+ordin)>=10)
            {
                ordin++;
                sprintf(aux,"%d",nr1)
                rez[i]=nr1+nr2-10;
            }

        }
    }
    printf("%d\n",nr1);
    printf("%d\n",nr2);
    rez[len+1]=0;
    return rez;
    free(rez);
}

int main(void)
{
    char a[100]="";
    char b[100]="";
    if((fgets(a,100,stdin)!=NULL)&&(fgets(b,100,stdin)))
    {
        puts(adunare(a,b));
    }
}*/

char* adunaSiruri(const char* numar1, const char* numar2) {
    int lungimeMaxima = 101;  // Lungimea maximă a rezultatului (100 cifre + terminatorul null)
    char* rezultat = malloc(lungimeMaxima);
    memset(rezultat, '0', lungimeMaxima - 1);  // Initializare cu zero
    rezultat[lungimeMaxima - 1] = '\0';

    int lungime1 = strlen(numar1);
    int lungime2 = strlen(numar2);

    int minte = 0;  // Variabila pentru memorarea mărimii
    int pozitieRezultat = lungimeMaxima - 2;  // Pozitia incepand de la final, fara terminatorul null

    while (lungime1 > 0 || lungime2 > 0 || minte > 0) {
        int cifra1 = (lungime1 > 0) ? (numar1[--lungime1] - '0') : 0;
        int cifra2 = (lungime2 > 0) ? (numar2[--lungime2] - '0') : 0;

        int suma = cifra1 + cifra2 + minte;
        minte = suma / 10;

        rezultat[pozitieRezultat] = (suma % 10) + '0';

        pozitieRezultat--;
    }

    return rezultat + pozitieRezultat + 1;  // Adaugam pointerul pentru a elimina zerourile initiale
}

int main() {
    const char numar1[] = "7366214790218435";
    const char numar2[] = "87878";

    char* rezultat = adunaSiruri(numar1, numar2);

    printf("Rezultat: %s\n", rezultat);

    free(rezultat);

    return 0;
}