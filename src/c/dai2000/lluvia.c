/* lluvia.c -- calcula totales anuales, promedio anual y promedio
               mensual de datos pluviométricos en un periodo
               determinado */
#include <stdio.h>
#define DOCE 12                 /* número de meses del año */
#define ANS   5                 /* número de años a tratar */
int main (void)
{
    /* inicialización de datos de lluvia en el periodo 1987 - 91 */
    static float lluvia[ANS][DOCE] = {
        {10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
        {9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
        {6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
    };
    int anno, mes;
    float subtot, total;

    printf (" AÑO      LLUVIA (cm.)\n\n");

    for (anno = 0, total = 0; anno < ANS; anno++) { /* en cada año suma la lluvia de todos los meses */

        for (mes = 0, subtot = 0; mes < DOCE; mes++)
            subtot += lluvia[anno][mes];

        printf ("%5d %12.1f\n", 1970 + anno, subtot);

        total += subtot;        /* calcula lluvia total del periodo */
    }

    printf ("\nEl promedio anual ha sido %.1f cm.\n\n", total / ANS);
    printf ("PROMEDIOS MENSUALES:\n\n");
    printf (" Ene  Feb  Mar  Abr  May  Jun  Jul  Ago  Sep  Oct ");
    printf (" Nov  Dic\n");

    for (mes = 0; mes < DOCE; mes++) {  /* suma la lluvia de todos los años en cada mes */

        for (anno = 0, subtot = 0; anno < ANS; anno++)
            subtot += lluvia[anno][mes];

        printf ("%4.1f ", subtot / ANS);
    }

    printf ("\n");
    return 0;
}
