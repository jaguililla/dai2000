//////////////////////////////////////////////////////////////////////////////
//                             P A L T E X T O                              //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : Esta librería de funciones permite manipular la        //
//                   paleta de colores de las tarjetas VGA                  //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 1.3.1999                                               //
//  Último Update  : 10.5.1999                                              //
//  Versión        : -BETA-                                                 //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * Cambiar el array Colors[] por una lista enlazada     //
//                     para ahorrar memoria en PalFade*()                   //
//                   * En PalSave() controlar si el nombre de la paleta     //
//                     existe para no sobreescribirlo                       //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
//#include <stdio.h>
//

#include <stdio.h>
#include <stddef.h>
#include "basico.h"             // Definiciones basicas

// D E F I N E S /////////////////////////////////////////////////////////////
#define INTPAL 0x10

// S T R U C T U R A S  /  T Y P E D E F S ///////////////////////////////////
typedef struct {
    byte Red;                   // Colores Basicos. Rango (0-63)
    byte Green;
    byte Blue;
} Ts_Color;                     // Tipo que define un color en la paleta

// P R O T O T I P O S ///////////////////////////////////////////////////////
void PalCambiaCol (int Pos, int CRed, int CGreen, int CBlue);

// Esta función cambia el color de la posición correspondiente en la tabla
// (Pos) por los valores especificados por (CRed, CGreen, CBlue)
// Produce warnigs porque devuelven un valor

Ts_Color PalCogeCol (byte Pos);

// Esta función almacena el valor de una posición de la paleta (Pos)
// en una variable de tipo estructura (Ts_Color)

Ts_Color *PalLoad (const char *Archivo);

// Carga la paleta que está en el fichero especificado y devuelve un puntero
// a ella (buffer en memoria donde está)

void PalSave (const char *Archivo);

// Almacena la paleta actual en un archivo (Archivo)

void CambiaPal (Ts_Color * Palet);

// Cambia la paleta actual por otra a la que apunta (*Palet)

void PalFadeIn (word Pasos, byte Colors[]);

// Hace un fundido desde negro de los colores indicados (Colors[]) en los
// pasos indicados (Pasos), los pasos determinan el tiempo del fundido

// F U N C I O N E S /////////////////////////////////////////////////////////
void PalCambiaCol (int Pos, int CRed, int CGreen, int CBlue)
{
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.h.ah = 0x10;
    InRegs.h.al = 0x10;
    InRegs.x.bx = Pos;
    InRegs.h.ch = CRed;
    InRegs.h.cl = CGreen;
    InRegs.h.dh = CBlue;
    int86 (INTPAL, &InRegs, &InRegs);
    */
}

//////////////////////////////////////////////////////////////////////////////
Ts_Color PalCogeCol (byte Pos)
{
    //union REGS InRegs;
    Ts_Color Color;

    /* Depende de MS-DOS (dos.h)
    InRegs.h.ah = 0x10;
    InRegs.h.al = 0x15;
    InRegs.x.bx = Pos;
    int86 (INTPAL, &InRegs, &InRegs);
    Color.Red = InRegs.h.ch;
    Color.Green = InRegs.h.cl;
    Color.Blue = InRegs.h.dh;
    */
    return (Color);
}

//////////////////////////////////////////////////////////////////////////////
Ts_Color *PalLoad (const char *Archivo)
{
    Ts_Color *Pal = NULL;
    FILE *Archiv = NULL;

    if ((Pal = (Ts_Color *) malloc (sizeof (Ts_Color) * 256)) == NULL)
        exit (1);
    if ((Archiv = fopen (Archivo, "rb")) == NULL)
        exit (2);
    fread (Pal, sizeof (Ts_Color), 256, Archiv);
    fclose (Archiv);
    return (Pal);
}

//////////////////////////////////////////////////////////////////////////////
void PalSave (const char *Archivo)
{
    FILE *Archiv = NULL;
    Ts_Color *Color = NULL;
    word Cont = 0;

    if ((Archiv = fopen (Archivo, "wb")) == NULL)
        exit (3);
    for (Cont = 0; Cont < 256; Cont++) {
        *Color = PalCogeCol (Cont);
        fwrite (Color, sizeof (Ts_Color), 1, Archiv);
    }
    fclose (Archiv);
}

//////////////////////////////////////////////////////////////////////////////
void CambiaPal (Ts_Color * Palet)
{
    int Cont = 0;

    for (Cont = 0; Cont < 256; Cont++, Palet++)
        PalCambiaCol (Cont, Palet->Red, Palet->Green, Palet->Blue);
}
//////////////////////////////////////////////////////////////////////////////
