/* tiradado.c -- juega a los dados */
#define ESCALA 32768.0
extern short aleat1 (void);
int cubilete (int lados)
{
    float tirada;

    tirada = ((float) aleat () / ESCALA + 1.0) * lados / 2.0 + 1.0;
    return ((int) (tirada));
}
