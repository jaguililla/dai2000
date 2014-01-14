// A L G O R I T M O   O R D E N A ///////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../basico.h"

// D E F I N E S /////////////////////////////////////////////////////////////
#define MAX 17000

// P R O T O T I P O S ///////////////////////////////////////////////////////
void cambiar (int *n1, int *n2);
void init_array (byte array[]);
void random_array (byte array[]);
void copiar (byte array1[], byte array2[], int num);

void ordena_sel (byte array[], int num);
void ordena_inter (byte array[], int num);
void ordena_burbu (byte array[], int num);
void ordena_inser (byte array[], int num);
void quicksort (byte array[], int ei, int ed);
void Shell (byte * Datos, int num);

//void imp_array (byte array[],int num);

// F U N C I O N E S /////////////////////////////////////////////////////////
void cambiar (int *n1, int *n2)
{
    int aux = 0;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

//////////////////////////////////////////////////////////////////////////////
void copiar (byte array1[], byte array2[], int num)
{
    int indice;

    for (indice = 0; indice <= num; indice++)
        array2[indice] = array1[indice];
}

//////////////////////////////////////////////////////////////////////////////

void init_array (byte array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        array[cont] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////////

void random_array (byte array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        array[cont] = rand ()%255 + 1;
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_sel (byte array[], int num)
{
    int cont = 0, cont2 = 0, pos_menor = 0;

    struct tm tiempo1, tiempo2;
    int tiempo;

    gettime (&tiempo1);

    for (cont = 0; cont < num; cont++) {    //max  <=
        pos_menor = cont;       //max-1 <

        for (cont2 = cont + 1; cont2 <= num; cont2++) {
            if (array[cont2] < array[pos_menor])    // menor = array[pos_menor]
            {
                pos_menor = cont2;
            }
        }

        cambiar (&array[pos_menor], &array[cont]);
        /*printf("Iteración %d: ",cont+1);  // Esta línea no es necesaria
           imp_array(array,num);                       // Esta línea no es necesaria
           printf("\n");        */// Esta línea no es necesaria
    }

    gettime (&tiempo2);
    tiempo = tiempo1.tm_hour * 60 * 60 * 100;
    tiempo += tiempo1.tm_min * 60 * 100;
    tiempo += tiempo1.tm_sec * 100;
    tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
    tiempo -= tiempo2.tm_min * 60 * 100;
    tiempo -= tiempo2.tm_sec * 100;
    printf ("%11d", abs (tiempo));
}

//////////////////////////////////////////////////////////////////////////////

void ordena_inter (byte array[], int num)
{
    int cont = 0, cont2 = 0;

    struct tm tiempo1, tiempo2;
    int tiempo;

    gettime (&tiempo1);

    for (cont = 0; cont < num; cont++) {
        for (cont2 = cont + 1; cont2 <= num; cont2++) { //No se puede usar una var a la q

            if (array[cont] > array[cont2]) //se le asigna el valor del array
            {                   // xq el prog no la cambia
                cambiar (&array[cont], &array[cont2]);
            }
        }

        /*printf("Iteración %d: ",cont+1);  // Esta línea no es necesaria
           imp_array(array, num);                       // Esta línea no es necesaria
           printf("\n"); */// Esta línea no es necesaria
    }

    gettime (&tiempo2);
    tiempo = tiempo1.tm_hour * 60 * 60 * 100;
    tiempo += tiempo1.tm_min * 60 * 100;
    tiempo += tiempo1.tm_sec * 100;
    tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
    tiempo -= tiempo2.tm_min * 60 * 100;
    tiempo -= tiempo2.tm_sec * 100;
    printf ("%11d", abs (tiempo));
}

//////////////////////////////////////////////////////////////////////////////

void ordena_burbu (byte array[], int num)
{
    int cont = 0, cont2 = 0, conta = 0;

    struct tm tiempo1, tiempo2;
    int tiempo;

    gettime (&tiempo1);

    for (cont = num, conta = 1; cont > 0; cont--, conta++)  // conta no es nec.
    {

        for (cont2 = 0; cont2 < num; cont2++) {
            if (array[cont2] > array[cont2 + 1]) {
                cambiar (&array[cont2], &array[cont2 + 1]);
            }
        }

        /*printf("Iteración %d: ",conta);   // Esta línea no es necesaria
           imp_array(array,num);                       // Esta línea no es necesaria
           printf("\n"); */// Esta línea no es necesaria
    }

    gettime (&tiempo2);
    tiempo = tiempo1.tm_hour * 60 * 60 * 100;
    tiempo += tiempo1.tm_min * 60 * 100;
    tiempo += tiempo1.tm_sec * 100;
    tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
    tiempo -= tiempo2.tm_min * 60 * 100;
    tiempo -= tiempo2.tm_sec * 100;
    printf ("%11d", abs (tiempo));
}

//////////////////////////////////////////////////////////////////////////////

void ordena_inser (byte array[], int num)
{
    int aux, hallado, p, k, cont = 1;

    struct tm tiempo1, tiempo2;
    int tiempo;

    gettime (&tiempo1);

    for (p = 1; p <= num; p++, cont++) {
        aux = array[p];
        k = p - 1;
        hallado = NO;

        while ((hallado == NO) && (k >= 0)) {
            if (array[k] > aux) {
                array[k + 1] = array[k];
                k--;
            }
            else {
                hallado = YES;
            }
        }

        array[k + 1] = aux;
        /*printf("Iteración %d: ",cont);   // Esta línea no es necesaria
           imp_array(array,num);                       // Esta línea no es necesaria
           printf("\n"); */// Esta línea no es necesaria

        /*ei=0;ed=num,hallado=0;
           do{
           medio=(ei+ed)/2;
           aux=a[medio];
           if(valor==aux)
           hallado=1;
           else
           if(valor>aux)
           ei=medio;
           else
           ed=medio;
           }while((ei>ed)||(hallado));
           return(medio);
         */

    }

    gettime (&tiempo2);
    tiempo = tiempo1.tm_hour * 60 * 60 * 100;
    tiempo += tiempo1.tm_min * 60 * 100;
    tiempo += tiempo1.tm_sec * 100;
    tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
    tiempo -= tiempo2.tm_min * 60 * 100;
    tiempo -= tiempo2.tm_sec * 100;
    printf ("%11d", abs (tiempo));
}

//////////////////////////////////////////////////////////////////////////////
void imp_array (byte array[], int num)
{
    int cont = 0;

    for (cont = 0; cont <= num; cont++) {
        printf ("%d ", array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////
void quicksort (byte array[], int ei, int ed)
{
    int i, d, pivote, aux;

    i = ei;
    d = ed;
    pivote = array[(ei + ed) / 2];

    do {
        while (array[i] < pivote)
            i++;

        while (pivote < array[d])
            d--;

        if (i <= d) {
            aux = array[i];
            array[i] = array[d];
            array[d] = aux;
            i++;
            d--;
        }
    }
    while (i <= d);

    if (ei < d)
        quicksort (array, ei, d);

    if (i < ed)
        quicksort (array, i, ed);
}

//////////////////////////////////////////////////////////////////////////////
void Shell (byte * Datos, int Total)
{                               /* Ordenación por método Shell */
    register int j, Salto;
    int aux, k, hallado;

    struct tm tiempo1, tiempo2;
    int tiempo;

    gettime (&tiempo1);
    Salto = Total / 2;

    while (Salto > 0) {
        for (j = Salto; j < Total; ++j) {
            /* Ordenación por inserción */
            aux = Datos[j];
            k = j - Salto;
            hallado = 0;

            while (k >= 0 && hallado == 0)
                if (aux < Datos[k]) {
                    Datos[k + Salto] = Datos[k];
                    k = k - Salto;
                }
                else
                    hallado = -1;

            Datos[k + Salto] = aux;
        }

        Salto = Salto / 2;
    }

    gettime (&tiempo2);
    tiempo = tiempo1.tm_hour * 60 * 60 * 100;
    tiempo += tiempo1.tm_min * 60 * 100;
    tiempo += tiempo1.tm_sec * 100;
    tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
    tiempo -= tiempo2.tm_min * 60 * 100;
    tiempo -= tiempo2.tm_sec * 100;
    printf ("%11d", abs (tiempo));
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int ei = 0, ed;
    long num = 1000;
    byte vector[MAX], copia[MAX];

    struct tm tiempo1, tiempo2;
    int tiempo;

    clrscr ();
    printf
        ("Nº de elementos  Selección  Intercambio  Burbuja  Inserción  Quicksort  Shell\n");
    init_array (vector);
    init_array (copia);
    random_array (vector);

    do {
        copiar (vector, copia, num);
        printf ("%10d", num);
        ordena_sel (copia, num);
        ordena_inter (copia, num);
        ordena_burbu (copia, num);
        ordena_inser (copia, num);

        ed = num;
        gettime (&tiempo1);
        quicksort (copia, ei, ed);
        gettime (&tiempo2);
        tiempo = tiempo1.tm_hour * 60 * 60 * 100;
        tiempo += tiempo1.tm_min * 60 * 100;
        tiempo += tiempo1.tm_sec * 100;
        tiempo -= tiempo2.tm_hour * 60 * 60 * 100;
        tiempo -= tiempo2.tm_min * 60 * 100;
        tiempo -= tiempo2.tm_sec * 100;
        printf ("%11d", abs (tiempo));

        Shell (copia, num);
        printf ("\n");
        num *= 2;
    }
    while (num <= MAX);
}
