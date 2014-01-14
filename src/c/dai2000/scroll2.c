#include<stdlib.h>


void main (void)
{
    char saludo[] = "que hay ";
    int indice;

    clrscr ();

    for (indice = 74; indice > 0; indice--) {
        gotoxy (indice, 10);
        delay (50);
        puts (saludo);
    }

    getch ();
}
