#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

// INSERE INICIO
void insere_incio(celula *le, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
        novo->dado=x;
        novo->prox =le->prox;
        le->prox= novo;
}

// INSERE ANTES
void insere_antes(celula *le, int x, int y) {
    celula *aux =le;
    while (aux-> prox !=NULL)
    {
        if (aux->prox->dado ==y)
        {
            celula *novo=(celula *)malloc(sizeof(celula));
                novo->dado =x;
                novo->prox =aux->prox;
                aux->prox=novo;
            return;
        }
        aux=aux->prox;
    }
    
}
