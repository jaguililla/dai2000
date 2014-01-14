int Radio, longitud;

#define pi 3.1416

/////////
void main (void)
{
    clrscr ();
    printf ("Introduzca el radio: ");
    scanf ("%d", &Radio);
    longitud = 2 * pi * Radio;
    printf ("La longitud es %d", longitud);
    getch ();
}
