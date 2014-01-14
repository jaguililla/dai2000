/* put1.c -- imprime una tira */
#include <stdio.h>
void put1 (char *tira)
{
    while (*tira != '\0')
        putchar (*tira++);

    putchar ('\n');
}
