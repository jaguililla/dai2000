/* nombre2.c -- lee un nombre */
#include <stdio.h>
#define MAX 81
int main (void)
{
    char nombre[MAX];
    char *ptr, *gets (char *);

    printf ("Hola, ¿cómo te llamas?\n");
    ptr = gets (nombre);
    printf ("¿%s? ¡Ah! ¡%s!\n", nombre, ptr);
    return 0;
}
