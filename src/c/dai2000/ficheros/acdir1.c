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
            ((CLAVE%REGISTROS)+1)   // Calcula posición de una clave

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

// F U N C I O N E S /////////////////////////////////////////////////////////
void inicializa (char *nomfich)
{
    int cont = 0;
    registro regaux;
    FILE *fiche;

    fiche = fopen (nomfich, "wb");
    regaux.activo = NO;         // Datos comunes de todos los
    regaux.clave = 0;           // registros
    regaux.dato = 0;
    regaux.sgte = REGISTROS + 1;    // Indice (1º pos libre)
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
    int posi = 0, sgte1;

    // Abre el fichero
    fiche = fopen (nomfich, "r+b");
    // Lee el indice
    fread (&indice, sizeof (registro), 1, fiche);
    // Introduce la clave
    printf ("Introduce la clave y el dato del registro: ");
    scanf ("%d %d %c", &regalta.clave, &regalta.dato);
    // Calcula la posición de la clave
    posi = posicion (regalta.clave);
    // Lee el registro de esa posición
    fseek (fiche, posi * sizeof (registro), SEEK_SET);
    fread (&regaux, sizeof (registro), 1, fiche);
    // Se posiciona posi en el último registro con un valor
    while (regaux.activo && regaux.sgte) {
        posi = regaux.sgte;
        fseek (fiche, posi * sizeof (registro), SEEK_SET);
        fread (&regaux, sizeof (registro), 1, fiche);
    }
    // Ajustar la lista de espacios libres
    fseek (fiche, (indice.sgte) * sizeof (registro), SEEK_SET);
    fread (&regaux, sizeof (registro), 1, fiche);   // 1º registro libre
    sgte1 = regaux.sgte;

    regalta.activo = SI;
    regalta.sgte = 0;
    //se situa en el registro a dar de alta y lo escribe
    fseek (fiche, (indice.sgte) * sizeof (registro), SEEK_SET);
    fwrite (&regalta, sizeof (registro), 1, fiche);

    indice.sgte = sgte1;
    fseek (fiche, 0, SEEK_SET);
    fwrite (&indice, sizeof (registro), 1, fiche);
    printf ("Registro dado de alta.\n");

}

//////////////////////////////////////////////////////////////////////////////

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
