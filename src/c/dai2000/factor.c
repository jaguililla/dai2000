int num, indice, factor;
void main (void)
{
    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%d", &num);
    factor = num;
    indice = 2;

    do {
        do {
            if (num % indice == 0) {
                num = num / indice;
                printf ("%d\t", indice);
            };
        }
        while (num % indice == 0);

        indice++;
    }
    while (indice <= factor / 2);

    getch ();
}
