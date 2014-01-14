#include<stdio.h>

long dias;
long bisiesto (long aa)
{
    int dias2;

    if (aa % 4 == 0) {
        dias2 = 366;

        if ((aa % 100 == 0) && (aa % 400 != 0)) // si el año acaba en 00. X ej. 1900
            dias2--;
    }
    else
        dias2 = 365;

    return (dias2);
}

int pico (int dd, int mm, int aa)   ///////////////////////////////
{                               //devuelve el nº de dias     //
    int dias2, indice;          //que hay desde el comienzo  //

    //del año hasta la fecha dada//
    ///////////////////////////////

    for (indice = mm; indice >= 2; indice--) {
        switch (indice) {

            case 2:

            case 4:

            case 6:

            case 8:

            case 9:

            case 11:

            case 13:
                dias += 31;
                break;

            case 3:
                dias2 = bisiesto (aa);

                if (dias2 == 366)
                    dias += 29;
                else
                    dias += 28;

                break;

            case 5:

            case 7:

            case 10:

            case 12:
                dias += 30;

                break;
        }
    }

    return (dias);
}

long int years (long aa_i, long aa_f)
{
    int indice;
    long mayor, menor, aux;

    if (aa_i > aa_f) {
        mayor = aa_i;           //Nos indica el nº de días
        menor = aa_f;           //desde el principio de un
    }
    else {                      //año hasta el final del año
        mayor = aa_f;           //anterior al dado en 2º lugar
        menor = aa_i;
    }

    for (indice = menor; indice < mayor; indice++) {
        dias += bisiesto (indice);
    }

    return (dias);
}

void ordenar (int *dd_i, int *mm_i, long *aa_i, int *dd_f, int *mm_f,
              long *aa_f)
{
    long aux1;
    int aux2, aux3;

    if (*aa_i > *aa_f) {
        aux1 = *aa_i;           //las 3 primeras líneas cambian el año
        *aa_i = *aa_f;
        *aa_f = aux1;           // las 3 ln sgtes cambian el mes
        aux2 = *mm_i;
        *mm_i = *mm_f;
        *mm_f = aux2;
        aux3 = *dd_i;           // las 3 ln sgtes cambian el día
        *dd_i = *dd_f;
        *dd_f = aux3;
    }
    else if ((*aa_i == *aa_f) && (*mm_i > *mm_f)) {
        aux2 = *mm_i;           // las 3 ln sgtes cambian el mes
        *mm_i = *mm_f;
        *mm_f = aux2;
        aux3 = *dd_i;           // las 3 ln sgtes cambian el día
        *dd_i = *dd_f;
        *dd_f = aux3;
    }
    else if ((*mm_i == *mm_f) && (*dd_i > *dd_f)) {
        aux3 = *dd_i;           // las 3 ln sgtes cambian el día
        *dd_i = *dd_f;
        *dd_f = aux3;
    }
}

/*
void main (void)
{
long valor,res,valor2,valor3;
clrscr();
printf("Mete el valor; ");
scanf("%ld%ld%ld",&valor,&valor2,&valor3);
res=pico(valor,valor2,valor3);
res+=valor;
printf("%ld",res);
getch();
} //falla pico
/*void pide (int *di,int *me,long *ao)
{
printf("Introduzca una fecha(dd/mm/aaaa): ");
scanf("%d%d%ld",&di,&me,&ao);
}
/*main */
void main (void)
{
    int dd_i, mm_i, dd_f, mm_f;
    long aa_i, aa_f, pico_i, pico_f, dias;

    clrscr ();
    printf ("Introduzca una fecha(dd/mm/aaaa): ");
    scanf ("%d%d%ld", &dd_i, &mm_i, &aa_i);
    printf ("Introduzca otra fecha(dd/mm/aaaa): ");
    scanf ("%d%d%ld", &dd_f, &mm_f, &aa_f);
    ordenar (&dd_i, &mm_i, &aa_i, &dd_f, &mm_f, &aa_f);
    pico_i = pico (dd_i, mm_i, aa_i);
    pico_f = pico (dd_f, mm_f, aa_f);

    if (aa_i != aa_f) {
        dias = years (aa_i, aa_f) - pico_i;
        dias += pico_f;
    }
    else {
        if (mm_f > mm_i)
            dias = pico_f - pico_i;
        else
            dias = pico_i - pico_f;

        if (mm_i == mm_f)
            dias = abs (dd_i - dd_f);
    }

    //printf ("los dias entre %d/%d/%ld y %d/%d/%ld son: %ld"
    //  ,dd_i,mm_i,aa_i,dd_f,mm_f,aa_f,dias);
    printf ("%d", dias);

    getch ();
}
