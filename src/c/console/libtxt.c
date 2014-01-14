//////////////////////////////////////////////////////////////////////////////
//                               L I B T X T                                //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : Esta librería de funciones proporciona funciones       //
//                   para la salida y manipulación de caracteres en         //
//                   modo texto (modo 0x03 -Texto 16 col 80x25-).           //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 7.11.1998                                              //
//  Último Update  : 18.4.1999                                              //
//  Versión        : 2.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * Revisar MemPrint():                                  //
//                       - Reservar memoria dinamicamente para Argu         //
//                   * Contrastar la rutina de memoria y la de bios para    //
//                     borrar una página de video                           //
//                   * BorraPg() tiene un ERROR (ver PRUEBAS\TETRIS.C)      //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "basico.h" // Definiciones basicas

// D E F I N E S /////////////////////////////////////////////////////////////
// Definiciones necesarias para las funciones (privadas)
#define   INTVIDEO    0x10        // Nº de interrupción de video de la BIOS
#define   SEGVIDEO    0xB800      // Segmento mem de video B800/B000(según tarjeta)
#define   FILA        80          // Nº de columnas de una fila 80=(0-79)
#define   PAGINA    2048        // Nº de bytes de una página: (ver Notas)
#define   MAXDIGIT    10          // Nº máximo de dígitos de número en MemPrint
#define   CBYTES    16          // Nº de bytes de la matriz de un caracter
// Definiciones de opciones de función (publicas) -BIOSVID.C-
#define   NOCUR        255         // Bandera de no cursor
#define   ROM8x14    1
#define   ROM8x8    2
#define   ROM8x16    4

// Definiciones de atributos (publicas) -HARDVID.C-
#define   DFT            255
#define   NEGRO          0       // Definiciones de los colores
#define   AZUL            1
#define   VERDE         2
#define   CIAN            3
#define   ROJO           4
#define   MAGENTA          5
#define   MARRON           6
#define   GRISCLARO     7
#define   GRISOSCURO    8       // Estos solo sirven para color del
#define   AZULCLARO     9       // texto, no para el fondo
#define   VERDECLARO    10
#define   CIANCLARO     11
#define   ROJOCLARO     12
#define   MAGENTACLARO  13
#define   AMARILLO      14
#define   BLANCO        15
#define      INTER            8       // Intermitencia (sumarlo en color fondo)
// Definiciones de códigos ASCII (publicas) -DIBUJO.C-
#define   SIMPLE        1       // Tipos de líneas
#define   DOBLE            2
#define   SPC            32      // ' '  Caracteres
#define   LLENO            219     // ''
#define   PTOS_D        178     // ''
#define   PTOS_M        177     // ''
#define   PTOS_C        176     // ''
// M A C R O S ///////////////////////////////////////////////////////////////
#define ColorDef(CT,CF)  ColDefecto=(CF<<4)+CT  // Colores x def del texto
#define Ira(X,Y)         MemX=X; MemY=Y // Fija posición del texto
#define MemPg(PG)         MemPag=PG  // Fija pag de impresión
#define CopiaPg(PF,PD)\
            MemPg(PF);\
            CopiaRegion(0,0,79,24,PD,0,0)   // Copia una pag a otra
#define BorraPg(PAG)\
            MemPg (PAG);\
            Color(DFT,DFT);\
            LLena (SPC,0,0,79,24);\
            Ira(0,0)            // Borra pag indicada (PAG)
// S T R U C T U R A S  /  T Y P E D E F S ///////////////////////////////////
typedef struct // Tipo de un caracter de pantalla
{
    byte Ascii;
    byte Atributo;
} Ts_Caracter;

typedef Ts_Caracter *Tp_Video; // Tipo de un puntero a la mem de video

// G L O B A L E S ///////////////////////////////////////////////////////////
byte PagActual = 0; // Var q guarda la pg de video activa

//Tp_Video Pos0 = (Tp_Video) MkDword (SEGVIDEO, 0); // Punt a 1ª pos de mem de vid
Tp_Video Pos0 = (dword)((SEGVIDEO << 16) + 0);
byte ColDefecto = (NEGRO << 4) + GRISCLARO; // Byte de los colores por defecto
byte ColTexto = (NEGRO << 4) + GRISCLARO; // Colores actuales (inicializados)
byte MemX = 0; // Columna actual (inicializada a 0)
byte MemY = 0; // Fila actual (inicializada a 0)
byte MemPag = 0; // Pag de impresión != pag activa

