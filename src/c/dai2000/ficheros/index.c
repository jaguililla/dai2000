// F I C H E R O S   I N D E X A D O S ///////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

#include <string.h>

// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1
#define NO 0

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct nodo {
    char *dni;                  // Clave
    int pos;                    // Posición en el registro de datos
    struct nodo *izq, *der;
} nodo;                         // Estructura del árbol (índice) en memoria

typedef struct {
    char *dni;
    int pos;
} tipoind;                      // Estructura del indice en el fichero

typedef struct {
    char *nom;
    int edad;
    int libre;
} tiporeg;                      // Estructura de un registro de datos en el disco

// P R O T O T I P O S ///////////////////////////////////////////////////////

// Funciones de árboles
void buscar (nodo * raiz, char *val, nodo ** ant, nodo ** act, int *hallado);
void insertar (nodo ** raiz, char *dni, int pos);
void borrar (nodo ** raiz, char *dni);
void inorden (nodo * raiz, FILE * fiche);
void preorden (nodo * raiz);
void postorden (nodo * raiz);

// Funciones del fichero
void inicializa (char *nomfich);
void cargaind (char *nomfich, nodo ** indice);
void alta (char *nomfich, nodo ** indice);
void baja (char *nomfich, nodo ** indice);
void lista (char *nomfich, nodo * indice);

// F U N C I O N E S /////////////////////////////////////////////////////////
void buscar (nodo * raiz, char *val, nodo ** ant, nodo ** act, int *hallado)
{
    *hallado = NO;
    *act = raiz;
    *ant = NULL;
    while (*act && !(*hallado)) {
        if ((strcmp (val, (*act)->dni)) == 0)
            *hallado = SI;
        else {
            *ant = *act;
            if ((strcmp (val, (*act)->dni)) > 0)
                *act = (*act)->izq;
            else if ((strcmp (val, (*act)->dni)) < 0)
                *act = (*act)->der;
        }
    }
}

// Fin buscar() //////////////////////////////////////////////////////////////
void insertar (nodo ** raiz, char *dni, int pos)
{
    nodo *nuevo;
    nodo *ant, *act;
    int hallado = NO;

    // Reserva memoria para el nuevo elemento e inicializa sus enlaces
    nuevo = (nodo *) malloc (sizeof (nodo));
    if (!nuevo) {
        gotoxy (20, 10);
        printf ("No hay suficiente memoria disponible");
        exit (1);
    }
    nuevo->izq = NULL;
    nuevo->der = NULL;
    // Comprueba q el elemento no existe y devuelve su posición de inserción
    buscar (*raiz, nuevo->dni, &ant, &act, &hallado);
    if (strcmp (act->dni, dni) == 0) {
        printf ("La clave está repetida");
    }
    else {
        strcpy (nuevo->dni, dni);
        nuevo->pos = pos;
        // Conecta el nuevo elemento en el subárbol del nodo correspondiente
        if (ant)                // árbol con algún elemento
        {
            if (strcmp (act->dni, dni) > 0)
                act->der = nuevo;
            else
                act->izq = nuevo;
        }
        else {                  // árbol vacio
            *raiz = nuevo;
        }
    }
}

// Fin inserta() /////////////////////////////////////////////////////////////
void borrar (nodo ** raiz, char *dni)
{
    nodo *ant = NULL, *act = NULL;
    int valor = 0, hallado = NO;

    do {
        gotoxy (10, 10);
        printf ("Introduce el valor a eliminar: ");
        scanf ("%d", &valor);
        buscar (*raiz, dni, &ant, &act, &hallado);
        if (hallado)
            printf ("¡¡¡ El valor introducido ya existe !!!");
    }
    while (hallado);
}

//////////////////////////////////////////////////////////////////////////////
void bajaarbol (struct nodo **r, char *dni)
{
    int hallado = 0;
    char *mayor;
    nodo *ant, *act, *aux, *aux2;

//void buscar (nodo *raiz, char *val, nodo **ant, nodo **act, int *hallado)
    buscar (*r, dni, &ant, &act, &hallado);
    if (act) {                  //si lo ha encontrado
        if ((!act->izq) && (!act->der)) //sin hijos
            if (ant)
                if (strcmp (act->dni, ant->dni) > 0)
                    ant->der = NULL;
                else
                    ant->izq = NULL;
            else {              //un hijo
                if ((act->der) && (!act->izq))
                    if (ant)
                        if (strcmp (act->dni, ant->dni) > 0)
                            ant->der = act->der;
                        else
                            ant->izq = act->der;
                    else
                        *r = act->der;
                if ((act->izq) && (!act->der))
                    if (ant)
                        if (strcmp (act->dni, ant->dni) > 0)
                            ant->der = act->izq;
                        else
                            ant->izq = act->izq;
                    else
                        *r = act->izq;
                else {          //dos hijos
                    aux = act->izq;
                    mayor = aux->dni;
                    while (aux->der) {
                        aux2 = aux;
                        aux = aux->der;
                        mayor = aux->dni;
                    }
                    act->dni = mayor;
                    if (aux->izq)
                        aux2->der = aux->izq;
                    act = aux;
                }
            }
        free (act);
    }
    else {
        printf ("No se ha podido encontrar la clave.");
    }
}

