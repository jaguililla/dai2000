/*
 * menor.c -
 * 
 * ejecución:
 *
 * números a b c : 23.5 11.7 42.8
 * (formato f) Menor = 11.700000
 * (formato g) Menor = 11.7
 * (formato e) Menor = 1.170000e+01
 *
 * Trabajando con el operador '?'
 *  (formato f) Menor = 11.700000
 *  (formato g) Menor = 11.7
 *  (formato e) Menor = 1.170000e+01
 *  (formato f) mayor = 42.799999
 *  (formato g) mayor = 42.799999237
 *  (formato e) mayor = 4.280000e+01
 */

/* I N C L U D E *************************************************************/
#include <stdio.h>

/* M A I N ********************************************************************/
void main (void)
{
    float a, b, c, menor, mayor;

    printf ("números a b c : ");
    scanf ("%f %f %f", &a, &b, &c);
    if (a < b) {
        if (a < c) {
            menor = a;
        }
        else {
            menor = c;
        }
    }
    else {
        if (b < c) {
            menor = b;
        }
        else {
            menor = c;
        }
    }

    printf ("(formato f) Menor = %f\n", menor);
    printf ("(formato g) Menor = %g\n", menor);
    printf ("(formato e) Menor = %e\n", menor);

    printf ("\n Trabajando con el operador '?' \n");
    menor = a <= b ? a : b;     /* se obtiene el primer menor */
    menor = menor <= c ? menor : c;

    printf ("(formato f) Menor = %*f\n", (int) a, menor);
    printf ("(formato g) Menor = %*g\n", (int) b, menor);
    printf ("(formato e) Menor = %*e\n", (int) c, menor);

    mayor = a <= b ? b : a;
    mayor = mayor <= c ? c : mayor;

    printf ("(formato f) mayor = %*f\n", (int) a, mayor);
    printf ("(formato g) mayor = %*.*g\n", (int) mayor, (int) menor, mayor);
    printf ("(formato e) mayor = %*e\n", (int) c, mayor);
}

/* E O F **********************************************************************/
