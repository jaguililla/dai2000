/* ultima.c -- imprime la última línea de un fichero */
#include <stdio.h>
void busca_fin (char *nombre, FILE * fichero);
int main (int argc, char *argv[])
{
    FILE *fp;
    int fich;

    if (argc < 2) {
        printf ("Uso: %s fichero(s)\n", argv[0]);
        exit (1);
    }

    for (fich = 1; fich < argc; fich++) {
        if ((fp = fopen (argv[fich], "r")) == NULL)
            fprintf (stderr, "%s no puede abrir %s\n", argv[0], argv[fich]);
        else {
            busca_fin (argv[fich], fp);
            fclose (fp);
        }
    }

    return 0;
}

void busca_fin (char *nombre, FILE * fichero)
{
    int ch;
    int nuevalinea = 0;
    long cont, inicio, ultimo;

    printf ("%s:\n", nombre);
    inicio = ftell (fichero);
    fseek (fichero, 0L, SEEK_END);  /* va al final del fichero */
    ultimo = ftell (fichero);

    for (cont = 1L; cont <= ultimo; cont++) {
        fseek (fichero, -cont, SEEK_END);   /* retrocede */
        ch = getc (fichero);

        if (ch == '\n')
            nuevalinea++;

        if (nuevalinea == 2) {  /* puede ser 3 */
            inicio = ftell (fichero);   /* puede ser ftell(fichero) -1 */
            break;
        }
    }

    fseek (fichero, inicio, SEEK_SET);

    while ((ch = getc (fichero)) != EOF)
        putchar (ch);
}
