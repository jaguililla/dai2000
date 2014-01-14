/* beli029a. Cuenta caracteres, palabras y líneas metidas por teclado */
#include <stdio.h>

#include <ctype.h>
#include <string.h>
#define longpal 20

void main (void)
{
    int contcar, contlin, contpal, i;
    char ca, palabra[longpal];

    clrscr ();
    contcar = contlin = contpal = i = 0;
    printf ("Escriba varias líneas de texto separadas por 'intro'\n");
    printf ("Después de la última línea introduzca Ctrl-Z o pulse F6\n");
    for (i = 0; i < longpal; i++)
        palabra[i] = '\0';
    i = 0;
    ca = getchar ();
    while (ca != EOF) {
        if (ca != '\n') {       /* mientras sea distinto fin de línea */
            contcar++;          /* incrementa caracteres */
            if (isalpha (ca)) { /* si es alfanumérico se concatena a la palabra */
                palabra[i] = ca;
                i++;
            }
            else {              /* No es alafanumérico. Es fin de palabra */
                if (strcmp (palabra, "")) { /* si no palabra vacía se escribe */
                    puts (palabra);
                    contpal++;
                    for (i = 0; i < longpal; i++)
                        palabra[i] = '\0';
                    i = 0;
                }
            }
        }
        else {                  //ca='\n'. Es fin de línea y de palabra
            contlin++;
            if (palabra[0] != '\0') {   /* si no palabra vacía se escribe */
                puts (palabra);
                contpal++;
                for (i = 0; i < longpal; i++)
                    palabra[i] = '\0';
                i = 0;
            }
        }
        ca = getchar ();
    }                           //eof
    printf ("caracteres   lineas    palabras \n");
    printf ("   %d          %d        %d\n", contcar, contlin, contpal);
    getch ();
}

/* TEXTO INTRODUCIDO LÍNEA A LÍNEA
en un lugar de la
Mancha de
cuyo nombre
no quiero acordarme

no ha mucho

que vivia un hidalgo
de

CARACTERES 89   LINEA 9 PALABRAS 20
*/
