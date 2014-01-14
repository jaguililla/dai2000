/* doblete3.c -- elementos de un array doble */
#include <stdio.h>
void dub2 (int ar[][4], int param);
int main (void)
{
    static int basura[3][4] = {
        {2, 4, 5, 8},
        {3, 5, 6, 9},
        {12, 10, 8, 6}
    };
    int i, j;

    dub2 (basura, 3);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf ("%5d", basura[i][j]);

        putchar ('\n');
    }
}

void dub2 (int ar[][4], int param)
{                               /* o int (*ar)[4] */
    int i, j;

    for (i = 0; i < param; i++)
        for (j = 0; j < 4; j++)
            ar[i][j] *= 2;
}
