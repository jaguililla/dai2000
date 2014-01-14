// T E T R I S ///////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include "libtxt.c"
#include "hardkeyb.c"

// D E F I N E S /////////////////////////////////////////////////////////////
#define   NPIEZAS  7            // Nº de piezas distintas
#define   HPIEZA   2            // Altura en caracteres de la pieza
#define   MAXDIM   4            // Maximo Nº de bloques de una pieza
#define   BLOQUE   '**'         // Cada bloque de la pieza son estos caracts
#define   XTABLERO 10           // Anchura del tablero en bloques
#define   YTABLERO 20           // Altura del tablero en bloques

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct {
    byte *Matriz[HPIEZA];       // Matriz de los bloques de la pieza
    byte Color;                 // Color de una pieza
} T_Pieza;                      // Tipo de una pieza

// GLOBALES
T_Pieza piezas[NPIEZAS] = {
    {                           // Pieza 0
     "****",                    // ********
     "",
     ROJO,
     },
    {                           // Pieza 1
     "*** ",                    // ******
     " *",                      //   **
     VERDE,
     },
    {                           // Pieza 2
     "**",                      // ****
     " **",                     //   ****
     AMARILLO,
     },
    {                           // Pieza 3
     " **",                     //   ****
     "**",                      // ****
     AZUL,
     },
    {                           // Pieza 4
     "**",                      // ****
     "**",                      // ****
     CIAN,
     },
    {                           // Pieza 5
     "***",                     // ******
     "*",                       // **
     MARRON,
     },
    {                           // Pieza 6
     "***",                     // ******
     "  *",                     //     **
     GRISCLARO,
     },
};
byte Tablero[YTABLERO][XTABLERO];
byte MatPiezaAct[MAXDIM][MAXDIM];

// P R O T O T I P O S ///////////////////////////////////////////////////////
void DibPant (void);
void DibPieza (byte pieza);
void GiraPieza (void);

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int Cont = 0;
    byte *Fuente = NULL, Tecla = 0;
    bool Seguir = SI, Salir = NO;

    Fuente = CargaTabla ("\\cpv\\font\\archon.fnt");
    CambiaTabla (Fuente);
    TipoCursor (NOCUR, NOCUR);
    ColorDef (BLANCO, AZUL);
    for (Cont = 0; Cont < 7; Cont++)
        BorraPg (Cont);
    MemPg (0);
    Ira (9, 4);
    Titulo ("TETRIS", PTOS_M, Fuente);
    Ira (10, 5);
    Titulo ("TETRIS", LLENO, Fuente);
    while (!HayTecla ()) ;
    LeeTecla ();
    BorraPg (0);
    while (Seguir) {
        Ira (35, 12);
        MemPrint ("Preparado");
        delay (1000);
        Ira (35, 13);
        MemPrint ("Otra Partida");
        do {
            Tecla = LeeTecla ();
            Salir = SI;
            if (Tecla == 's') {
                Seguir = SI;
                Color (rand()%15, AZUL);
            }
            else if (Tecla == 'n')
                Seguir = NO;
            else
                Salir = NO;
        }
        while (!Salir);
    }
    while (!HayTecla ()) ;
    RestauraTabla (ROM8x16);
    free (Fuente);
}
