// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include "basico.h"
#include "libtxt.c"

// M A I N ///////////////////////////////////////////////////////////////////
int main (void) // Xa q funcione main, incluir #include "biosvid.c"
{
    byte Cont = 0;
    byte *Cadena1 = "Ya esta", Cadena2[10] = " Seguro";
    byte *Font = NULL;

    clrscr ();
    Font = CargaTabla ("\\cpv\\font\\bold.fnt");
    CambiaTabla (Font);
    for (Cont = 0; Cont < 7; Cont++) {
        MemPagina (Cont);
        MemIra (Cont, Cont);
        MemCol (GRISOSCURO, Cont);
        MemPrint ("%c%dEsto prueba %s 21%s%c ", Cont + 1, Cont + 1, Cadena1, Cadena2, Cont + 1);
        MemIra (Cont, Cont + 1);
        MemPrint ("C:%d F:%d ", MemX, MemY - 1); // -1 por el MemIra anterior
        ////////////////// PRUEBA MEMASCIIDE y MEMCOPYCOL
        MemCol (AZULCLARO, NEGRO);
        MemIra (Cont, Cont + 2);
        MemPrint ("Caracter %c", MemAsciiDe (Cont, Cont, Cont));
        MemCopyCol (Cont, Cont, Cont);
        MemPagina (Cont + 1);
        MemIra (20, 12);
        MemPrint ("Colores pag anterior");
        MemIra (79, 0);
        MemPrint ("%c", Cont + 1);
        MemIra (0, 24);
        MemPrint ("%c", Cont + 1);
        MemIra (0, 0);
        MemPrint ("%c", Cont + 1);
        MemIra (79, 24);
        MemPrint ("%c", Cont + 1);
    }
    MemColDef (AZULCLARO, AZUL);
    ////////////////// PRUEBA DE MEMCOPYPAG
    MemCopyPag (1, 2);
    MemCopyPag (3, 4);
    MemCopyPag (0, 5);
    ////////////////// VISUALIZAR PÁGINAS
    for (Cont = 0; Cont < 7; Cont++) {
        PagActiva (Cont);
        CursorTipo (7, 7);
        CursorIra (PagActual, Cont, Cont); // Igual que la inferior
        getch ();
    }
    free (Font);
    RestauraTabla (ROM8x16);
    return 0;
}
////////////////////////////// EOF [PHARDVID.C] //////////////////////////////
