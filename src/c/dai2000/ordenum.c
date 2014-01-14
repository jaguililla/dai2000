/* ordenum.c -- ordena enteros */
#define TAMMAX 100              /* límite de números a clasificar */
extern int getarray (int ar[], int n);
extern void ordena (int ar[], int n);
extern void imprime (int ar[], int n);
int main (void)
{
    int numeros[TAMMAX];        /* array para entrada */
    int total;                  /* número de entradas */

    total = getarray (numeros, TAMMAX); /* mete entrada en array */
    ordena (numeros, total);    /* ordena el array */
    imprime (numeros, total);   /* imprime el array ordenado */
    return 0;
}
