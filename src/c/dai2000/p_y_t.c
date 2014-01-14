/* p_y_t.c -- punteros y tiras */
#include <stdio.h>
int main (void)
{
    static char *mnsj = "¡Te estás pasando!";
    static char *copia;

    copia = mnsj;
    printf ("%s\n", copia);
    printf ("mnsj = %s; &mnsj = %u; valor = %u\n", mnsj, &mnsj, mnsj);
    printf ("copia = %s; &copia = %u; valor = %u\n", copia, &copia, copia);
    return 0;
}
