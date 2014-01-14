/****************************************************************
                    CALENDARIO PERPETUO
****************************************************************/
/* Dada una fecha (dia, mes, año)
 * indicar el día correspondiente de la semana.
 *
 * calendar.c
 */
#include <stdio.h>
#include <stdlib.h>

void LeerFecha (int *dia, int *mes, int *anyo);
void EntradaDatos (int *dia, int *mes, int *anyo);
int DatosValidos (int dia, int mes, int anyo);
int AnyoBisiesto (int anyo);
void EscribirFecha (int dd, int mm, int aa);
int DiaSemana (int dia, int mes, int anyo);

void main (void)
{                               /* función Principal */
    int dia, mes, anyo;

    LeerFecha (&dia, &mes, &anyo);
    EscribirFecha (dia, mes, anyo);
}

/****************************************************************
                          FUNCIONES
****************************************************************/

void LeerFecha (int *dia, int *mes, int *anyo)
{
    int datos_validos;

    do {
        EntradaDatos (dia, mes, anyo);
        datos_validos = DatosValidos (*dia, *mes, *anyo);
    }
    while (!datos_validos);
}

void EntradaDatos (int *dia, int *mes, int *anyo)
{
    printf ("Día (1 - 31)   ");
    scanf ("%d", dia);
    printf ("Mes (1 - 12)   ");
    scanf ("%d", mes);
    printf ("Año (1582 -->) ");
    scanf ("%d", anyo);
}

int DatosValidos (int dia, int mes, int anyo)
{
    int r, anyoB, mesB, diaB;

    anyoB = (anyo >= 1582);
    mesB = (mes >= 1) && (mes <= 12);
    switch (mes) {
        case 2:
            if (r == AnyoBisiesto (anyo))
                diaB = (dia >= 1) && (dia <= 29);
            else
                diaB = (dia >= 1) && (dia <= 28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diaB = (dia >= 1) && (dia <= 30);
            break;
        default:
            diaB = (dia >= 1) && (dia <= 31);
    }
    if (!(diaB && mesB && anyoB)) {
        printf ("\nDATOS NO VALIDOS\n\n");
        printf ("Pulse <Entrar> para continuar ");
        r = getchar ();
        fflush (stdin);
        return (0);
    }
    else
        return (1);
}

int AnyoBisiesto (int anyo)
{
    int verdad = 1, falso = 0;

    if ((anyo % 4 == 0) && (anyo % 100 != 0) || (anyo % 400 == 0))
        return (verdad);
    else
        return (falso);
}

void EscribirFecha (int dd, int mm, int aa)
{
    int d;
    static char dia[7][10] = { "Sábado", "Domingo", "Lunes",
        "Martes", "Miércoles", "Jueves",
        "Viernes"
    };
    static char mes[12][11] = { "Enero", "Febrero", "Marzo",
        "Abril", "Mayo", "Junio", "Julio",
        "Agosto", "Septiembre", "Octubre",
        "Noviembre", "Diciembre"
    };

    d = DiaSemana (dd, mm, aa);
    printf ("\n%s %d de %s de %d\n", dia[d], dd, mes[mm - 1], aa);
}

int DiaSemana (int dia, int mes, int anyo)
{
    if (mes <= 2) {
        mes = mes + 12;
        anyo = anyo - 1;
    }
    return ((dia + 2 * mes + 3 * (mes + 1) / 5 + anyo + anyo / 4 -
             anyo / 100 + anyo / 400 + 2) % 7);
}
