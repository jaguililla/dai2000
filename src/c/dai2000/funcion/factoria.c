main ()
{
    int num;
    double factorial ();

    clrscr ();
    gotoxy (15, 10);
    printf ("Introduce un número (0 para terminar):  ");
    scanf ("%d", &num);
    while (num != 0) {
        gotoxy (15, 15);
        printf ("El factorial de %d es:  %g", num, factorial (num));
        getch ();
        clrscr ();
        gotoxy (15, 10);
        printf ("Introduce un número (0 para terminar):  ");
        scanf ("%d", &num);
    }
    gotoxy (15, 20);
    printf ("Pulse una tecla para continuar ");
    getch ();
}

double factorial (numero)
     int numero;
{
    int i;
    double resultado = 1;

    for (i = 1; i <= numero; ++i)
        resultado *= i;

    return (resultado);

}
