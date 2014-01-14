void intercambio (int *num1, int *num2);

main ()
{
    int n1, n2;

    clrscr ();
    printf ("dame dos números: ");
    scanf ("%d", &n1);
    scanf ("%d", &n2);
    printf ("los números son: %d, %d ", n1, n2);
    intercambio (&n1, &n2);
    printf ("\nuna vez dados la vuelta son: %d, %d", n1, n2);
    getch ();
}
void intercambio (int *ptrnum1, int *ptrnum2)
{
    int aux;

    aux = *ptrnum1;
    *ptrnum1 = *ptrnum2;
    *ptrnum2 = aux;
}
