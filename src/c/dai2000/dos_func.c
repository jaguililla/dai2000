/* dos_func.c  -- programa que usa dos funciones en un fichero */
#include <stdio.h>
void mayordomo (void);          /* prototipo de función ANSI C */

/* utilícese void mayordomo(); en sistemas pre-ANSI C */
main ()
{
    printf ("Llamar a la función mayordomo.\n");
    mayordomo ();
    printf ("Sí. Tráigame un café y el libro de C.\n");
}

void mayordomo (void)
{                               /* comienza definición de la función */
    printf ("¿Llamó el señor?\n");
}
