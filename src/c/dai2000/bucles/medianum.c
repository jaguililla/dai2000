#include "stdio.h"
void main (void)
{
    float f, suma = 0.0, media;
    unsigned cont = 0;

    clrscr ();                  /* necesita conio.h */
    printf ("Introduzca flotante: ");
    scanf ("%f%c", &f);
    while (f) {
        suma += f;
        cont++;
        printf ("Introduzca flotante: ");
        scanf ("%f", &f);
    }
    printf ("La media es %5.3f \n", suma / cont);
    getch ();
}
