/* hashlse.c TRANSFORMACIÓN DE CLAVES.direccionamiento encadenado */
#include<stdio.h>

#define prin 10                 /* tamaño zona principal */
#define coli  13                /* hasta zona de excedentes */

typedef struct {
    int clave;
} regdatos;                     /* registro de datos */

typedef struct {
    regdatos datos;
    int activo;
    long int sig;
} regfi;                        /* registro del fichero */
int bytes = sizeof (regfi);

void leerregdatos (regdatos * r)
{                               /* leer los datos de un registro */
    char c;

    printf ("alta: ");
    scanf ("%d%c", &r->clave, &c);
}

void verregdatos (regdatos r)
{
    printf ("%4d", r.clave);
}

long int hash (int clave)
{
    return ((long) clave % prin + 1);
}

void listar (char nomfi[])
{
    FILE *f;
    regfi rf, ver[coli + 1];
    int i, n = 0;

    f = fopen (nomfi, "rb");

    if (f == NULL)
        printf ("el fichero no existe\n");
    else {
        fread (&ver[n], bytes, 1, f);

        while (!feof (f)) {
            n++;
            fread (&ver[n], bytes, 1, f);
        }                       //fin lectura del fichero

        n--;

        printf ("%60s\n", "DATOS DEL FICHERO");

        printf ("numreg");

        for (i = 0; i <= n; i++) {
            cprintf ("%4d", i);

            if (i == prin)
                cprintf ("%4c", '_');
        }

        printf ("\nactivo");

        for (i = 0; i <= n; i++) {
            cprintf ("%4d", ver[i].activo);

            if (i == prin)
                cprintf ("%4c", '_');
        }

        printf ("\nclaves");

        for (i = 0; i <= n; i++) {
            if (ver[i].datos.clave == -1)
                printf ("%4c", ' ');
            else
                cprintf ("%4d", ver[i].datos.clave);

            if (i == prin)
                cprintf ("%4c", '_');
        }

        printf ("\nsigui ");

        for (i = 0; i <= n; i++) {
            cprintf ("%4d", ver[i].sig);

            if (i == prin)
                cprintf ("%4c", '_');
        }

        printf ("\n");
    }

    fclose (f);
}

void inicializar (char nomfi[])
{
    FILE *f;
    int nr;
    regfi rf;

    f = fopen (nomfi, "w+b");   /* INICIALIZACIÓN REGISTRO VACÍO */
    rf.activo = 0;
    rf.datos.clave = -1;        /* INICIALIZACIÓN DEL REGISTRO 0 */
    nr = 0;
    rf.sig = prin + 1;
    printf ("genero registro %d\n", nr);
    fseek (f, bytes * nr, SEEK_SET);
    fwrite (&rf, bytes, 1, f);

    rf.sig = 0;                 /* INICIALIZACIÓN DE LA ZONA PRINCIPAL */

    for (nr = 1; nr <= prin; nr++) {
        fseek (f, bytes * nr, SEEK_SET);
        fwrite (&rf, bytes, 1, f);
    }

    for (nr = prin + 1; nr < coli; nr++) {  /* Inicialización zona de colisiones */
        rf.sig = nr + 1;
        fseek (f, bytes * nr, SEEK_SET);
        fwrite (&rf, bytes, 1, f);
    }

    nr = coli;
    rf.sig = 0;                 /* último registro de colisiones */
    fseek (f, bytes * nr, SEEK_SET);
    fwrite (&rf, bytes, 1, f);
    printf ("fin creación. estoy en %ld\n", ftell (f));
    fclose (f);
}

void buscar (char *nomfi, int vbus, int *hallado, long *ant, long *act)
{
    FILE *f;
    long nr;
    regfi rf;
    int busco;

    f = fopen (nomfi, "rb");

    if (f) {
        nr = hash (vbus);
        // leo registro actual
        fseek (f, bytes * nr, SEEK_SET);
        fread (&rf, bytes, 1, f);

        if (rf.activo == 0) {   // Está vacío
            *hallado = 0;
            *ant = 0;
            *act = nr;
        }
        else                    //hay un registro ACTIVO en ZP
        if (rf.datos.clave == vbus) {
            *hallado = 1;
            *ant = 0;
            *act = nr;
        }
        else {                  //buscar en colisiones
            busco = 1;
            *hallado = 0;
            *ant = nr;
            *act = rf.sig;

            while (busco && *act) {
                fseek (f, bytes * *act, SEEK_SET);
                fread (&rf, bytes, 1, f);

                if (rf.datos.clave >= vbus)
                    busco = 0;
                else {
                    *ant = *act;
                    *act = rf.sig;
                }
            }                   //while                      fin búsqueda en colisiones

            if (busco)
                *hallado = 0;
            else
                *hallado = vbus == rf.datos.clave;
        }                       // fin búsqueda en colisiones
    }                           //if(f)
    else
        printf ("no existe el fichero \n");

    fclose (f);
}

