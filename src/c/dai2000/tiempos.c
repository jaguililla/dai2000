/* tiempos */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   N  200

void Cargar (unsigned char d[], int Total)
{
    int i;

    randomize ();

    for (i = 0; i < Total; i++)
        d[i] = rand()%256 /*(0xFFFF) */ ;
}

void copiar (unsigned char o[], unsigned char d[], int total)
{
    int i;

    for (i = 0; i < total; i++)
        d[i] = o[i];
}

int Ordenada (unsigned char *o, int Total)
{
    int i;

    for (i = 0; i < Total - 1; ++i)
        if (o[i] > o[i + 1])
            return 0;

    return -1;
}

void OrdenBurbuja (unsigned char *o, int Total)
{
    register int i, j;
    unsigned char aux;

    for (i = 1; i < Total; ++i) /*Se realizan Total - 1 iteraciones */
        for (j = 0; j < Total - i; ++j)
            if (o[j] > o[j + 1]) {
                aux = o[j];
                o[j] = o[j + 1];
                o[j + 1] = aux;
            }
}

void intercambio (unsigned char *o, int Total)
{
    register int i, j;
    unsigned char aux;

    for (i = 0; i < Total - 1; ++i) /*Se realizan Total - 1 iteraciones */
        for (j = i + 1; j < Total; ++j)
            if (o[i] > o[j]) {
                aux = o[i];
                o[i] = o[j];
                o[j] = aux;
            }
}

void main (void)
{
    unsigned char origen[N], copia[N];

    struct tm t1, t2;

    /* gettime(&t);
       printf("h: %2d:%02d:%02d\n", t.tm_hour,t.tm_min,t.tm_sec); */

    printf ("%45s", "CARGANDO....\n");
    Cargar (origen, N);
    copiar (origen, copia, N);  /*Presentar (origen,N); */
    gettime (&t1);
    OrdenBurbuja (copia, N);
    gettime (&t2);
    printf ("%50s", "METODO: BURBUJA\n");
    printf ("h: %2d:%02d:%02d", t1.tm_hour, t1.tm_min, t1.tm_sec);
    printf ("\th: %2d:%02d:%02d", t2.tm_hour, t2.tm_min, t2.tm_sec);
    /*Presentar (origen,N); */

    if (Ordenada (copia, N))
        printf ("\t ORDEN \n");
    else
        printf ("\t ¡¡ CAOS !!\n");

    printf ("%45s", "CARGANDO....\n");

    copiar (origen, copia, N);  /*Presentar (origen,N); */

    gettime (&t1);

    intercambio (copia, N);

    gettime (&t2);

    printf ("%50s", "METODO: INTERCAMBIO\n");

    printf ("h: %2d:%02d:%02d", t1.tm_hour, t1.tm_min, t1.tm_sec);

    printf ("\th: %2d:%02d:%02d", t2.tm_hour, t2.tm_min, t2.tm_sec);

    /*Presentar (origen,N); */
    if (Ordenada (copia, N))
        printf ("\t ORDEN \n");
    else
        printf ("\t ¡¡ CAOS !!\n");

}
