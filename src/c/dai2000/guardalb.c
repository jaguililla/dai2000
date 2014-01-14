/* guardalb.c -- guarda estructura en un fichero */
#include <stdio.h>
#define MAXTIT 40
#define MAXAUT 40
#define MAXLIB 100              /* número máximo de libros      */
#define STOP ""                 /* tira nula, finaliza entrada  */

struct biblio {                 /* prepara patrón de estructura */
    char titulo[MAXTIT];
    char autor[MAXAUT];
    double precio;
};

int main (void)
{

    struct biblio libro[MAXLIB];    /* array de estructuras biblio */
    int cont = 0;
    int indice, fichcont;
    FILE *plibros;

    int ocupa = sizeof (struct biblio);

    if ((plibros = fopen ("libro.dat", "a+b")) == NULL) {
        fputs ("No puedo abrir el fichero libro.dat\n", stderr);
        exit (1);
    }

    rewind (plibros);           /* va a comienzo del fichero */

    while (cont < MAXLIB && fread (&libro[cont], ocupa, 1, plibros) == 1) {
        if (cont == 0)
            puts ("Contenido actual de libro.dat:");

        printf ("%s por %s: %.2f pts.\n", libro[cont].titulo,
                libro[cont].autor, libro[cont].precio);

        cont++;
    }

    fichcont = cont;

    if (cont == MAXLIB) {
        fputs ("El fichero libro.dat está lleno.", stderr);
        exit (2);
    }

    puts ("Añada nuevos títulos de libros.");
    puts ("Pulse [Intro] a comienzo de línea para parar.");

    while (cont < MAXLIB && strcmp (gets (libro[cont].titulo), STOP) != 0) {
        puts ("Introduzca ahora el autor.");
        gets (libro[cont].autor);
        puts ("Ahora ponga el precio.");
        scanf ("%f", &libro[cont++].precio);

        while (getchar () != '\n')  /* limpia línea entrada */
            continue;

        if (cont < MAXLIB)
            puts ("Introduzca el siguiente título.");
    }

    puts ("Ahí va su lista de libros:");

    for (indice = 0; indice < cont; indice++)
        printf ("%s por %s: %.2f pts.\n", libro[indice].titulo,
                libro[indice].autor, libro[indice].precio);

    fseek (plibros, 0L, SEEK_END);  /* va al final del fichero */

    fwrite (&libro[fichcont], ocupa, cont - fichcont, plibros);

    fclose (plibros);

    return 0;
}
