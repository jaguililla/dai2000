/* impr_put.c -- uso de puts() */
#include <stdio.h>
#define DEF "Nací de un #define."
int main (void)
{
    static char str1[] = "Un array me inicializó.";
    static char *str2 = "Un puntero me inicializó.";

    puts ("Soy un argumento de puts().");
    puts (DEF);
    puts (str1);
    puts (str2);
    puts (&str1[4]);
    puts (str2 + 4);
    return 0;
}
