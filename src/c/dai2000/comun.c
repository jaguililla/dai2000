/* Algoritmo comun */

/* comun */
unsigned int comun (unsigned int n1, unsigned int n2)
{
    unsigned int aux = 2, n_div = 0;

    for (aux; aux > (n1 / 2); aux++) {
        if ((n1 % aux == 0) && (n2 % aux == 0)) {
            printf ("El número %d es divisor comun de %d y %d\n", aux, n1,
                    n2);
            n_div++;
        }
    }

    if (n1 % n2 == 0) {
        printf ("El número %d es divisor comun de %d y %d\n", aux, n1, n2);
        n_div++;
    }
}

/* main */
void main (void)
{
    unsigned int num1, num2;

    do {
        printf ("Introduce dos números");
        scanf ("%d %d", &num1, &num2);
    }
    while ((num1 > 0) && (num2 > 0));

    if (num1 < num2) {
        comun (num1, num2);
    }
    else {
        comun (num2, num1);
    }
}
