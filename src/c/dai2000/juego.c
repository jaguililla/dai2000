#include <stdlib.h>
#include "../basico.h"

void main (void)
{
    int cont = 0;
    byte *Font = NULL;

    clrscr ();

    for (cont = 0; cont <= 255; cont++) {
        printf ("%c ", cont);
    }

    getch ();
    BiosCargaTabla (Font, "\\f\\font\\ascii.fnt");
    getch ();
}
