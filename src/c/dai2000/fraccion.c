int num1, num2, indice, mayor, menor;
void main (void)
{
    clrscr ();
    printf ("Introduzca el numerador: ");
    scanf ("%d", &num1);
    printf ("Introduzca el denominador: ");
    scanf ("%d", &num2);
    indice = 2;

    if (num1 > num2) {
        menor = num2;
        mayor = num1;
    }
    else {
        menor = num1;
        mayor = num2;
    };

    do {
        while ((num1 % indice == 0) && (num2 % indice == 0)) {
            num1 = num1 / indice;
            num2 = num2 / indice;
        };

        if (indice <= 2)
            indice++;
        else
            indice += 2;
    }
    while (indice <= mayor / 2);

    printf ("La fracción irreducible es %d/%d ", num1, num2);

    getch ();
}
