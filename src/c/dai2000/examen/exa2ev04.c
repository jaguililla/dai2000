/* exa2ev04.c */
#include <string.h>
#include <stdio.h>
#define N 255

void cambiar (char *a, char *b)
{
    char aux;

    aux = *a, *a = *b, *b = aux;
}
void main (void)
{
    char c1[N], c2[N], ascii;
    int i, i1, i2, iguales;

    clrscr ();
    printf ("Introduzca cadena: ");
    gets (c1);
    printf ("cadena= ");
    puts (c1);
    printf ("Longitud strlen= %d\n", strlen (c1));

    i = 0;
    while (c1[i])
        i++;
    printf ("Longitud while =%d \n", i);

    i = 0;
    while (c1[i]) {
        c2[i] = c1[i];
        i++;
    }
    c2[i] = c1[i];
    printf ("Cadena copiada con while: ");
    puts (c2);
    strcpy (c2, "");
    printf ("Cadena copiada con strcpy: ");
    strcpy (c2, c1);
    puts (c2);

    printf ("%50s\n", "COMPARACIÓN DE CADENAS ");
    printf ("Introduzca c1: ");
    gets (c1);
    printf ("c1= ");
    puts (c1);
    printf ("Introduzca c2: ");
    gets (c2);
    printf ("c2= ");
    puts (c2);
    if (strcmp (c1, c2) < 0)
        printf ("%s < %s\n", c1, c2);
    else if (strcmp (c1, c2) == 0)
        printf ("%s =  %s\n", c1, c2);
    else
        printf ("%s > %s\n", c1, c2);

    i1 = 0;
    i2 = 0;
    iguales = 1;
    while (c1[i1] && c2[i2] && iguales) {
        if (c1[i1] != c2[i2])
            iguales = 0;
        else {
            i1++;
            i2++;
        }
    }
    if (iguales)
        iguales = (c1[i1] == c2[i2]);
    if (iguales)
        printf ("son iguales\n");
    else if (c1[i1] > c2[i2])
        printf ("la primera es mayor que la segunda\n");
    else
        printf ("la primera es menor\n");

    printf ("%40s\n", "inversión de cadena con strrev");
    printf ("Introduzca ccadena: ");
    gets (c1);
    printf ("C1= ");
    puts (c1);
    printf ("inversión con strrev: ");
    strrev (c1);
    printf ("c1= ");
    puts (c1);

}
