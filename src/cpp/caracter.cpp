//////////////////////////////////////////////////////////////////////////////
//  CARACTER.CPP - Esta clase define una posición en pantalla (es la        //
//                 estructura de la memoria de video en modo texto).        //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 3.9.1999                                               //
//  Última Revisión: 3.9.1999                                               //
//  Versión        : 1.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * El formato para introducir el valor numérico del     //
//                     atributo es "(CF << 4) + CT + 128". 128 solo se suma //
//                     si se desea texto intermitente. INTER = 128.         //
//                   * En general sumando 128 (INTER) al byte de atributos  //
//                     se consigue que el caracter parpadee.                //
//                   * Para conseguir que un caracter parpadee solo hay que //
//                     sumarle 128 (INTER) al color del texto, con el color //
//                     de fondo NO funcionará, por ejemplo en SetColF ().   //
//                   * La constante INTER se puede declarar dentro de la    //
//                     clase.                                               //
//                   * No se controla la validez de rangos para los         //
//                     colores.                                             //
//////////////////////////////////////////////////////////////////////////////

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __CARACTER_CPP          // Evita la inclusión de un archivo dos veces
#        define __CARACTER_CPP   // mediante el identificador del archivo

// M O D I F I C A D O R E S /////////////////////////////////////////////////
//#define P_CARACTER        // Para probar el modulo quita el comentario

// A R C H I V O S ///////////////////////////////////////////////////////////
#include <iostream>
#include "common.hpp"

#include <stdio.h>

// C O N S T A N T E S ///////////////////////////////////////////////////////
const byte INTER = 0x80;

using namespace std;

// C L A S E S ///////////////////////////////////////////////////////////////
class C_Caracter {
  protected:
    // Datos
    byte Ascii;
    byte Atributos;
  public:
    // Constructores
     C_Caracter (byte CodAscii = 0, byte Atribs = 0);
     C_Caracter (byte CodAscii, byte ColF, byte ColT);
    // Operadores
     C_Caracter & operator= (const C_Caracter & Car);
    // Funciones Miembro
    void SetAscii (byte CodAscii);
    void SetAtributos (byte Atribs);
    void SetColores (byte ColF, byte ColT);
    void SetColF (byte ColF);
    void SetColT (byte ColT);
    void SetInter (bool Inter);
    byte GetAscii (void) const;
    byte GetAtributos (void) const;
    void GetColores (byte & ColF, byte & ColT) const;
    byte GetColF (void) const;
    byte GetColT (void) const;
    bool GetInter (void) const;
    void InfoCar (void) const;
    void PruebaOrden (const char *Orden) const;
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
inline C_Caracter::C_Caracter (byte CodAscii, byte Atribs)
{
    Ascii = CodAscii;
    Atributos = Atribs;
}

//////////////////////////////////////////////////////////////////////////////
inline C_Caracter::C_Caracter (byte CodAscii, byte ColF, byte ColT)
{
    Ascii = CodAscii;
    Atributos = (ColF << 4) + ColT;
}

//////////////////////////////////////////////////////////////////////////////

//  ----------
//  OPERADORES
//  ----------
C_Caracter & C_Caracter::operator= (const C_Caracter & Car)
{
    Ascii = Car.Ascii;
    Atributos = Car.Atributos;
    return (*this);
}

//////////////////////////////////////////////////////////////////////////////

//  -----------------
//  FUNCIONES MIEMBRO
//  -----------------
inline void C_Caracter::SetAscii (byte CodAscii)
{
    Ascii = CodAscii;
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Caracter::SetAtributos (byte Atribs)
{
    Atributos = Atribs;
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Caracter::SetColores (byte ColF, byte ColT)
{
    Atributos &= 0x80;          // Deja a 0 los bits menos intermitencia
    Atributos |= (ColF << 4) + ColT;
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Caracter::SetColF (byte ColF)
{
    Atributos &= 0x8F;          // Pone a 0 los bits del color de fondo
    Atributos |= ColF << 4;     // Copia los bits del color de fondo
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Caracter::SetColT (byte ColT)
{
    Atributos &= 0xF0;          // Pone a 0 los bits del color del texto
    Atributos |= ColT;          // Copia los bits del color de fondo
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Caracter::SetInter (bool Inter)
{
    if (Inter)
        Atributos |= 0x80;      // Pone a 1 el bit de intermitencia
    else
        Atributos &= 0x7F;      // Pone a 0 el bit de intermitencia
}

//////////////////////////////////////////////////////////////////////////////
inline byte C_Caracter::GetAscii (void) const {
    return (Ascii);
}
//////////////////////////////////////////////////////////////////////////////
    inline byte C_Caracter::GetAtributos (void) const {
         return (Atributos);
     }
//////////////////////////////////////////////////////////////////////////////
    inline void C_Caracter::GetColores (byte & ColF,
                                        byte & ColT) const {
         ColF = (Atributos & 0x70) >> 4;
         ColT = Atributos & 0x0F;
     }
//////////////////////////////////////////////////////////////////////////////
    inline byte C_Caracter::GetColF (void) const {
         return ((Atributos & 0x70) >> 4);
     }
//////////////////////////////////////////////////////////////////////////////
    inline byte C_Caracter::GetColT (void) const {
         return (Atributos & 0x0F);
     }
//////////////////////////////////////////////////////////////////////////////
    inline bool C_Caracter::GetInter (void) const {
         return ((Atributos & 0x80) ? true : false);
     }
//////////////////////////////////////////////////////////////////////////////
     void C_Caracter::InfoCar (void) const {
         printf ("Código Ascii / Caracter: %d - %c\n", Ascii, Ascii);
         printf ("Byte de Atributos: %2X ", Atributos);
         printf ("Fondo ");
         printf ("Texto ");
         printf ("\nPrueba del caracter: ");
         printf ("\n");
     }
//////////////////////////////////////////////////////////////////////////////
     void C_Caracter::PruebaOrden (const char *Orden) const {
         byte C1 = 0, C2 = 0;

         cout << Orden << "\n";
         cout << "-------------------------------------\n";
         this->InfoCar ();
         cout << "-------------------------------------\n";
         cout << " * GetColF (): " << (int) this->GetColF () << endl;
         cout << " * GetColT (): " << (int) this->GetColT () << endl;
         this->GetColores (C1, C2);
         cout << " * GetColores (Cf, Ct): " << (int) C1 << " " << (int) C2 <<
             endl;
         cout << " * GetInter (): ";
         if (this->GetInter ())
             cout << "SI";
         else
             cout << "NO";
         cout << "\n\n";
     }
//////////////////////////////////////////////////////////////////////////////// M A I N ///////////////////////////////////////////////////////////////////
int main (void)
{
    C_Caracter Car1 (205, 1, 14 + INTER);

    cout << "\n\t\tPRUEBA DE L0S CONSTRUCTORES\n\n";
    Car1.PruebaOrden ("C_Caracter Car1 (205, 1, 14 + INTER);");
    getchar ();
    cout << "\n\t\tPRUEBA LAS FUNCIONES MIEMBRO\n\n";
    Car1.PruebaOrden ("Estado Inicial");
    getchar ();
    Car1.SetInter (false);
    Car1.PruebaOrden ("Car1.SetInter (NO);");
    getchar ();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
#endif
// EOF
