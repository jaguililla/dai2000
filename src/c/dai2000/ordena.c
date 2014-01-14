// A L G O R I T M O   O R D E N A ///////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

#include <time.h>

#include "basico.h"

// D E F I N E S /////////////////////////////////////////////////////////////
#define MAX 6
#define max 5
// P R O T O T I P O S ///////////////////////////////////////////////////////
void cambiar (int *n1, int *n2);
void init_array (int array[]);
void random_array (int array[], int num);
void lee_array (int array[]);

void ordena_sel (int array[]);
void ordena_sel2 (int array[]);
void ordena_inter (int array[]);
void ordena_burbu (int array[]);
void ordena_inser (int array[]);

void imp_array (int array[]);

// F U N C I O N E S /////////////////////////////////////////////////////////
void cambiar (int *n1, int *n2)
{
    int aux = 0;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

//////////////////////////////////////////////////////////////////////////////

void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        array[cont] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////////

void random_array (int array[], int num)
{
    int cont = 0;

    randomize ();

    for (cont = 1; cont < MAX; cont++) {
        array[cont] = rand ()%num + 1; // Nº aleatorio entre 0 y num
    }
}

//////////////////////////////////////////////////////////////////////////////

void lee_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        scanf ("%d", &array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_sel (int array[])
{
    int cont = 0, cont2 = 0, pos_menor = 0;

    for (cont = 0; cont < MAX - 1; cont++) {
        pos_menor = cont;

        for (cont2 = cont + 1; cont2 < MAX; cont2++) {
            if (array[cont2] < array[pos_menor])    // menor = array[pos_menor]
            {
                pos_menor = cont2;
            }
        }

        cambiar (&array[pos_menor], &array[cont]);
        printf ("Iteración %d: ", cont + 1);    // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_sel2 (int array[])  // Optimizar: sustituir: menor, mayor y pos_*
{
    int cont_i = 0, cont_f = 0, cont = 0;
    int pos_menor = 0, pos_mayor = 0;

    for (cont_i = 0, cont_f = MAX - 1; cont_i <= cont_f; cont_i++, cont_f--) {
        pos_menor = cont_i;
        pos_mayor = cont_f;

        for (cont = cont_i + 1; cont <= cont_f; cont++) {
            if (array[cont] < array[pos_menor]) //menor=array[pos_menor]
            {
                pos_menor = cont;
            }
            else if (array[cont] > array[pos_mayor])    //mayor=array[pos_mayor]

            {
                pos_mayor = cont;
            }
        }

        cambiar (&array[pos_menor], &array[cont_i]);
        cambiar (&array[pos_mayor], &array[cont_f]);
        printf ("Iteración %d: ", cont_i + 1);  // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_inter (int array[])
{
    int cont = 0, cont2 = 0;

    for (cont = 0; cont < MAX - 1; cont++) {
        for (cont2 = cont + 1; cont2 < MAX; cont2++) {  //No se puede usar una var a la q

            if (array[cont] > array[cont2]) //se le asigna el valor del array
            {                   // xq el prog no la cambia
                cambiar (&array[cont], &array[cont2]);
            }
        }

        printf ("Iteración %d: ", cont + 1);    // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_burbu (int array[])
{
    int cont = 0, cont2 = 0, conta = 0;

    for (cont = 5, conta = 1; cont > 0; cont--, conta++)    // conta no es nec.
    {

        for (cont2 = 0; cont2 < MAX - 1; cont2++) {
            if (array[cont2] > array[cont2 + 1]) {
                cambiar (&array[cont2], &array[cont2 + 1]);
            }
        }

        printf ("Iteración %d: ", conta);   // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_inser (int array[])
{
    int aux, hallado, p, k, cont = 1;

    for (p = 1; p <= MAX - 1; p++, cont++) {
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
        printf ("Iteración %d: ", cont);    // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria

    }
}

//////////////////////////////////////////////////////////////////////////////
void imp_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        printf ("%d ", array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////

/* M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
 int vector[MAX], control=0, control2=0, control3=0, num=0;
 do{
 clrscr();
 init_array (vector);
 printf ("\nSeleccione el método de inicialización:\n");
 printf ("\n\t1.- Inicialización manual");
 printf ("\n\t2.- Inicialización aleatoria");
 printf ("\n\nSu selección es: ");
 scanf("%d",&control);
 if (control == 1)
 {
  printf ("\nIntroduzca los valores del array: ");
  lee_array (vector);
 }
 else if (control == 2)
 {
  printf ("\nIntroduzca el número máximo de números (0-N): ");
  scanf("%d",&num);
  random_array (vector, num);
 }
 printf ("\nSeleccione el método de ordenación:\n");
 printf ("\n\t1.- Ordenación por selección (menor)");
 printf ("\n\t2.- Ordenación por selección (mayor y menor)");
 printf ("\n\t3.- Ordenación por intercambio");
 printf ("\n\t4.- Ordenación por el método de la burbuja");
 printf ("\n\t5.- Ordenación por el método de inserción");
 printf ("\n\nSu selección es: ");
 scanf("%d",&control2);
 printf ("\n\n\nValor inicial del array: ");
 imp_array (vector);
 printf ("\n------------------------------------------\n");
 switch (control2)
 {
  case 1:
   ordena_sel(vector);
   break;
  case 2:
   ordena_sel2(vector);
   break;
  case 3:
   ordena_inter(vector);
   break;
  case 4:
   ordena_burbu(vector);
   break;
  case 5:
   ordena_inser(vector);
   break;
 }
 printf ("------------------------------------------");
 printf ("\nValor final del array: ");
 imp_array (vector);
 printf("\n\n\n¿Desea ordenar otro array?(1-sí/0-no): ");
 scanf("%d",&control3);
 }while(control3==1);
}*/
