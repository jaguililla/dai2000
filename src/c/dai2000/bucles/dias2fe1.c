  /* cálculo días entre dos fechas BIN\YO\DIAS2FE1 */
#define CIERTO 1
#define FALSO 0
int dias (int, int, int, int, int, int);
void leerfecha (int *, int *, int *);
int enteros (int, int);
int bisiesto (int);
int picos (int, int, int);

void main (void)
{
    int d1, m1, a1, d2, m2, a2;

    clrscr ();
    printf ("Introduzca fecha inicial: ");
    leerfecha (&d1, &m1, &a1);
    printf ("Día inicial: %d de %d de %d\n", d1, m1, a1);
    printf ("Introduzca fecha final: ");
    leerfecha (&d2, &m2, &a2);
    printf ("Día final: %d de %d de %d\n", d2, m2, a2);
    printf ("Dias transcurridos: %d\n", dias (d1, m1, a1, d2, m2, a2));
    getch ();
}
void leerfecha (int *d, int *m, int *a)
{                               // d- dias,  m- mes,  a-año
    printf ("Introduzca fecha d m a: ");
    scanf ("%d %d %d", d, m, a);
}
int dias (int di, int mi, int ai, int df, int mf, int af)
{
    return (enteros (ai, af) + picodias (af, mf, df) - picodias (ai, mi, di));
}
int enteros (int ai, int af)
{
    /* Calcula el número de días entre el año 'ai' y el año 'af - 1' */
    int i, dias = 0;

    for (i = ai; i <= af - 1; i++) {
        dias = dias + 365;
        if (bisiesto (i))
            dias++;
    }
    return (dias);
}
int picodias (int a, int m, int d)
{
    int i, dias;

    dias = 0;
    for (i = 1; i <= m - 1; i++)
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dias = dias + 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dias = dias + 30;
                break;
            case 2:
                if (bisiesto (a))
                    dias = dias + 29;
                else
                    dias = dias + 28;
                break;
        }                       //switch y for
    dias = dias + d;
    return (dias);
}
int bisiesto (int i)
{
    return (!(i % 4 && (i % 100 != 0 || i % 400 == 0)));
    /*  if (i % 4 != 0) return (FALSO);
       else
       if (i % 100 == 0)
       if (i % 400 ==0) return (CIERTO);
       else return (FALSO); */
}

/* YO\DIAS2FE1
  #define CIERTO 1
  #define FALSO 0
  int dias (int, int,int,int,int,int);
  void leerfecha (int *,int *, int * );
  int enteros (int, int);
  int bisiesto (int);
  int picos (int, int, int);

void main (void) {
  int d1,m1,a1,d2,m2,a2;
  clrscr();
  printf ("Introduzca fecha inicial: ");  leerfecha (&d1,&m1,&a1);
  printf ("Día inicial: %d de %d de %d\n",d1,m1,a1);
  printf ("Introduzca fecha final: ");    leerfecha (&d2,&m2,&a2);
  printf ("Día final: %d de %d de %d\n",d2,m2,a2);
  printf ("Dias transcurridos: %d\n", dias (d1,m1,a1,d2,m2,a2));
  getch();
}
  void leerfecha (int *d,int *m, int *a){ // d- dias,  m- mes,  a-año
    printf ("Introduzca fecha d m a: ");  scanf ("%d %d %d",d,m,a);
  }
  int dias (int di, int mi, int ai, int df, int mf, int af){
    return (enteros(ai,af) + picodias (af,mf,df) - picodias (ai,mi,di) );
  }
  int enteros (int ai, int af){
  /* Calcula el número de días entre el año 'ai' y el año 'af - 1'
    int i, dias=0;
    for (i=ai; i <= af-1; i++){
      dias = dias + 365;
      if (bisiesto(i))    dias++;
    }
    return (dias);
  }
  int picodias (int a, int m, int d) {
    int i,dias;
    dias = 0;
    for (i=1; i<= m-1; i++)
      switch (i) {
    case 1:    case 3:    case 5:    case 7:    case 8:    case 10: case 12:
      dias = dias + 31;
    break;
    case 4:    case 6:    case 9:    case 11:
      dias = dias + 30;
    break;
    case 2:
      if (bisiesto(a))  dias = dias + 29;
      else              dias = dias + 28;
    break;
      } //switch y for
    dias = dias + d;
    return (dias);
  }
  int bisiesto (int i) { return (!(i%4 && (i%100 != 0 || i%400 == 0)));
  /*  if (i % 4 != 0) return (FALSO);
      else
    if (i % 100 == 0)
      if (i % 400 ==0) return (CIERTO);
      else return (FALSO);
  }                           */
