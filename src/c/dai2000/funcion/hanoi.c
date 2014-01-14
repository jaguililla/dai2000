#include <stdio.h>


void moverdisco (int origen, int destino)
{
    /* Traslada un solo disco desde el origen al destino */
    printf ("TRASLADAR UN DISCO DESDE EL POSTE %3d HASTA EL POSTE %3d\n",
            origen, destino);
}

void transferir (int n, int origen, int destino, int otro)
{
    if (n > 0) {
        transferir (n - 1, origen, otro, destino);
        moverdisco (origen, destino);
        transferir (n - 1, otro, destino, origen);
    }
}

int main (argc, argv)
     int argc;
     char *argv[];
{
    int n;

    clrscr ();
    printf ("Introduzca número de discos en juego: ");
    scanf ("%d", &n);
    printf ("Para %d discos los movimientos sucesivos son:\n");
    transferir (n, 1, 3, 2);
}
