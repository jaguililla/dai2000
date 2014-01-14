int num, indice, prod, cont;
float nume;
void main (void)
{
    clrscr ();
    printf ("Introduzca un número:");
    scanf ("%d", &num);
    nume = 1;

    for (indice = 1; indice <= num; indice++) {
        prod = 1;
        cont = 1;

        do {
            prod *= cont;
            cont++;
        }
        while (cont <= indice);

        cont = cont - 1;

        nume = nume + (float) (1.0 / prod);
    }

    printf ("%f", nume);
    getch ();
}
