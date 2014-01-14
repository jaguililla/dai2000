/* punt_fun.c -- usa punteros a funciones */
#include <stdio.h>
int rputs (const char *);
void saca (int (*fp) (const char *ps), char *str);
int main (argc, argv)
     int argc;
     char *argv[];
{
    if (argc < 2)
        exit (1);

    saca (puts, argv[1]);       /* usa puts()  */

    saca (rputs, argv[1]);      /* usa rputs() */

    return 0;
}

int rputs (const char *str)
{
    const char *princ = str;

    while (*str != '\0')
        str++;                  /* va al final de la tira */

    while (str != princ)
        putchar (*--str);

    return putchar ('\n');
}

void saca (int (*fp) (const char *ps), char *str)
/* fp apunta a una función que devuelve int */
{
    (*fp) (str);                /* pasa str a la función apuntada */
}
