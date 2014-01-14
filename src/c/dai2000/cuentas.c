/* cuentas.c -- uso de E/S estándar */
#include <stdio.h>
#include <stdlib.h>             /* prototipo ANSI C de exit() */
int main (int argc, char *argv[])
{
    int ch;                     /* aquí se almacenan los caracteres que se leen */
    FILE *fp;                   /* "puntero a fichero" */
    long cont = 0;

    if (argc != 2) {
        printf ("Uso: %s nombre de fichero\n", argv[0]);
        exit (1);
    }

    if ((fp = fopen (argv[1], "r")) == NULL) {
        printf ("No puedo abrir %s\n", argv[1]);
        exit (1);
    }

    while ((ch = getc (fp)) != EOF) {
        putc (ch, stdout);
        cont++;
    }

    fclose (fp);
    printf ("El fichero %s tiene %ld caracteres\n", argv[1], cont);
    return 0;
}
