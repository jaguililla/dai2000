void main ()
{
    int n1, n2;
    int sw;

    clrscr ();
    printf ("\n Introduzca un número, 0 para salir :");
    scanf ("%d", &n1);
    while (n1 != 0) {
        sw = 0;
        n2 = 2;
        if (n1 == 1)
            printf ("\nEl nº 2 es el siguiente nº primo ");
        else if (n1 == 2)
            printf ("\nEl número 3 es el siguiente nº primo ");
        else {
            ++n1;
            while (sw == 0) {
                while ((n2 < n1) && (sw == 0))
                    if (n1 % n2 != 0)
                        ++n2;
                    else
                        sw = 1;
            }
            ++n1;
        }
        if (sw == 1)
            printf ("\nEl número %d es el siguiente nº primo", n1);
        delay (3000);
        printf ("\n Introduzca un número, 0 para salir: ");
        scanf ("%d", &n1);
    }
}
