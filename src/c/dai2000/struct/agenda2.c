/* agendarr.c GESTIÓN DE UNA AGENDA EN UN ARRAY */
#include<stdio.h>
#include<string.h>

#define n 4
#define l 20

typedef struct {                /* definición del componente de la agenda */
    int edad;
    char nombre[l], direccion[l], telefono[l];
} registro;

void leer (registro * r)
{                               /* carga un registro por teclado */
    char c;

    printf ("nombre: ");
    gets (r->nombre);
    printf ("Edad: ");
    scanf ("%d%c", &r->edad, &c);
    printf ("dirección: ");
    gets (r->direccion);
    printf ("telefono: ");
    gets (r->telefono);
}

void escribir (registro r)
{                               /* muestra un registro por pantalla */
    printf ("%15s%8d%15s%15s\n", r.nombre, r.edad, r.direccion, r.telefono);
}

void listar (registro a[], int total)
{                               /* lista toda la agenda */
    int i;

    printf ("REGISTRO       NOMBRE   EDAD        DIRECCIÓN     TELÉFONO\n");
    for (i = 0; i <= total; i++) {
        printf ("%4d", i + 1);
        escribir (a[i]);
    }
}

void buscar (registro a[], int ei, int ed, char nbus[], int *hallado, int *p)
{
    /* 'h' indica si el dato está o no. 'p' indica su posición */
    int medio;

    *hallado = 0;
    while (!(*hallado) && (ei <= ed)) {
        medio = (ei + ed) / 2;
        if (strcmp (a[medio].nombre, nbus) == 0)
            *hallado = 1;
        else if (strcmp (a[medio].nombre, nbus) > 0)
            ed = medio - 1;
        else
            ei = medio + 1;
    }
    if (*hallado)
        *p = medio;             /* si está, su posición es medio */
    else
        *p = ei;                /* si no está, debería encotrarse en 'ei' */
}

void altas (registro a[], int *total)
{
    registro ralta;             /* registro que queremos dar de alta */
    int hallado, posicion, i;

    printf ("\n");
    leer (&ralta);              /* carga los datos de alta */
    buscar (a, 0, *total, ralta.nombre, &hallado, &posicion);
    if (hallado)
        printf ("%30s", "datos en la agenda \n");
    else if (*total == n - 1)
        printf ("%60s\n", "Agenda completa.No hay espacio");
    else {                      /* ralta se inserta en la posición o celda 'p' */
        for (i = *total; i >= posicion; i--)
            a[i + 1] = a[i];    /* desplazamiento */
        a[posicion] = ralta;    /* inserción */
        (*total)++;             /* aumenta número de registros */
    }
}

void bajas (registro a[], int *total)
{
    char nombaja[l];
    int hallado, posicion, i;

    printf ("Nombre a dar de baja: ");
    gets (nombaja);
    buscar (a, 0, *total, nombaja, &hallado, &posicion);
    if (!hallado)
        printf ("los datos no están en la agenda \n");
    else {                      /* se desplazan hacia abajo los datos una posición */
        for (i = posicion; i < *total; i++)
            a[i] = a[i + 1];
        (*total)--;
    }
}

void main (void)
{
    registro a[n];
    int total = -1;
    char opc;

    do {
        printf ("\n0.-fin  1.-Altas    2.-Bajas         OPCION:>");
        opc = getch ();
        switch (opc) {
            case '1':
                altas (a, &total);
                break;
            case '2':
                bajas (a, &total);
                break;
            case '3':
                listar (a, total);
                break;
            case '0':
                break;
        }                       /* SWITCH */
        listar (a, total);
        printf ("PULSE TECLA....");
        getch ();
    } while (opc != '0');
}
