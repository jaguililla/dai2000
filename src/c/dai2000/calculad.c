//calculadora
int num1, num2, operador;
long producto;

void main (void)
{
    clrscr ();

    do {
        printf ("Introduzca dos números: ");
        scanf ("%d%d", &num1, &num2);
        printf ("Introduzca un operador (+(1),-(2),*(3),/(4)): ");
        scanf ("%d", &operador);

        switch (operador) {

            case 1:
                producto = num1 + num2;
                printf ("La suma es %d\n", producto);
                break;

            case 2:
                producto = num1 - num2;
                printf ("La diferencia es %d\n", producto);
                break;

            case 3:
                producto = num1 * num2;
                printf ("El producto es %d\n", producto);
                break;

            case 4:
                producto = num1 / num2;
                printf ("El cociente es %d\n", producto);
                break;

            default:
                printf (":-(\n");
                break;
        };

        printf ("¿Desea realizar otra operación?(s(1)/n(2)): ");

        scanf ("%d", &operador);
    }
    while (operador == 1);
}
