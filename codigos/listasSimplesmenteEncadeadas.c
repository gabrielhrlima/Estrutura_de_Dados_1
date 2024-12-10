#include <stdio.h>
#include <stdlib.h>
// #include "biblioteca/minhabiblioteca.h"



// criar os nós da listas
typedef int Item;
typedef struct node no; // apelido da struct, no lugar de struct node usa no
struct node
{
    Item info;
    no *prox;
};

// Cria o tipo da cabeça da lista
typedef struct head cabeca;
struct head
{
    int tam;
    no *prox;
    no *ultimo;
};


//cria a cabeça da lista 
cabeca *criar_lista(){
    cabeca *lista = malloc(sizeof(cabeca)); 
    if (lista == NULL) return NULL; // Verifica se a alocação foi bem-sucedida
    lista->tam = 0;
    lista->prox = NULL;
    lista->ultimo = NULL;

    return lista;
}

// cria mais um no da lista
no *criar_no(Item x){
    no *novo = malloc(sizeof(no));
    if (novo == NULL) return NULL; // Verifica se a alocação foi bem-sucedida
    novo->info =x;
    novo->prox =NULL;

    return novo;
}

void inserir_inicio(cabeca *lista, no *elem){
    elem->prox = lista->prox;
    lista->prox= elem;
    lista->tam++;
    if(elem->prox == NULL)lista->ultimo =elem;
}

void inserir_depois(cabeca *lista, no *ref, no *novo){
    novo->prox = ref->prox;
    ref->prox = novo;
    lista->tam++;
    if(ref->prox ==NULL)lista->ultimo = novo;
}

void inserir_fim(cabeca *lista, no * novo){

    if(vazia(lista)) {
    return inserir_inicio(lista, novo);
    }else{
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }
    lista->tam++;
}

void remover_inicio(cabeca *lista){
    if(vazia(lista)) return;
    no *lixo =lista->prox;
    lista->prox =lixo->prox;
    lista->tam--;
    if(lista->prox ==NULL) lista->ultimo = NULL;
    free(lixo);
}

void remover_no(cabeca *lista,  no *lixo){
    if(lista->prox == lixo) {
        remover_inicio(lista);
        return;
    }

    no *ant=lista->prox;

    while (ant->prox !=NULL && ant->prox != lixo) ant =ant->prox;

    if(ant->prox == NULL){
        printf("ERRO: nó não encontrado\n");
    }

    ant->prox = lixo->prox;
    lista->tam--;
    if(lixo->prox ==NULL) lista->ultimo = ant;
    free(lixo);

}

no *busca(cabeca *lista, Item x){
    no *aux = lista->prox;
    while (aux != NULL)
    {
        if (aux->info == x)
        {
            return aux;
        }

        aux = aux->prox;
    }
    return NULL;
}

int vazia(cabeca *lista){
    return (lista->prox ==NULL);
}

void imprime_lista(cabeca *lista){
    no *aux = NULL;
    if( vazia(lista)) {
    printf("lista vazia. \n");
    }else{
        aux = lista->prox;
        while (aux !=NULL)
        {
            printf("info: %d --> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL \ntamanho da lista: %d\nLista->ultimo %d\n", lista->tam, lista->ultimo->info);
    }
}
void liberar_lista(cabeca *lista) {
    if (lista == NULL) return; // Se a lista for NULL, não faz nada

    no *atual = lista->prox; // Começa do primeiro nó
    no *temp; // Ponteiro temporário para armazenar o nó a ser liberado

    while (atual != NULL) {
        temp = atual;         // Armazena o nó atual
        atual = atual->prox;  // Avança para o próximo nó
        free(temp);           // Libera a memória do nó atual
    }

    free(lista); // Libera a memória da estrutura da lista
}




int main(int argc, char const *argv[])
{

int a = lerinttela("informe o inteiro:");
printf("o numero é: %d", a);




// criar uma lista
// cabeca *a =criar_lista();
//  imprime_lista(a);

// no *no0 = criar_no(10);
// no *no1 = criar_no(20);
// no *no2 = criar_no(30);
// no *no3 = criar_no(40);

// // INSERINDO NO INCIO
// inserir_inicio(a, no0);
// inserir_inicio(a, no1);
// inserir_inicio(a, no2);
// inserir_inicio(a, no3);

// INSERINDO NO FIM
// inserir_fim(a, no0);
// inserir_fim(a, no1);
// inserir_fim(a, no2);
// inserir_fim(a, no3);

// INSERINDO DEPOIS DE UMA REFERENCIA
// inserir_inicio(a, no0); // iniciando a lista
// inserir_depois(a, no0, no1);
// inserir_depois(a, no1, no2);
// inserir_depois(a, no1, no3); // colocando em uma posição aleatória 

// BUSCA DE UM ELEMENTO
// inserir_inicio(a, no0);
// inserir_inicio(a, no1);
// int valor_busca =40 ;
// no *buscador = busca(a,valor_busca );
// if (buscador != NULL) {
//         printf("Elemento %d encontrado.\n", buscador->info);
//     } else {
//         printf("Elemento %d não encontrado.\n", valor_busca);
//     }

// REMOVENDO O PRIMEIRO ITEM DA LISTA
// inserir_inicio(a, no0);
// inserir_inicio(a, no1);
// inserir_inicio(a, no2);
// inserir_inicio(a, no3);
// printf("Lista antes\n");
// imprime_lista(a);
// remover_inicio(a);
// printf("Lista depois\n");

// REMOVENDO UM ITEM DA LISTA
// inserir_inicio(a, no0);
// inserir_inicio(a, no1);
// inserir_inicio(a, no2);
// inserir_inicio(a, no3);
// printf("Lista antes\n");
// imprime_lista(a);
// remover_no(a, no3);
// printf("Lista depois\n");


// imprime_lista(a);
// liberar_lista(a);







}
