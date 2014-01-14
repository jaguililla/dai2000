// PRUEBA BIOSCARGATABLA()

// INCLUDES
#include "basico.h"
#include "libtxt.c"

// MAIN
void main (void)
{
    unsigned long int cont = 0;
    byte *Fuente_ = NULL;
    byte Caracter[16] =
        { 1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2, 1, 255 };

    BorraPg (0);
    for (cont = 0; cont < 256; cont++) {
        MemPrint ("%c", cont);
        MemX++;
    }
    getch ();
    Fuente_ = CargaTabla ("\\cpv\\font\\upercase.fnt");
    CambiaTabla (Fuente_);
    free (Fuente_);
    getch ();
    Fuente_ = CargaTabla ("\\cpv\\font\\thai.fnt");
    CambiaTabla (Fuente_);
    free (Fuente_);
    getch ();
    Fuente_ = CargaTabla ("\\cpv\\font\\ascii.fnt");
    CambiaTabla (Fuente_);
    free (Fuente_);
    getch ();
    Fuente_ = CargaTabla ("\\cpv\\font\\bold.fnt");
    CambiaTabla (Fuente_);
    for (cont = 0; cont < 10; cont++) {
        CambiaCaract (Fuente_, cont, Caracter);
        CambiaTabla (Fuente_);
        getch ();
    }
    free (Fuente_);
    for (cont = 0; cont < 501; cont++) {
        Fuente_ = CargaTabla ("\\cpv\\font\\bold.fnt");
        CambiaTabla (Fuente_);
        free (Fuente_);
        BorraPg (0);
        MemPrint ("Ciclo %d", cont);
    }
    free (Fuente_);
    RestauraTabla (ROM8x16);
}
