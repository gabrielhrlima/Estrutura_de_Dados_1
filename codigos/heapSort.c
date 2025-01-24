# include <stdio.h>
# include <stdlib.h>
# include "../Biblioteca/myLib.h"

// static Item *pq; // Criando uma lista de forma global
// static int N; // tamnaho da fila


// void PQinit_a(int maxN){
//     pq = malloc(sizeof(pq)*(maxN+1));
//     N = 0;
// }

// int PQempty_a(){
//     return N==0;
// }

// void fixUp_a(int k){
//     printf("FixUp:\n");
//     imprime_Vetor(pq, N+1);
//     while (k>1 && less(pq[k/2], pq[k]))
//     {
//         swap(pq[k], pq[k/2]);
//     imprime_Vetor(pq, N+1);
//         k/=2;
//     }
// }

// void PQinsert_a(Item x){
    
//     pq[++N] = x;
//     printf("Insert %d\n", x);
//     fixUp_a(N);
// }

// void fixDown_a(int k, int n){
//     printf("FixDown:\n");
//     imprime_Vetor(pq, N+1);
//     while (k*2 <=n)
//     {
//         int j = k*2; // filho esquerda
//         if (j<n && less(pq[j], pq[j+1])) j++;// filho direita

//         if (less(pq[k], pq[j])) swap(pq[k], pq[j]);
//     imprime_Vetor(pq, N+1);

//         k =j;
//     }
// }



// Item PQremove_a(){
//     if(!PQempty_a()){
//     swap(pq[1], pq[N]);
//     fixDown_a(1,N-1);
//     printf("O item liberado foi: %d\n", pq[N]);
//     return pq[N--];
//     }

//     printf("Fila vazia!\n");
//         return -1; // Valor inválido
// }




int main(int argc, char const *argv[])
{
    PQinit_a(10);
    
    PQinsert_a(8);
    PQinsert_a(9);
    PQinsert_a(7);
    PQinsert_a(6);
    PQinsert_a(3);
    PQinsert_a(5);
    PQinsert_a(3);
    PQinsert_a(4);
    PQinsert_a(1);
    PQinsert_a(10);
    imprimepq();

    // imprime_Vetor(pq, N+1);
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    PQremove_a();
    // imprime_Vetor(pq, 10);
    imprimepq();
    return 0;
}
