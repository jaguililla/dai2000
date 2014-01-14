struct nodo {
    int clave;
    struct nodo *sig;
};

//modulo de vaciar una pila con una lista simplemente enlazada
void vaciar (struct nodo **cl)
{
    struct nodo *cl2;

    while (*cl) {
        cl2 = (*cl)->sig;
        free (cl);
        *cl = cl2;
    }
    printf ("La pila está vacía.");
}

//modulo de comprobar si una lse está ordenada
int comprobar (struct nodo *cl)
{
    struct nodo *cl2;

    do {
        cl2 = (cl)->sig;
        if ((cl)->clave > (cl2)->clave)
            return (1);
    } while (cl);
    return (0);
}

//modulo que comprueba si tiene elementos repetidos en una lse
int repe (struct nodo *cl)
{
    struct nodo *cl2;

    cl2 = cl->sig;
    while (cl2) {
        if (cl2->clave == cl->clave)
            return (1);
        cl = cl2;
        cl2 = cl->sig;
    }
    return (0);
}
