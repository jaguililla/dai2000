// A L G O R I T M O    C I R C U L O ////////////////////////////////////////

// I N C L U D E /////////////////////////////////////////////////////////////
#include <stdio.h>

#include <math.h>

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    // Variables MAIN
    int Ptos;                   // Nº de puntos dentro del círculo
    int Linea;                  // Nº de puntos de una línea del círculo
    int Cont;                   // Contador del bucle
    float R;                    // Radio de la circunferencia

    clrscr ();                  // Borra la pantalla
    printf ("Introduzca el radio del círculo:");
    scanf ("%f", &R);           // Pide el radio (float)
    Ptos = 0;                   // Inicializa el número de ptos a 0

    for (Cont = 0; Cont <= abs (R); Cont++) {
        Linea = abs (sqrt (pow (R, 2) - pow (Cont, 2)));
        ;
        Ptos += Linea;
    }                           // Fin FOR

    Ptos = (Ptos * 4) + 1;      // Ptos de un cte x 4 (4 ctes) + el centro

    printf ("El número de puntos es: %d", Ptos);

    getch ();
}                               // Fin MAIN

// Con Ptos = 1 no funciona xq al multiplicar Ptos * 4 multiplica x 4 el
// centro q solo es uno
