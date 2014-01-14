/* nombres2.c -- pasa y devuelve estructuras */
#include <stdio.h>

struct nombrect {
    char nombre[20];
    char apell[20];
    int letras;
};

struct nombrect tomainfo (void);

struct nombrect creainfo (struct nombrect);

void sacainfo (struct nombrect);
int main (void)
{

    struct nombrect persona;

    persona = tomainfo ();
    persona = creainfo (persona);
    sacainfo (persona);
    return 0;
}

struct nombrect tomainfo (void)
{

    struct nombrect temp;

    printf ("Introduzca su nombre.\n");
    gets (temp.nombre);
    printf ("Introduzca su apellido.\n");
    gets (temp.apell);
    return temp;
}

struct nombrect creainfo (struct nombrect info)
{
    info.letras = strlen (info.nombre) + strlen (info.apell);
    return info;
}

void sacainfo (struct nombrect info)
{
    printf ("%s %s, su nombre contiene %d letras.",
            info.nombre, info.apell, info.letras);
}
