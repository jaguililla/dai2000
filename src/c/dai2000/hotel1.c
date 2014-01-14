/* hotel1.c -- reserva de hoteles; continúa en listado 9.11 */
#include <stdio.h>
#include "hoteles.h"            /* define constantes, declara funciones */
int main (void)
{
    double noches, hotel;
    int codigo;

    while ((codigo = menu ()) != SALIR) {
        switch (codigo) {

            case 1:
                hotel = HOTEL1;
                break;

            case 2:
                hotel = HOTEL2;
                break;

            case 3:
                hotel = HOTEL3;
                break;

            case 4:
                hotel = HOTEL4;
                break;

            default:
                hotel = 0.0;
                printf ("¡Ahí va!\n");
                break;
        }

        noches = tomanoches ();
        sacaprecio (hotel, noches);
    }

    return 0;
}
