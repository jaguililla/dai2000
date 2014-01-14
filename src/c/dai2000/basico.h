//////////////////////////////////////////////////////////////////////////////
// BASICS.H - Archivo de cabecera con definiciones básicas                  //
//////////////////////////////////////////////////////////////////////////////

// D E F I N E S  ////////////////////////////////////////////////////////////
#define   TRUE    1
#define   FALSE   0
#define   ERR        (-1)
#define   EOS     '\0'          // Fin de cadena (End Of String)
#define   YES     1
#define      SI      1
#define   NO      0
#define   OK      1
#define   ON      1
#define   OFF     0

// M A C R O S //////////////////////////////////////////////////////////////
#define      MK_WORD(HIBYTE, LOBYTE)\
            (word)((HIBYTE<<8)+LOBYTE)  // Crea un WORD a partir de 2 bytes
#define   HI(WORDVAR)\
            (byte)(WORDVAR>>8)
#define   LO(WORDVAR)\
            (byte)(WORDVAR)

// T Y P E D E F S / S T R U C T U R E S ////////////////////////////////////
//typedef int bits;               // Def. de bit para campos de bits
//typedef unsigned char byte;     // Improvisamos un byte (8 bits)
//typedef unsigned int word;      // Un word (2 bytes) (16 bits)
//typedef unsigned long dword;    // Un dword (4 bytes) (32 bits)
//typedef char bool;              // Boolean (TRUE/FALSE o YES/NO)

/////////////////////////////// EOF BASICS.H ////////////////////////////////
