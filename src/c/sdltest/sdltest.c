/*
 * Prueba SDL
 * Compilación: gcc sdltest.c -lmingw32 -lSDLmain -lSDL
 */

/* I N C L U D E S ************************************************************/
#include <stdio.h>
#include "SDL/SDL.h"

/* P R E P R O C E S S O R ****************************************************/
#ifndef __SDLTEST_C
#    define __SDLTEST_C

#ifdef __cplusplus
extern "C" {
#endif

/* C O N S T A N T S **********************************************************/
#define FALSE 0

/* P R O T O T Y P E S ********************************************************/
void printPixelFormatInfo (SDL_PixelFormat *);

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

/*
 *
 */
void printPixelFormatInfo (SDL_PixelFormat * pixelFormat) { }

/*
 *
 * PENDIENTE: listar los modos de video soportados, describir el mejor (vfmt)
 */
void printVideoInfo () {
    SDL_VideoInfo *ptrVidInfo = NULL;
    char *driverName = NULL;

    driverName = SDL_VideoDriverName (driverName, 20);
    printf ("Nombre del driver: %s\n", driverName);
    // ERROR: esta sentencia da un warning
    ptrVidInfo = (SDL_VideoInfo *)SDL_GetVideoInfo ();
    printf ("\t* Superficies graficas por hardware disponibles: %s\n", (ptrVidInfo->hw_available != FALSE) ? "V" : "F");
    printf ("\t* Gestor de ventanas disponible: %s\n", (ptrVidInfo->wm_available != FALSE) ? "V" : "F");
    printf ("\t* Copia hardware-hardware acelerada disponible: %s\n", (ptrVidInfo->blit_hw != FALSE) ? "V" : "F");
    printf ("\t* Copia hardware-hardware con color transparente acelerada disponible: %s\n", (ptrVidInfo->blit_hw_CC != FALSE) ? "V" : "F");
    printf ("\t* Copia hardware-hardware con canal alfa acelerada disponible: %s\n", (ptrVidInfo->blit_hw_A != FALSE) ? "V" : "F");
    printf ("\t* Copia software-hardware acelerada disponible: %s\n", (ptrVidInfo->blit_sw != FALSE) ? "V" : "F");
    printf ("\t* Copia software-hardware con color transparente acelerada disponible: %s\n", (ptrVidInfo->blit_sw_CC != FALSE) ? "V" : "F");
    printf ("\t* Copia software-hardware con canal alfa acelerada disponible: %s\n", (ptrVidInfo->blit_sw_A != FALSE) ? "V" : "F");
    printf ("\t* Relleno de color acelerado disponible: %s\n", (ptrVidInfo->blit_fill != FALSE) ? "V" : "F");
    printf ("\t* Tamaño de la memoria de video: %d\n", ptrVidInfo->video_mem);
    printPixelFormatInfo (ptrVidInfo->vfmt);
}

void loadFontFile (char *fileName) { }

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
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
                    /* Keyboard event */
                    /* Pass the event data onto PrintKeyInfo() */
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    printf ("Tecla Pulsada");
                    break;
                    /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
            }
        }
    }

    quitSDL ();
    exit (0);
}

#ifdef __cplusplus
}
#endif

#endif /* __SDLTEST_C */
/* E O F **********************************************************************/
