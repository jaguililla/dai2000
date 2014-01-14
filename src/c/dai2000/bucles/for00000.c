void main (void)
{
    float var = 10;
    int cont = 0;

    for (var = 10; var <= 15; var = var + 0.5) {
        printf ("Contador     Valor\n");
        printf ("%-8d         %2.2f \n", cont, var);
        ++cont;
    }
    printf ("OBSERVE CAMBIOS EN EL INCREMENTO DEL FOR\n");
    for (var = 10; var <= 15; var += 2.5) {
        printf ("Contador     Valor\n");
        printf ("%8d         %2.2f \n", cont, var);
        ++cont;
    }
}
