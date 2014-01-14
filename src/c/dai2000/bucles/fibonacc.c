main ()
{
/* Este programa imprime por pantalla la serie de Fibonacci hasta un tér-
mino deseado o inferior al límite solicitado */
    int limite, aux, termino1, termino2;
    char res = 's';

    while (res == 's') {
        clrscr ();
        termino1 = 1, termino2 = 2;
        gotoxy (10, 10);
        printf ("Deme un número ");
        scanf ("%d", &limite);
        gotoxy (10, 12);
        printf ("0, 1, ");
        while (termino1 <= limite) {
            aux = termino2;
            termino2 += termino1;
            printf ("%d, ", termino1);
            termino1 = aux;
        }
        gotoxy (10, 14);
        printf
            ("El siguiente término (%d) hubiera excedido del límite deseado ",
             termino2);
        gotoxy (10, 20);
        printf ("¿Deseas repetir la ejecución? (s/n) ");
        res = getche ();
    }
}
