/* eco.c -- main() con argumentos */
int main (int argc, char *argv[])
{
    int cont;

    for (cont = 1; cont < argc; cont++)
        printf ("%s ", argv[cont]); /* procesa los argumentos */

    printf ("\n");

    return 0;
}
