#include <stdio.h>
#include <stdlib.h>
void main (void)
{
    unsigned char c;

    clrscr ();
/*  printf ("%35c ASCII con FOR \n",' ');
  for (c=32; c<255;++c)
    printf ("%3d-%c   ",c,c);
  printf ("%3d-%c\n",c,c);
  getch();*/

/*  printf ("%35c ASCII con DO \n",' ');
  c=31;
  do
    printf ("%3d-%c   ",++c,c);
  while (c < 255);
  c=255;
  printf ("\n prueba con número=%d código=%c\n",c,c);
  getch();*/

    printf ("%35c ASCII con WHILE \n", ' ');
    c = 31;
    while (c < 255) {
        printf ("%3d-%c   ", c++, c);
        // c++;
    }
    c = 255;
    printf ("\n prueba con número=%d código=%c\n", c, c);
    getch ();
}
