struct nodo {
    int clave;
    struct nodo *i, *d;
};
int cont = 0, mayor = 0;

void esarbol (struct nodo *r, int *hallado)
{
    struct nodo *aux;

    if (*hallado) {
        if (r->i) {
            aux = r->i;
            if (aux->clave > r->clave)
                *hallado = 0;
            else
                esarbol (aux, hallado);
        }
        if (r->d) {
            aux = r->d;
            if (aux->clave < r->clave)
                *hallado = 0;
            else
                esarbol (aux, hallado);
        }
    }
}

void nivel (struct nodo *r)
{
    struct nodo *aux;

    if (r->i) {
        aux = r->i;
        cont++;
        nivel (aux);
    }
    if (r->d) {
        aux = r->d;
        cont++;
        nivel (aux);
    }
    if (cont > mayor)
        mayor = cont;
    cont--;
}
void nodos (struct nodo *r)
{
    struct nodo *aux;

    if (r->i) {
        aux = r->i;
        cont++;
        nivel (aux);
    }
    if (r->d) {
        aux = r->d;
        cont++;
        nivel (aux);
    }
}
