/* invierte.c -- modifica una tira */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 80
void modifica (char *);
int main (void)
{
    char linea[LIM];

    puts ("Introduzca una línea:");
    gets (linea);
    modifica (linea);
    puts (linea);
    return 0;
}

void modifica (char *str)
{
    while (*str != '\0') {
        if (isupper (*str))
            *str = tolower (*str);
        else if (islower (*str))
            *str = toupper (*str);

        str++;
    }
}
