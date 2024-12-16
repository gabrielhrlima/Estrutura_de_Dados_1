#include <stdio.h>
#include <stdlib.h>

typedef int Item;


// ========================SIMPLES==========================================

// no simples
typedef struct node_s
{
    Item info;
    struct node_s *prox;
}no_s;

// cabeca simples
typedef struct head_s
{
    int tam;
    no_s *prox;
    no_s *ultimo;
}cabeca_s;

// criar lista simples
cabeca_s *criar_lista_s(){
    cabeca_s *lista = malloc(sizeof(cabeca_s));
    if (lista == NULL) return NULL;
    lista->prox= NULL;
    lista->ultimo = NULL;
    lista->tam = 0;

    return lista;
}

// criar no simples
no_s *criar_no_s(Item x){
    no_s *novo = malloc(sizeof(no_s));
    if (novo == NULL) return NULL;
    novo->info = x;
    novo->prox= NULL;
     
    return novo;
}

// verifica se uma lista simplesmente encadeada está vazia
int vazia_s(cabeca_s *lista){
    return (lista->prox ==NULL);
}

// enfineira uma lista simplesmente encadeada
void enfileirar_s(cabeca_s *fila, Item x)
{
    no_s *novo = criar_no_s(x);
    if(novo ==NULL){
        printf("Não foi possível criar nó\n");
        return;
    }
    if(vazia_s(fila)){
        fila->prox = novo;
    }else{
        fila->ultimo->prox = novo;
    }
        fila->ultimo = novo;
        fila->tam++;

        printf("Item enfileirado com sucesso!\n");
}

