#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int remove_depois(celula *p){
    if (p->prox ==NULL || p ==NULL)
    {
        return 0;
    }else
    {
        celula *temp= p->prox;
        p->prox = p->prox->prox;
        free(temp);
    }
    return 1; 
}

void remove_elemento(celula *le, int x){
    celula *ant = le;
    celula *atual =le->prox;

    while (atual != NULL)
    {
        if (atual->prox == x)
        {
            ant->prox =atual->prox;
            free(atual);
            break;
        }
        ant = atual;
        atual=atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x){
    celula *ant = le;
    celula *atual =le->prox;

    while (atual != NULL)
    {
        if (atual->prox == x)
        {
            ant->prox =atual->prox;
            free(atual);
            atual =ant->prox;
        }else
        {
            ant = atual;
            atual=atual->prox;
        }
        
    }
}