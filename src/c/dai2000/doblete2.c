/* doblete2.c -- elementos de un array doble */
#include <stdio.h>
void dub (int ar[], int param);
int main (void)
{
    static int basura[3][4] = {
        {2, 4, 5, 8},
        {3, 5, 6, 9},
        {12, 10, 8, 6}
    };
    int i, j;

    dub (basura[0], 3 * 4);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf ("%5d", basura[i][j]);

        putchar ('\n');
    }

    return 0;
}

void dub (int ar[], int param)
{                               /* o int *ar; */
    int i;

    for (i = 0; i < param; i++)
        ar[i] *= 2;
}
