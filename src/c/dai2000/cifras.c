int indice, coc, ind, cont1, cont3, coc1, coc2, coc3;
long num, diez, cont2;

//''''''''''''''''''''''''''''''''''''''''''''''''
void main (void)
{
    clrscr ();
    printf ("Escriba un número: ");
    scanf ("%d", &num);
    indice = 0;
    diez = 1;

    do {
        coc = num / diez;
        diez = diez * 10;
        indice++;
    }
    while (coc != 0);

    //indice-1 = nº de cifras
    printf ("El número de cifras es: %d\n", indice - 1);

    ind = indice - 1;

    cont1 = 1;

    cont2 = pow10 (ind);

    cont3 = 0;

    do {
        coc2 = coc3;
        /////////////////////////
        coc2 = num / cont2;
        coc3 = num % cont2;
        cont1 = cont1 * 10;
        cont2 = cont2 / 10;
        cont3++;
    }
    while ((coc1 == coc2) || (cont3 == ind));

    if (cont3 == indice / 2)
        printf ("El número %d es capicua", num);
    else
        printf ("El número %d no es capicua", num);

    getch ();

    return;
}
