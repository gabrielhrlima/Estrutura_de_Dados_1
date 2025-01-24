#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
// gcc codigos/SEI_LA.c Biblioteca/mylib.c -o a
typedef int Item; 
// MACROS
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A)<=key(B))
#define swap(A,B) {int t =A; A=B; B=t;}
#define compswap(A,B) if(less(A,B)) swap(A, B)
#define TAM 10

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

// modelo básico de todos os vetores
typedef struct FilaPrioridades
{
    Item* v; // array que vai ser criada a fila
    int N; // quantidade de elementos dentro da fila 
    int maxN; //Capacidade maxima da fila
}PQ;

Item PQremove(PQ* pq);
void fixDown(PQ *pq);
void PQinsert(PQ *pq, Item x);
void fixUp(PQ *pq);
int PQempty(PQ *fila);
void libera_pq(PQ *fila);
PQ *PQinit(int maxN);
void imprime_pq(PQ *pq);


// Inicializa a fila de prioridade com um tamanho máximo
void PQinit_a(int maxN);

// Verifica se a fila de prioridade está vazia
int PQempty_a(void);

// Insere um item na fila de prioridade
void PQinsert_a(Item x);

// Remove e retorna o maior item da fila de prioridade
Item PQremove_a(void);

// Ajusta a posição de um item para cima no heap
void fixUp_a(int k);

// Ajusta a posição de um item para baixo no heap
void fixDown_a(int k, int n);

void imprimepq();

#endif // MYLIB_H
