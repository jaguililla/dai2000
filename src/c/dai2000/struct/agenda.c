#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
////////////////////////////////////////////////////////////////////////////
typedef struct {
    char nombre[15], ape[20], direc[25];
    int edad;
} people;
int reg = 0;

void vaciar (people array[])
{
    int cont;

    for (cont = 0; cont < 15; cont++)
        array[reg].nombre[cont] = 255;
    for (cont = 0; cont < 20; cont++)
        array[reg].ape[cont] = 255;
    for (cont = 0; cont < 25; cont++)
        array[reg].direc[cont] = 255;
}

////////////////////////////////////////////////////////////////////////////
void agregar (people array[])
{
    int pos = 1, indice, hallado = 0;

    printf ("Introduzca datos:\n");
    printf ("Nombre: ");
    gets (array[0].nombre);
    array[0].nombre[0] = toupper (array[0].nombre[0]);
    printf ("Apellido: ");
    gets (array[0].ape);
    printf ("Dirección: ");
    gets (array[0].direc);
    printf ("Edad: ");
    scanf ("%d", &(array[0].edad));
    vaciar (array);
    if (reg != 1) {
        pos = busca (array, &hallado);
        for (indice = reg; indice >= pos; indice--) {
            strcpy (array[indice].nombre, array[indice - 1].nombre);
            strcpy (array[indice].ape, array[indice - 1].ape);
            strcpy (array[indice].direc, array[indice - 1].direc);
            array[indice].edad = array[indice - 1].edad;
        }
    }
    strcpy (array[pos].nombre, array[0].nombre);    //1º donde y luego el que
    array[pos].nombre[0] = toupper (array[pos].nombre[0]);
    strcpy (array[pos].ape, array[0].ape);
    array[pos].ape[0] = toupper (array[pos].ape[0]);
    strcpy (array[pos].direc, array[0].direc);
    array[pos].direc[0] = toupper (array[pos].direc[0]);
    array[pos].edad = array[0].edad;
    printf ("\nSe ha dado de alta satisfactoriamente.");
}

////////////////////////////////////////////////////////////////////////////)
void borrar (people array[])
{
    int indice, pos, hallado = 0;
    char resp;

    printf ("Introduzca el nombre a dar de baja: ");
    gets (array[0].nombre);
    array[0].nombre[0] = toupper (array[0].nombre[0]);
    pos = busca (array, &hallado);
    if (hallado == 1) {
        printf ("¿Está seguro de querer eliminar este registro?(s/n);");
        do {
            resp = getche ();
            //scanf("%s%c",&resp);
            resp = tolower (resp);
            if ((resp != 's') && (resp != 'n'))
                printf ("\n(s/n): ");
        } while ((resp != 's') && (resp != 'n'));
        if (resp == 's') {
            for (indice = pos; indice <= reg; indice++) {
                strcpy (array[indice].nombre, array[indice + 1].nombre);
                strcpy (array[indice].ape, array[indice + 1].ape);
                strcpy (array[indice].direc, array[indice + 1].direc);
                array[indice].edad = array[indice + 1].edad;
            }
            reg--;
            printf ("\nEl registro ha sido dado de baja");
        }
    }
    else
        printf ("\nEl registro no se encuentra.");
}

//////////////////////////////////////////////////////////////////////////////
void modificar (people array[])
{
    int pos, hallado = 0, indice;
    char resp;

    printf ("Introduzca el nombre del registro a modificar: ");
    gets (array[0].nombre);
    array[0].nombre[0] = toupper (array[0].nombre[0]);
    pos = busca (array, &hallado) - 1;
    if (hallado != 0) {
        printf ("¿Está seguro de que desea modificar este registro?(s/n): ");
        do {
            resp = getche ();
            if ((resp != 's') && (resp != 'n'))
                printf ("\n(s/n): ");
        } while ((resp != 's') && (resp != 'n'));
        if (resp == 's') {
            printf ("\nNombre: ");
            puts (array[pos].nombre);
            printf ("Nuevo nombre: ");
            gets (array[0].nombre);
            printf ("Apellido: ");
            puts (array[pos].ape);
            printf ("Nuevo apellido: ");
            gets (array[0].ape);
            printf ("Dirección: ");
            puts (array[pos].direc);
            printf ("Nueva dirección: ");
            gets (array[0].direc);
            printf ("Edad: ");
            printf ("%d", array[pos].edad);
            printf ("\nNueva edad: ");
            scanf ("%d", array[0].edad);
            fflush (stdin);
            for (indice = pos; indice <= reg; indice++) {
                strcpy (array[indice].nombre, array[indice + 1].nombre);
                strcpy (array[indice].ape, array[indice + 1].ape);
                strcpy (array[indice].direc, array[indice + 1].direc);
                array[indice].edad = array[indice + 1].edad;
            }                   //lo borra
            if (reg != 1) {
                pos = busca (array, &hallado);
                for (indice = reg; indice >= pos; indice--) {
                    strcpy (array[indice].nombre, array[indice - 1].nombre);
                    strcpy (array[indice].ape, array[indice - 1].ape);
                    strcpy (array[indice].direc, array[indice - 1].direc);
                    array[indice].edad = array[indice - 1].edad;
                }
            }
            strcpy (array[pos].nombre, array[0].nombre);    //1º donde y luego el que
            array[pos].nombre[0] = toupper (array[pos].nombre[0]);
            strcpy (array[pos].ape, array[0].ape);
            array[pos].ape[0] = toupper (array[pos].ape[0]);
            strcpy (array[pos].direc, array[0].direc);
            array[pos].direc[0] = toupper (array[pos].direc[0]);
            array[pos].edad = array[0].edad;

            printf ("Registro modificado.");
        }
    }
    else
        printf ("No se ha encontrado el registro.");
}

