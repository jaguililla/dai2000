/* preproc.c -- ejemplos sencillos de preprocesador */
#include <stdio.h>
#define DOS 2                   /* se pueden usar comentarios */
#define MSJ "Gato escaldado del agua fría \
    huye."                      /* una barra invertida continúa definición en otra línea */
#define CUATRO DOS*DOS
#define PX printf("X es %d.\n", x)
#define FMT "X es %d.\n"
int main (void)
{
    int x = DOS;

    PX;
    x = CUATRO;
    printf (FMT, x);
    printf ("%s\n", MSJ);
    printf ("DOS: MSJ\n");
    return 0;
}
