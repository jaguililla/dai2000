void main (void)
{
    float num, max, min, total, total2;
    int indice, cont;

    clrscr ();
    printf ("Introduce un número: ");
    scanf ("%f", &num);
    indice = 1;

    while ((indice * indice) <= num) {
        indice++;
    };

    max = indice;

    min = indice - 1;

    cont = 1;

    if ((min * min) == num)
        printf ("La raíz es: %f", min);
    else {
        do {
            total = max + min;
            total2 = total / 2;

            if ((total2 * total2) > num)
                max = total2;
            else
                min = total2;

            cont++;
        }
        while (cont < 5);

        printf ("La raíz es: %f", total2);
    };

    getch ();
}
