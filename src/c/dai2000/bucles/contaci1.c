/* contaci1.c */
/* Programa que cuenta todas la cifras de un entero */
void main (void)
{

    unsigned int entero, copia, cifras;

    clrscr ();
    do {
        printf ("Introduzca un entero: ");
        scanf ("%d", &copia);
        entero = copia;
        cifras = 1;
        while (entero >= 10) {
            printf ("%f\n", (float) entero / 10);
            entero = entero / 10;
            ++cifras;
        }
        printf ("Número de cifras= %d \n", cifras);
    } while (copia != 0);
}
