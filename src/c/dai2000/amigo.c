/* amigo.c -- ejemplo de estructura anidada */
#include <stdio.h>
#define LEN 20
#define M1 "     Gracias por esa tarde maravillosa, "
#define M2 "Me has demostrado que realmente un "
#define M3 "no es una persona corriente. A ver si quedamos"
#define M4 "frente a un delicioso plato de "
#define M5 "y pasamos otra buena velada."

struct nombres {                /* primer patrón de estructura */
    char nom[LEN];
    char apell[LEN];
};

struct tio {                    /* segundo patrón     */

    struct nombres maneja;      /* estructura anidada */
    char comifavo[LEN];
    char trabajo[LEN];
    float gana;
};

int main (void)
{

    static struct tio feten = { /* inicializa variable */
        {"Pepe", "Gafe"},
        "alcachofas",
        "sexador de pollos",
        3535000.00
    };

    printf ("Querido %s, \n\n", feten.maneja.nom);
    printf ("%s%s.\n", M1, feten.maneja.nom);
    printf ("%s%s\n", M2, feten.trabajo);
    printf ("%s\n", M3);
    printf ("%s%s\n%s\n\n", M4, feten.comifavo, M5);
    printf ("%40s%s\n", " ", "Hasta pronto,");
    printf ("%40s%s\n", " ", "Juanita");
    return 0;
}
