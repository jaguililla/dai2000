//////////////////////////////////////////////////////////////////////////////
//                               F I C H E R O S                            //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : proporciona acceso a ficheros indexados                //
//                   independientemente de la estructura de sus registros   //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla                                    //
//  Desarrollado el: 16.5.1999                                              //
//  Última Revisión: 25.5.1999                                              //
//  Versión        : 0.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * Para cada fichero de datos se crea un fichero        //
//                     índice que se carga en memoria al abrir el archivo   //
//                   * La estructura del índice en memoria es una lista     //
//                     simplemente enlazada                                 //
//                   * La clave y los datos son pasados como punteros a     //
//                     un bloque de memoria -malloc()- para permitir        //
//                     cualquier tipo de datos                              //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

#include "../../basico.h"             // Definiciones basicas

// D E F I N E S /////////////////////////////////////////////////////////////
#define  DAT_EXT  ".dat"
#define  IND_EXT  ".ndx"

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct T_Indice {
    byte *Clave;                // Clave del registro
    unsigned Posicion;          // Nº de registro de esa clave
    struct T_Indice *sig;       // Siguiente elemento de la lista
} T_Indice;                     // Estructura de un registro de indice

typedef struct T_Registro {
    byte *Datos;                // Datos del registro
    unsigned SigLibre;          // Siguiente libre
} T_Registro;                   // Estructura de un registro de datos

// P R O T O T I P O S ///////////////////////////////////////////////////////
void BuscaInd (T_Indice ** Indice, byte * Clave, byte LongClave,
               T_Indice * Ant, T_Indice * Act, bool * Hallado);
// función auxiliar usada por AltaInd () y BajaInd () para localizar un
// elemento dentro del indice.
// Parametros:
//      -T_Indice **Indice: cabecera de la lista indice en memoria.
//      -byte *Clave: puntero a la clave.
//      -byte LongClave: nº de byte que ocupa la clave.
//      -T_Indice *Ant: puntero a la posición anterior de la clave buscada.
//      -T_Indice *Act: puntero a la posición de la clave buscada.
//      -bool *Hallado: indica si existe la clave buscada.

void AltaInd (T_Indice ** Indice, byte * Clave, byte LongClave,
              unsigned Posicion, byte * PosHallado);
// Da de alta en la lista indice de memoria.
// Parametros:
//      -T_Indice **Indice: cabecera de la lista indice en memoria.
//      -byte *Clave: puntero a la clave (debe ser un dato simple).
//      -byte LongClave: nº de byte que ocupa la clave.
//      -unsigned Posicion: nº de registro de la clave en el fichero de datos.
//      -byte *PosHallado: indica la posición de la clave si la encuentra,
//       sino devuelve 0.

void BajaInd (T_Indice ** Indice, byte * Clave, byte LongClave,
              unsigned Posicion, bool * Hallado);
// Da de baja en la lista indice de memoria.
// Parametros:
//      -T_Indice **Indice: cabecera de la lista indice en memoria.
//      -byte *Clave: puntero a la clave (debe ser un dato simple).
//      -byte LongClave: nº de byte que ocupa la clave.
//      -unsigned Posicion: nº de registro de la clave en el fichero de datos.
//      -bool *hallado: indica si existe la clave a dar de baja.

T_Indice *CargaFich (char *NomFich);

// Carga el fichero y devuelve la cabecera de su índice, si no existe lo crea.
// Parametros:
//      -char *NomFich: el nombre del fichero a abrir/crear.

void LeeReg (char *NomFich, T_Indice * Indice, byte * Clave, byte * Datos);

// Lee el registro al que corresponde la clave indicada y devuelve un puntero
// a sus datos, si la clave no existe devuelve NULL.
// Parametros:
//      -char *NomFich: nombre del fichero.
//      -T_Indice *Indice: cabecera de la lista indice en memoria.
//      -byte *Clave: puntero a la clave a leer, si no existe es NULL.

void EscribeReg (char *NomFich, T_Indice * Indice, byte * Clave,
                 byte * Datos);
// Escribe en el registro al que corresponde a la clave indicada, si la clave
// no existe inserta el registro al final del fichero.

bool BorraReg (char *NomFich, T_Indice * Indice, byte * Clave);

void GrabaCambios (char *NomFich, T_Indice * Indice);

// Almacena la lista indice en el archivo indice se ejecuta siempre al dar
// de alta y de baja.
//      -char *NomFich: nombre del fichero a escribir (extensión .ndx).
//      -T_Indice *Indice: cabecera del indice en memoria.

// F U N C I O N E S /////////////////////////////////////////////////////////
void BuscaInd (T_Indice ** Indice, byte * Clave, byte LongClave,
               T_Indice * Ant, T_Indice * Act, bool * Hallado)
{
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
