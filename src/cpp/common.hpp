/*
 * Notas:
 * - Las funciones Mayor () y Menor () usan
 *   plantillas, para poder comparar valores constantes,
 *   Hay que tener cuidado con los tipos de los valores
 *   que se comparan.
 * - Si en las funciones Mayor () y Menor () ambos
 *   argumentos son iguales se devuelve el valor de uno
 *   de los dos (en este caso el segundo).
 * - En la función Swap () se puede comprobar si las
 *   variables a intercambiar son iguales antes de
 *   cambiar sus valores ¿Sería más rápido?
 * - Para aumentar la portabilidad se puede sustituir el
 *   nº de bits de desplazamiento en las funciones
 *   Mk* (), Hi* () y Lo* () por la expresión:
 *   sizeof (Var) * BITS_BYTE
 * - La unión anónima no requiere el operador ".", se
 *   utilizan sus miembros "ValEnt" y "ValCar" como
 *   variables.
 */

// I D E N T I F I C A D O R /////////////////////////////////////////////////
#ifndef __COMMON_HPP
#    define __COMMON_HPP        // Identificador del archivo

// T I P O S /////////////////////////////////////////////////////////////////
typedef int bit;                // Def. de bit para campos de bits
typedef unsigned char byte;     // Improvisamos un byte (8 bits)
typedef unsigned int word;      // Un word (2 bytes) (16 bits)
typedef unsigned long dword;    // Un dword (4 bytes) (32 bits)

static union {                  // Unión sin tipo "anonima"
    int ValEnt;                 // ValEnt = Entero
    char ValCar;                // ValCar = Caracter
};

// C O N S T A N T E S ///////////////////////////////////////////////////////
const byte OK = 0;              // Proceso finalizado correctamente
const char EOS = '\0';          // Fin de cadena (End Of String)

// F U N C I O N E S /////////////////////////////////////////////////////////
dword MkDword (word Hi, word Lo) {    // Crea un dword a partir de 2 words
    return (dword ((Hi << 16) + Lo));
}

word HiWord (dword DwordVar) {    // Devuelve el word alto del dword
    return (word (DwordVar >> 16));
}

word LoWord (dword DwordVar) {    // Devuelve el word bajo del dword
    return (word (DwordVar));
}

word MkWord (byte Hi, byte Lo) {  // Crea un word a partir de 2 bytes
    return (word ((Hi << 8) + Lo));
}

byte HiByte (word WordVar) {      // Devuelve el byte alto del word
    return (byte (WordVar >> 8));
}

byte LoByte (word WordVar) {      // Devuelve el byte bajo del word
    return (byte (WordVar));
}

template < class T1 > inline void Swap (T1 & Val1, T1 & Val2) {   // Intercambia dos vars.
    T1 Aux;

    Aux = Val2;
    Val2 = Val1;
    Val1 = Aux;
}

template < class T1, class T2 > inline T1 Mayor (T1 Val1, T2 Val2) {  // Devuelve el mayor
    if (Val1 > Val2)
        return (Val1);
    else
        return (Val2);
}

template < class T1, class T2 > inline T1 Menor (T1 Val1, T2 Val2) {  // Devuelve el menor
    if (Val1 < Val2)
        return (Val1);
    else
        return (Val2);
}

#endif
// E O F /////////////////////////////////////////////////////////////////////

