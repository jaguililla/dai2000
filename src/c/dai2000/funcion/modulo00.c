// modulo01
/* cambia de cartesianas a polares o viceversa, según menú */
#include <stdio.h>
#include <math.h>
void apolares (double, double, double *, double *);
void acartesianas (double, double, double *, double *);
void menu (void);
void main (void)
{
    double x, y, radio, angulo;
    int opcion;

    do {
        clrscr ();
        menu ();
        do {
            printf ("Introduzca opción: ");
            scanf ("%d", &opcion);
        } while ((0 > opcion) || (opcion > 3));
        switch (opcion) {
            case 0:
                printf ("fin de programa\n");
                break;
            case 1:
                printf ("Introduzca coordenadas cartesianas: ");
                scanf ("%lf %lf", &x, &y);
                printf ("x=%f y=%lf    radio=%f   angulo=%f\n");
                apolares (x, y, &radio, &angulo);
                printf ("x=%f y=%f    radio=%f   angulo=%f\n");
                printf ("radio= %f  angulo=%f\n", radio, angulo);
                break;
            case 2:
                printf ("Introduzca coordenadas polares: ");
                scanf ("%lf %lf", &radio, &angulo);
                acartesianas (radio, angulo, &x, &y);
                printf ("x= %f  y=%f\n", x, y);
                break;
            default:
                printf ("opción no disponible\n");
                break;
        }
        printf ("pulse una tecla \n");
        getch ();
    } while (opcion != 0);
}

void menu (void)
{
    printf ("0.- salir de programa\n");
    printf ("1.- Paso a polares\n");
    printf ("2.- Paso a cartesianas\n");
}

void apolares (double x, double y, double *radio, double *angulo)
{
    *radio = sqrt (x * x + y * y);
    *angulo = atan (y / x);
}

void acartesianas (double radio, double angulo, double *x, double *y)
{
    *x = radio * cos (angulo);
    *y = radio * sin (angulo);
}
