//////////////////////////////////////////////////////////////////////////////
//  PMEM.CPP - Esta clase permite crear y manipular posiciones concretas de //
//             memoria (como la de video). PMem = Puntero a Memoria.        //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 21.7.1999                                              //
//  Última Revisión: 20.8.1999                                              //
//  Versión        : 0.5                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * No tiene constructor por defecto (siempre se tiene   //
//                     que especificar la cantidad de elementos).           //
//                   * El constructor con el número de elementos reserva    //
//                     memoria del montón (heap), mientras que si se        //
//                     especifica una dirección la memoria se colocará a    //
//                     partir de esa dirección.                             //
//                   * El tamaño del buffer se especifica en número de      //
//                     elementos (del tipo de datos), no de bytes.          //
//                   * El índice de los elementos es 0 - (N-1).             //
//                   * La longitud máxima es de 4.294.967.294 elementos.    //
//                   * Añadir la comprobación de límites.                   //
//////////////////////////////////////////////////////////////////////////////

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __PMEM_CPP              // Evita la inclusión de un archivo dos veces
#        define __PMEM_CPP       // mediante el identificador del archivo

// M O D I F I C A D O R E S /////////////////////////////////////////////////
#    define P_PMEM              // Para probar el modulo quita el comentario

// A R C H I V O S ///////////////////////////////////////////////////////////
#    ifdef P_PMEM               // Archivos necesarios para la prueba
#            include <iostream>
#    endif

#    include "common.hpp"

using namespace std;

// C L A S E S ///////////////////////////////////////////////////////////////
template < class T1 > class C_PMem {
  protected:
    // Datos
    T1 * PtrIni;
    dword NumEle;

  public:
    // Constructores
    C_PMem (const dword & NEle);
    C_PMem (const word & Seg, const word & Off, const dword & NEle);

    // Operadores
    T1 *operator[] (const dword & Index);
    C_PMem & operator= (const C_PMem & PMem);

    // Funciones Miembro
    dword GetNumEle (void);
    void PMemCpy (T1 Valor, dword PosIni = 0, dword NEle = 0);
    void PMemCpy (const T1 * Valor, dword PosIni = 0, dword NEle = 0);
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
template < class T1 > inline C_PMem < T1 >::C_PMem (const dword & NEle)
{
    PtrIni = new T1[NEle];
    NumEle = NEle;
}

//////////////////////////////////////////////////////////////////////////////
template < class T1 >
    inline C_PMem < T1 >::C_PMem (const word & Seg, const word & Off,
                                  const dword & NEle)
{
    PtrIni = (T1 *)MkDword (Seg, Off);
    NumEle = NEle;
}

//////////////////////////////////////////////////////////////////////////////

//  ----------
//  OPERADORES
//  ----------
template < class T1 >
    inline T1 * C_PMem < T1 >::operator[](const dword & Index) {
    if (Index < NumEle)         // Comprobación de rangos
        return (PtrIni + Index);
    else
        return (NULL);
}

//////////////////////////////////////////////////////////////////////////////
template < class T1 >
    inline C_PMem < T1 > &C_PMem < T1 >::operator= (const C_PMem < T1 > &PMem)
{
    T1 *Ptr1 = PtrIni;
    T1 *Ptr2 = PMem.PtrIni;
    dword NEle = Menor (PMem.NumEle, NumEle);

    for (; NEle; Ptr1++, Ptr2++, NEle--)
        *Ptr1 = *Ptr2;
    return (*this);
}

//////////////////////////////////////////////////////////////////////////////

//  -----------------
//  FUNCIONES MIEMBRO
//  -----------------
template < class T1 > inline dword C_PMem < T1 >::GetNumEle (void)
{
    return (NumEle);
}

//////////////////////////////////////////////////////////////////////////////
template < class T1 >
    void C_PMem < T1 >::PMemCpy (T1 Valor, dword PosIni, dword NEle)
{
    if (PosIni >= NumEle || NEle > NumEle)  // Comprobación de rangos
        return;
    T1 *PIni = PtrIni + PosIni;

    if (!NEle || (PosIni + NEle - 1 > NumEle))
        NEle = NumEle - PosIni;
    T1 *PFin = PIni + NEle;

    for (; PIni != PFin; PIni++)
        *PIni = Valor;
}

//////////////////////////////////////////////////////////////////////////////
template < class T1 >
    void C_PMem < T1 >::PMemCpy (const T1 * Valor, dword PosIni,
                                 dword NEle)
{
    T1 *PIni = PtrIni + PosIni;

    if (!NEle || (PosIni + NEle - 1 > NumEle))
        NEle = NumEle - PosIni;
    T1 *PFin = PIni + NEle;

    for (; PIni != PFin; PIni++, Valor++)
        *PIni = *Valor;
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
#    ifdef P_PMEM
int main (void)
{
    C_PMem < byte > Linea1 (0xB800, 0x0000, 160);
    C_PMem < byte > Linea2 = Linea1;
    C_PMem < byte > Linea3 (0xB800, 160, 160);
    C_PMem < byte > Linea4 = Linea3;
    C_PMem < byte > Linea5 (0xB800, 3 * 160, 160);

    *Linea1[0] = 'H';
    *Linea1[2] = 'o';
    *Linea1[4] = 'l';
    *Linea1[6] = 'a';
    *Linea3[0] = 'A';
    *Linea3[2] = 'd';
    *Linea3[4] = 'i';
    *Linea3[6] = 'o';
    *Linea3[8] = 's';
    cout << "\n\n" << *Linea1[6] << "\n" << *Linea3[6] << "\n";
    Linea1.PMemCpy ('\x2', 0, 9);
    Linea5.PMemCpy (Linea1[0], 4, 4);
    Linea1 = Linea3;
    Linea2 = Linea5;
}
#    endif
//////////////////////////////////////////////////////////////////////////////
#endif
// EOF
