/*    *************** JUEGO DE LOTERIA ******************************/
#include <stdio.h>
#include <stdlib.h>             /* biblioteca obligatoria para randomize */
void main (void)
{
    int premio;
    int loteria = 1;            /* 0 = falso.  <> 0 = cierto */

    clrscr ();
    randomize ();               /* número al azar */
    premio = rand () % 100 + 1;      /* entre 1 y 100  */
    /* printf("premio=%d \n",premio);    no se debe mostrar el premio */

    do {
        printf ("meta un número(1 a 100) (0=salir): ");
        scanf ("%d", &loteria);
        if (loteria > premio)
            printf ("Apunte más bajo!!\n");
        else if (loteria < premio)
            printf ("Apunte más alto!!\n");
    } while (loteria != premio);
    getch ();
}
