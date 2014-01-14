/* cuenta_p.c -- cuenta caracteres, palabras y líneas */
#include <stdio.h>
#define STOP '|'
#define SI 1
#define NO 0
int main (void)
{
    char c;                     /* para capturar caracteres        */
    long nc = 0L;               /* número de caracteres            */
    int nl = 0;                 /* número de líneas                */
    int np = 0;                 /* número de palabras              */
    int palabra = NO;           /* == SI si ch está en una palabra */

    while ((c = getchar ()) != STOP) {
        nc++;                   /* cuenta caracteres */

        if (c == '\n')
            nl++;               /* cuenta líneas     */

        if (c != ' ' && c != '\n' && c != '\t' && palabra == NO) {
            palabra = SI;       /* empieza palabra   */
            np++;               /* cuenta la palabra */
        }

        if ((c == ' ' || c == '\n' || c == '\t') && palabra == SI)
            palabra = NO;       /* final de palabra  */
    }

    printf ("caracteres = %ld, palabras = %d, líneas = %d\n", nc, np, nl);
    return 0;
}
