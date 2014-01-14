/* nombres1.c -- usa punteros a estructuras */
#include <stdio.h>

struct nombrect {
    char nombre[20];
    char apell[20];
    int letras;
};

void tomainfo (struct nombrect *);

void creainfo (struct nombrect *);

void sacainfo (struct nombrect *);
int main (void)
{

    struct nombrect persona;

    tomainfo (&persona);
    creainfo (&persona);
    sacainfo (&persona);
    return 0;
}

void tomainfo (struct nombrect *pst)
{
    printf ("Introduzca su nombre.\n");
    gets (pst->nombre);
    printf ("Introduzca su apellido.\n");
    gets (pst->apell);
}

void creainfo (struct nombrect *pst)
{
    pst->letras = strlen (pst->nombre) + strlen (pst->apell);
}

void sacainfo (struct nombrect *pst)
{
    printf ("%s %s, su nombre contiene %d letras.",
            pst->nombre, pst->apell, pst->letras);
}
