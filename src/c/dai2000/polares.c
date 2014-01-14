/* polares.c -- pasa coordenadas cartesianas a polares */
#include <stdio.h>
#include <math.h>
#define RAD_A_GRAD (180/3.141592654)

typedef struct polar_v {
    double magnitud;
    double angulo;
} POLAR_V;

typedef struct rect_v {
    double x;
    double y;
} RECT_V;
POLAR_V rect_a_polar (RECT_V);
int main (void)
{
    RECT_V entra;
    POLAR_V result;

    puts ("Introduzca coordenadas x,y; pulse s para salir:");

    while (scanf ("%lf %lf", &entra.x, &entra.y) == 2) {
        result = rect_a_polar (entra);
        printf ("magnitud = %0.2f, ángulo = %0.2f\n", result.magnitud,
                result.angulo);
    }

    return 0;
}

POLAR_V rect_a_polar (RECT_V rv)
{
    POLAR_V pv;

    pv.magnitud = sqrt (rv.x * rv.x + rv.y * rv.y);

    if (pv.magnitud == 0)
        pv.angulo = 0.0;
    else
        pv.angulo = RAD_A_GRAD * atan2 (rv.y, rv.x);

    return pv;
}
