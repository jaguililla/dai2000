/* rangos.c -- conversiones automáticas de tipos */
#include <stdio.h>
main ()
{
    char ch;
    int i;
    float fl;

    fl = i = ch = 'A';          /* línea 8  */
    printf ("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = ch + 1;                /* línea 10 */
    i = fl + 2 * ch;            /* línea 11 */
    fl = 2.0 * ch + i;          /* línea 12 */
    printf ("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = 52122055.17;            /* línea 14 */
        printf ("Ahora ch = %c\n", ch);
}
