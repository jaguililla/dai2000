//primitiva
#include<stdlib.h>

int sacarbola (int aux[])
{
    int bola;

    do {
        bola = rand ()%49;
    }
    while (aux[bola] != 0);

    aux[bola] = 1;
}

void vaciar (int tabla[])
{
    int indice3;

    for (indice3 = 0; indice3 < 49; indice3++)
        tabla[indice3] = 0;
}

void rellenar (int aux[], int primi[][7])
{
    int indice, cont;

    for (indice = 0; indice < 10; indice++) {
        cont = 0;
        vaciar (aux);

        do {
            do {
                primi[indice][cont] = rand ()%49;

                if (aux[primi[indice][cont]] == 0)
                    cont++;
            }
            while (aux[primi[indice][cont]] == 1);

            aux[primi[indice][cont]] = 1;   //rellena hasta 6 elementos
        }
        while (cont < 6);
    }                           //llave del for

    for (indice = 0; indice < 10; indice++)
        primi[indice][6] = rand ()%10; //reintegro
}

void comprobar (int primi[][7], int bola, int aux2[])
{
    int cont, cont2;

    for (cont = 0; cont < 10; cont++)
        for (cont2 = 0; cont2 < 7; cont2++)
            if (primi[cont][cont2] == bola) {
                primi[cont][cont2] = -1;
                aux2[cont]++;
            }
}

void premios (int aux2[], int primi[][7], int comple)
{
    int cont, cont2, cont3;

    for (cont = 0; cont < 10; cont++)
        switch (aux2[cont]) {

            case 3:
                printf ("El jugador %d ha tenido %d aciertos(3).\n", cont + 1,
                        aux2[cont]);
                break;

            case 4:
                printf ("El jugador %d ha tenido %d aciertos(4).\n", cont + 1,
                        aux2[cont]);
                break;

            case 5:

                for (cont3 = 0; cont3 < 6; cont3++)
                    if (primi[cont][cont3] == comple)
                        printf
                            ("El jugador %d tiene %d y el complementario.(5)",
                             cont + 1, aux2[cont]);
                    else
                        printf ("El jugador %d ha tenido %d aciertos(5).\n",
                                cont + 1, aux2[cont]);

                break;

            case 6:
                printf ("El jugador %d ha tenido %d aciertos(6).\n", cont + 1,
                        aux2[cont]);

                break;

            default:
                printf ("El jugador %d será mejor que haga una quiniela.\n",
                        cont + 1);

                break;
        }
}

void main (void)
{
    int primi[10][7], aux[49], aux2[10], indice2, bola, rein, comple;

    clrscr ();
    randomize ();

    for (indice2 = 0; indice2 < 10; indice2++)
        aux2[indice2] = 0;

    vaciar (aux);

    rellenar (aux, primi);

    for (indice2 = 0; indice2 < 6; indice2++) {
        bola = sacarbola (aux);
        comprobar (primi, bola, aux2);
    }

    printf ("\nComplementario: ");
    comple = sacarbola (aux);
    printf ("%d", comple);
    rein = rand ()%10;
    printf ("\nReintegro: %d\n", rein);
    premios (aux2, primi, comple);

    for (indice2 = 0; indice2 < 10; indice2++)
        if (primi[indice2][6] == rein)
            printf ("El jugador %d se conforma con el reintegro.");

    getch ();
}