void baja (char *nomfich, nodo ** r)
{
    FILE *fiche;
    char *aux;
    nodo *pun;
    int esta = 0, borrar;
    tiporeg indice;

    fiche = fopen (nomfich, "r+b");
    fflush (stdin);
    printf ("introducir clave a dar de baja: ");
    gets (aux);
    pun = *r;
    while (!esta && pun != NULL) {
        if (strcmp (aux, pun->dni) == 0)
            esta = 1;
        else if (strcmp (aux, pun->dni) > 0)
            pun = pun->der;
        else
            pun = pun->izq;
    }
    if (esta == 0)
        printf ("la clave no existe.");
    else {
        borrar = pun->pos;
        bajaarbol (r, aux);
        fseek (fiche, 0, SEEK_SET);
        fread (&indice, sizeof (tiporeg), 1, fiche);
        fseek (fiche, borrar * sizeof (tiporeg), SEEK_SET);
        fwrite (&indice, sizeof (tiporeg), 1, fiche);
        indice.libre = borrar;
        fseek (fiche, 0, SEEK_SET);
        fwrite (&indice, sizeof (tiporeg), 1, fiche);
        printf ("\nLa clave ha sido dada de baja satisfactoriamente.");
    }
    getch ();
    fclose (fiche);
}

// Fin borrar () //////////////////////////////////////////////////////////////
void cargaind (char *nomfich, nodo ** indice)
{
    FILE *fiche;
    tipoind auxind;
    nodo auxnodo;

    strcat (nomfich, ".ndx");
    fiche = fopen (nomfich, "ab");
    if (fiche == NULL)          // Si no existe fichero
    {
        printf ("El fichero no existe, lo creo...");
        fiche = fopen (nomfich, "wb");  // Lo crea
        auxnodo.dni = NULL;
        auxnodo.pos = 1;
        fwrite (&auxnodo, sizeof (tipoind), 1, fiche);
    }
    else                        // Si existe el fichero
    {
        while (!feof (fiche))   // Da de alta en el árbol de memoria
        {
            fread (&auxind, sizeof (tipoind), 1, fiche);
            strcpy (auxnodo.dni, auxind.dni);
            auxnodo.pos = auxind.pos;
            auxnodo.izq = NULL;
            auxnodo.der = NULL;
            insertar (&(*indice), auxnodo.dni, auxnodo.pos);
        }
    }
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void alta (char *nomfich, nodo ** indice)
{
    FILE *fiche = NULL;
    tiporeg cero, aux;
    nodo aux2;
    int libre = 0;

    // Abre el fichero
    strcat (nomfich, ".dat");
    fiche = fopen (nomfich, "a+b");
    if (fiche == NULL)
        fiche = fopen (nomfich, "wb");
    // Lee datos
    fflush (stdin);
    printf ("Introduzca DNI: ");
    gets (aux2.dni);            // Dato para el indice en memoria
    printf ("Introduzca nombre: ");
    gets (aux.nom);             // Dato del registro en disco
    printf ("Introduzca edad: ");
    scanf ("%d", &aux.edad);    // Dato del registro en disco
    // Carga el registro indice (1ª posición libre) para dar de alta
    fseek (fiche, 0, SEEK_SET);
    fread (&cero, sizeof (tiporeg), 1, fiche);
    // Da de alta el indice en memoria
    insertar (&(*indice), aux2.dni, cero.libre);
    // Carga el 1º registro libre para almacenar su siguiente
    fseek (fiche, cero.libre, SEEK_SET);
    fread (&aux, sizeof (tiporeg), 1, fiche);
    libre = aux.libre;
    // Guarda el registro en disco
    aux.libre = 0;
    fseek (fiche, cero.libre * sizeof (tiporeg), SEEK_SET);
    fwrite (&aux, sizeof (tiporeg), 1, fiche);
    // Actualiza el valor del registro indice del fichero
    cero.libre = libre;
    fseek (fiche, 0, SEEK_SET);
    fwrite (&cero, sizeof (tiporeg), 1, fiche);
    printf ("Ya está.");
    getch ();
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void inorden (nodo * r, FILE * fiche)
{
    nodo *aux = r;
    tiporeg reg;

    if (aux) {
        inorden (aux->izq, fiche);
        //printf ("%d",aux->pos);
        puts (aux->dni);
        fseek (fiche, aux->pos * sizeof (tiporeg), SEEK_SET);
        fread (&reg, sizeof (tiporeg), 1, fiche);
        printf ("\t");
        puts (reg.nom);
        printf ("\t%d\n", &reg.edad);
        inorden (aux->der, fiche);
    }
}
void lista (char *nomfich, nodo * indice)
{
    tiporeg regaux;
    FILE *fiche;

    fiche = fopen (nomfich, "rb");
    printf ("\nDNI\tNombre\tEdad\n");
    printf ("------\t-----\t----\n");
    inorden (indice, fiche);

    fclose (fiche);
    getch ();
}

// M A I N ///////////////////////////////////////////////////////////////////
int main (void)
{
    int op;
    char *fichero, *copia;
    nodo *indmem = NULL;

    printf ("Introduce el nombre del fichero a cargar: ");
    gets (fichero);
    strcpy (copia, fichero);
    cargaind (copia, &indmem);
    do {
        printf ("INTRODUZCA UNA OPCION: ");
        printf ("\n0.-SALIR\n1.-ALTAS\n2.-BAJAS\n3.-LISTAR ");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                alta (fichero, &indmem);
                lista (fichero, indmem);
                break;
            case 2:
                baja (fichero, &indmem);
                lista (fichero, indmem);
                break;
            case 3:
                lista (fichero, indmem);
        }
    }
    while (op);
}

/* FIN DE PRUEBA...........................................................*/
