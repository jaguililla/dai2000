#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<ctype.h>

int indice, cero;

int comprobar (char cad[], int total)
{
    for (indice = 0; indice < total; indice++)
        if (isdigit (cad[indice]) == 0)
            return (1);

    return (0);
}

void ceros (char cad[])
{
    int indice = 0, cont;

    while (cad[indice] == '0') {
        for (cont = 1; cont <= strlen (cad); cont++)
            cad[cont - 1] = cad[cont];
    }
}

int todoceros (char cad[])
{
    int cuenta = 0;

    if (cad[0] == '-')
        cuenta = 1;

    for (cuenta; cuenta < strlen (cad); cuenta++)
        if (cad[cuenta] != '0')
            return (1);

    return (0);

}

void menos (char cad[])
{
    int cont;

    cero = todoceros (cad);

    if (cero == '0')
        printf ("cero ");
    else if (cad[0] == '-')
        printf ("menos ");

    if (cad[0] == '-')
        for (cont = 1; cont <= strlen (cad); cont++)
            cad[cont - 1] = cad[cont];

}

void leer (char cad[], int total)
{
    int cont = 0, coc;          //partirá de la posición cero y llegará hasta indice

    while ((cont >= 0) && (cont < total)) {
        coc = (total - cont) / 6;

        switch ((total - cont) % 6) {

            case 1:

                switch (cad[total - 1 - (6 * coc)]) {

                    case '1':

                        if ((total - cont) > 6)
                            printf ("un ");
                        else
                            printf ("uno ");

                        break;

                    case '2':
                        printf ("dos ");

                        break;

                    case '3':
                        printf ("tres ");

                        break;

                    case '4':
                        printf ("cuatro ");

                        break;

                    case '5':
                        printf ("cinco ");

                        break;

                    case '6':
                        printf ("seis ");

                        break;

                    case '7':
                        printf ("siete ");

                        break;

                    case '8':
                        printf ("ocho ");

                        break;

                    case '9':
                        printf ("nueve ");

                        break;
                }

                break;

            case 2:

                switch (cad[total - 2 - (6 * coc)]) {

                    case '1':

                        switch (cad[total - 1 - (6 * coc)]) {

                            case '1':
                                printf ("once ");
                                break;

                            case '2':
                                printf ("doce ");
                                break;

                            case '3':
                                printf ("trece ");
                                break;

                            case '4':
                                printf ("catorce ");
                                break;

                            case '5':
                                printf ("quince ");
                                break;

                            case '6':
                                printf ("dieciseis ");
                                break;

                            case '7':
                                printf ("diecisiete ");
                                break;

                            case '8':
                                printf ("dieciocho ");
                                break;

                            case '9':
                                printf ("diecinueve ");
                                break;

                            case '0':
                                printf ("diez ");
                                break;
                        }

                        cont++;
                        break;

                    case '2':

                        if (cad[total - 1 - (6 * coc)] == '0')
                            printf ("veinte ");
                        else
                            printf ("veinti");

                        break;

                    case '3':
                        printf ("treinta ");

                        break;

                    case '4':
                        printf ("cuarenta ");

                        break;

                    case '5':
                        printf ("cincuenta ");

                        break;

                    case '6':
                        printf ("sesenta ");

                        break;

                    case '7':
                        printf ("setenta ");

                        break;

                    case '8':
                        printf ("ochenta ");

                        break;

                    case '9':
                        printf ("noventa ");

                        break;
                }

                if ((cad[total - 2 - (6 * coc)] > '2')
                    && (cad[total - 1 - (6 * coc)] != '0'))
                    printf ("y ");

                break;

            case 3:
                switch (cad[total - 3 - (6 * coc)]) {

                    case '1':

                        if ((cad[total - 2 - (6 * coc)] == '0')
                            && (cad[total - 1 - (6 * coc)] == '0'))
                            printf ("cien ");
                        else
                            printf ("ciento ");

                        break;

                    case '2':
                        printf ("dos");

                        break;

                    case '3':
                        printf ("tres");

                        break;

                    case '4':
                        printf ("cuatro");

                        break;

                    case '5':
                        printf ("quinientos ");

                        break;

                    case '6':
                        printf ("seis");

                        break;

                    case '7':
                        printf ("sete");

                        break;

                    case '8':
                        printf ("ocho");

                        break;

                    case '9':
                        printf ("nove");

                        break;
                }

                if ((cad[total - 3 - (6 * coc)] != '1')
                    && (cad[total - 3 - (6 * coc)] != '5')
                    && (cad[total - 3 - (6 * coc)] != '0'))
                    printf ("cientos ");

                break;

            case 4:
                switch (cad[total - 4 - (6 * coc)]) {

                    case '1':

                        if (cont != 0)
                            printf ("un ");

                        break;

                    case '2':
                        printf ("dos ");

                        break;

                    case '3':
                        printf ("tres ");

                        break;

                    case '4':
                        printf ("cuatro ");

                        break;

                    case '5':
                        printf ("cinco ");

                        break;

                    case '6':
                        printf ("seis ");

                        break;

                    case '7':
                        printf ("siete ");

                        break;

                    case '8':
                        printf ("ocho ");

                        break;

                    case '9':
                        printf ("nueve ");

                        break;
                }

                printf ("mil ");
                break;

            case 5:

                switch (cad[total - 5 - (6 * coc)]) {

                    case '1':

                        switch (cad[total - 4]) {

                            case '1':
                                printf ("once ");
                                break;

                            case '2':
                                printf ("doce ");
                                break;

                            case '3':
                                printf ("trece ");
                                break;

                            case '4':
                                printf ("catorce ");
                                break;

                            case '5':
                                printf ("quince ");
                                break;

                            case '6':
                                printf ("dieciseis ");
                                break;

                            case '7':
                                printf ("diecisiete ");
                                break;

                            case '8':
                                printf ("dieciocho ");
                                break;

                            case '9':
                                printf ("diecinueve ");
                                break;

                            case '0':
                                printf ("diez ");
                                break;
                        }

                        printf ("mil ");
                        cont++;
                        break;

                    case '2':

                        if (cad[total - 4 - (6 * coc)] == '0')
                            printf ("veinte ");
                        else
                            printf ("veinti");

                        break;

                    case '3':
                        printf ("treinta ");

                        break;

                    case '4':
                        printf ("cuarenta ");

                        break;

                    case '5':
                        printf ("cincuenta ");

                        break;

                    case '6':
                        printf ("sesenta ");

                        break;

                    case '7':
                        printf ("setenta ");

                        break;

                    case '8':
                        printf ("ochenta ");

                        break;

                    case '9':
                        printf ("noventa ");

                        break;
                }

                if ((cad[total - 5 - (6 * coc)] > '2')
                    && (cad[total - 4 - (6 * coc)] != '0'))
                    printf ("y ");

                break;

            case 0:
                switch (cad[total - (6 * coc)]) {

                    case '1':

                        if ((cad[total - 5 - (6 * coc)] == '0')
                            && (cad[total - 4 - (6 * coc)] == '0'))
                            printf ("cien ");
                        else
                            printf ("ciento ");

                        break;

                    case '2':
                        printf ("dos");

                        break;

                    case '3':
                        printf ("tres");

                        break;

                    case '4':
                        printf ("cuatro");

                        break;

                    case '5':
                        printf ("quinientos ");

                        break;

                    case '6':
                        printf ("seis");

                        break;

                    case '7':
                        printf ("sete");

                        break;

                    case '8':
                        printf ("ocho");

                        break;

                    case '9':
                        printf ("nove");

                        break;
                }

                if ((cad[total - (6 * coc)] != '1')
                    && (cad[total - (6 * coc)] != '5'))
                    printf ("cientos ");

                break;
        }

        if (((total - cont) % 6 == 1) && (total > 1))
            switch ((total - cont) / 6) {

                case 1:

                    if ((total == 7) && (cad[total - 7] == '1'))
                        printf ("millón ");
                    else
                        printf ("millones ");

                    break;

                case 2:
                    if ((total == 13) && (cad[total - 13] == '1'))
                        printf ("billón ");
                    else
                        printf ("billones ");

                    break;

                case 3:
                    if ((total == 19) && (cad[total - 19] == '1'))
                        printf ("trillón ");
                    else
                        printf ("trillones ");

                    break;

                case 4:
                    if ((total == 25) && (cad[total - 25] == '1'))
                        printf ("cuatrillón ");
                    else
                        printf ("cuatrillones ");

                    break;
            }

        cont++;
    }

    printf ("\b.");
}

void main (void)
{
    char cad[50], resp;
    int total, esta;

    clrscr ();

    do {
        printf ("Introduzca un número: ");

        do {
            gets (cad);
            menos (cad);
            total = strlen (cad);
            esta = comprobar (cad, total);

            if (esta != 0) {
                printf ("No metas porquería.");

                if (indice != total - 1)
                    printf (" A partir de la %c no vale.", cad[indice]);
                else
                    printf (" La %c no vale.", cad[indice]);

                printf ("\nIntroduzca otro: ");
            }

            if (total == 0)
                esta = 1;
        }
        while (esta != 0);

        ceros (cad);

        total = strlen (cad);

        leer (cad, total);

        printf ("\n\n¿Desea probar otro número?(s/n): ");

        do {
            resp = getche ();
            printf ("\n");
            resp = tolower (resp);

            if ((resp != 's') && (resp != 'n'))
                printf ("¿Otro número?(s/n): ");
        }
        while ((resp != 's') && (resp != 'n'));
    }
    while (resp == 's');
}
