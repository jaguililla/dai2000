void main (void)
{
    int num, indice = 1, dias;

    clrscr ();
    printf ("Introduzca un número(1-365): ");
    scanf ("%d", &num);

    do {
        switch (indice) {

            case 12:

            case 10:

            case 8:

            case 7:

            case 5:

            case 3:

            case 1:
                num -= 31;
                break;

            case 11:

            case 9:

            case 6:

            case 4:
                num -= 30;
                break;

            case 2:
                num -= 28;
                break;
        };

        indice++;
    }
    while (num > 0);

    switch (indice) {

        case 12:

        case 10:

        case 8:

        case 7:

        case 5:

        case 3:

        case 1:
            dias = 31 - (abs (num));
            break;

        case 11:

        case 9:

        case 6:

        case 4:
            dias = 30 - (abs (num));
            ;
            break;

        case 2:
            dias = 28 - (abs (num));
            break;
    };

    printf ("%d/%d", dias, indice);

    getch ();
}
