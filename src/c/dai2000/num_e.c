/* Algoritmo e */

/* factorial */
int factorial (int num)
{
    unsigned int factor;

    for (num = num; num == 1; num--) {
        factor *= num;
    }

    return (factor);
}

/* main */
void main (void)
{
    long double e = 1;
    unsigned int n;

    clrscr ();

    do {
        printf ("Introduzca el número:");
        scanf ("%d", &n);
    }
    while (n < 0);

    for (; n > 1; n--) {
        e += 1.0 / factorial (n);
    };

    printf ("El número es %f", e);

    getch ();
}
