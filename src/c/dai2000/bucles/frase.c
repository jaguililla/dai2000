main ()
{
    char caracter;
    int contcar = 0, contpal = 1;

    clrscr ();
    printf ("Dame una frase:  ");
    while ((caracter = getchar ()) != '\n') {
        ++contcar;
        if (caracter == ' ')
            ++contpal;

    }
    printf ("tu frase tiene %d caracteres y %d palabras", contcar, contpal);
    getch ();
}
