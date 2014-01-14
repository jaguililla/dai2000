// I N C L U D E S ///////////////////////////////////////////////////////////
#include "basico.h"
#include "libtxt.c"

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    byte Cont = 0, *Font = NULL;

    clrscr ();
    Font = CargaTabla ("\\cpv\\font\\archon.fnt");
    CambiaTabla (Font);
    ColorDef (MAGENTACLARO, MAGENTA);
    Color (DFT, DFT);
    Cuadro (SIMPLE, 0, 0, 79, 24);
    Color (AZULCLARO, AZUL);
    Cuadro (DOBLE, 1, 1, 78, 23);
    MemPg (1);
    Cuadro (SIMPLE, 2, 2, 77, 22);
    LLena (PTOS_D, 3, 3, 76, 21);
    MemPg (2);
    Color (DFT, DFT);
    LLena (PTOS_D, 0, 0, 39, 12);
    ColorDef (GRISCLARO, NEGRO);
    CopiaPg (1, 4);
    CopiaPg (2, 5);
    ///////////// PRUEBA MEMCOPYREG
    MemPg (2);
    CopiaRegion (1, 1, 4, 2, 3, 1, 1);
    MemPg (6);
    LLena (PTOS_D, 3, 3, 5, 3);
    ///////////// PRUEBA MEMCCOL
    Ira (3, 4);
    MemPrint ("123");
    CambiaColor (AZULCLARO, AZUL, 3, 4, 10, 10);
    ///////////// PRUEBA DIBLINEAH
    Linea (DOBLE, 0, 10, 79, 10);
    Linea (DOBLE, 0, 10, 0, 24);
    Linea (DOBLE, 1, 11, 16, 11);
    for (Cont = 10; Cont < 20; Cont++) {
        Linea (DOBLE, Cont, Cont, 79, Cont);
        Linea (DOBLE, Cont, Cont, Cont, 24);
    }
/*    ///////////// VENTANA
    MemPg(6);
    Color(GRISOSCURO,GRISCLARO);
    Ira(12,11);
    LLena(SPC,32,21);
    Color(BLANCO,AZUL);
    Ira(10,10);
    LLena(SPC,30,20);
    Ira(11,10);
    Cuadro(SIMPLE,29,20);
    /////////////*/
    for (Cont = 0; Cont < 7; Cont++) {
        PagActiva (Cont);
        TipoCursor (7, 7);
        CursorIra (PagActual, 39, 12);
        getch ();
    }
    BorraPg (0);
    BorraPg (2);
    BorraPg (4);
    BorraPg (6);
    for (Cont = 0; Cont < 7; Cont++) {
        PagActiva (Cont);
        TipoCursor (NOCUR, NOCUR);
        getch ();
    }
    free (Font);
    RestauraTabla (ROM8x16);
}

/////////////////////////////// EOF [DIBUJO.C] ///////////////////////////////
