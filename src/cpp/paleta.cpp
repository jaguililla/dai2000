//////////////////////////////////////////////////////////////////////////////
//  PALETA.CPP - Esta clase permite crear y manipular la paleta de colores  //
//               de las tarjetas VGA (256 colores).                         //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla Martínez                           //
//  Desarrollado el: 3.6.1999                                               //
//  Última Revisión: 12.6.1999                                              //
//  Versión        : 0.5                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//                   * El tipo de datos T_Colores (unión con los nombres de //
//                     los colores) se define en otro fichero puesto que es //
//                     usado por otras clases.                              //
//                   * En SalvaPal() controlar si el nombre de la paleta    //
//                     existe para no sobreescribirlo.                      //
//                   * Controlar en el constructor que:                     //
//                     NCol > 0 && NCol <= 256                              //
//                   * El nº máximo de colores de una paleta es de 256.     //
//                   * Cuando NumCol es mayor de 256 quiere decir que la    //
//                     paleta está activa.                                  //
//////////////////////////////////////////////////////////////////////////////

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __PALETA_CPP            // Evita la inclusión de un archivo dos veces
#        define __PALETA_CPP     // mediante el identificador del archivo

// M O D I F I C A D O R E S /////////////////////////////////////////////////
#    define P_PALETA            // Para probar el modulo quita el comentario

// A R C H I V O S ///////////////////////////////////////////////////////////
#    ifdef P_PALETA             // Archivos necesarios para la prueba
#    endif

#    include <fstream>
#    include <stdlib.h>
#    include "common.hpp"
#    include "color.cpp"

// C L A S E S ///////////////////////////////////////////////////////////////
class C_Paleta {
  private:
    // Datos
    C_Color * Paleta;
    word NumCol;
  public:
    // Constructores
     C_Paleta (const word & NCol = 256, const char *NomArchivo = "");
     C_Paleta (const C_Paleta & Pal);
    // Destructor
    ~C_Paleta ();
    // Operadores
    bool operator== (const C_Paleta & Pal);
    bool operator!= (const C_Paleta & Pal);
     C_Paleta & operator= (const C_Paleta & Pal);
    // Funciones Miembro
    void SetColPal (byte NumCol, byte Red, byte Green, byte Blue);
    C_Color GetColPal (byte NumCol);
    void PonerPal (void);       // Activa la paleta
    void CogerPal (void);       // Copia la paleta activa a la paleta
    void CargaPal (const char *NomArchivo);
    void SalvaPal (const char *NomArchivo);
    void Degradado (byte ColIni, byte ColFin);
    void FundidoNegro (int Pasos, const char *Colores);
    void FundidoColor (int Pasos, const char *Colores);
        /*--------------------------------------------------------------
           Colores es una cadena del tipo "1-4" desde el color 1 hasta
           el 4 o del tipo "1,4" los colores 1 y 4 (Colores del fundido)
          --------------------------------------------------------------*/
};

// I M P L E M E N T A C I O N ///////////////////////////////////////////////

//  -------------
//  CONSTRUCTORES
//  -------------
C_Paleta::C_Paleta (const word & NCol, const char *NomArchivo):NumCol (NCol)
{
    if (NCol > 0 && NCol <= 256)    // Comprueba los datos de entrada
    {
        Paleta = new C_Color[NCol]; // Reserva espacio para la paleta
        if (NomArchivo && NomArchivo != "") // Si hay NomArchivo != NULL
        {
            fstream PalFile (NomArchivo, ios::binary | ios::in);
            if (PalFile)        // Si el archivo existe
            {
                PalFile.read ((char *) Paleta, (sizeof (C_Color) * 256));
                PalFile.close ();
            }
        }
        // Inicializa la paleta
    }
}

//////////////////////////////////////////////////////////////////////////////
C_Paleta::C_Paleta (const C_Paleta & Pal)   // De copia
{
    for (int Cont = 0; Cont < 256; Cont++)
        Paleta[Cont] = Pal.Paleta[Cont];
}

//////////////////////////////////////////////////////////////////////////////

//  ----------
//  DESTRUCTOR
//  ----------
C_Paleta::~C_Paleta ()
{
    delete[]Paleta;
}

//////////////////////////////////////////////////////////////////////////////

//  ----------
//  OPERADORES
//  ----------
bool C_Paleta::operator== (const C_Paleta & Pal)
{
    bool Idem = true;

    for (int Cont = 0; Cont < 256 && Idem; Cont++)
        Idem = (Paleta[Cont] == Pal.Paleta[Cont]);
    return (Idem);
}

//////////////////////////////////////////////////////////////////////////////
bool C_Paleta::operator!= (const C_Paleta & Pal)
{
    return (bool (!(*this == Pal)));
}

//////////////////////////////////////////////////////////////////////////////
C_Paleta & C_Paleta::operator= (const C_Paleta & Pal)
{
    for (int Cont = 0; Cont < 256; Cont++)
        Paleta[Cont] = Pal.Paleta[Cont];
    return (*this);
}

//  -----------------
//  FUNCIONES MIEMBRO
//  -----------------
void C_Paleta::SetColPal (byte NumCol, byte Red, byte Green, byte Blue)
{
    Paleta[NumCol].SetCol (Red, Green, Blue);
}

//////////////////////////////////////////////////////////////////////////////
C_Color C_Paleta::GetColPal (byte NumCol)
{
    return (Paleta[NumCol]);
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::PonerPal (void)  // Activa la paleta
{
    for (int Cont = 0; Cont < 256; Cont++)
        Paleta[Cont].ColAPal (Cont);
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::CogerPal (void)  // Copia la paleta activa a la paleta
{
    for (int Cont = 0; Cont < 256; Cont++)
        Paleta[Cont].PalACol (Cont);
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::CargaPal (const char *NomArchivo)
{
    if (NomArchivo && NomArchivo != "") // Si NomArchivo != NULL
    {
        fstream PalFile (NomArchivo, ios::binary | ios::in);

        PalFile.read ((char *) Paleta, (sizeof (C_Color) * 256));
        PalFile.close ();
    }
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::SalvaPal (const char *NomArchivo)
{
    if (NomArchivo && NomArchivo != "") // Si NomArchivo != NULL
    {
        fstream PalFile (NomArchivo, ios::binary | ios::out);

        PalFile.write ((char *) Paleta, (sizeof (C_Color) * 256));
        PalFile.close ();
    }
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::Degradado (byte ColIni, byte ColFin)
{
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::FundidoNegro (int Pasos, const char *Colores)
{
}

//////////////////////////////////////////////////////////////////////////////
void C_Paleta::FundidoColor (int Pasos, const char *Colores)
{
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
#    ifdef P_PALETA
int main (void)
{
    return 0;
}
#    endif
//////////////////////////////////////////////////////////////////////////////
#endif
// EOF
