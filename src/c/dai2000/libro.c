/* libro.c -- inventario de un solo libro */
#include <stdio.h>
#define MAXTIT 41               /* longitud máxima del título + 1 */
#define MAXAUT 31               /* longitud máxima del autor  + 1 */

struct biblio {                 /* nuestro primer patrón de estructura:
                                   la etiqueta es biblio          */
    char titulo[MAXTIT];        /* tira de caracteres para título */
    char autor[MAXAUT];         /* tira de caracteres para autor  */
    float precio;               /* variable para precio del libro */
};                              /* fin del patrón de estructura   */
int main (void)
{

    struct biblio libro;        /* declara  libro  de tipo biblio */

    printf ("Introduzca título del libro.\n");
    gets (libro.titulo);        /* accede a la porción título */
    printf ("Introduzca ahora el autor.\n");
    gets (libro.autor);
    printf ("Ahora ponga el precio.\n");
    scanf ("%f", &libro.precio);
    printf ("%s por %s: %.2f pts.\n", libro.titulo,
            libro.autor, libro.precio);
    printf ("%s: \"%s\" \(%.2f pts.\)\n", libro.autor,
            libro.titulo, libro.precio);
    return 0;
}
