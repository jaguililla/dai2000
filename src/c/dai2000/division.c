int Ddendo, divisor, cociente;
void main (void)
{
    printf ("Introduce el dividendo: ");
    scanf ("%d", &Ddendo);
    printf ("Introduce el divisor: ");
    scanf ("%d", &divisor);
    cociente = 0;

    while (Ddendo >= divisor) {
        Ddendo = Ddendo - divisor;
        cociente++;
    };

    printf ("El cociente es %d y el resto %d.", cociente, Ddendo);
}
