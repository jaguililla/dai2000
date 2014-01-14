//////////////////////////////////////////////////////////////////////////////
//                            F A C T O R I A L                             //
//////////////////////////////////////////////////////////////////////////////
//  Nombre       : Juan José Aguililla Martínez.                            //
//  Fecha        : 14/12/1998                                               //
//  Curso        : 1º                                                       //
//  Clase        : 310                                                      //
//  Asignatura   : Programación                                             //
//  Especialidad : Informática                                              //
//////////////////////////////////////////////////////////////////////////////
//  Tarea        : Calcular el factorial de un número utilizando            //
//                 todas las estructuras repetitivas                        //
//////////////////////////////////////////////////////////////////////////////
//  Algoritmo    :                                                        //
//////////////////////////////////////////////////////////////////////////////
//  Pseudocódigo :                                                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////

#include <stdio.h>


// P R O T O T I P O S ///////////////////////////////////////////////////////

long int factorial_for (long n);

// Tarea:   Calcula el factorial de un número usando un bucle for.
// Entrada: -N-   Variable long int.
// Salida:  -FACTORIAL- Variable long int.

long int factorial_do (long n);

// Tarea:   Calcula el factorial de un número usando un bucle do-while.
// Entrada: -N-   Variable long int.
// Salida:  -FACTORIAL- Variable long int.

long int factorial_while (long n);

// Tarea:   Calcula el factorial de un número usando un bucle while.
// Entrada: -N-   Variable long int.
// Salida:  -FACTORIAL- Variable long int.

// F U N C I O N E S /////////////////////////////////////////////////////////

long int factorial_for (long int n)
{
    long int factorial = 1;
    int indice = 0;

    for (indice = 1; indice <= n; indice++) {
        factorial *= indice;
    }                           // Fin  for

    return (factorial);
}                               // Fin  factorial_for()

//////////////////////////////////////////////////////////////////////////////

long int factorial_do (long n)
{
    long int factorial = 1;
    int indice = 1;

    do {
        factorial *= indice;
        indice++;
    }                           // Fin  do-while
    while (indice <= n);

    return (factorial);
}                               // Fin  factorial_do ()

//////////////////////////////////////////////////////////////////////////////

long int factorial_while (long n)
{
    long int factorial = 1;
    int indice = 1;

    while (indice <= n) {
        factorial *= indice;
        indice++;
    }                           // Fin while

    return (factorial);
}                               // Fin  factorial_while ()

// M A I N ///////////////////////////////////////////////////////////////////

void main (void)
{
    long int numero;

    clrscr ();

    do {
        printf ("Introduzca un número positivo para hallar su factorial: ");
        scanf ("%ld", &numero);
    }
    while (numero < 0);

    printf ("El factorial de %ld usando factorial_for() es: %ld\n",
            numero, factorial_for (numero));

    printf ("El factorial de %ld usando factorial_do() es: %ld\n",
            numero, factorial_do (numero));

    printf ("El factorial de %ld usando factorial_while() es: %ld\n",
            numero, factorial_while (numero));

    getch ();
}                               // Fin  main()

//                    --++**>  EOF BIOSTXT.C  <**++--
