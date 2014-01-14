/********************* Tirada de un dado *********************/
/* dado.c
 */
#include <stdio.h>
#include <ctype.h>
void rnd (long *prandom);

void main ()
{
    unsigned int inicio;        /* inicio contiene un valor entre 0 y 65535 */
    long random = inicio;       /* random = número entre 0 y 65535 */
    long tirada;
    char c;

    printf ("Para tirar el dado, pulse una <Entrar>\n");
    printf ("Para finalizar pulse <f>.\n\n");
    c = getchar ();
    fflush (stdin);
    while (tolower (c) != 'f') {
        rnd (&random);          /* random contiene un número seudoaleatorio */
        tirada = random % 6 + 1;    /* número entre 1 y 6 */
        printf ("%10d\n", tirada);
        c = getchar ();
        fflush (stdin);
    }
}

void rnd (long *prandom)
{
    *prandom = (25173 * *prandom + 13849) % 65536;
}
