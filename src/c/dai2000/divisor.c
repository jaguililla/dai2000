/* divisores.c -- calcula divisores con if anidados */
#include <stdio.h>
#define NO 0
#define SI 1
int main (void)
{
    long num;                   /* número a analizar     */
    long div;                   /* divisores potenciales */
    int primo;

    printf ("Introduzca el número deseado; ");
    printf ("pulse s para salir.\n");

    while (scanf ("%ld", &num) == 1) {
        for (div = 2, primo = SI; (div * div) <= num; div++) {
            if (num % div == 0) {
                if ((div * div) != num)
                    printf ("%ld es divisible por %ld y %ld.\n", num, div,
                            num / div);
                else
                    printf ("%ld es divisible pro %ld.\n", num, div);

                primo = NO;     /* el número no es primo */
            }
        }

        if (primo == SI)
            printf ("%ld es primo.\n", num);

        printf ("Introduzca otro número para analizar; ");

        printf ("pulse s para salir.\n");
    }

    return 0;
}
