//halla la media entre los factores primos de un número
int num, indice, factor, acum = 1, cont = 1;
void main (void)
{
    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%d", &num);
    factor = num;
    indice = 2;

    do {
        do {
            if (num % indice == 0) {
                num = num / indice; //halla el factor primo
                acum += indice; //guarda la suma total
                cont++;         //indica entre que hay que dividir suma al final
            }
        }
        while (num % indice == 0);

        indice++;
    }
    while (indice <= factor / 2);

    printf ("La media es: %f", (float) acum / cont);

    getch ();
}
