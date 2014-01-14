//////////////////////////////////////////////////////////////////////////////
//                               J C H A R S                                //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : Esta librería de funciones proporciona funciones       //
//                   para la modificación de los juegos de caracteres       //
//                   de la tarjeta VGA en el modo texto 80x25.              //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 11.5.1999                                              //
//  Último Update  : 18.4.1999                                              //
//  Versión        : 0.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * Información en el archivo MIKADO.C de PC INTERNO     //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdio.h>

#include "basico.h"             // Definiciones básicas
// D E F I N E S /////////////////////////////////////////////////////////////
#define  SEQUENCER  0x3C4       // Dirección del puerto VGA Sequencer Controler
#define  GRAPHICS   0x3CE       // Dirección del puerto VGA Graphics Controler
#define  DIRJUEGOS  0xA000      // Dirección Bit-Plane #2 (juegos de caracteres)
#define  CBYTES        32          // Nº de bytes de un caracter en memoria (matriz)
// P R O T O T I P O S ///////////////////////////////////////////////////////
void ActivaJuego (void); // Permite acceso a juegos de caracteres en mem
void DesactJuego (void); // Restaura estructura de mem de video
void CargaJuego (const char *nomfich, byte NJuego);
void SelectJuegos (byte Juego1, byte Juego2);
void CambiaChar (byte NJuego, byte NChar, byte ** Matriz);

// F U N C I O N E S /////////////////////////////////////////////////////////
void ActivaJuego (void) {
    static unsigned SeqCont[4] = {0x0100, 0x0402, 0x0704, 0x0300};
    static unsigned GraCont[3] = {0x0204, 0x0005, 0x0006};
    byte Cont = 0;

    disable ();
    for (Cont = 0; Cont < 4; ++Cont)
        outport (SEQUENCER, SeqCont[Cont]);
    for (Cont = 0; Cont < 3; ++Cont)
        outport (GRAPHICS, GraCont[Cont]);
    enable ();
}

void DesactJuego (void) {
    static unsigned SeqCont[4] = {0x0100, 0x0302, 0x0304, 0x0300};
    static unsigned GraCont[3] = {0x0004, 0x1005, 0x0E06};
    byte Cont = 0;

    disable ();
    for (Cont = 0; Cont < 4; ++Cont)
        outport (SEQUENCER, SeqCont[Cont]);
    for (Cont = 0; Cont < 3; ++Cont)
        outport (GRAPHICS, GraCont[Cont]);
    enable ();
}

void CargaJuego (const char *NomFich, byte NJuego) {
    FILE *Fuente = NULL; // Archivo que contiene la fuente
    byte *NewFont = NULL;
    byte *PtrJuego = NULL;
    int Cont = 0, Cont1 = 0;

    ActivaJuego ();
    if ((NewFont = (byte *)malloc (CBYTES * 256)) == NULL ) // Buffer xa almacenar
    exit (1); // archivo.fnt: Newfont
    if ((Fuente = fopen (NomFich, "rb")) == NULL ) // Abre archivo.fnt
    exit (2); // (Fuente)
    for (Cont = 0; Cont < 256; Cont++) {
        fread (NewFont, (CBYTES / 2), 1, Fuente); // Copia archivo.fnt
        for (Cont1 = 0; Cont1 < (CBYTES / 2); Cont1++, NewFont++)
            *NewFont = 0;
    }
    fclose (Fuente); // a buffer (Newfont)
    PtrJuego = MK_FP (DIRJUEGOS, (NJuego * (CBYTES * 256)));
    _fmemcpy (PtrJuego, NewFont, CBYTES * 256);
    free (NewFont);
    DesactJuego ();
}

void SelectJuegos (byte Juego1, byte Juego2) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;

     InRegs.x.ax = 0x1103;       // Valor de ax (ah=0x11 y al=0x03)
     InRegs.h.bl = (Juego1 & 3) + ((Juego1 & 4) << 2) +
     ((Juego2 & 3) << 2) + ((Juego2 & 4) << 3);
     int86 (0x10, &InRegs, &InRegs);
     */
}

// M A I N ///////////////////////////////////////////////////////////////////
void main (void) {
    int Cont = 0;

    for (Cont = 0; Cont < 256; Cont++)
        cprintf ("%c", Cont);
    for (Cont = 0; Cont < 256; Cont++)
        cprintf ("%c", Cont);
    CargaJuego ("\\cpv\\font\\upercase.fnt", 0);
    CargaJuego ("\\cpv\\font\\bold.fnt", 0);
    SelectJuegos (0, 1);
}
//////////////////////////////////////////////////////////////////////////////
