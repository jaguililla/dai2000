/* animales.c -- ejemplo de sentencia switch */
#include <stdio.h>
int main (void)
{
    char ch;

    printf ("Dáme una letra y responderé con ");
    printf ("un nombre de animal\nque comience por ella.\n");
    printf ("Pulse una letra; para terminar pulse #.\n");

    while ((ch = getchar ()) != '#') {
        if (ch >= 'a' && ch <= 'z') /* sólo minúsculas */
            switch (ch) {

                case 'a':
                    printf ("aranillo, oveja salvaje del Caribe\n");
                    break;

                case 'b':
                    printf ("babirusa, cerdo arlequinado de Malasia\n");
                    break;

                case 'c':
                    printf ("chascalote, ballena gigante del Amazonas\n");
                    break;

                case 'd':
                    printf ("destemplat, pingüino rojo de Kenia\n");
                    break;

                case 'e':
                    printf ("equigobo, camello siberiano\n");
                    break;

                default:
                    printf ("Humm....ése no me lo sé.\n");
            }                   /* fin del switch */
        else
            printf ("Sólo me trato con letras minúsculas.\n");

        while (getchar () != '\n')
            continue;           /* salta carácter nueva línea */

        printf ("Introduzca otra letra o un #.\n");
    }                           /* fin del while */

    return 0;
}
