 /* algoritmo de selección óptima */

#include <stdio.h>
#include <stdlib.h>
#define  MaxNumObjetos  10

typedef struct {
    int Valor, Peso;
} objeto;

  /* declaración del array de objetos. Global */
objeto Objetos[MaxNumObjetos];

  /* declaración de las selecciones actual y óptima */
int selact[MaxNumObjetos + 1], selopti[MaxNumObjetos];

int maxvalposib, maxvalact, PesoPasada, IncPeso, PesoMax, valorfinal;

   /* si se encuentra el objeto escribe '*', si no escribe ' ' */
char SeEncuentra[2];

void ensayar (int NumObje, int PesoActual, int ValorAlcanzable)
{
    int ValorAlcanzableActual, NuevoPeso;

    /*se investiga la inclusión del objeto en la selección actual */
    NuevoPeso = PesoActual + Objetos[NumObje].Peso; /* modifica peso */
    if (NuevoPeso <= PesoPasada) {
        /* el objeto es incluible porque no se sobrepasa el peso máximo */
        selact[NumObje] = 1;
        /* si no es el último se ensaya el siguiente */
        if (NumObje < MaxNumObjetos)
            ensayar (NumObje + 1, NuevoPeso, ValorAlcanzable);
        else /* es el último. Se comprueba si hay mejora */
        if (ValorAlcanzable > maxvalact) {
            /* se mejora el máximo valor transportable */
            maxvalact = ValorAlcanzable;    /* se actualiza */
            /* y la selección actual se convierte en óptima */
            for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
                selopti[NumObje] = selact[NumObje];
        }
        /* se quita el objeto actual para investigar su 'no inclusión' */
        selact[NumObje] = 0;
    }
    /* Se investiga la no inclusión del objeto */
    ValorAlcanzableActual = ValorAlcanzable - Objetos[NumObje].Valor;
    /* continúa la investigación si a pesar de haber disminuído el
       valor alcanzable, éste puede ser mayor, todavía, que el máximo actual */
    if (ValorAlcanzableActual > maxvalact)
        if (NumObje < MaxNumObjetos)
            /* si no es el último investigar el siguiente */
            ensayar (NumObje + 1, PesoActual, ValorAlcanzableActual);
        else {                  /* es el último */
            /* actualizamos máximo valor */
            maxvalact = ValorAlcanzableActual;
            /* actualizamos selección óptima */
            for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
                selopti[NumObje] = selact[NumObje];
        }
}                               //ensayar

void main (void)
{
    int NumObje;

    clrscr ();
    randomize ();
    maxvalposib = 0;
    /* INTRODUCCION VALORES Y PESOS DE LOS OBJETOS */
    for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++) {
        Objetos[NumObje].Peso = 1 + rand () % 10;
        Objetos[NumObje].Valor = 1 + rand () % 10;
        maxvalposib += Objetos[NumObje].Valor;
    }
    /* DEFINICION INTERVALO DE PESOS QUE SE INVESTIGA */
    printf ("Introduzca rango de pesos a investigar\n");
    printf ("peso inferior: ");
    scanf ("%d%*c", &PesoPasada);
    printf ("incremento: ");
    scanf ("%d%*c", &IncPeso);
    printf ("peso superior: ");
    scanf ("%d%*c", &PesoMax);

    /* SI EL OBJETO SE ENCUENTRA EN SELECCION OPTIMA, ESCRIBE '*' */
    SeEncuentra[1] = '*';
    SeEncuentra[0] = ' ';

    /* SALIDA DE DATOS */
    /* índices de objetos */
    printf ("OBJETO: ");
    for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
        printf ("%4d", NumObje);
    printf ("\n");
    /* valores de cada objeto */
    printf (" VALOR: ");
    for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
        printf ("%4d", Objetos[NumObje].Valor);
    printf ("%16s\n", "SUMA VALORES");
    /* pesos de cada objeto */
    printf ("  PESO: ");
    for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
        printf ("%4d", Objetos[NumObje].Peso);
    printf ("\n");
    /* CONJUNTO ITERACIONES DESDE PESO INFERIOR A PESO SUPERIOR */
    do {
        valorfinal = 0;
        maxvalact = 0;
        /* inicializaciones de la selección actual y la óptima */
        for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
            selact[NumObje] = 0;
        for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++)
            selopti[NumObje] = 0;
        ensayar (1, 0, maxvalposib);
        printf ("%6d  ", PesoPasada);
        for (NumObje = 1; NumObje <= MaxNumObjetos; NumObje++) {
            printf ("%4c", SeEncuentra[selopti[NumObje]]);
            /* si el objeto de encuentra se incrementa el valor final */
            if (selopti[NumObje])
                valorfinal += Objetos[NumObje].Valor;
        }
        printf ("%12d\n", valorfinal);
        PesoPasada += IncPeso;
    } while (PesoPasada <= PesoMax);
    getch ();
}
