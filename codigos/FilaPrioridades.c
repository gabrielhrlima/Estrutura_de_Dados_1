# include<stdio.h>
# include<stdlib.h>
# include "../Biblioteca/myLib.h"


// Criar os vetores de uma forma mais genérica

// modelo básico de todos os vetores
typedef struct FilaPrioridades
{
    Item* v; // array que vai ser criada a fila
    int N; // quantidade de elementos dentro da fila 
    int maxN; //Capacidade maxima da fila
}PQ;


void imprime_pq(PQ *pq) {
    printf("FILA: [");
    for (int i = 0; i <= pq->N; i++) {
        printf("%d-", pq->v[i]);
    }
    printf("]\n");

}
// INICIALIZADOR DA FILA 

PQ *PQinit(int maxN){
    PQ *pq = malloc(sizeof(PQ));
    pq->v = malloc(sizeof(Item)*(maxN+1));
    pq->N = 0;
    pq->maxN = maxN;
    return pq;
}

//FUNÇÃO PARA LIBERAR A FILA DA MEMÓRIA
void libera_pq(PQ *fila){
    free(fila->v);
    free(fila);
}

//FUNÇÃO PARA VERIFICAR SE UMA FILA ESTÁ VAZIA 
int PQempty(PQ *fila){
    return fila->N == 0;
}

void fixUp(PQ *pq){
    printf("FixUP\n");
    imprime_pq(pq);
    int k = pq->N;
    while (k>1 && less(pq->v[k/2], pq->v[k]))
    {
        swap(pq->v[k], pq->v[k/2]);
        imprime_pq(pq);
        k /=2;
    }
}

// FUNÇÃO PARA INSERIR NA FILA 
void PQinsert(PQ *pq, Item x){
    if(pq->N >= pq->maxN){
        printf("Fila Cheia!\n");
        return;
    }
    pq->v[++pq->N] = x;

    fixUp(pq);

}

void fixDown(PQ *pq){
    int k =1;
    while (2*k <= pq->N)
    {
        //primeiro passo é encontrar o maior filho
        int j = 2*k; //filho a esquerda
        // se o elemento da direita for o maior??
        if (j<pq->N && less(pq->v[j], pq->v[j+1])) j++;
        
        //se o pai for menor q o filho tem q trocar 
//                   pai       filho
        if (less(pq->v[k], pq->v[j])) 
        {
        swap(pq->v[k], pq->v[j]);
        }else{
            break;
        }
        //atualizando: o filho vira o novo pai
        k= j;
    }
}

Item PQremove(PQ* pq) {
    if (PQempty(pq)) {
        printf("Fila vazia!\n");
        return -1; // Valor inválido
    }
    Item max = pq->v[1]; // Maior elemento
    swap(pq->v[1], pq->v[pq->N]); // Troca com o último elemento
    pq->N--; // Reduz o tamanho da fila
    fixDown(pq); // Reorganiza a heap
    printf("O item liberado foi: %d\n", max);
    return max; // Retorna o maior elemento
}

// Função principal
int main(int argc, char const *argv[]) {
    PQ *pq1 = PQinit(10);

    PQinsert(pq1, 8);
    PQinsert(pq1, 9);
    PQinsert(pq1, 7);
    PQinsert(pq1, 6);
    PQinsert(pq1, 3);
    PQinsert(pq1, 5);
    PQinsert(pq1, 3);
    PQinsert(pq1, 4);
    PQinsert(pq1, 1);
    PQinsert(pq1, 10);

    imprime_pq(pq1);
    PQremove(pq1);
    imprime_pq(pq1);



    libera_pq(pq1);

    // int a =less(10,8);
    // printf("%d\n",a);
    return 0;
}
