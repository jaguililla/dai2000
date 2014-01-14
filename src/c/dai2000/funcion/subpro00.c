/* subpro00 */
/* Ejemplo paso de parámetros. Intercambio de dos variables */
void main (void)
{
    int n1, n2;

    clrscr ();
    leerentero (&n1);
    leerentero (&n2);
    printf ("Antes del cambio n1= %d, n2= %d \n", n1, n2);
    swapint (&n1, &n2);
    printf ("Después del cambio n1= %d, n2= %d \n", n1, n2);
}

leerentero (n)
     int *n;
{
    printf ("Introduzca entero: ");
    scanf ("%d", n);
    return;
}

swapint (a, b)
     int *a, *b;
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
    return;
}
