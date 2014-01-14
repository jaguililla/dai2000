// B I N G O /////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <iostream.h>

// C L A S E S ///////////////////////////////////////////////////////////////
class C_Carton {
  private:
    int Carton[4][7];           // Matriz del cartón
  public:
    void TachaCarton ();
    void CompLinea ();
    void CompBingo ();
}
//////////////////////////////////////////////////////////////////////////////
    class C_Jugador {
  private:
    char *NomJug;               // Nombre del jugador
    unsigned long int PtsJug;   // Saldo del jugador
    C_Carton CartonJug[4][7];   // Matriz del cartón del jugador
    static int Linea;           // número del jugador con línea
    static int Bingo;           // número del jugador con bingo

  public:
    // Constructores
     C_Jugador ();
    // Destructor
    ~C_Jugador ();
    // Funciones
    void PonNombre (char *Nombre);
}
////////////////////////////////////////////////////////////////////////////// class C_Admin
{
  private:
    unsigned long int PtsAdmin;
    int Tablero[90];

  public:
}
