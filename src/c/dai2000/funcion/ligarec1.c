/* generación del calendario de una liga */

#include <stdio.h>
#define equipos 31
#define jornadas equipos-1
#define false 0
#define true 1
int juegan[jornadas][equipos], calendario[equipos][equipos];

void ensayar (int p, int n, int *e)
{
    int jor, lo, vi, acierto;

    if (p > n * (n - 1))
        *e = false;
    else {
        /* cálculo de local y visitante para el partido p */
        if (p % n == 0) {
            lo = p / n;
            vi = n;
        }
        else {
            lo = p / n + 1;
            vi = p % n;
        }
        /* buscar un partido de la primera vuelta.
           El equipo local 'lo' debe ser '<' que el visitante 'vi'  */
        while ((lo >= vi) && (p < n * (n - 1))) {
            p = p + 1;
            if (p % n == 0) {
                lo = p / n;
                vi = n;
            }
            else {
                lo = p / n + 1;
                vi = p % n;
            }
        }
        /* asignación del partido 'p' a una jornada. Empezamos por la 1ª */
        jor = 0;
        acierto = false;
        do {
            jor++;
            if (!juegan[jor][lo] && !juegan[jor][vi]) {
                /* si no juegan 'lo' y 'vi' en esta jornada, se le
                   asignan temporalmente */
                juegan[jor][lo] = juegan[jor][vi] = 1;
                calendario[lo][vi] = jor;
                if ((lo == n - 1) && (vi == n)) /* si es el último acierto=true */
                    acierto = true;
                else {
                    ensayar (p + 1, n, &acierto);
                    if (!acierto) {
                        /* si no se consigue asignar el partido siguiente
                           se desasigna el partido anterior */
                        juegan[jor][lo] = juegan[jor][vi] = 0;
                        calendario[lo][vi] = 0;
                    }
                }

            }
        } while (jor <= n - 1 && acierto == false);
        *e = acierto;
    }
}                               /* ensayar */

void main (void)
{
    int exito, local, visitante, equipo, jornada, n;

    clrscr ();
    printf ("equipos= ");
    scanf ("%d%*c", &n);
    /* inicializar los equipos de todas las jornadas a 0 */
    for (jornada = 1; jornada <= n - 1; jornada++)
        for (equipo = 1; equipo <= equipos; equipo++)
            juegan[jornada][equipo] = 0;
    /* inicializar calendario a 0 */
    for (local = 1; local <= n; local++)
        for (visitante = 1; visitante <= n; visitante++)
            calendario[local][visitante] = 0;

    ensayar (1, n, &exito);
    if (exito) {
        printf ("\a");
        /* se rellena la segunda vuelta */
        for (local = 1; local <= n - 1; local++)
            for (visitante = local + 1; visitante <= n; visitante++)
                calendario[visitante][local] =
                    calendario[local][visitante] + n - 1;
        /* presentación de datos */
        /* línea superior */
        printf ("%3c", ' ');
        for (local = 1; local <= n; local++)
            printf ("%3d", local);
        printf ("\n");
        /* separación */
        printf ("%3c", '_');
        for (local = 1; local <= n; local++)
            printf ("%3c", '-');
        printf ("\n");
        /* salida de jornadas */
        for (local = 1; local <= n; local++) {
            printf ("%2d", local);
            putch ('_');
            for (visitante = 1; visitante <= n; visitante++)
                printf ("%3d", calendario[local][visitante]);
            printf ("\n");
        }
    }
    else
        printf ("no hay futbol\n");
    getch ();
}
