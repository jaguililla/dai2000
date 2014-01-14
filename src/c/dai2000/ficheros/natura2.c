// MEZCLA NATURAL

// INCLUDES
#include <stdlib.h>
#include <stdio.h>


// PROTOTIPOS
void dividir (char *nf, char *nf1, char *nf2);

// FUNCIONES
void dividir (char *nf, char *nf1, char *nf2)
{
    int rant, ract, cambio;
    FILE *f, *f1, *f2;

    f = fopen (nf, "rb");
    f1 = fopen (nf1, "wb");
    f2 = fopen (nf2, "wb");
    fread (&rant, sizeof (int), 1, f);
    if (feof (f))
        printf ("El fichero está vacío.");
    else {
        cambio = 1;
        fread (&ract, sizeof (int), 1, f);
        fwrite (&rant, sizeof (int), 1, f1);
        while (!feof (f)) {
            if (rant > ract)
                cambio = !cambio;
            if (cambio)
                fwrite (&ract, sizeof (int), 1, f1);
            else
                fwrite (&ract, sizeof (int), 1, f2);
            rant = ract;
            fread (&ract, sizeof (int), 1, f);
        }
    }
    fclose (f);
    fclose (f1);
    fclose (f2);
}
