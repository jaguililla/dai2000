void intercambio (int *ptrnum1, int *ptrnum2);

main ()
{
    int *ptrn1, *ptrn2;

    clrscr ();
    printf ("dame dos números: ");
    scanf ("%d", ptrn1);
    scanf ("%d", ptrn2);
    intercambio (ptrn1, ptrn2);
    printf ("%d , %d ", *ptrn1, *ptrn2);
    getch ();
}
void intercambio (int *ptrnum1, int *ptrnum2)
{
    int aux;

    aux = *ptrnum1;
    *ptrnum1 = *ptrnum2;
    *ptrnum2 = aux;
}
