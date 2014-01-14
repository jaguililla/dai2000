/* groucho2.c -- más detalles sobre groucho */
#include <stdio.h>
int main (void)
{
    int groucho[4][2];

    printf ("groucho = %u, groucho[0] = %u, &groucho[0][0] = %u\n",
            groucho, groucho[0], &groucho[0][0]);
    printf ("*groucho = %u\n", *groucho);

    printf ("groucho + 1 = %u, groucho[0] + 1 = %u\n",
            groucho + 1, groucho[0] + 1);
    printf ("&groucho[0][0] + 1 = %u, *groucho + 1 = %u\n",
            &groucho[0][0] + 1, *groucho + 1);
    printf ("*(groucho + 1) = %u\n", *(groucho + 1));
    return 0;
}
