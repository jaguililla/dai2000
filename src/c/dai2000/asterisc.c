//asteriscos
int num, indice, cont;

void main (void)
{
    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%d", &num);

    for (indice = 1; indice <= num; indice++) {
        for (cont = 1; cont <= indice; cont++) {
            printf ("*");
        };

        printf ("\n");
    };

    getch ();
}
