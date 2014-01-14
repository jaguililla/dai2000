/* obtenpal.c Obtiene caracteres, palabras y líneas de un fichero de texto */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define longpal 20

void main (void)
{
    FILE *f;
    int contcar, contlin, contpal, carlin, i;
    char ca, palabra[longpal], nomfi[100];

    clrscr ();
    strcpy (nomfi, "c:\\textogod\\beli029a.C");
    f = fopen (nomfi, "r");
    contcar = contlin = contpal = i = 0;
    strcpy (palabra, "");
    i = 0;
    ca = fgetc (f);
    carlin = 0;
    while (ca != EOF) {
        if (ca != '\n') {       /* mientras sea distinto fin de línea */
            contcar++;          /* incrementa caracteres */
            if (isalpha (ca)) { /* si es alfanumérico se concatena a la palabra */
                palabra[i] = ca;
                i++;
            }
            else {              /* No es alafanumérico. Es fin de palabra */
                palabra[i] = '\0';
                if (strcmp (palabra, "")) { /* si no palabra vacía se escribe */
                    //puts (palabra); getch();
                    contpal++;
                    strcpy (palabra, "");
                    i = 0;
                }
            }
            carlin++;
        }
        else {                  //ca='\n'. Es fin de línea y de palabra
            contlin++;
            printf ("linea %d caracteres %d\n", contlin, carlin);
            carlin = 0;
            palabra[i] = '\0';
            if (strcmp (palabra, "")) { /* si no palabra vacía se escribe */
                //puts (palabra); getch();
                contpal++;
                strcpy (palabra, "");
                i = 0;
            }
        }
        ca = fgetc (f);
    }                           //eof

    fclose (f);
    printf ("caracteres   lineas    palabras \n");
    printf ("   %d          %d        %d\n", contcar, contlin, contpal);
    getch ();
}
