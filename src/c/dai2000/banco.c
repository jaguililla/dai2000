#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct banco {
    int ncc, importe;
} cuenta, i;

void nueva (char cad[]);
void operacion (char cad[]);
void actualiza (char cad1[], char cad2[]);
void visualiza (char cad[]);
int ultimo (char cad[]);

void main (void)
{
    int val, indice, bandera = 0;
    char resp;
    FILE *movs;

    clrscr ();
    i.ncc = 0;
    printf ("\nBienvenido al Banco de Peces.\n");

    do {
        printf ("\n\t1.-Cuenta nueva.\n");
        printf ("\t2.-Realizar una operación.\n");
        printf ("\t3.-Actualizar fichero maestro.\n");
        printf ("\t4.-Ver fichero maestro.\n");
        printf ("\t5.-Ver últimas operaciones.\n");
        printf ("\t6.-Salir.\n\n");
        printf ("Su elección es: ");
        scanf ("%d", &val);

        switch (val) {

            case 1:
                nueva ("maestro.dat");
                break;

            case 2:
                operacion ("movis.dat");
                bandera = 1;
                break;

            case 3:

                if (bandera) {
                    actualiza ("maestro.dat", "movis.dat");
                    printf ("Fichero actualizado.");
                    bandera = 0;
                }
                else
                    printf ("No hay nuevos movimientos.");

                getch ();

                break;

            case 4:
                visualiza ("maestro.dat");

                getch ();

                break;

            case 5:
                if (bandera)
                    visualiza ("movis.dat");
                else
                    printf ("No hay nuevos movimientos.");

                getch ();

                break;

            case 6:
                if (bandera) {
                    printf
                        ("Las últimas operaciones serán borradas.\n¿Desea salvarlas antes de salir de la aplicación?(s/n): ");
                    resp = getche ();
                    resp = tolower (resp);

                    if (resp == 's') {
                        actualiza ("maestro.dat", "movis.dat");
                    }
                    else
                        remove ("movis.dat");
                }

                clrscr ();
                gotoxy (30, 10);
                printf ("Hasta la próxima vez.");
                delay (100);

                for (indice = 29; indice < 50; indice++) {
                    gotoxy (indice, 10);
                    delay (100);
                    printf (" ");
                }

                delay (50);
                break;

            default:
                printf ("\nIntroduzca una opción válida.");
                delay (1000);
                break;
        }

        clrscr ();
    }
    while (val != 6);
}

void nueva (char cad[])
{
    FILE *fiche;

    struct banco i;
    int i2, dig;

    fiche = fopen (cad, "ab");

    if (fiche == NULL)
        printf ("No hay memoria.");
    else {
        i2 = ultimo (cad);
        cuenta.ncc = i2 + 1;
        printf ("Introduzca el importe para abrir la cuenta: ");

        do {
            scanf ("%d", &cuenta.importe);
            dig = digito (cuenta.importe);

            if (dig == 0)
                printf ("Introduzca sólo números: ");
        }
        while (dig == 0);

        fwrite (&cuenta, sizeof (struct banco), 1, fiche);

        printf ("Cuenta dada de alta.");
    }

    getch ();
    fclose (fiche);
}

void operacion (char cad[])
{
    FILE *fiche;
    int num, dig;

    fiche = fopen (cad, "ab");

    if (fiche == NULL)
        printf ("No hay memoria.");
    else {
        do {
            printf ("Introduzca el número de cuenta: ");

            do {
                scanf ("%d", &cuenta.ncc);
                dig = digito (cuenta.ncc);

                if (dig == 0)
                    printf ("Introduzca sólo números: ");
            }
            while (dig == 0);

            num = ultimo ("maestro.dat");

            if (cuenta.ncc > num)
                printf ("El número de cuenta no existe.");
        }
        while (cuenta.ncc > num);

        printf ("Introduzca el importe de la operación: ");

        do {
            scanf ("%d", &cuenta.importe);
            dig = digito (cuenta.importe);

            if (dig == 0)
                printf ("Introduzca sólo números: ");
        }
        while (dig == 0);

        fwrite (&cuenta, sizeof (struct banco), 1, fiche);

        printf ("Movimiento aceptado.");
    }

    getch ();
    fclose (fiche);
}

void actualiza (char cad1[], char cad2[])
{
    FILE *mae, *mov, *aux;

    struct banco m, n;
    int pasta = 0;

    aux = fopen ("auxilio.dat", "wb");
    mae = fopen (cad1, "rb");

    fread (&m, sizeof (struct banco), 1, mae);

    while (!feof (mae)) {
        mov = fopen (cad2, "rb");
        pasta = m.importe;

        fread (&n, sizeof (struct banco), 1, mov);

        while (!feof (mov)) {
            if (m.ncc == n.ncc)
                pasta += n.importe;

            fread (&n, sizeof (struct banco), 1, mov);
        }

        fclose (mov);
        m.importe = pasta;

        fwrite (&m, sizeof (struct banco), 1, aux);

        fread (&m, sizeof (struct banco), 1, mae);
    }

    fclose (mae);
    fclose (aux);
    aux = fopen ("auxilio.dat", "rb");
    mae = fopen (cad1, "wb");

    fread (&i, sizeof (struct banco), 1, aux);

    while (!feof (aux)) {

        fwrite (&i, sizeof (struct banco), 1, mae);

        fread (&i, sizeof (struct banco), 1, aux);
    }

    fclose (aux);
    fclose (mov);

    remove ("auxilio.dat");

    remove (cad2);

    fclose (mae);
}

void visualiza (char cad[])
{
    FILE *fiche;

    struct banco tamano;

    fiche = fopen (cad, "rb");

    fread (&tamano, sizeof (struct banco), 1, fiche);

    while (!feof (fiche)) {
        printf ("Cuenta Nº %2d \t Importe: %4d\n", tamano.ncc, tamano.importe); //problema con los nombres

        fread (&tamano, sizeof (struct banco), 1, fiche);
    }

    fclose (fiche);

}

int ultimo (char cad[])
{
    int num;
    FILE *archi;

    archi = fopen (cad, "rb");

    fread (&i, sizeof (struct banco), 1, archi);

    while (!feof (archi)) {

        fread (&i, sizeof (struct banco), 1, archi);
    }

    num = i.ncc;
    return (num);
}

int digito (int num)
{
    if (isdigit (num))
        return (0);

    return (1);
}
