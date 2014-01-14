// A C C E S O   D I R E C T O ///////////////////////////////////////////////
// Tratamiento de ficheros de acceso directo por transformación de claves   //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>


// D E F I N E S /////////////////////////////////////////////////////////////
#define REGISTROS 10            // Registros de la zona principal
#define COLISIONES ((REGISTROS*30)/100) // Colisiones (30% de registros)
#define SI 1
#define NO 0

// M A C R O S ///////////////////////////////////////////////////////////////
#define posicion(CLAVE)\
            (CLAVE%REGISTROS)   // Calcula posición de una clave

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct {
    int activo;                 // Indica si el registro está ocupado
    int clave;                  // Determina pos del registro (!= 0)
    int dato;
    int sgte;                   // Posición de la siguiente colisión
} registro;                     // Tipo de un registro

// P R O T O T I P O S ///////////////////////////////////////////////////////
void inicializa (char *nomfich);    // Inicializa los valores de archivo
void menu (void);               // Imprime el menú en pantalla
void lista (char *nomfich);     // Saca un listado del fichero
void alta (char *nomfich);      // Da de alta un registro
void baja (char *nomfich);      // Da de baja un registro

// F U N C I O N E S //////
void inicializa (char *nomfich)
{
    int cont = 0;
    registro regaux;
    FILE *fiche;

    fiche = fopen (nomfich, "wb");
    regaux.activo = NO;         // Datos comunes de todos los
    regaux.clave = 0;           // registros
    regaux.dato = 0;
    regaux.sgte = REGISTROS + 1;    // Indice (1ª pos libre)
    fwrite (&regaux, sizeof (registro), 1, fiche);  // Graba registro indice (0)
    for (cont = 1; cont <= REGISTROS + COLISIONES; cont++) {
        if (cont <= REGISTROS || cont == REGISTROS + COLISIONES)
            regaux.sgte = 0;    // Si el reg está en zona ppal o es el último
        else
            regaux.sgte = cont + 1; // Si el reg está en zona de colisiones
        fwrite (&regaux, sizeof (registro), 1, fiche);
    }
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void menu (void)
{
    clrscr ();
    gotoxy (3, 2);
    printf ("Acceso Directo por Transformación de Claves\n\n");
    printf ("\t1.- Insertar registro\n");
    printf ("\t2.- Borrar registro\n");
    printf ("\t3.- Salir\n");
}

//////////////////////////////////////////////////////////////////////////////
void lista (char *nomfich)
{
    int cont = 0;
    registro regaux;
    FILE *fiche;

    fiche = fopen (nomfich, "rb");
    printf ("\n\tPos\tActivo\tClave\tDato\tSiguiente\n");
    printf ("\t---\t------\t-----\t----\t---------\n");
    for (cont = 0; cont <= REGISTROS + COLISIONES; cont++) {
        fread (&regaux, sizeof (registro), 1, fiche);
        printf ("\t%d\t%s\t%d\t%d\t%d\n", cont, (regaux.activo) ? "SI" : "NO",
                regaux.clave, regaux.dato, regaux.sgte);
        if (cont == 10)
            printf ("\n");      // Si zona de colisiones dejar una ln
    }
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void alta (char *nomfich)
{
    FILE *fiche;
    registro regaux, regalta, indice;
    int posi = 0, sgte1, posi2, band = 0;

    // Abre el fichero
    fiche = fopen (nomfich, "r+b");
    // Lee el indice
    fread (&indice, sizeof (registro), 1, fiche);
    // Introduce la clave
    printf ("Introduce la clave y el dato del registro: ");
    scanf ("%d %d", &regalta.clave, &regalta.dato);
    // Calcula la posición de la clave
    posi = posicion (regalta.clave);
    if (posi == 0)
        posi = 10;
    // Lee el registro de esa posición
    fseek (fiche, posi * sizeof (registro), SEEK_SET);
    fread (&regaux, sizeof (registro), 1, fiche);
    // Se posiciona posi en el último registro con un valor
    posi2 = posi;
    if (regaux.activo) {
        if (regaux.sgte)

            while (regaux.sgte) {
                posi = regaux.sgte;
                fseek (fiche, posi * sizeof (registro), SEEK_SET);
                fread (&regaux, sizeof (registro), 1, fiche);
                posi2 = posi;
            }

        if (regaux.clave == regalta.clave)
            band = 1;
        else {
            posi = indice.sgte;
            regaux.sgte = indice.sgte;
            fseek (fiche, posi2 * sizeof (registro), SEEK_SET);
            fwrite (&regaux, sizeof (registro), 1, fiche);
        }
    }
    if (!band) {
        // Completa el registro
        regalta.activo = SI;
        regalta.sgte = 0;
        // Decide según está en z. principal o de colisiones
        if (posi) {

            if (posi > REGISTROS) {
                fseek (fiche, posi * sizeof (registro), SEEK_SET);
                fread (&regaux, sizeof (registro), 1, fiche);
                indice.sgte = regaux.sgte;
                fseek (fiche, 0, SEEK_SET);
                fwrite (&indice, sizeof (registro), 1, fiche);
            }

            fseek (fiche, posi * sizeof (registro), SEEK_SET);
            fwrite (&regalta, sizeof (registro), 1, fiche); // 1º registro libre

            printf ("Registro dado de alta.\n");
        }
        else
            printf ("No hay espacio.");
    }
    else
        printf ("La clave ya existe.");
    getch ();
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void baja (char *nomfich)
{
    FILE *fiche;
    registro regbaja, regaux, regaux2, regaux3, indice;
    int num, posi, posi2 = 0, aux;

    fiche = fopen (nomfich, "r+b");
    printf ("Introduzca la clave a dar de baja: ");
    scanf ("%d", &num);

    fseek (fiche, 0, SEEK_SET);
    fread (&indice, sizeof (registro), 1, fiche);
    regaux.sgte = indice.sgte;
    regaux.activo = NO;
    regaux.clave = 0;
    regaux.dato = 0;

    posi = posicion (num);
    fseek (fiche, posi * sizeof (registro), SEEK_SET);
    fread (&regbaja, sizeof (registro), 1, fiche);
    if (regbaja.activo) {
        while ((num != regbaja.clave) && (regbaja.sgte)) {
            posi2 = posi;
            posi = regbaja.sgte;
            fseek (fiche, posi * sizeof (registro), SEEK_SET);
            fread (&regbaja, sizeof (registro), 1, fiche);
        }
        if (num == regbaja.clave) {
            if (posi2) {        //zona de colisiones
                fseek (fiche, posi * sizeof (registro), SEEK_SET);
                fread (&regaux3, sizeof (registro), 1, fiche);
                fseek (fiche, posi2 * sizeof (registro), SEEK_SET);
                fread (&regaux2, sizeof (registro), 1, fiche);

                aux = regaux2.sgte;
                regaux2.sgte = regaux3.sgte;
                regaux.sgte = indice.sgte;
                indice.sgte = aux;

                fseek (fiche, 0, SEEK_SET);
                fwrite (&indice, sizeof (registro), 1, fiche);

                fseek (fiche, posi2 * sizeof (registro), SEEK_SET);
                fwrite (&regaux2, sizeof (registro), 1, fiche);
                fseek (fiche, posi * sizeof (registro), SEEK_SET);
                fwrite (&regaux, sizeof (registro), 1, fiche);

            }
            else {              //zona principal
                if (regbaja.sgte) { //si tiene continuacion
                    fseek (fiche, regbaja.sgte * sizeof (registro), SEEK_SET);
                    fread (&regaux2, sizeof (registro), 1, fiche);
                    fseek (fiche, regbaja.sgte * sizeof (registro), SEEK_SET);
                    fwrite (&regaux, sizeof (registro), 1, fiche);

                    fseek (fiche, posi * sizeof (registro), SEEK_SET);
                    fwrite (&regaux2, sizeof (registro), 1, fiche);
                    fseek (fiche, 0, SEEK_SET);
                    indice.sgte = regbaja.sgte;
                    fwrite (&indice, sizeof (registro), 1, fiche);
                }
                else {          //si sólo está esa clave
                    regaux.sgte = 0;
                    fseek (fiche, posi * sizeof (registro), SEEK_SET);
                    fwrite (&regaux, sizeof (registro), 1, fiche);
                }
            }
            printf ("Registro dado de baja.");
        }
        else
            printf ("No se ha encontrado la clave dada.");
    }
    else
        printf ("La clave especificada no estaba dada de alta.");
    getch ();
    fclose (fiche);
}

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int op = 0, seguir = SI;
    char *fichero = NULL;

    clrscr ();
    printf ("Introduce el nombre del fichero a escribir: ");
    gets (fichero);
    clrscr ();
    inicializa (fichero);
    do {
        menu ();
        lista (fichero);
        printf ("Su opción es: ");
        op = getch ();
        switch (op) {
            case '1':
                alta (fichero);
                break;
            case '2':
                baja (fichero);
                break;
            case '3':
                seguir = NO;
                break;
            default:
                printf ("Opción no valida");
                break;
        }
    }
    while (seguir);
}

//////////////////////////////////////////////////////////////////////////////
