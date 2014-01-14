/*
 * al_reves.c - presenta un fichero en orden inverso
 */

/* I N C L U D E **************************************************************/
#include <stdio.h>
#include <stdlib.h>

/* D E F I N E ****************************************************************/
#define CNTL_Z '\032'           /* marca EOF en ficheros DOS */

/* M A I N ********************************************************************/
int main (int argc, char *argv[])
{
    char ch;
    FILE *fp;
    long cont, ultimo;

    if (argc != 2) {
        printf ("Uso: al_reves fichero\n");
        exit (1);
    }

    if ((fp = fopen (argv[1], "rb")) == NULL) { /* modo sólo lectura binario */
        printf ("al_reves no puede abrir %s\n", argv[1]);
        exit (1);
    }

    fseek (fp, 0L, SEEK_END);   /* va al final del fichero */
    ultimo = ftell (fp);

    for (cont = 1L; cont <= ultimo; cont++) {
        fseek (fp, -cont, SEEK_END);    /* retrocede en el fichero */
        ch = getc (fp);

        if (ch != CNTL_Z && ch != '\r')
            putchar (ch);
    }

    fclose (fp);
    return 0;
}

/* E O F **********************************************************************/
