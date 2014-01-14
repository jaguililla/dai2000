int num1, num2, indice, suma, fac1, fac2;
void main (void)
{
    clrscr ();
    printf ("introduzca dos factores: ");
    scanf ("%d%d", &num1, &num2);

    if ((num1 == 0) || (num2 == 0)) {
        printf ("El producto es 0");
    }
    else {
        fac1 = abs (num1);
        fac2 = abs (num2);
        indice = 1;
        suma = 0;

        while (indice <= fac1) {
            suma += fac2;
            indice++;
        };

        if (num1 < 0)
            suma = -suma;

        if (num2 < 0)
            suma = -suma;

        printf ("El producto es %d.", suma);
    };

    getch ();
}