//////////////////////////////////////////////////////////////////////////////
int busca (people array[], int *hallado)
{
    int central, EI = 1, ES = reg, dicci;

    do {
        central = (EI + ES) / 2;
        dicci = strcmp (array[0].nombre, array[central].nombre);
        if (dicci == 0) {
            *hallado = 1;
            return (central + 1);
        }
        else if (dicci > 0)
            EI = central + 1;
        else
            ES = central - 1;
    } while ((EI <= ES) && (*hallado == 0));
    //printf ("EI= %d",EI);
    return (EI);                //devuelve EI porque siempre lo inserta a la derecha
}

//////////////////////////////////////////////////////////////////////////////
void filtrar (people array[])
{
    int indice, cont, valor = 1;
    char cadena[16];

    if (reg > 0) {
        printf ("Introduzca nombre: ");
        gets (cadena);
        cadena[0] = toupper (cadena[0]);
        for (indice = 1; indice <= reg; indice++) {
            if (strcmp (cadena, array[indice].nombre) == 0) {
                printf ("Registro %d\n", valor);
                printf (" Nombre: ");
                puts (array[indice].nombre);
                printf (" Apellido: ");
                puts (array[indice].ape);
                printf (" Dirección: ");
                puts (array[indice].direc);
                printf (" Edad: %d", array[indice].edad);
                if (indice < reg)
                    printf ("\n\n\n");
                valor++;
                if (valor % 3 == 0)
                    getch ();
            }
        }
    }
    else
        printf ("La agenda está vacía.");
    if (reg % 3 != 0)
        getch ();

}

////////////////////////////////////////////////////////////////////////////
void listar (people array[])
{
    int indice, cont;

    if (reg > 0) {
        for (indice = 1; indice <= reg; indice++) {
            printf ("Registro %d\n", indice);
            printf (" Nombre: ");
            puts (array[indice].nombre);
            printf (" Apellido: ");
            puts (array[indice].ape);
            printf (" Dirección: ");
            puts (array[indice].direc);
            printf (" Edad: %d", array[indice].edad);
            if (indice < reg)
                printf ("\n\n\n");
            if (indice % 3 == 0)
                getch ();
        }
    }
    else
        printf ("La agenda está vacía.");
    if (reg % 3 != 0)
        getch ();
}

////////////////////////////////////////////////////////////////////////////
void main (void)
{
    people gente[10];
    int indice, cont, resp, valor = 0;

    printf ("Bienvenido a la agenda electrónica de estos de aquí.\n");
    do {
        printf ("Seleccione una opción:\n");
        printf ("\t1.- Agregar.\n");
        printf ("\t2.- Borrar.\n");
        printf ("\t3.- Modificar\n");
        printf ("\t4.- Listar.\n");
        printf ("\t5.- Filtrar.\n");
        printf ("\t6.- Salir\n");
        printf ("Ha elegido: ");
        scanf ("%d", &resp);
        fflush (stdin);         //o "%d%c"
        switch (resp) {
            case 1:
                if (reg < 10) {
                    reg++;
                    agregar (gente);
                }
                else {
                    printf
                        ("La agenda está completa.\nDe un registro de baja e inténtelo de nuevo.");
                }
                getch ();
                break;
            case 2:
                if (reg > 0) {
                    borrar (gente);
                }
                else {
                    printf ("La agenda está vacía. No se puede dar de baja.");
                }
                getch ();
                break;
            case 3:
                if (reg != 0)
                    modificar (gente);
                else
                    printf ("La agenda está vacía.No se puede modificar.");
                getch ();
                break;
            case 4:
                listar (gente);
                break;
            case 5:
                filtrar (gente);
                break;
            case 6:
                valor++;
                break;
        }
    } while (valor != 1);
    gotoxy (30, 10);
    printf ("Hasta la próxima vez.");
    delay (100);
    for (indice = 29; indice < 50; indice++) {
        gotoxy (indice, 10);
        delay (100);
        printf (" ");
    }
    delay (50);
}
