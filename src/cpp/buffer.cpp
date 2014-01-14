/*
 * B U F F E R
 *
 * Esta clase permite crear y manipular buffers en posiciones concretas de
 * memoria (como la de video)
 *
 * Autor: Juan José Aguililla Martínez
 * Creado el: 21.7.1999
 */

// I N C L U D E S ///////////////////////////////////////////////////////////
#include "common.hpp"

#include <iostream>
#include <sstream>

// D E F I N E S /////////////////////////////////////////////////////////////
#define __BUFFER_CPP

using namespace std;

// C L A S E S ///////////////////////////////////////////////////////////////
template < class T1 > class C_Buffer {
  private:
    // Datos
    T1 * PtrIni;            // Puntero a la dirección inicial del buffer
    dword Longitud;             // Guarda la longitud en bytes del buffer

  public:
    // Constructores
    C_Buffer (const void * DirBuffer, dword TamBuffer); // General

    // Operadores
    T1 & operator[](dword Index);
    bool operator== (const C_Buffer < T1 > & Buf);
    bool operator!= (const C_Buffer < T1 > & Buf);
    C_Buffer < T1 > & operator= (const C_Buffer < T1 > & Buf);

    // Funciones Miembro
    T1 *GetPtrIni (void);
    T1 *GetPtr (const dword Offset = 0);
    dword GetLongitud (void);
    T1 GetVal (const dword Offset);
    void SetBuffer (const T1 Valor, dword PosIni, dword PosFin);
    void SetBuffer (const C_Buffer & Buf, dword PosIni, dword PosFin);
    void SetVal (dword Offset, T1 Valor);
    bool CompBuffer (dword Offset1, const C_Buffer & Buf, dword Offset2);
    bool CopyBuffer (dword Offset1, const C_Buffer & Buf, dword Offset2);
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
template < class T1 >
inline C_Buffer < T1 >::C_Buffer (const void * DirBuffer, dword TamBuffer)
{
    PtrIni = (T1 *) DirBuffer;
    Longitud = TamBuffer;
}

//  ----------
//  OPERADORES
//  ----------
template < class T1 >
inline bool C_Buffer < T1 >::operator== (const C_Buffer < T1 > &Buf)
{
    if (Longitud == Buf.Longitud)
        return (bool (!memcmp (PtrIni, Buf.PtrIni, Longitud)));
    else
        return (bool (255));
}

template < class T1 >
inline bool C_Buffer < T1 >::operator!= (const C_Buffer < T1 > &Buf)
{
    if (Longitud == Buf.Longitud)
        return (bool (memcmp (PtrIni, Buf.PtrIni, Longitud)));
    else
        return (bool (255));
}

template < class T1 >
inline C_Buffer < T1 > & C_Buffer < T1 >::operator= (const C_Buffer < T1 > &Buf)
{
    if (Longitud == Buf.Longitud)
        memcpy (PtrIni, Buf.PtrIni, Longitud);
    return NULL;
}

// M A I N ///////////////////////////////////////////////////////////////////
int main (void)
{
    //C_Buffer < byte > BufByte (MK_FP (0xB800, 0x0000), 10);
    //C_Buffer < byte > BufInteger = BufByte;

    cout << "Esto es una prueba";
    return 0;
}
// EOF ///////////////////////////////////////////////////////////////////////

