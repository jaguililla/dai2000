#define SI 1
#define NO 0
main ()
{
    char ch;
    long nc = 0L;
    int nl = 1, np = 0, palabra = NO;

    clrscr ();
    while ((ch = getchar ()) != '0') {
        nc++;
        if (ch == '\n')
            nl++;
        if (ch != ' ' && ch != '\n' && ch != '\t' && palabra == NO) {
            palabra = SI;
            np++;
        }
        if ((ch == ' ' || ch == '\n' || ch == '\t') && palabra == SI)
            palabra = NO;
    }

    printf ("caracteres = %ld, palabras = %d, líneas = %d\n", nc, np, nl);
    getch ();
}
