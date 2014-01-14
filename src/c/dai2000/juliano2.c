void main (void)
{
    int num, indice = 0, dias, d;

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
                d = 31;
                break;

            case 11:

            case 9:

            case 6:

            case 4:
                num -= 30;
                d = 30;
                break;

            case 2:
                num -= 28;
                d = 28;
                break;
        };

        indice++;
    }
    while (num > 0);

    dias = d - abs (num);

    printf ("%d/%d", dias, indice - 1);

    getch ();
}
