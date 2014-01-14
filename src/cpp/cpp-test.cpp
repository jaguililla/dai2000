// A R C H I V O S //////////////////////////////////////////////////////////
#include <iostream>
#include <ios>

#include "common.hpp"

using namespace std;

// M A I N //////////////////////////////////////////////////////////////////
int main (void)
{
    byte Byte1 = 0xEE;
    byte Byte2 = 0xEE;
    word Word1 = 0x0000;
    float Val1 = 1.5, Val2 = 2.5;
    const char Char1 = 'A';
    char Char2 = 'B';

    cout.setf (ios::hex, ios::basefield);
    cout << "Byte Alto: " << int (Byte1) << "  " << "Byte Bajo: " << int (Byte2) << endl;
    Word1 = MkWord (Byte1, Byte2);
    cout << "Palabra Final: " << Word1 << endl;
    Word1 = 0x0101;
    cout << "Palabra Inicial: " << Word1 << endl;
    Byte1 = HiByte (Word1);
    Byte2 = LoByte (Word1);
    cout << "Byte Alto: " << int (Byte1) << "  " << "Byte Bajo: "
        << int (Byte2) << endl;
    cout << Val1 << "  " << Val2 << endl;
    Swap (Val1, Val2);
    cout << Val1 << "  " << Val2 << endl;
    cout << Mayor (Val1, Val2) << endl;
    cout << Menor (Val1, Val2) << endl;
    cout << Mayor (Char1, Char2) << endl;
    cout << Menor (Char1, Char2) << endl;
    cout << "\n\n\tPRUEBA DEL OPERADOR INDICE \"[]\" EN PUNTEROS.\n\n";
    const byte NBuf = 3;
    byte *Buffer = NULL;

    Buffer = new byte[NBuf];
    for (byte Cont = 0; Cont < NBuf; Cont++) {
        cout << "Introduce el valor de la posición " << int (Cont) <<
            " del buffer: ";
        cin >> Buffer[Cont];
    }
    int Cont = 0;
    for (Cont = 0; Cont < NBuf; Cont++) {
        cout << "El valor de la posición " << int (Cont) <<
            " del buffer es: ";
        cout << Buffer[Cont] << "\n";
    }
    Buffer[4] = 'W';
    cout << "El valor de la posición 4 (fuera de rango) del buffer es: ";
    cout << Buffer[4] << "\n";
}

//////////////////////////////////////////////////////////////////////////////
