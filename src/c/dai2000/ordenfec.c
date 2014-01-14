void main (void)
{
    int dd_i, dd_f, mm_i, mm_f, aux2, aux3;
    long int aa_i, aa_f, aux1;

    clrscr ();
    printf ("Introduzca una fecha(dd/mm/aaaa): ");
    scanf ("%d%d%ld", &dd_i, &mm_i, &aa_i);
    printf ("Introduzca otra fecha: ");
    scanf ("%d%d%ld", &dd_f, &mm_f, &aa_f);

    if (aa_i > aa_f) {
        aux1 = aa_i;            //las 3 primeras líneas cambian el año
        aa_i = aa_f;
        aa_f = aux1;            // las 3 ln sgtes cambian el mes
        aux2 = mm_i;
        mm_i = mm_f;
        mm_f = aux2;
        aux3 = dd_i;            // las 3 ln sgtes cambian el día
        dd_i = dd_f;
        dd_f = aux3;
    }
    else if ((aa_i == aa_f) && (mm_i > mm_f)) {
        aux2 = mm_i;            // las 3 ln sgtes cambian el mes
        mm_i = mm_f;
        mm_f = aux2;
        aux3 = dd_i;            // las 3 ln sgtes cambian el día
        dd_i = dd_f;
        dd_f = aux3;
    }
    else if ((mm_i == mm_f) && (dd_i > dd_f)) {
        aux3 = dd_i;            // las 3 ln sgtes cambian el día
        dd_i = dd_f;
        dd_f = aux3;
    }

    printf ("La fecha mayor es: %d/%d/%ld\n", dd_f, mm_f, aa_f);
    printf ("La fecha menor es: %d/%d/%ld", dd_i, mm_i, aa_i);
    getch ();
}
