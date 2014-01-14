//////////////////////////////////////////////////////////////////////////////
//                             H A R D K E Y B                              //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : Esta librería de funciones controla el teclado         //
//                   mediante el acceso directo al hardware de este,        //
//                   permite instalar un controlador propio                 //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 15.2.1999                                              //
//  Último Update  : 15.2.1999                                              //
//  Versión        : -BETA-                                                 //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>

#include "basico.h"

// D E F I N E S /////////////////////////////////////////////////////////////
// Definiciones necesarias para las funciones (privadas)
#define INTTECL 0x16 // Nº de interrupción de teclado (BIOS)
#define INTRATON 0x33 // Nº de interrupción del ratón (BIOS)
#define ZF 64 // Bandera de cero en registro flags

// Definiciones de opciones de función (publicas)
#define RSHIFT 1
#define LSHIFT 2
#define CTRL 4
#define ALT 8

#define VISIBLE 1 // Bandera de cursor visible
#define OCULTO 2 // Bandera de cursor oculto

#define MUEVERATON 1
#define P_BOTONIZQ 2
#define S_BOTONIZQ 4
#define P_BOTONDER 8
#define S_BOTONDER 16

// G L O B A L E S ///////////////////////////////////////////////////////////
void (*Irq9) () = NULL;
byte BotonIzq = NO;
byte BotonDer = NO;
byte RatonX = 0;
byte RatonY = 0;

// P R O T O T I P O S ///////////////////////////////////////////////////////
word LeeTecla (void);

// Espera a que el usuario pulse una tecla (si no hay ninguna en el buffer
// de) teclado y devuelve su código ASCII en el byte bajo y el código SCAN
// en el byte alto de la word devuelta
word HayTecla (void);

// Comprueba si se ha pulsado alguna tecla (devuelve 1 -SI- si se ha pulsado)
// para leer esta tecla se usa LeeTecla: if (HayTecla()) Var=LeeTecla();
word EstadoTecl (void);

// Devuelve la palabra de estado del teclado. Se sabe si se ha pulsado alguna
// tecla especial haciendo un AND (&) con la cte correspondiente
void CambiaInt (void);          // PENDIENTE

// Cambia la rutina que gestiona la interrupción del teclado
word ResetRaton (void);

// Devuelve el número de botones del ratón si está presente, si no devuelve 0

// F U N C I O N E S /////////////////////////////////////////////////////////
word LeeTecla (void) {
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.h.ah = 0x10;
    int86 (INTTECL, &InRegs, &InRegs);
    return (InRegs.x.ax);
    */
    return 0;
}

word HayTecla (void) {
    /* Depende de MS-DOS (dos.h)
    struct REGPACK InRegs;

    InRegs.r_ax = MK_WORD (0x11, 0x0);
    intr (INTTECL, &InRegs);
    return (!(InRegs.r_flags & ZF));    // Si se ha pulsado tecla ZF=0
    */
    return 0;
}

word EstadoTecl (void) {
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.h.ah = 0x12;
    int86 (INTTECL, &InRegs, &InRegs);
    return (InRegs.x.ax);
    */
    return 0;
}

void CambiaInt (void) { }

word ResetRaton (void)
{
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.x.ax = 0x00;
    int86 (INTRATON, &InRegs, &InRegs);

    if (InRegs.x.ax)
        return (InRegs.x.bx);
    else
        return (InRegs.x.ax);
    */
    return 0;
}

void RatonCursor (byte Estado) {
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.x.ax = Estado;
    int86 (INTRATON, &InRegs, &InRegs);
    */
}

void LimitaRaton (byte Xi, byte Yi, byte Xf, byte Yf) {
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    InRegs.x.ax = 0x07;
    InRegs.x.cx = Xi;
    InRegs.x.dx = Xf;
    int86 (INTRATON, &InRegs, &InRegs);
    InRegs.x.ax = 0x08;
    InRegs.x.cx = Yi;
    InRegs.x.dx = Yf;
    int86 (INTRATON, &InRegs, &InRegs);
    */
}

void IntRaton (void (*Funcion) (void), byte Eventos) {
    /* Depende de MS-DOS (dos.h)
    union REGS InRegs;

    struct SREGS SegRegs;

    InRegs.x.ax = 0x0C;
    SegRegs.es = FP_SEG (Funcion);
    InRegs.x.dx = FP_OFF (Funcion);
    InRegs.x.cx = Eventos;
    int86x (INTRATON, &InRegs, &InRegs, &SegRegs);
    */
}

//#pragma option -a- -N-
void PruebaInt (void) {
//    word Eventos = 0, PosX = 0, PosY = 0, Botones = 0;

    /* Depende del compilador (Turbo C)
    asm mov ax, seg (Eventos)   // Cargo el segmento de datos del controlador
    asm mov ds, ax asm mov Eventos, ax  // Cargo los eventos de llamada
     asm mov Botones, bx        // Cargo el estado de los botones
     asm mov PosX, cx           // Cargo la posición horizontal del cursor
     asm mov PosY, dx           // Cargo la posición vertical del cursor
    if (Botones & 1) {
        gotoxy (PosX, PosY);
        printf ("%d %d", PosX, PosY);
    }
    */
}
//#pragma option -a -N
//////////////////////////////////////////////////////////////////////////////
