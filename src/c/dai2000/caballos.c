#include<stdlib.h>
void main (void)
{
    int avanza, caballo[6] = { 0, 0, 0, 0, 0, 0 };
    clrscr ();
    randomize ();

    do {
        //textcolor y textbackground
        avanza = rand ()%6;
        delay (40);
        caballo[avanza]++;
        gotoxy (caballo[avanza], avanza * 3 + 1);
        textcolor (avanza + 10);
        cprintf (" X");
        sound (100 * avanza);
    }
    while (caballo[avanza] <= 75);

    nosound ();

    gotoxy (6, 22);

    switch (avanza) {

        case 0:
            printf ("Caballo ganador: Imperioso");
            break;

        case 1:
            printf ("Caballo ganador: Babieca");
            break;

        case 2:
            printf ("Caballo ganador: Rocinante");
            break;

        case 3:
            printf ("Caballo ganador: Demon");
            break;

        case 4:
            printf ("Caballo ganador: Devil");
            break;

        case 5:
            printf ("Caballo ganador: Arrow");
            break;
    }

    printf ("\nJULIO Aplicaciones informáticas S.A.");
    getch ();
}
