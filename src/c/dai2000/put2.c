/* put2.c -- imprime una tira y cuenta sus caracteres */
#include <stdio.h>
int put2 (char *tira)
{
    int cont = 0;

    while (*tira != '\0') {
        putchar (*tira++);
        cont++;
    }

    putchar ('\n');             /* nueva línea no se cuenta */
    return (cont);
}
