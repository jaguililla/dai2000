/* sumame.c -- cuatro tipos de sentencias */
#include <stdio.h>
main ()
{                               /* calcula la suma de los 20 primeros enteros */
    int cont, suma;             /* sentencia de declaración */

    cont = 0;                   /* sentencia de asignación  */
    suma = 0;                   /* idem                     */

    while (cont++ < 20)         /* while                    */
        suma = suma + cont;     /*   sentencia              */

    printf ("suma = %d\n", suma);   /* sentencia de función     */
}
