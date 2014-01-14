/*IFI2.C    *************** JUEGO DE LOTERIA ******************************/
#include <stdio.h>
#include <stdlib.h>             /* biblioteca obligatoria para randomize */
void main (void)
{
    int premio;
    int loteria = 1;            /* 0 = falso.    <> 0 = cierto */

    clrscr ();
    randomize ();               /* número al azar */
    premio = rand () % 100 + 1;      /* entre 1 y 100  */
    printf ("premio=%d \n", premio);    /* no se debe mostrar el premio */

    while (loteria) {           /* mientras loteria <> 0, es decir, cierto */
        printf ("meta un número(1 a 100) (0=salir) :\n");
        scanf ("%d", &loteria);
        if (loteria == premio) {
            printf ("EUREKA!!! numero=%d\n", loteria);
            loteria = 0;
            /*break; */
        }
        else if (loteria > premio)
            printf ("Apunte más bajo!!\n");
        else
            printf ("Apunte más alto!!\n");
    }
    getch ();
}
