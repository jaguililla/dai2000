
/*4.1     Calcular el factorial de un número entero leído desde el
    teclado utilizando las sentencias DO-WHILE, WHILE y FOR.

    CODIFICACION}*/

/* Cálculo del factorial */
void main (void)
{
    int n, factorial, numero;

    clrscr ();
    printf ("Introduzca entero: ");
    scanf ("%d", &numero);
    /* cálculo del factorial con for */
    factorial = 1;
    for (n = 1; n <= numero; ++n)
        factorial = factorial * n;
    printf ("%d != %d\n", numero, factorial);

    /* cálculo del factorial con DO-WHILE */
    factorial = 1;
    if (numero != 0) {
        n = 0;
        do {
            ++n;
            factorial = factorial * n;
        } while (n < numero);
    }
    printf ("%d != %d\n", numero, factorial);

/* cálculo del factorial con WHILE */
    factorial = 1;
    n = 0;
    while (n < numero) {
        ++n;
        factorial = factorial * n;
    };
    printf ("%d != %d\n", numero, factorial);
}
