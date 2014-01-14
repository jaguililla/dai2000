int menor (void)
{
    int indice = 1;

    do {
        indice++;
    }
    while (indice * indice <= 1000);

    return (indice);
}

void main (void)
{
    int peque, cont;

    clrscr ();
    peque = menor ();
    printf ("Los cuadrados perfectos son:\n");

    for (cont = peque; cont * cont < 10000; cont++) {
        printf ("%d\t", cont * cont);
    }

    getch ();
}
