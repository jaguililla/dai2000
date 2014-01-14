/* groucho1.c -- direcciones */
#include <stdio.h>
int main (void)
{
    int groucho[4][2];

    printf ("groucho = %u, groucho[0] = %u, &groucho[0][0] = %u ",
            groucho, groucho[0], &groucho[0][0]);
    printf ("*groucho = %u\n", *groucho);
    return 0;
}
