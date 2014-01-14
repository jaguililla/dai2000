int num, indice;
unsigned long prod;
void main (void)
{
    clrscr ();

    do {
        printf ("Introduzca un número: ");
        scanf ("%d", &num);
    }
    while (num < 0);

    if (num <= 1) {
        printf ("El factorial es 1");
    }
    else {
        indice = 1;
        prod = 1;

        while (indice <= num) {
            prod *= indice;
            indice++;
        };

        printf ("El factorial de %d es %d.", num, prod);
    };

    getch ();
}
