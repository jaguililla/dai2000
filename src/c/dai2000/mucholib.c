/* mucholib.c -- inventario de varios libros */
#include <stdio.h>
#define MAXTIT 40
#define MAXAUT 40
#define MAXLIB 100              /* número máximo de libros     */
#define STOP ""                 /* tira nula, finaliza entrada */

struct biblio {                 /* prepara patrón estructura   */
    char titulo[MAXTIT];
    char autor[MAXAUT];
    double precio;
};

int main (void)
{

    struct biblio libro[MAXLIB];    /* array de estructuras biblio */
    int cont = 0;
    int indice;

    printf ("Introduzca título del libro.\n");
    printf ("Pulse [Intro] a comienzo de línea para parar.\n");

    while (cont < MAXLIB && strcmp (gets (libro[cont].titulo), STOP) != 0) {
        printf ("Introduzca ahora el autor.\n");
        gets (libro[cont].autor);
        printf ("Ahora ponga el precio.\n");
        scanf ("%f", &libro[cont++].precio);

        while (getchar () != '\n')  /* limpia línea entrada */
            continue;

        if (cont < MAXLIB)
            printf ("Introduzca el siguiente título.\n");
    }

    printf ("Ahí va su lista de libros:\n");

    for (indice = 0; indice < cont; indice++)
        printf ("%s por %s: %.2f pts.\n", libro[indice].titulo,
                libro[indice].autor, libro[indice].precio);

    return 0;
}
