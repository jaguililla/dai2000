/* cade0000.c */
#include <string.h>
#include <stdio.h>
#define N 255
void main (void)
{
    char c1[N], c2[N], c3[N], ascii;
    int i;

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

    c2[i] = c1[i];              /* asigna el \0 */
    printf ("Cadena copiada con while: ");
    puts (c2);
    strcpy (c2, "");
    printf ("Cadena copiada con strcpy: ");
    strcpy (c2, c1);
    puts (c2);

    printf ("%35s \n", "CONCATENAR");
    printf ("Introduzca c1: ");
    gets (c1);
    printf ("c1= ");
    puts (c1);
    printf ("Introduzca c2: ");
    gets (c2);
    printf ("c2= ");
    puts (c2);
    strcpy (c3, "");
    strcat (c3, c1);
    strcat (c3, c2);            /* c3 = c1 + c2 */

    printf ("c1= ");
    puts (c1);
    printf ("c1 + c2 = ");
    puts (c3);
    printf ("posición de c2 en c1+c2 =%u\n", strstr (c3, c2) - c3 + 1);

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

    printf ("%40s\n", "inversión de cadena con strrev");

    printf ("Introduzca c1 con alguna mayúscula: ");

    gets (c1);

    printf ("C1= ");

    puts (c1);

    printf ("inversión con strrev y a minúsculas con strlwr: ");

    strrev (c1);                /* invierte cadena */

    strlwr (c1);                /* todo a minúsculas */

    printf ("c1= ");

    puts (c1);

    printf ("Inicializa cadena a carácter. Meta carácter: ");

    ascii = getche ();

    strset (c1, ascii);

    printf ("\nc1= ");

    puts (c1);

    getch ();
}