// P R O T O T I P O S ///////////////////////////////////////////////////////
void PagActiva (byte Pag);
void CursorIra (byte Pag, byte CursorX, byte CursorY);
void TipoCursor (byte LnSup, byte LnInf);
void EstadoCur (byte Pag, byte * LnSup, byte * LnInf, byte * CursorX, byte * CursorY);
byte *CargaTabla (const char *Archivo);
void CambiaTabla (byte * Fuente);
void CambiaCaract (byte * NewFont, byte Pos, byte * Matriz);

//void PonLogo (byte *Font, byte CIni, byte *Matriz[], byte h);//PENDIENTE
void RestauraTabla (byte Juego);
void ScrollAr (byte NLn, byte Xi, byte Yi, byte Xf, byte Yf);
void ScrollAb (byte NLn, byte Xi, byte Yi, byte Xf, byte Yf);

void Color (byte ColorTxt, byte ColorFon);
void MemPrint (const byte * Cad, ...);
void Titulo (const byte * Cad, byte Caracter, byte * Fuente);
byte AsciiDe (byte PosPag, byte PosX, byte PosY);
void CopiaColor (byte PosPag, byte PosX, byte PosY);
void CopiaRegion (byte Xi, byte Yi, byte Xf, byte Yf, byte PagDest, byte PosX, byte PosY);
void CambiaColor (byte ColT, byte ColF, byte Xi, byte Yi, byte Xf, byte Yf);

void LLena (byte Caracter, byte Xi, byte Yi, byte Xf, byte Yf);
void Cuadro (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf);
void Linea (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf);
void LnAjustada (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf);

// F U N C I O N E S /////////////////////////////////////////////////////////
void PagActiva (byte Pag) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x05;
     InRegs.h.al = Pag;
     int86 (INTVIDEO, &InRegs, &InRegs);
     PagActual = Pag;
     */
}

//////////////////////////////////////////////////////////////////////////////
void CursorIra (byte Pag, byte CursorX, byte CursorY) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x02;
     InRegs.h.bh = Pag;
     InRegs.h.dh = CursorY;
     InRegs.h.dl = CursorX;
     int86 (INTVIDEO, &InRegs, &InRegs);
     */
}

//////////////////////////////////////////////////////////////////////////////
void TipoCursor (byte LnSup, byte LnInf) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x01;
     if ((LnSup <= 7) && (LnInf <= 7))   // Si LnInf o LnSup = NOCUR
     {                           // (255) no entra aqui
     InRegs.h.ch = LnSup;
     InRegs.h.cl = LnInf;
     }
     else                        // LnInf o LnSup = NOCUR o son mayores del valor permitido
     {
     InRegs.x.cx = 0x2000;
     }
     int86 (INTVIDEO, &InRegs, &InRegs);
     */
}

//////////////////////////////////////////////////////////////////////////////
void EstadoCur (byte Pag, byte * LnSup, byte * LnInf, byte * CursorX, byte * CursorY) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x03;
     InRegs.h.bh = Pag;
     int86 (INTVIDEO, &InRegs, &InRegs);
     if (InRegs.x.cx == 0x2000)  // Cursor desactivado
     {
     *LnSup = NOCUR;
     *LnInf = NOCUR;
     }
     else {
     *LnSup = InRegs.h.ch;
     *LnInf = InRegs.h.cl;
     }
     *CursorY = InRegs.h.dh;
     *CursorX = InRegs.h.dl;
     */
}

//////////////////////////////////////////////////////////////////////////////
byte *CargaTabla (const char *Archivo) {
    byte *NewFont = NULL;
    FILE *Fuente = NULL; // Archivo que contiene la fuente

    if ((NewFont = (byte *)malloc (CBYTES * 256)) == NULL) // Buffer xa almacenar
    exit (1); // archivo.fnt: Newfont
    if ((Fuente = fopen (Archivo, "rb")) == NULL) // Abre archivo.fnt
    exit (2); // (Fuente)
    fread (NewFont, CBYTES, 256, Fuente); // Copia archivo.fnt
    fclose (Fuente); // a buffer (Newfont)
    return (NewFont);
}

//////////////////////////////////////////////////////////////////////////////
void CambiaTabla (byte * NewFont) {
    /* Depende de MS-DOS (dos.h)
     struct REGPACK InReg;       // Registros pasados a intr()

     InReg.r_ax = MK_WORD (0x11, 0x10);  //   ah=0x11   al=0x10
     InReg.r_bx = MK_WORD (16, 0);   //   bh=16     bl=0
     InReg.r_cx = 0x00FF;
     InReg.r_dx = 0x0000;
     InReg.r_es = FP_SEG (NewFont);  // Pasa la dirección del buffer
     InReg.r_bp = FP_OFF (NewFont);  // con el contenido de archivo.fnt
     intr (INTVIDEO, &InReg);
     */
}

