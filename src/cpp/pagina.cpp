//////////////////////////////////////////////////////////////////////////////
//  PAGINA.CPP - define una página de video en el modo texto.               //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 6.9.1999                                               //
//  Última Revisión: 6.9.1999                                               //
//  Versión        : 0.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//////////////////////////////////////////////////////////////////////////////

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __PAGINA_CPP            // Evita la inclusión de un archivo dos veces
#        define __PAGINA_CPP     // mediante el identificador del archivo

// M O D I F I C A D O R E S /////////////////////////////////////////////////
#    define P_PAGINA            // Para probar el modulo quita el comentario

// A R C H I V O S ///////////////////////////////////////////////////////////
#    ifdef P_PAGINA             // Archivos necesarios para la prueba
#            include <iostream>
#    endif

#    include "common.hpp"
#    include "caracter.cpp"

// C L A S E S ///////////////////////////////////////////////////////////////
class C_Pagina {
  protected:
    // Datos
    C_Caracter * MemPag;
    word Fils;
    word Cols;
  public:
    // Constructores
     C_Pagina (word Seg, word Off, word Ln, word Cl);
     C_Pagina (word Ln, word Cl);
    // Destructor
    ~C_Pagina ();
    // Operadores
     C_Caracter & operator[] (const dword & Index);
     C_Pagina & operator= (const C_Pagina & Pagina);
    // Funciones Miembro
    word GetFils (void) const;
    word GetCols (void) const;
    void PgCpy (const C_Caracter * Valor, dword PosIni = 0, dword NEle =
                0);
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
C_Pagina::C_Pagina (word Seg, word Off, word Ln, word Cl)
{
    MemPag = (C_Caracter *)MkDword (Seg, Off);
    Fils = Ln;
    Cols = Cl;
}

//////////////////////////////////////////////////////////////////////////////
C_Pagina::C_Pagina (word Ln, word Cl)
{
    MemPag = new C_Caracter[Fils * Cols];
}
//////////////////////////////////////////////////////////////////////////////
#endif
