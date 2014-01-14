void main (void)
{
    int c;

    clrscr ();
    for (c = 48; c <= 57; c++)
        printf ("%c.-%3d  ", c, c);
    printf ("\n\n");
    {                           /* También puedo declarar una variable dentro de un bloque {} */
        unsigned char d;

        for (d = 48; d <= 57; d++)
            printf ("%c.-%3d  ", d, d);
        printf ("Introduzca carácter: ");
        d = getchar ();
        putchar (d);
    }
    /*   d = getchar(); putchar(d); Quitar estos comentarios */
    getch ();

}
