int num, iva;
long prod;
void main (void)
{
    clrscr ();
    printf ("Introduzca el precio: ");
    scanf ("%d", &num);
    printf ("Introduzca el valor del I.V.A.(16,7,4): ");
    scanf ("%d", &iva);

    while ((num == 16) || (num == 7) || (num == 4)) {
        printf ("Introduzca un número correcto para el I.V.A.: ");
        scanf ("%d", &iva);
    }

    prod = num + (num * iva / 100);
    printf ("El valor total de %d es %d. ", num, prod);
    getch ();
}
