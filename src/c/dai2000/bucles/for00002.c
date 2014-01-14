/* 4101 */
/* Muestra el código ASCII en pantalla */
void main (void)
{
    int codigo;

    for (codigo = 32; codigo <= 255; codigo++)
        /*  Desde codigo 32 y mientras código <= 255
           escribir código en 3 espacios y
           su caracter correspondiente (%c)
           DESPUES, INCREMENTAR código */
    {
        printf ("%3d  %c  ", codigo, codigo);
    }
}
