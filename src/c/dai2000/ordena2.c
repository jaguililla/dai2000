/* ordena.c -- ordena el array en orden decreciente */
void ordena (int array[], int limite)
{
    int tope, busca, temp;

    for (tope = 0; tope < limite - 1; tope++)
        for (busca = tope + 1; busca < limite; busca++)
            if (array[busca] > array[tope]) {
                temp = array[busca];
                array[busca] = array[tope];
                array[tope] = temp;
            }
}
