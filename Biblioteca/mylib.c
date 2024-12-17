#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>

// MACROS
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A)<=key(B))
#define swap(A,B) {int t =A; A=B; B=t;}
#define compswap(A,B) if(less(A,B)) swap(A, B)



// Funções para lista duplamente encadeada--------------------------------------------------------------------------
void imprime_lista_d(cabeca_d *lista) {
    if (vazia_d(lista)) {
        printf("Lista vazia!\n");
        return;
    }

    no_d *atual = lista->prox;
    printf("Lista (direta): ");
    while (atual != NULL) {
        printf("%d", atual->info);
        if (atual->prox != NULL) printf(" -> ");
        atual = atual->prox;
    }
    printf("\n");

    atual = lista->ultimo;
    printf("Lista (reversa): ");
    while (atual != NULL && atual->ant != (no_d *) lista) {
        printf("%d", atual->info);
        if (atual->ant != (no_d *) lista) printf(" <- ");
        atual = atual->ant;
    }
    printf("\n");
}

cabeca_d *criar_lista_d() {
    cabeca_d *lista = malloc(sizeof(cabeca_d));
    if (lista == NULL) return NULL;
    lista->prox = NULL;
    lista->ultimo = NULL;
    lista->tam = 0;
    return lista;
}

no_d *criar_no_d(Item x) {
    no_d *novo = malloc(sizeof(no_d));
    if (novo == NULL) return NULL;
    novo->info = x;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

int vazia_d(cabeca_d *lista) {
    return (lista->prox == NULL);
}

void liberar_lista_d(cabeca_d *lista) {
    if (lista == NULL) return;

    no_d *atual = lista->prox;
    no_d *temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(lista);
}

// Funções para lista simplesmente encadeada--------------------------------------------------------------------------------------
cabeca_s *criar_lista_s() {
    cabeca_s *lista = malloc(sizeof(cabeca_s));
    if (lista == NULL) return NULL;
    lista->prox = NULL;
    lista->ultimo = NULL;
    lista->tam = 0;
    return lista;
}

no_s *criar_no_s(Item x) {
    no_s *novo = malloc(sizeof(no_s));
    if (novo == NULL) return NULL;
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

int vazia_s(cabeca_s *lista) {
    return (lista->prox == NULL);
}

void liberar_lista_s(cabeca_s *lista) {
    if (lista == NULL) return;

    no_s *atual = lista->prox;
    no_s *temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(lista);
}

void imprime_lista_s(cabeca_s *lista) {
    no_s *aux = NULL;
    if (vazia_s(lista)) {
        printf("Lista vazia! \n");
    } else {
        aux = lista->prox;
        printf("Lista simples: [");
        while (aux != NULL) {
            printf("info: %d --> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL ]\ntamanho da lista: %d\n", lista->tam);
    }
}

//Funções para usar com vetores-----------------------------------------------------------------------------------
void imprime_vetor(int v[],int l, int r){
    printf("{");
    for (int i = l; i <= r; i++)
    {
    printf("%d ", v[i]);
        
    }
    printf("}\n");
    
}

void imprime_Vetor(int v[], int tam ){
    printf("Vetor auxiliar [");
    for (int i = 0; i <tam ; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}



