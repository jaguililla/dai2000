#include <stdio.h>

/* for: formato general:
       for (inicialización; comprobación; incrementos) {
         ...
       }
   1º Se inicializa
   2º Se comprueba la condición. Si la condición es cierta se ejecuta
      el bucle. Si no lo es se salta
   3º Se incrementan las variables
*/

void main (void)
{
    int i, x = 1, y = 1;

    clrscr ();
    for (i = 1; i < 20; i += x * y /* i = i + x*y */ ) {
        x += y;                 /* x = x + y */
        y++;
        i = (x > y) ? x : y;
        /* Equivale a
           if (x>y)
           i = x;
           else
           i = y;
         */
        printf ("%d %d %d\n", i, x, y);
    }
    printf ("%d %d %d\n", i, x, y);
    getch ();
}

/* ejecución

 2 2 2
 4 4 3
 7 7 4
 35 7 4

*/
