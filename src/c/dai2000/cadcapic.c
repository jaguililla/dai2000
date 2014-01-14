//capicua
#include<string.h>
#include<stdio.h>


#define N 51

int capi (char cad[], int longi)
{
    int indice;

    for (indice = 0; indice < longi / 2; indice++)
        if (cad[indice] != cad[longi - indice - 1])
            return (0);

    return (1);                 //1 quiere decir que es capicúa
}

void elimina (char cad[], char resul[])
{
    int longitud = 0, cont1 = 0, cont2 = 0;

    longitud = strlen (cad);

    for (cont1 = 0, cont2 = 0; cont1 <= longitud; cont1++) {
        if (cad[cont1] != ' ') {
            resul[cont2] = cad[cont1];
            cont2++;
        }
    }
}

void main (void)
{
    char cadena[N], cad[N];
    int valor, longi;

    clrscr ();
    printf ("Introduzca una cadena(Max. 50 caracteres): ");
    gets (cad);
    elimina (cad, cadena);
    longi = strlen (cadena);
    valor = capi (cadena, longi);

    if (valor)
        printf ("La cadena es capicúa.");
    else
        printf ("La cadena no es capicúa.");

    getch ();
}
