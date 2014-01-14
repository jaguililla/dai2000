/* ADIVNUME.C */

#define ALTO 100
#define BAJO 1

int main (void)
{
    int sup = (ALTO + BAJO) / 2, max = ALTO, min = BAJO;
    char respuesta;

    clrscr ();
    printf ("Meta un entero entre %d y %d.", ALTO, BAJO);
    printf (" Trataré de adivinarlo.\n");
    printf ("Responda 's' si acierto, 'a' si alto y 'b' si es bajo.\n");
    printf ("Apuesto por: %d?\n", sup);
    respuesta = getch ();

    while (respuesta != 's') {
        if (respuesta == 'a') {
            max = sup - 1;
            sup = (max + min) / 2;
            printf ("Demasiado alto... Entonces será %d\n", sup);
        }
        else {
            if (respuesta == 'b') {
                min = sup + 1;
                sup = (max + min) / 2;
                printf ("Demasiado bajo... Entonces será %d\n", sup);
            }
            else {
                printf ("No comprendo; utilice s,  a o  b.\n");
            }
        }
        respuesta = getch ();
    }
    printf ("¡¡Sabía que lo conseguiría!!\n");
    getch ();
    return 0;
}
