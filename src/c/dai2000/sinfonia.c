/* sinfonia.c -- memoriza orquestas sinfónicas */
#include <stdio.h>

#ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#    define EXIT_FAILURE 1
#endif

#define ANSI
#ifdef ANSI
#    include <stdlib.h>         /* encabezamiento ANSI de malloc()  */
#else
char *malloc ();                /* declaración pre-ANSI             */
#endif
#define LINEA 81                /* longitud máxima línea entrada    */
#define MAX  100                /* número máximo de orquestas       */

int main (void)
{
    char temp[LINEA];           /* almacenamiento temporal entrada  */
    char *ps[MAX];              /* array de punteros a tiras        */
    int indice = 0;             /* número de líneas de entrada      */
    int cont;                   /* contador bucle for               */

    puts ("Nombre algunas orquestas sinfónicas.");
    puts ("Introduzca una cada vez; pulse [Intro] a comienzo de");
    puts ("línea para terminar. Adelante, estoy listo.");

    while (indice < MAX && fgets (temp, LINEA, stdin) != NULL
           && temp[0] != '\n') {
        ps[indice] = (char *) malloc (strlen (temp) + 1);

        if (ps[indice] == NULL) {
            fputs ("¡Error de ubicación de memoria!", stderr);
            exit (EXIT_FAILURE);
        }

        strcpy (ps[indice], temp);

        if (++indice < MAX)
            printf ("Ya tenemos %d. Continúe si lo desea.\n", indice);
    }

    puts ("De acuerdo. Tenemos:");

    for (cont = 0; cont < indice; cont++)
        fputs (ps[cont], stdout);

    exit (EXIT_SUCCESS);

    return 0;
}