// imprime uma lista simplesmente encadeada
void imprime_lista_s(cabeca_s *lista){
    no_s *aux = NULL;
    if( vazia_s(lista)) {
    printf("lista vazia! \n");
    }else{
        aux = lista->prox;
        printf("Lista simples:[");
        while (aux !=NULL)
        {
            printf("info: %d --> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL ]\ntamanho da lista: %d\nLista->ultimo %d\n", lista->tam, lista->ultimo->info);
    }
}

Item desenfileirar_s(cabeca_s *fila){
    if(vazia_s(fila)){
        printf("Não foi possível desenfileirar, fila vazia!\n");
        return -1;
    }

    no_s *lixo = fila->prox;
    Item valor = lixo->info;
    fila->prox =lixo->prox;

    if (fila->prox == NULL) fila->ultimo = NULL;
    fila->tam--;

    free(lixo);
    printf("Item desenfileirado %d\n", valor);
    return valor;
}

// libera uma lista simplesmete encadeada
void liberar_lista_s(cabeca_s *lista) {
    if (lista == NULL) return; // Se a lista for NULL, não faz nada

    no_s *atual = lista->prox; // Começa do primeiro nó
    no_s *temp; // Ponteiro temporário para armazenar o nó a ser liberado

    while (atual != NULL) {
        temp = atual;         // Armazena o nó atual
        atual = atual->prox;  // Avança para o próximo nó
        free(temp);           // Libera a memória do nó atual
    }

    free(lista); // Libera a memória da estrutura da lista
}


// ========================DUPLA==========================================


// no duplo
typedef struct node_d
{
    Item info;
    struct node_d *prox;
    struct node_d *ant;
}no_d;


// cabeca dupla
typedef struct head_d
{
    int tam;
    no_d *prox;
    no_d *ultimo;
}cabeca_d;



// criar lista dupla

cabeca_d *criar_lista_d(){

    cabeca_d *lista = malloc(sizeof(cabeca_d));

    if(lista == NULL) return NULL;
    lista->prox = NULL;
    lista->ultimo = NULL;
    lista->tam=0;

    return lista;
}


// criar no duplo

no_d *criar_no_d(Item x){

    no_d *novo = malloc(sizeof(no_d));
    if (novo ==NULL) return NULL;
    novo->info = x;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

// verifica se uma lista duplamente encadeada está vazia
int vazia_d(cabeca_d *lista){
    return (lista->prox ==NULL);
}


// deve enfileirar uma lista duplamente encadeada
void enfileirar_d(cabeca_d *fila, Item x)
{
    no_d *novo = criar_no_d(x);
    if(novo ==NULL){
        printf("Não foi possível criar nó\n");
        return;
    }
    if(vazia_d(fila)){
        fila->prox = novo;
        novo->ant = fila;
    }else{
        fila->ultimo->prox = novo;
        novo->ant = fila->ultimo;
    }
        fila->ultimo = novo;
        fila->tam++;

        printf("Item enfileirado com sucesso!\n");
}

// deve desenfileirar uma lista duplamente encadeada

Item desenfileirar_d(cabeca_d *fila){

    if(vazia_d(fila))
    {
        printf("Não foi possível desenfileirar, fila vazia!\n");
        return -1;
    }

    no_d *lixo =fila->prox;
    Item valor = lixo->info;
    fila->prox =lixo->prox;
    lixo->prox->ant = fila;
    if (fila->prox == NULL) fila->ultimo = NULL;
    fila->tam--;

    free(lixo);
    printf("Item desenfileirado %d\n", valor);
    return valor;
}




// libera uma lista duplamete encadeada
void liberar_lista_d(cabeca_d *lista) {
    if (lista == NULL) return; // Se a lista for NULL, não faz nada

    no_d *atual = lista->prox; // Começa do primeiro nó
    no_d *temp; // Ponteiro temporário para armazenar o nó a ser liberado

    while (atual != NULL) {
        temp = atual;         // Armazena o nó atual
        atual = atual->prox;  // Avança para o próximo nó
        free(temp);           // Libera a memória do nó atual
    }

    free(lista); // Libera a memória da estrutura da lista
}

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

//======================== FILA COM ARRAY=================================================
// #define TAM 10

// Item fila[TAM];
// int p,u;

// // criando a fila
// void criar_fila_etc(){ // INICIALIZA OS DOIS APONTADORES DE INÍCIO E FIM DA LISTA
//     p=u=0;
// }

// // vazia
// int vazia(){
//     return p==u;
// }

// // desenfileirar
// Item desenfileirar_etc(){
//     return fila[p++];
//     //retorna o valor da primeira posição e depois incrementa p, dessa forma o Item que estava em p é "removido da lista" pois a lista começa a contar apenas depois dele 
// }

// void enfileirar_etc(Item x){
//     fila[u++] = x;
//     // primeira mente adiona o novo Item na fila e depois incrementa o valor de u
// }

//========================================== PILHA =================================================


void empilha_s(cabeca_s *pilha, Item x){
    no_s *novo = criar_no_s(x);

    if(novo)
    {
        if (vazia_s(pilha))
        {
            pilha->ultimo = novo;
        }
        novo->prox = pilha->prox;
        pilha->prox = novo;
        pilha->tam++;
    }else
    {
        printf("Erro ao empilhar!\n");
    }
}

Item desempilhar_s(cabeca_s *pilha)
{
    if (vazia_s(pilha))
    {
        printf("Pilha vazia!\n");
        return -1;
    }else
    {
        Item valor = pilha->prox->info;
        no_s *temp = pilha->prox;
        if (pilha->tam ==1) 
        {
            pilha->prox=NULL;
            pilha->ultimo=NULL;
        }else
        {
            pilha->prox = pilha->prox->prox; 
        }
        free(temp);
        pilha->tam--;
        printf("Item desempilhado com sucesso!\nItem desempilhado: %d\n", valor);
        return valor;   
    }
}



int main(int argc, char const *argv[])
{
    
    cabeca_s *pilha = criar_lista_s();
    // cabeca_d *fila = criar_lista_s();
    // cabeca_d *fila_d = criar_lista_d();
    Item a=5,b=6,c=2,d=9,e=20,f=50,g= 10,h=1,i=46,j=30,k=14,l=90;

    // desenfileirar_s(fila);
    // enfileirar_s(fila,a);
    // enfileirar_s(fila,b);
    // enfileirar_s(fila,c);
    // enfileirar_s(fila,d);
    // enfileirar_s(fila,e);
    // enfileirar_s(fila,f);
    // enfileirar_s(fila,g);
    // enfileirar_s(fila,h);
    // enfileirar_s(fila,i);
    // enfileirar_s(fila,j);
    // enfileirar_s(fila,k);
    // enfileirar_s(fila,l);
    // imprime_lista_s(fila);
    // desenfileirar_s(fila);
    // desenfileirar_s(fila);    
    // desenfileirar_s(fila);
    // desenfileirar_s(fila);
    // desenfileirar_s(fila);
    // imprime_lista_s(fila);
    // liberar_lista_s(fila);
    
    // desenfileirar_d(fila_d);
    // enfileirar_d(fila_d,a);
    // enfileirar_d(fila_d,b);
    // enfileirar_d(fila_d,c);
    // enfileirar_d(fila_d,d);
    // enfileirar_d(fila_d,e);
    // enfileirar_d(fila_d,f);
    // enfileirar_d(fila_d,g);
    // enfileirar_d(fila_d,h);
    // enfileirar_d(fila_d,i);
    // enfileirar_d(fila_d,j);
    // enfileirar_d(fila_d,k);
    // enfileirar_d(fila_d,l);
    // imprime_lista_d(fila_d);
    // desenfileirar_d(fila_d);
    // desenfileirar_d(fila_d);    
    // desenfileirar_d(fila_d);
    // desenfileirar_d(fila_d);
    // desenfileirar_d(fila_d);
    // imprime_lista_d(fila_d);
    // liberar_lista_d(fila_d);


    desempilhar_s(pilha);
    empilha_s(pilha, a);
    empilha_s(pilha, b);
    empilha_s(pilha, c);
    empilha_s(pilha, d);
    empilha_s(pilha, e);
    empilha_s(pilha, f);
    empilha_s(pilha, g);
    empilha_s(pilha, h);
    imprime_lista_s(pilha);
    desempilhar_s(pilha);
    desempilhar_s(pilha);
    desempilhar_s(pilha);
    imprime_lista_s(pilha);
    liberar_lista_s(pilha);



    return 0;
}
