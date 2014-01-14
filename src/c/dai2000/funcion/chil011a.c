/* chil011a */

void main (void)
{
    int p, x, y, j, k;

    x = 1;
    y = 2;
    p = multiplica (x, y);
    printf ("%d \n", p);

    j = 234;
    k = 10;
    p = multiplica (j, k);
    printf ("%d \n", p);
}

multiplica (a, b)
     int a, b;
{
    return (a * b);
}
