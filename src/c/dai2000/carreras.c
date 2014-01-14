/* carreras.c -- para corredores de fondo  */
#include <stdio.h>
#define SM      60              /* segundos por minuto  */
#define SH    3600              /* segundos por hora    */
#define MK 0.62137              /* millas por kilómetro */

main ()
{
    float distk, distm;         /* distancia en kilómetros y en millas */
    float veloc;                /* velocidad promedio en millas hora   */
    int min, seg;               /* minutos y segundos corriendo        */
    int tiempo;                 /* tiempo de carrera sólo en segundos  */
    float tporm;                /* tiempo en segundos para una milla   */
    int mporm, sporm;           /* minutos y segundos en una milla     */

    printf ("Este programa convierte el tiempo de una carrera\n");
    printf ("en tiempo para correr una milla y en promedio de\n");
    printf ("velocidad en millas por hora.\n");
    printf ("Introduzca la distancia recorrida en km.\n");
    scanf ("%f", &distk);
    printf ("Ahora indique el tiempo en minutos y segundos.\n");
    printf ("Comience por los minutos.\n");
    scanf ("%d", &min);
    printf ("Y ahora los segundos.\n");
    scanf ("%d", &seg);
    tiempo = SM * min + seg;    /* pasa el tiempo a segundos */
    distm = MK * distk;         /* pasa kilómetros a millas  */
    veloc = distm / tiempo * SH;    /* millas por segundo
                                       multiplicado por segundos por hora = millas por hora */
    tporm = (float) tiempo / distm; /* tiempo por milla          */
    mporm = (int) tporm / SM;   /* calcula minutos truncando */
    sporm = (int) tporm % SM;   /* calcula resto de segundos */
    printf ("Ha corrido %1.2f km (%1.2f millas) en %d min, %d seg.\n", distk,
            distm, min, seg);
    printf ("Este ritmo corresponde a hacer 1 milla en %d min, ", mporm);
    printf ("%d seg.\nSu velocidad promedio fue %1.2f mph.\n", sporm, veloc);
}
