int coord1, coord2;
float radio, ang;
void main (void)
{
    clrscr ();
    printf ("Introduzca las coordenadas: ");
    scanf ("%d%d", &coord1, &coord2);
    radio = (coord1 * coord1) + (coord2 * coord2);
    radio = sqrt (radio);
    ang = atan (coord2 / coord1);
    printf ("(%f,%f)", radio, ang);
    getch ();
}
