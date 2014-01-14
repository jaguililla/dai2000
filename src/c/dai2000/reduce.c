/* reduce.c -- ¡reduce su fichero a la tercera parte! */
#include <stdio.h>
#include <stdlib.h>
main (int argc, char *argv[])
{
    FILE *in, *out;             /* declara dos punteros FILE   */
    int ch;
    char nombre[40];            /* para guardar fichero salida */
    int cont = 0;

    if (argc < 2) {             /* comprueba que hay fichero de entrada */
        fprintf (stderr, "Uso: %s nombre del fichero\n", argv[0]);
        exit (1);
    }
    if ((in = fopen (argv[1], "r")) == NULL) {
        fprintf (stderr, "No puedo abrir el fichero \"%s\"\n", argv[1]);
        exit (2);
    }

    strcpy (nombre, argv[1]);   /* copia nombre del fichero en un array */
    strcat (nombre, ".red");    /* añade .red al nombre */

    if ((out = fopen (nombre, "w")) == NULL) {  /* abre otro fichero como
                                                   salida en escritura */
        fprintf (stderr, "No puedo crear fichero de salida.\n");
        exit (3);
    }
    while ((ch = getc (in)) != EOF)
        if (cont++ % 3 == 0)
            putc (ch, out);     /* envía un carácter cada tres */

    if (fclose (in) != 0 || fclose (out) != 0)
        fprintf (stderr, "Error al cerrar ficheros\n");

    return 0;
}
