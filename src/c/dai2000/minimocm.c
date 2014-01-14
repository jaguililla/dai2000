int num1, num2, indice, prod, cociente;
void main (void)
{
    clrscr ();
    printf
        ("Vamos a hallar el m.c.m. de dos números.\nIntroducce dos números: ");
    scanf ("%d%d", &num1, &num2);
    indice = 1;

    do {
        prod = num1 * indice;
        cociente = prod % num2;
        indice++;
    }
    while (cociente != 0);

    printf ("El m.c.m.es %d", prod);

    getch ();
}
