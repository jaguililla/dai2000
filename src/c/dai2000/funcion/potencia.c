potencia (int base, int exp);

main ()
{
    int i, j;

    clrscr ();
    printf ("dame base ");
    scanf ("%d", &i);
    printf ("dame exponente");
    scanf ("%d", &j);
    printf ("la potencia de %d elevado a %d es: %d", i, j, potencia (i, j));
    getch ();

}
potencia (int base, int exp)
{
    int rtdo, i;

    if (exp < 0)
        return;                 //no puede hacer exponentes negativos

    for (rtdo = 1, i = 1; i <= exp; ++i)
        rtdo = rtdo * base;
    return (rtdo);
}
