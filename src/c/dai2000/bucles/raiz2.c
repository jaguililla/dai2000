#include <stdio.h>
void main (void)
{
    double numero, sup, inf, medio, cuadrado, raiz, tolerancia;

    // calcula la raíz cuadrada de un número por métodos aproximados
    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%lf", &numero);
    sup = 0;
    do
        sup = sup + 1;
    while (sup * sup < numero);
    if (sup * sup == numero)
        printf ("La raíz cuadrada es %f\n", sup);
    else {
        printf ("Introduzca tolerancia: ");
        scanf ("%lf", &tolerancia);
        inf = sup - 1;
        medio = (inf + sup) / 2;
        cuadrado = medio * medio;
        while ((cuadrado != numero) && (tolerancia < sup - inf)) {
            if (cuadrado > numero)
                sup = medio;
            else
                inf = medio;
            medio = (inf + sup) / 2;
            cuadrado = medio * medio;
        }
        if (cuadrado == numero)
            raiz = medio;
        else
            raiz = (inf + sup) / 2;
    }
    printf ("Error entre raíz calculada y sqrt %f\n", raiz - sqrt (numero));
    getch ();
}
