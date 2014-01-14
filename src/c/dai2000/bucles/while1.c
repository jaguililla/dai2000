/*WHILE1  ********* Bucles while ***********************************/
#include <stdio.h>              /* obligado para E/S                        */
void main (void)
{
    int LIMITE = 4;
    int indice = 0;
    int n = 5;
    char caracter;

    clrscr ();                  /* borrado de pantalla             */
    while (++indice <= LIMITE) {    /*   ++indice-->(indice=indice+1)  */
        printf ("RESULTADOS 1 \n");
        printf ("indice=%d\n", indice);
    }

/* 2º ejemplo de indice decreciente    */
    while (--n) {               /* se cumple si n <> 0                      */
        printf ("RESULTADOS 2 \n");
        printf ("indice=%d \n", n);
    }
/* ejemplo 3                                                     */
    printf ("INGRESE UNA LETRA \n");

    while ((caracter = getch ()) != 's') {  /* letra s para salir  */
        printf ("la letra es una %c \n", caracter);
        printf ("Ingrese una letra (s=salida)  ");

    }
}
