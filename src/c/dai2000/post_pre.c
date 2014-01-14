/* post_pre.c -- compara sufijos y prefijos */
#include <stdio.h>
main ()
{
    int a = 1, b = 1;
    int amas, masb;

    amas = a++;                 /* sufijo  */
    masb = ++b;                 /* prefijo */
    printf ("  a   amas    b   masb\n");
    printf ("%3d %5d %5d %5d\n", a, amas, b, masb);
}
