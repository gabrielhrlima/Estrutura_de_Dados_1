#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2){
    celula *aux = l->prox;
    celula *aux_1 = l1;
    celula *aux_2 =l2;

    while (aux != NULL)
    {
        if(aux->dado %2 ==0)
        {
            aux_2->prox = aux;
            aux_2 = aux_2->prox;
        }else
        {
            aux_1->prox=aux;
            aux_1= aux_1->prox;
        }
        aux =aux->prox;
    }
    
    aux_1->prox = NULL;
    aux_2->prox = NULL;
    l->prox = NULL;
}