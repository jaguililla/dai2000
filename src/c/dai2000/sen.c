//ALGORITMO SENO
long factorial (long num)
{
    unsigned long factor = 0;

    for (; num >= 1; num--) {
        factor *= num;
    }

    return (factor);
}

float sumando (long numero, int angulo)
{
    float suma = 0;

    suma = pow (angulo, numero);
    //suma/=factorial(numero);
    return (suma);
}

void main (void)
{
    float num1, res;
    int num2;

    printf ("Introduce: ");
    scanf ("%f%d", &num1, &num2);
    res = sumando (num1, num2);
    printf ("%f", res);
}

/*
void main(void)
{
 long num;
 int inter,indice;
 float seno,ang;
 clrscr();
 printf("Introduce el ángulo: ");
 scanf("%f",&ang);
 printf("Introduzca la precisión: ");
 scanf("%ld",&num);
 inter=1;
 if(num%2==0)
  num++;
 for(indice=1 ; indice <= num ;indice+=2 ){
  if(inter==1){
   seno+=sumando(indice,ang);
   inter--;
  }else{
   seno-=sumando(indice,ang);
   inter++;
  }
 }
 printf("El resultado es: %f\n",seno);
 printf("Según C: %ld",sin(ang));
 getch();
}*/
