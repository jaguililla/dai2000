/* comp_ret.c -- return de strcmp */
#include <stdio.h>
#include <string.h>
int main (void)
{
    printf ("%d\n", strcmp ("A", "A"));
    printf ("%d\n", strcmp ("A", "B"));
    printf ("%d\n", strcmp ("B", "A"));
    printf ("%d\n", strcmp ("C", "A"));
    printf ("%d\n", strcmp ("manzanas", "manzana"));
    return 0;
}