//////////////////////////////////////////////////////////////////////////////
void CambiaCaract (byte * NewFont, byte Pos, byte * Matriz) {
    byte Cont = 0;
    byte *Aux = NewFont + (Pos * CBYTES);

    for (Cont = 0; Cont < CBYTES; Cont++, Aux++, Matriz++)
        *Aux = *Matriz;
}

//////////////////////////////////////////////////////////////////////////////
void PonLogo (byte * Font, byte CIni, byte * Matriz[], byte h) { // PENDIENTE
    byte *Aux = NULL; // Punt aux xa recorrer las matrices de chars
    byte Ancho = 0; // Anchura en caracteres de la matriz (logo)
    byte Alto = 0; // Altura en caracteres de la matriz (logo)
    byte Cont1 = 0, Cont2 = 0; // Contadores
    byte Cont3 = 0, Cont4 = 0;

    /*
     PROCESO:
     * Para cada caracter del logo (cada 8 cols) de (Matriz[])
     1.- Salvar la matriz del caracter anterior (se hace ln a ln)
     2.- Modificar la matriz del caracter para que se ajuste al logo
     3.- Imprimir caracter en la posición apropiada
     */

    Ancho = (strlen (Matriz[h]) + 7) / 8; // Calcula anchura en caracteres del logo
    Alto = (h + 15) / 16; // Calcula altura en caracteres del logo
    Aux = Font + (CIni * 16); // Inicializa Aux a 1ª pos a modificar

    // Convierto el array de caracteres en "array de bits" por caracteres
    for (Cont1 = 0; Cont1 < Alto; Cont1++) { // Recorro todas las filas del logo
        for (Cont2 = 0; Cont2 < Ancho; Cont2++) { // Recorro todas las columnas del logo
            for (Cont3 = 0; Cont3 < 16; Cont3++, h++, Aux++) { // Recorro las filas del caracter del logo
                for (Cont4 = 0; Cont4 < 8; Cont4++, Matriz[h]++, *Aux >>= 1) { // Por cada 8 caracteres defino una ln de caracter
                    if (*Matriz[h] == '*') // Si caracter == '*' poner un 1
                        *Aux += 128; // al final
                    else
                        // Si no pone un cero
                        *Aux &= 127;
                }
            } // Define un caracter
            h = Cont1 * 8; // Vuelve a la fila inicial
            MemPrint ("%c", CIni);
            CIni++;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void RestauraTabla (byte Juego) {
    /* Depende de MS-DOS (dos.h)
     struct REGPACK InReg;       // Registros pasados a intr()

     InReg.r_ax = MK_WORD (0x11, Juego); //   ah=0x11   al= Id del juego
     InReg.r_bx = 0;             //   bh=0x00   bl=0x00
     intr (INTVIDEO, &InReg);
     */
}

//////////////////////////////////////////////////////////////////////////////
void ScrollAr (byte NLn, byte Xi, byte Yi, byte Xf, byte Yf) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x06;
     InRegs.h.al = NLn;
     InRegs.h.bh = ColDefecto;   // Variable en hardvid.c
     InRegs.h.ch = Yi;           // Variable en hardvid.c
     InRegs.h.cl = Xi;           // Variable en hardvid.c
     InRegs.h.dh = Yf;
     InRegs.h.dl = Xf;
     int86 (INTVIDEO, &InRegs, &InRegs);
     */
}

//////////////////////////////////////////////////////////////////////////////
void ScrollAb (byte NLn, byte Xi, byte Yi, byte Xf, byte Yf) {
    /* Depende de MS-DOS (dos.h)
     union REGS InRegs;          // Registros pasados a las funciones BIOS

     InRegs.h.ah = 0x07;
     InRegs.h.al = NLn;
     InRegs.h.bh = ColDefecto;
     InRegs.h.ch = Yi;
     InRegs.h.cl = Xi;
     InRegs.h.dh = Yf;
     InRegs.h.dl = Xf;
     int86 (INTVIDEO, &InRegs, &InRegs);
     */
}

//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * Es totalmente transportable al usar las funciones    //
//                     de la BIOS.                                          //
//                   * No se controla la validez de los parametros pasados  //
//                     a las funciones !!! OJO !!!                          //
//                   * En la función CargaTabla() es responsabilidad        //
//                     del programador liberar el puntero devuelto cuando   //
//                     no sea necesario.                                    //
//                   * Controlar el error de que no exista el archivo en    //
//                     CargaTabla()                                         //
////////////////////////////// EOF [BIOSTXT.C] ///////////////////////////////
// F U N C I O N E S /////////////////////////////////////////////////////////
void Color (byte ColorTxt, byte ColorFon) {
    // Fija el color del fondo
    if (ColorFon == DFT
    )
        ColTexto = ColDefecto; // Col Fondo = Valor Defecto
    else
        ColTexto = (ColorFon << 4); // Col Fondo = Parametro
    // Fija el color del texto
    ColTexto &= 240; // Pone a 0 los bits de CT
    if (ColorTxt == DFT
    )
        ColTexto += ColDefecto & 15; // Col Texto = Valor Defecto
    else
        ColTexto += ColorTxt & 15; // Col Texto = Parametro
}

void MemPrint (const byte * Cad, ...)
{
    va_list VarArgs;
    Tp_Video PPos = NULL;
    byte Argu[MAXDIGIT], *PArgu = NULL;

    va_start (VarArgs, Cad);
    PPos = (Tp_Video) (Pos0 + (MemPag * PAGINA) + (MemY * FILA) + MemX);
    for (; *Cad; Cad++) {
        if (*Cad == '%') // ¿Imprimir variable?
    {
        Cad++;
        switch (*Cad) {
            case 'd':
            PArgu = itoa (va_arg (VarArgs, int), Argu, 10);

            for (; *PArgu; PPos++, PArgu++) {
                PPos->Ascii = *PArgu;
                PPos->Atributo = ColTexto;
            } // PPos es incrementado al salir del bucle
            break;
            case 'c':
            PPos->Ascii = va_arg (VarArgs, byte);
            PPos->Atributo = ColTexto;
            PPos++;// Incrementa la posición al escribir
            break;
            case 's':
            PArgu = va_arg (VarArgs, byte *);
            for (; *PArgu; PPos++, PArgu++) {
                PPos->Ascii = *PArgu;
                PPos->Atributo = ColTexto;
            } // PPos es incrementado al salir del bucle
            break;
        }
    }
    else // Impresión de la cadena normal
    {
        PPos->Ascii = *Cad;
        PPos->Atributo = ColTexto;
        PPos++; // Incrementa la posición al escribir
    }
}
va_end (VarArgs);
}

void Titulo (const byte * Cad, byte Caracter, byte * Fuente) {
    byte *Aux = NULL;
    byte Mascara = 128, Cont1 = 0, Cont2 = 0;
    byte Xi = MemX, Yi = MemY;

    while (*Cad) { // Mientras halla letras
        Aux = Fuente + ((*Cad) * 16); // Pone Aux sobre el caracter preciso
        for (Cont1 = 0; Cont1 < 16; Cont1++, Aux++) { // Imprime el caracter línea a línea
            for (Cont2 = 0; Cont2 < 8; Cont2++, Mascara >>= 1) // while (Mascara)?
                { // Pone cada "punto" del caracter
                if (*Aux & Mascara) MemPrint ("%c", Caracter);
                MemX++;
            }
            // Se inicializan las variables necesarias
            Mascara = 128; // La mascara va desde el último bit al 1º
            MemX = Xi;
            MemY++;
        }
        MemY = Yi;
        Xi += 9; // Incrementa el espacio para el sgte caracter
        MemX = Xi;
        Cad++;
    }
}

//////////////////////////////////////////////////////////////////////////////
byte AsciiDe (byte PosPag, byte PosX, byte PosY) {
    Tp_Video PPos = NULL;

    PPos = (Tp_Video)(Pos0 + (PosPag * PAGINA) + (PosY * FILA) + PosX);
    return (PPos->Ascii);
}

//////////////////////////////////////////////////////////////////////////////
void CopiaColor (byte PosPag, byte PosX, byte PosY) {
    Tp_Video PPos = NULL;

    PPos = (Tp_Video)(Pos0 + (PosPag * PAGINA) + (PosY * FILA) + PosX);
    ColTexto = PPos->Atributo;
}

//////////////////////////////////////////////////////////////////////////////
void CopiaRegion (byte Xi, byte Yi, byte Xf, byte Yf, byte PagDest, byte PosX, byte PosY) {
    Tp_Video PosOrigen = NULL, PosFinal = NULL;

    for (; Yi <= Yf; Yi++, PosY++) // Copia la region línea a línea
        {
        PosOrigen = (Tp_Video)(Pos0 + (MemPag * PAGINA) + (Yi * FILA) + Xi);
        PosFinal = (Tp_Video)(Pos0 + (PagDest * PAGINA) + (PosY * FILA) + PosX);
        _fmemcpy (PosFinal, PosOrigen, (Xf - Xi + 1) * 2); // Copiar punteros far
    }
}

//////////////////////////////////////////////////////////////////////////////
void CambiaColor (byte ColT, byte ColF, byte Xi, byte Yi, byte Xf, byte Yf) {
    Tp_Video PPos = NULL;

    Ira(Xi, Yi);
    for (; MemY <= Yf; MemY++) {
        PPos = (Tp_Video)(Pos0 + (MemPag * PAGINA) + (MemY * FILA) + Xi);
        for (; MemX <= Xf; MemX++, PPos++) // Imprime una línea horizontal
            {
            PPos->Atributo = (ColF << 4) + ColT;
        }
        MemX = Xi; // Asignar a MemX col inicial xa volver a inicio fila
    }
}

//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * No se puede crear un typedef con un array            //
//                   * El orden de los campos de la estructura t_caracter es//
//                     importante debido a la posición que ocupan en memoria//
//                   * No se controla la validez de los parametros pasados  //
//                     a las funciones !!! OJO !!!                          //
//                   * La longitud de página varía dependiendo de si el     //
//                     juego de caracteres es cambiado:                     //
//                          - Si es cambiado: 80*25*2+256=4096/2 (2128)     //
//                          - Si no:          80*25*2+96=4096/2  (2048)     //
//                   * Un caracter (matriz) tiene 16 bytes (1 x pto de h)   //
////////////////////////////// EOF [HARDVID.C] ///////////////////////////////
// F U N C I O N E S //////////////////////////////////////////////////////////
void LLena (byte Caracter, byte Xi, byte Yi, byte Xf, byte Yf) {
    Ira(Xi, Yi);
    for (; MemY <= Yf; MemY++) {
        for (; MemX <= Xf; MemX++) // Imprime una línea horizontal
            {
            Ira(MemX, MemY);
            MemPrint ("%c", Caracter);
        }
        MemX = Xi; // Va al inicio de la sgte linea a escribir
    }
}

//////////////////////////////////////////////////////////////////////////////
void Cuadro (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf) {
    byte ESupIzq = 0, ESupDer = 0, EInfDer = 0, EInfIzq = 0;
    byte RHoriz = 0, RVert = 0;

    Ira(Xi, Yi);
    // Selecciona los caracteres de las líneas (simples o dobles)
    if (Estilo == SIMPLE) {
        ESupIzq = 218; // ''
        ESupDer = 191; // ''
        EInfDer = 217; // ''
        EInfIzq = 192; // ''
        RHoriz = 196; // ''
        RVert = 179; // ''
    }
    else // Estilo == DOBLE
    {
        ESupIzq = 201; // ''
        ESupDer = 187; // ''
        EInfDer = 188; // ''
        EInfIzq = 200; // ''
        RHoriz = 205; // ''
        RVert = 186; // ''
    }
    // Imprime las 4 esquinas
    Ira(Xi, Yi);
    // Esquina superior izquierda
    MemPrint ("%c", ESupIzq);
    Ira(Xf, Yi);
    // Esquina superior derecha
    MemPrint ("%c", ESupDer);
    Ira(Xf, Yf);
    // Esquina inferior derecha
    MemPrint ("%c", EInfDer);
    Ira(Xi, Yf);
    // Esquina inferior izquierda
    MemPrint ("%c", EInfIzq);
    for (MemX = Xi + 1; MemX < Xf; MemX++) // Imprime las líneas horizontales (las dos)
        {
        Ira(MemX, Yi);
        // Imprime línea superior
        MemPrint ("%c", RHoriz);
        Ira(MemX, Yf);
        // Imprime línea inferior
        MemPrint ("%c", RHoriz);
    }
    for (MemY = Yi + 1; MemY < Yf; MemY++) // Imprime las líneas verticales (las dos)
        {
        Ira(Xi, MemY);
        // Imprime línea izquierda
        MemPrint ("%c", RVert);
        Ira(Xf, MemY);
        // Imprime línea derecha
        MemPrint ("%c", RVert);
    }
}

//////////////////////////////////////////////////////////////////////////////
void Linea (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf) {
    Ira(Xi, Yi);
    switch (Estilo) {
        case DOBLE:
            if (MemY == Yf) // Selecciona la dirección
                {
                while (MemX <= Xf) {
                    MemPrint ("_");
                    MemX++; // Incrementa la posición
                }
            }
            else {
                while (MemY <= Yf) {
                    MemPrint ("_");
                    MemY++; // Incrementa la posición
                }
            }
            break;
        case SIMPLE:
            if (MemY == Yf) // Selecciona la dirección
                {
                while (MemX <= Xf) {
                    MemPrint ("_");
                    MemX++; // Incrementa la posición
                }
            }
            else {
                while (MemY <= Yf) {
                    MemPrint ("_");
                    MemY++; // Incrementa la posición
                }
            }
            break;
    }
}

//////////////////////////////////////////////////////////////////////////////
void LnAjustada (bool Estilo, byte Xi, byte Yi, byte Xf, byte Yf) {
    Ira(Xi, Yi);
    switch (Estilo) {
        case DOBLE: // Estilo Doble
            if (MemY == Yf) // Dirección Horizontal
                {
                switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                    case (byte)'_':
                        MemPrint ("_");
                        break;
                    case (byte)'A':
                        MemPrint ("_");
                        break;
                } // Fin switch (primer caracter)
                for (MemX++; MemX <= Xf - 1; MemX++) {
                    switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                        case (byte)'B':
                            MemPrint ("_");
                            break;
                        case (byte)'C':
                            MemPrint ("_");
                            break;
                        default:
                            MemPrint ("_");
                            break;
                    }
                } // Fin for (imprime la línea menos extremos)
                switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                    case (byte)'D':
                        MemPrint ("_");
                        break;
                    case (byte)'E':
                        MemPrint ("_");
                        break;
                } // Fin switch (ultimo caracter)
            }
            else // Dirección Vertical
            {
                switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                    case (byte)'F':
                        MemPrint ("_");
                        break;
                    case (byte)'G':
                        MemPrint ("_");
                        break;
                } // Fin switch (primer caracter)
                for (MemY++; MemY <= Yf - 1; MemY++) {
                    switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                        case (byte)'H':
                            MemPrint ("_");
                            break;
                        case (byte)'I':
                            MemPrint ("_");
                            break;
                        default:
                            MemPrint ("_");
                            break;
                    }
                } // Fin for (imprime la línea menos extremos)
                switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                    case (byte)'J':
                        MemPrint ("_");
                        break;
                    case (byte)'K':
                        MemPrint ("_");
                        break;
                } // Fin switch (ultimo caracter)
            }
            break;
        case SIMPLE: // Estilo Simple
            if (MemY == Yf) // Dirección Horizontal
                {
                switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                    case (byte)'L':
                        MemPrint ("_");
                        break;
                    case (byte)'M':
                        MemPrint ("_");
                        break;
                } // Fin switch (primer caracter)
                for (MemX++; MemX <= Xf - 1; MemX++) {
                    switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                        case (byte)'N':
                            MemPrint ("_");
                            break;
                        case (byte)'O':
                            MemPrint ("_");
                            break;
                        default:
                            MemPrint ("_");
                            break;
                    }
                } // Fin for (imprime la línea menos extremos)
                switch (AsciiDe (PagActual, MemX, Yf + 1)) {
                    case (byte)'P':
                        MemPrint ("_");
                        break;
                    case (byte)'Q':
                        MemPrint ("_");
                        break;
                } // Fin switch (ultimo caracter)
            }
            else // Dirección Vertical
            {
                switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                    case (byte)'R':
                        MemPrint ("_");
                        break;
                    case (byte)'S':
                        MemPrint ("_");
                        break;
                } // Fin switch (primer caracter)
                for (MemY++; MemY <= Yf - 1; MemY++) {
                    switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                        case (byte)'T':
                            MemPrint ("_");
                            break;
                        case (byte)'U':
                            MemPrint ("_");
                            break;
                        default:
                            MemPrint ("_");
                            break;
                    }
                } // Fin for (imprime la línea menos extremos)
                switch (AsciiDe (PagActual, Xf + 1, MemY)) {
                    case (byte)'V':
                        MemPrint ("_");
                        break;
                    case (byte)'W':
                        MemPrint ("_");
                        break;
                } // Fin switch (ultimo caracter)
            }
            break;
    }
}
/////////////////////////////// EOF DIBUJO.C ///////////////////////////////
