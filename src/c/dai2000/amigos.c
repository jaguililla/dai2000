/* amigos.c -- puntero a estructura */
#include <stdio.h>
#define LEN 20

struct nombres {
    char nom[LEN];
    char apell[LEN];
};

struct tio {

    struct nombres maneja;
    char comifavo[LEN];
    char trabajo[LEN];
    float gana;
};

int main (void)
{

    static struct tio feten[2] = {
        {
         {"Pepe", "Gafe"},

         "alcachofas",
         "sexador de pollos",
         3535000.00},

        {{"Santi", "Fever"},
         "salmón ahumado",
         "programador",
         9999995.00}
    };

    struct tio *este;           /* AQUI ESTA: puntero a estructura */

    printf ("dirección 1: %u; 2: %u\n", &feten[0], &feten[1]);
    este = &feten[0];           /* indica al puntero dónde apuntar */
    printf ("puntero   1: %u; 2: %u\n", este, este + 1);
    printf ("este->gana vale %.2f: (*este).gana vale %.2f\n",
            este->gana, (*este).gana);
    este++;                     /* apunta a la siguiente estructura */
    printf ("este->comifavo es %s; este->nombres.apell es %s\n",
            este->comifavo, este->maneja.apell);
    return 0;
}
