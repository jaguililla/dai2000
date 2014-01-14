#include <stdio.h>
typedef struct {
    int num, den;
} frac;

void leer (frac * c);
void escribir (frac c);
void sumar (frac c1, frac c2, frac * c);
void restar (frac c1, frac c2, frac * c);
void multiplicar (frac c1, frac c2, frac * c);
void dividir (frac c1, frac c2, frac * c);
int mcd (int a, int b);
void simplifica (frac * c);

void main (void)
{
    frac c1, c2, c;
    int opcion;

    clrscr ();
    leer (&c1);
    leer (&c2);
    do {
        printf ("0.-fin    1(+)  2(-)  3(*)   4(/)    opcion: ");
        scanf ("%d", &opcion);
        switch (opcion) {
            case 1:
                sumar (c1, c2, &c);
                escribir (c1);
                putchar ('+');
                escribir (c2);
                putchar ('=');
                simplifica (&c);
                escribir (c);
                break;
            case 2:
                restar (c1, c2, &c);
                escribir (c1);
                putchar ('-');
                escribir (c2);
                putchar ('=');
                simplifica (&c);
                escribir (c);
                break;
            case 3:
                multiplicar (c1, c2, &c);
                escribir (c1);
                putchar ('*');
                escribir (c2);
                putchar ('=');
                simplifica (&c);
                escribir (c);
                break;
            case 4:
                dividir (c1, c2, &c);
                escribir (c1);
                putchar ('/');
                escribir (c2);
                putchar ('=');
                simplifica (&c);
                escribir (c);
                break;
        }
        printf ("\n");
    } while (opcion);
    printf ("fin de programa...\n");
    getch ();
}

int mcd (int a, int b)
{
    int aux;

    aux = a;
    while (a % aux || b % aux)
        aux--;
    return (aux);
}

void leer (frac * c)
{
    printf ("Introduzca numerador y denominador: ");
    scanf ("%d %d", &c->num, &c->den);
}

void escribir (frac c)
{
    printf ("(%d/%d)", c.num, c.den);
}

void sumar (frac c1, frac c2, frac * c)
{
    c->num = c1.num * c2.den + c1.den * c2.num;
    c->den = c1.den * c2.den;
}

void restar (frac c1, frac c2, frac * c)
{
    c->num = c1.num * c2.den - c1.den * c2.num;
    c->den = c1.den * c2.den;
}

void multiplicar (frac c1, frac c2, frac * c)
{
    c->num = c1.num * c2.num;
    c->den = c1.den * c2.den;
}

void dividir (frac c1, frac c2, frac * c)
{
    c->num = c1.num * c2.den;
    c->den = c1.den * c2.num;
}

void simplifica (frac * c)
{
    int aux;

    aux = mcd (c->num, c->den);
    c->num /= aux;
    c->den /= aux;
}
