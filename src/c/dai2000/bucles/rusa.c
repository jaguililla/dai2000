/* 4.18 Diseñe un programa que multiplique dos números enteros mediante el
algoritmo de la multiplicación rusa. El algoritmo de la multiplicación
rusa multiplica por 2 el multiplicando y divide por 2 el multiplicador
hasta que el multiplicador toma el valor 1. Después suma todos los
multiplicandos correspondientes a multiplicadores impares. Dicha suma
resulta ser el producto de los dos números.

Ejemplo 37 * 12 = 444  (multiplicador: 37.   multiplicando: 12)

37   12
18   24
9    48
4    96
2    192
1    384

12 + 48 + 384 = 444*/
void main (void)
{                               /* la función no devuelve nada */
    int producto, mcando, mcador;   /* las variables se declaran enteras */

    clrscr ();
    printf ("Introduzca multiplicando: ");
    scanf ("%d", &mcando);      /* la función scanf necesita la dirección */
    printf ("Introduzca multiplicador: ");
    scanf ("%d", &mcador);
    printf ("%d * %d = ", mcando, mcador);  /* imprime parte de la salida */
    producto = 0;
    while (mcando > 0) {
        if (mcando % 2 == 1)    /* si 'mcando' es impar, se añade */
            producto = producto + mcador;
        mcando = mcando / 2;
        mcador = mcador * 2;
    };
    printf ("%d \n", producto);
}
