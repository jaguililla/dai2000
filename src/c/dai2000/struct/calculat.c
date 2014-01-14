#include<stdlib.h>
#include<ctype.h>

typedef struct {
    int nume, deno;
} fraccion;

//////////////////////////////////////////////////////////////////////////////
void suma (fraccion frac1, fraccion frac2, fraccion * total) {
    if (frac1.deno == frac2.deno) {
        total->nume = frac1.nume + frac2.nume;
        total->deno = frac1.deno;
    }
}

//////////////////////////////////////////////////////////////////////////////
void main (void) {
    char ope, resp;
    int repe;
    fraccion frac1, frac2, *total;

    do {
        printf ("Introduzca numerador y denominador: ");
        scanf ("%d %d", &frac1.nume, &frac1.deno);
        printf ("Introduzca numerador y denominador: ");
        scanf ("%d %d", &frac2.nume, &frac2.deno);
        printf ("Elija operación(+,-,*,/)");
        do {
            repe = 0;
            ope = getch ();
            switch (ope) {
                case '+':
                    suma (frac1, frac2, &total);
                    break;
                case '-':
                    suma (frac1, frac2, &total);
                    break;
                case '*':
                    suma (frac1, frac2, &total);
                    break;
                case '/':
                    suma (frac1, frac2, &total);
                    break;
                default:
                    printf ("\nIntroduzca un operador valido: ");
                    repe = 1;
                    break;
            }                   //llave del switch
        }
        while (repe == 1);    //si el operador no es valido pide otro
        printf ("\n¿Desea realizar otra operación?(s/n): ");
        resp = getch ();
        resp = tolower (resp);
    }
    while (resp == 's');
}
