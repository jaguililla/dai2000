/* voltios.c -- calcula el recibo de la luz */

#include <stdio.h>

#define TARIFA1 5.418           /* tarifa de los primeros 240 kwh */
#define TARIFA2 7.047           /* tarifa de los siguientes 300 kwh */
#define TARIFA3 9.164           /* tarifa por encima de 540 kwh */
#define LIMITE1 240.0           /* primer bloque de tarifa */
#define LIMITE2 540.0           /* segundo bloque de tarifa */
#define BASE1 (TARIFA1 * LIMITE1)

/* coste total primeros 240 kwh */
#define BASE2 (BASE1 + (TARIFA2 * (LIMITE2 - LIMITE1)))

/* coste total primeros 540 kwh */
int main (void)
{
    float kwh;                  /* kilowatios gastados */
    float recibo;               /* precio */

    printf ("Introduzca el gasto en kwh.\n");
    scanf ("%f", &kwh);

    if (kwh <= LIMITE1)
        recibo = TARIFA1 * kwh;
    else if (kwh <= LIMITE2)    /* kwh entre 240 y 540 */
        recibo = BASE1 + (TARIFA2 * (kwh - LIMITE1));
    else                        /* kwh por encima de 540 */
        recibo = BASE2 + (TARIFA3 * (kwh - LIMITE2));

    printf ("La cuenta total por %.1f kwh es %.0f pts.\n", kwh, recibo);
    return 0;
}
