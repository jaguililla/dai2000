/*
 * Teclado
 * Compilación: gcc keyboard.c -lmingw32 -lSDLmain -lSDL
 */

/* I N C L U D E S ************************************************************/
#include <stdio.h>
#include "SDL/SDL.h"

/* P R E P R O C E S S O R ****************************************************/
#ifndef __KEYBOARD_C
#    define __KEYBOARD_C

#ifdef __cplusplus
extern "C" {
#endif

/* C O N S T A N T S **********************************************************/
#define FALSE 0

/* F U N C T I O N S **********************************************************/
/*
 * Inicialización de la libreria SDL (http://www.libsdl.org)
 */
void initSDL () {
    printf ("Inicializando SDL.\n");
    /* Inicializa los subsistemas de video y audio */
    if ((SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        printf ("No se pudo inicializar SDL: %s.\n", SDL_GetError ());
        exit (-1);
    }
    printf ("SDL inicializado.\n");
}

/*
 *
 */
void quitSDL () {
    printf ("Liberando SDL.\n");
    /* Libera todos los subsistemas de SDL */
    SDL_Quit ();
    printf ("SDL Liberado.\n");
}

/* M A I N ********************************************************************/
/*
 * Esta función no necesita presentación...
 */
int main (int argc, char *argv[]) {
    SDL_Event event;
    int quit = 0;

    initSDL ();
    //printVideoInfo ();
    while (!quit) {
        /* Poll for events */
        SDL_PollEvent (&event);
        switch (event.type) {
            /* Keyboard event */
            /* Pass the event data onto PrintKeyInfo() */
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                printf ("Tecla Pulsada");
                break;
            /* SDL_QUIT event (window close) */
            case SDL_QUIT:quit = 1;
                break;
            default:
                break;
        }
    }
    quitSDL ();
    exit (0);
}

#ifdef __cplusplus
}
#endif

#endif /* __KEYBOARD_C */
/* E O F **********************************************************************/
