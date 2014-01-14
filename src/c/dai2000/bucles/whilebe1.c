/*  ********* Bucles while *******************   */
#include <stdio.h>              /* obligatorio para E/S    */
void main (void)
{
    int limite = 4, indice = 0, n = 12;
    char caracter;

    clrscr ();                  /* borrado de pantalla     */
    printf ("INDICE CRECIENTE \n");
    while (++indice <= limite) {    /*   ++indice _> (indice=indice+1)  */
        /*printf("RESULTADOS 1 \n"); */
        printf ("indice=%d\n", indice);
    }
    printf ("indice decreciente \n");
    while (--n) {               /* se cumple si n <> 0      */
        /*printf("RESULTADOS 2 \n"); */
        printf ("indice=%d \n", n);
    }
/*  ejemplo 3             */
    printf ("INGRESE UNA LETRA \n");
    while ((caracter = getch ()) != 's') {  /* letra s para salir  */
        /* caracter almacena la pulsación que se teclea.
           mientras caracter <> 's' pulsar tecla y verla */
        printf ("la letra es una %c \n", caracter);
        printf ("Ingrese una letra (s=salida)  ");
    }
}