void altas (char *nomfi)
{
    FILE *f;
    regfi r0, rfant, rfact, rfalta, rf;
    int hallado;
    long ant, act, libre;

    f = fopen (nomfi, "r+b");
    leerregdatos (&rfalta.datos);
    buscar (nomfi, rfalta.datos.clave, &hallado, &ant, &act);

    if (hallado) {
        fseek (f, bytes * act, SEEK_SET);
        fread (&rf, bytes, 1, f);
        printf ("\aya existen los datos: ");
        verregdatos (rf.datos);
        printf ("\n");
    }
    else {                      // los datos NO ESTÁN. Cargar datos en registro del fichero

        if (ant == 0) {         // alta en zona principal
            rfalta.activo = 1;
            rfalta.sig = 0;
            fseek (f, bytes * act, SEEK_SET);
            fwrite (&rfalta, bytes, 1, f);
            //printf ("datos de alta en %ld \n",act);
        }
        else {                  //alta en colisiones. Si hay sitio
            //leo registro 0 para tomar celda libre
            fseek (f, 0, SEEK_SET);
            fread (&r0, bytes, 1, f);

            if (r0.sig) {       // tenemos registros libres
                //actualizo registro 0
                libre = r0.sig; //printf ("datos de alta en %ld\n",libre);
                // subo la información de libre a 0
                fseek (f, bytes * libre, SEEK_SET);
                fread (&r0, bytes, 1, f);
                fseek (f, 0, SEEK_SET);
                fwrite (&r0, bytes, 1, f);
                //printf ("modificado R0. Siguiente libre %ld\n",r0.sig);

                // escribo datos en libre
                rfalta.activo = 1;
                rfalta.sig = act;
                fseek (f, bytes * libre, SEEK_SET);
                fwrite (&rfalta, bytes, 1, f);
                //printf ("datos escritos en %ld\n",libre);
                //printf ("siguiente registro al actual %ld",r0.sig);

                // enlazo con anterior
                fseek (f, bytes * ant, SEEK_SET);
                fread (&rfant, bytes, 1, f);
                rfant.sig = libre;  // enlazo con colisión anterior
                fseek (f, bytes * ant, SEEK_SET);
                fwrite (&rfant, bytes, 1, f);
                //printf ("rfant.sig= %ld \n",rfant.sig);
            }
            else
                printf ("No hay espacio disponible en fichero \n");
        }
    }

    fclose (f);
}                               // altas

void bajas (char *nomfi)
{
    FILE *f;
    int kbaja, hallado;
    regfi r0, rf, rfant, rfact;
    long ant, act, libre;

    f = fopen (nomfi, "r+b");

    if (f) {
        printf ("baja: ");
        scanf ("%d", &kbaja);
        buscar (nomfi, kbaja, &hallado, &ant, &act);

        if (!hallado)
            printf ("no existen los datos\n");
        else {
            // el registro está en el fichero en registro 'act'
            fseek (f, bytes * act, SEEK_SET);
            fread (&rfact, bytes, 1, f);
            rfact.datos.clave = -1;

            if (ant == 0) {     // baja en zona principal

                if (rfact.sig == 0) {   // no tiene siguiente en colisiones
                    rfact.activo = 0;
                    fseek (f, bytes * act, SEEK_SET);
                    fwrite (&rfact, bytes, 1, f);
                }
                else {
                    //subir primera colisión
                    libre = rfact.sig;
                    fseek (f, bytes * libre, SEEK_SET);
                    fread (&rf, bytes, 1, f);
                    fseek (f, bytes * act, SEEK_SET);
                    fwrite (&rf, bytes, 1, f);
                    // actualizar r0
                    fseek (f, bytes * 0, SEEK_SET);
                    fread (&r0, bytes, 1, f);
                    rf.sig = r0.sig;
                    rf.datos.clave = -1;
                    fseek (f, bytes * libre, SEEK_SET);
                    fwrite (&rf, bytes, 1, f);
                    r0.sig = libre;
                    fseek (f, 0, SEEK_SET);
                    fwrite (&r0, bytes, 1, f);
                }
            }
            else {              // baja en colisiones
                //actualizo enlace con registro anterior
                fseek (f, bytes * ant, SEEK_SET);
                fread (&rfant, bytes, 1, f);
                // su siguiente será el siguiente de actual
                rfant.sig = rfact.sig;
                // actualizo anterior
                fseek (f, bytes * ant, SEEK_SET);
                fwrite (&rfant, bytes, 1, f);

                // actualizo libre 'act'
                fseek (f, bytes * 0, SEEK_SET);
                fread (&r0, bytes, 1, f);
                rfact.sig = r0.sig;
                fseek (f, bytes * act, SEEK_SET);
                fwrite (&rfact, bytes, 1, f);
                // actualizo registro 0
                r0.sig = act;
                fseek (f, bytes * 0, SEEK_SET);
                fwrite (&r0, bytes, 1, f);

            }
        }
    }
    else
        printf ("no puedo abrir para bajar. ERROR ");

    fclose (f);
}                               // bajas

void main (void)
{
    char nomfichero[60], c;
    int opc;

    strcpy (nomfichero, "atomos.dat");

    remove (nomfichero);

    inicializar (nomfichero);

    do {
        cprintf ("0-FIN  1-Altas 2-baja OPCION: ");
        scanf ("%d%c", &opc, &c);

        switch (opc) {

            case 1:
                altas (nomfichero);
                break;

            case 2:
                bajas (nomfichero);
                break;
        }

        //printf ("Pulse una tecla..\n"); getch();
        listar (nomfichero);

        printf ("\n\n");
    }
    while (opc);

    //fclose(f);
    printf ("fin de programa.PULSE TECLA...\n");
}
