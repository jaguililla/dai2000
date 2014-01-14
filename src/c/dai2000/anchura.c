/* anchura.c -- anchuras de los campos */
#include <stdio.h>
#define PAGINAS 336
main ()
{
    printf ("/%d/\n", PAGINAS);
    printf ("/%2d/\n", PAGINAS);
    printf ("/%10d/\n", PAGINAS);
    printf ("/%-10d/\n", PAGINAS);
}
