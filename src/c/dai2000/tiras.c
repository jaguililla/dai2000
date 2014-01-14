/* tiras.c -- hágase en solitario */
#include <stdio.h>
#define MSJ "Debe tener muchas cualidades. Dígame algunas."
/* constante simbólica de tira de caracteres   */
#define LIM  5
#define LONLIN 81               /* longitud máxima + 1 */
char m1[] = "Limítese a una sola línea.";

/* inicialización de un array de char externo  */
char *m2 = "Si no se le ocurre nada, muérase.";

/* inicialización de un puntero a char externo */

int main (void)
{
    char nombre[LONLIN];
    static char talentos[LONLIN];
    int i;
    int cont = 0;
    char *m3 = "\nYa basta sobre mí -- ¿cómo se llama?";

    /* inicialización de un puntero */
    static char *mistal[LIM] = { "Sumo números con sutileza",
        "Multiplico con precisión", "Almaceno datos",
        "Sigo instrucciones al pie de la letra",
        "Entiendo el lenguaje C"
    };
    /* inicialización de un array de tiras */

    printf ("¡Hola! Soy Juanito, su ordenador favorito.\n");
    printf ("Tengo muchas cualidades. Le diré algunas.\n");
    puts ("Las tengo en la punta del byte...¡Ah, sí! ahí van:");

    for (i = 0; i < LIM; i++)
        puts (mistal[i]);       /* imprime las cualidades del ordenador */

    puts (m3);

    gets (nombre);

    printf ("Bien, %s. %s\n", nombre, MSJ);

    printf ("%s\n%s\n", m1, m2);

    gets (talentos);

    puts ("A ver si he cogido toda la lista:");

    puts (talentos);

    printf ("Gracias por la información, %s.\n", nombre);

    return 0;
}
