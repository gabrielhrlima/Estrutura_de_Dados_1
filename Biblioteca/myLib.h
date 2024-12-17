#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item; 

// Estruturas para lista duplamente encadeada
typedef struct node_d {
    Item info;
    struct node_d *prox;
    struct node_d *ant;
} no_d;

typedef struct head_d {
    int tam;
    no_d *prox;
    no_d *ultimo;
} cabeca_d;

// Funções para lista duplamente encadeada
cabeca_d *criar_lista_d();
no_d *criar_no_d(Item x);
int vazia_d(cabeca_d *lista);
void liberar_lista_d(cabeca_d *lista);
void imprime_lista_d(cabeca_d *lista);

// Estruturas para lista simplesmente encadeada
typedef struct node_s {
    Item info;
    struct node_s *prox;
} no_s;

typedef struct head_s {
    int tam;
    no_s *prox;
    no_s *ultimo;
} cabeca_s;

// Funções para lista simplesmente encadeada
cabeca_s *criar_lista_s();
no_s *criar_no_s(Item x);
int vazia_s(cabeca_s *lista);
void liberar_lista_s(cabeca_s *lista);
void imprime_lista_s(cabeca_s *lista);
void imprime_vetor(int v[],int l, int r);
void imprime_Vetor(int v[], int tam );


#endif // MYLIB_H
