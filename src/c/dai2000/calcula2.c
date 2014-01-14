//calculadora
int num1, num2, num1i, num2i, operador;

void suma (int r1, int r2, int i1, int i2, int *rs, int *ri)
{
    *rs = r1 + r2;
    *ri = i1 + i2;
}

void resta (int r1, int r2, int i1, int i2, int *rs, int *ri)
{
    *rs = r1 - r2;
    *ri = i1 - i2;
}

void producto (int r1, int r2, int i1, int i2, int *rs, int *ri)
{
    *rs = (r1 * r2) - (i1 * i2);
    *ri = (r1 * i2) + (i1 * r2);
}

void cociente (int r1, int r2, int i1, int i2, int *rs, int *ri)
{
    *rs = ((r1 * r2) - (i1 * i2)) / ((r2 * r2) + (i2 * i2));
    *ri = ((r1 * i2) + (i1 * r2)) / ((r2 * r2) + (i2 * i2));
}

void main (void)
{
    int resr = 0, resi = 0;
    char op;

    clrscr ();

    do {
        printf ("Introduzca el primer número imaginario(a,b)(a+bi): ");
        scanf ("%d%d", &num1, &num1i);
        printf ("Introduzca el segundo número imaginario: ");
        scanf ("%d%d", &num2, &num2i);
        printf ("Introduzca un operador (+(1),-(2),*(3),/(4)): ");
        scanf ("%d", &operador);

        switch (operador) {

            case 1:
                suma (num1, num2, num1i, num2i, &resr, &resi);
                op = '+';
                break;

            case 2:
                resta (num1, num2, num1i, num2i, &resr, &resi);
                op = '-';
                break;

            case 3:
                producto (num1, num2, num1i, num2i, &resr, &resi);
                op = '*';
                break;

            case 4:
                cociente (num1, num2, num1i, num2i, &resr, &resi);
                op = '/';
                break;

            default:
                printf (":-}\n");
                break;
        };

        if ((resr != 0) && (resi != 0))
            printf ("(%d+%di) %c (%d+%di) = (%d+%di)", num1, num1i, op, num2,
                    num2i, resr, resi);
        else if (resr == 0)
            printf ("(%d+%di) %c (%d+%di) = %di", num1, num1i, op, num2,
                    num2i, resi);
        else
            printf ("(%d+%di) %c (%d+%di) = %d", num1, num1i, op, num2, num2i,
                    resr);

        printf ("\n¿Desea realizar otra operación?(s(1)/n(2)): ");

        scanf ("%d", &operador);
    }
    while (operador == 1);
}
