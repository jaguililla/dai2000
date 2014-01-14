int indice;
float grados (float grado)
{
    float radian;

    radian = (grado * 3.14) / 180;
    return (radian);
}

long factorial (int nume)
{
    long suma = 1;
    int indice1;

    for (indice1 = 1; indice1 <= nume; indice1++)
        suma *= indice;

    return (suma);
}

long eleva (long base, long exp)
{
    int indice2, expo;

    expo = base;

    for (indice2 = 2; indice2 <= exp; indice2++) {
        base *= expo;
    }

    return (base);
}

long sumando (float ang, int num)
{
    float suma;

    suma = eleva (ang, num);
    suma = suma / factorial (num);
    return (suma);
}

void main (void)
{
    float ang, total = 0, total2;
    int num, cont;
    long sum;

    clrscr ();
    printf ("Introduzca el ángulo y la precisión: ");
    scanf ("%f%d", &ang, &num);

    if (num % 2 == 0)
        num--;

    cont = 1;

    total = grados (ang);

    total2 = total;

    for (indice = 3; indice <= num; indice += 2) {
        if (cont == 1) {
            sum = sumando (total2, indice);
            total += sum;
            cont = 0;
        }
        else {
            sum = sumando (total2, indice);
            total -= sum;
            cont = 1;
        }
    }

    printf ("%f\t%f", total, sin (total));
    getch ();
}
