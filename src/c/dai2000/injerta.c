/* injerta.c -- añade ficheros a otros ficheros */
#include <stdio.h>
#define TAMBUF 1024
char temp[TAMBUF];
void append (FILE * fuente, FILE * dest);

int main (int argc, char *argv[])
{
    FILE *fa, *fr;
    int fich;

    if (argc < 3) {
        fprintf (stderr, "Uso: %s fichero(s) fuente  destino\n", argv[0]);
        exit (1);
    }

    if ((fa = fopen (argv[argc - 1], "a")) == NULL) {
        fprintf (stderr, "No puedo abrir %s\n", argv[argc - 1]);
        exit (2);
    }

    if (setvbuf (fa, NULL, _IOFBF, TAMBUF) != 0) {
        fputs ("No puedo crear buffer de salida\n", stderr);
        exit (3);
    }

    for (fich = 1; fich < argc - 1; fich++) {
        if (strcmp (argv[argc - 1], argv[fich]) == 0)
            fputs ("No puedo añadir un fichero a sí mismo\n", stderr);
        else if ((fr = fopen (argv[fich], "r")) == NULL)
            fprintf (stderr, "No puedo abrir %s\n", argv[fich]);
        else {
            if (setvbuf (fr, NULL, _IOFBF, TAMBUF) != 0) {
                fputs ("No puedo crear buffer de salida\n", stderr);
                continue;
            }

            append (fr, fa);

            if (ferror (fr) != 0)
                fprintf (stderr, "Error al leer fichero %s.\n", argv[fich]);

            if (ferror (fa) != 0)
                fprintf (stderr, "Error al escribir fichero %s.\n",
                         argv[argc - 1]);

            return 0;
        }
    }

    fclose (fa);
}

void append (FILE * fuente, FILE * dest)
{
    size_t bytes;
    extern char temp[];

    while ((bytes = fread (temp, sizeof (char), TAMBUF, fuente)) > 0)
        fwrite (temp, sizeof (char), bytes, dest);
}
