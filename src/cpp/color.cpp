//////////////////////////////////////////////////////////////////////////////
//  COLOR.CPP - Esta clase permite crear y manipular colores de la paleta o //
//              independientes.                                             //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 5.6.1999                                               //
//  Última Revisión: 20.6.1999                                              //
//  Versión        : 1.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//////////////////////////////////////////////////////////////////////////////

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __COLOR_CPP             // Evita la inclusión de un archivo dos veces
#        define __COLOR_CPP      // mediante el identificador del archivo

// M O D I F I C A D O R E S /////////////////////////////////////////////////
//#define P_COLOR           // Para probar el modulo quita el comentario

// A R C H I V O S ///////////////////////////////////////////////////////////
#include <iostream>

#include "common.hpp"

#include <stdio.h>

using namespace std;

// C L A S E S ///////////////////////////////////////////////////////////////
class C_Color {
  protected:
    // Datos
    byte Rojo;
    byte Verde;
    byte Azul;
  public:
    // Constructores
     C_Color (byte Red = 0, byte Green = 0, byte Blue = 0);
    // Operadores
    friend ostream & operator<< (ostream & Out, const C_Color & Col);
    bool operator== (const C_Color & Col);
    bool operator!= (const C_Color & Col);
     C_Color & operator= (const C_Color & Col);
    // Funciones Miembro
    void SetCol (byte Red = 0, byte Green = 0, byte Blue = 0);
    void ColAPal (byte Pos);
    void PalACol (byte Pos);
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
inline C_Color::C_Color (byte Red, byte Green, byte Blue)
{
    Rojo = Red;
    Verde = Green;
    Azul = Blue;
}

//////////////////////////////////////////////////////////////////////////////

//  ----------
//  OPERADORES
//  ----------
ostream & operator<< (ostream & Out, const C_Color & Col)
{
    Out << "R: " << int (Col.Rojo) << " "
        << "V: " << int (Col.Verde) << " " << "A: " << int (Col.Azul);
    return (Out);
}
//////////////////////////////////////////////////////////////////////////////
inline bool C_Color::operator== (const C_Color & Col)
{
    return (bool
            (Rojo == Col.Rojo && Verde == Col.Verde && Azul == Col.Azul));
}

//////////////////////////////////////////////////////////////////////////////
inline bool C_Color::operator!= (const C_Color & Col)
{
    return (bool
            (!(Rojo == Col.Rojo && Verde == Col.Verde && Azul == Col.Azul)));
}

//////////////////////////////////////////////////////////////////////////////
inline C_Color & C_Color::operator= (const C_Color & Col)
{
    Rojo = Col.Rojo;
    Verde = Col.Verde;
    Azul = Col.Azul;
    return (*this);
}

//////////////////////////////////////////////////////////////////////////////

//  -----------------
//  FUNCIONES MIEMBRO
//  -----------------
inline void C_Color::SetCol (byte Red, byte Green, byte Blue)
{
    Rojo = Red;
    Verde = Green;
    Azul = Blue;
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Color::ColAPal (byte Pos)
{
    /* TODO Implementar
    outp (0x3C8, Pos);
    outp (0x3C9, Rojo);
    outp (0x3C9, Verde);
    outp (0x3C9, Azul);
    */
}

//////////////////////////////////////////////////////////////////////////////
inline void C_Color::PalACol (byte Pos)
{
    /* TODO Implementar
    outp (0x3C7, Pos);
    Rojo = inp (0x3C9);
    Verde = inp (0x3C9);
    Azul = inp (0x3C9);
    */
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
/*
int main (void)
{
    int Rojo = 0, Verde = 0, Azul = 0;  // Vars auxiliares para la prueba
    C_Color Col1;
    C_Color Col2 (10, 10, 10);
    C_Color Col3 (20, 20);
    C_Color Col4 (30);
    C_Color Col5 (Col3);
    C_Color Col6 = Col4;

    // Prueba de los constructores y <<
    cout << "\n\n" << "Prueba de los constructores" << "\n\n";
    cout << "C_Color Col1;" << " --> " << Col1 << "\n";
    cout << "C_Color Col2(10,10,10);" << " --> " << Col2 << "\n";
    cout << "C_Color Col3(20,20);" << " --> " << Col3 << "\n";
    cout << "C_Color Col4(30);" << " --> " << Col4 << "\n";
    cout << "C_Color Col5(Col3);" << " --> " << Col5 << "\n";
    cout << "C_Color Col6=Col4;" << " --> " << Col6 << "\n";
    getchar ();
    // Prueba de los operadores relacionales
    cout << "\n\n" << "Prueba de los operadores relacionales" << "\n\n";
    cout << Col1 << " == " << Col2 << " --> " << (Col1 == Col2) << "\n";
    cout << Col5 << " == " << Col3 << " --> " << (Col5 == Col3) << "\n";
    cout << Col1 << " != " << Col2 << " --> " << (Col1 != Col2) << "\n";
    cout << Col5 << " != " << Col3 << " --> " << (Col5 != Col3) << "\n";
    getchar ();
    // Prueba de los operadores de asignación
    cout << "\n\n" << "Prueba de los operadores de asignación" << "\n\n";
    cout << Col1;
    Col1 = Col3;
    cout << " --> " << "Col1 = Col3;" << " --> " << Col1 << "\n";
    cout << Col1;
    Col1 = Col6;
    cout << " --> " << "Col1 = Col6;" << " --> " << Col1 << "\n";
    getchar ();
    // Prueba de las funciones miembro
    cout << "\n\n" << "Prueba de las funciones miembro" << "\n\n";
    cout << "Introduce los valores del nuevo color de fondo (RGB): ";
    cin >> Rojo >> Verde >> Azul;
    cout << "\n";
    Col3.SetCol (Rojo, Verde, Azul);
    cout << "Introduce los valores del nuevo color de letra (RGB): ";
    cin >> Rojo >> Verde >> Azul;
    cout << "\n";
    Col4.SetCol (Rojo, Verde, Azul);
    Col1.PalACol (0);           // Salvo el color de la posición 0 de la paleta
    Col2.PalACol (7);           // Salvo el color de la posición 7 de la paleta
    Col3.ColAPal (0);           // Pongo el color en la posición 0 de la paleta
    Col4.ColAPal (7);           // Pongo el color en la posición 7 de la paleta
    getchar ();
    Col1.ColAPal (0);           // Restauro el color de fondo original
    Col2.ColAPal (7);           // Restauro el color de letra original
    getchar ();
    return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////
#endif
// EOF
