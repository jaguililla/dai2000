/* vars01.c - Variables globales y locales */
#include <stdio.h>

/* Definición de var1 como variable GLOBAL */
int var1 = 50;

void main (void)
{                               /* COMIENZO DE main Y DEL PROGRAMA */

    printf ("%d\n", var1);      /* se escribe 50 */

    {                           /* COMIENZO BLOQUE 1. Definición de var1 y var2 como variables
                                   LOCALES en el BLOQUE 1 y en el BLOQUE 2 */
        int var1 = 100, var2 = 200;

        printf ("%d %d\n", var1, var2); /* escribe 100 y 200 */

        {                       /* COMIENZO BLOQUE 2. Redefinición de variable LOCAL var1 */
            int var1 = 0;

            printf ("%d %d\n", var1, var2); /* escribe 0 y 200 */
        }                       /* FINAL DEL BLOQUE 2 */

        printf ("%d\n", var1);  /* se escribe 100 */
    }                           /* FINAL DEL BLOQUE 1 */

    printf ("%d\n", var1);      /* se escribe 50 */
    getch ();
}                               /* FINAL DE main Y DEL PROGRAMA */
