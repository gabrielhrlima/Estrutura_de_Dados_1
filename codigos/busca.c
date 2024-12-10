#include <stdio.h>
#include <stdlib.h>
// #include "biblioteca/minhabiblioteca.h"

#define key(A) (A.chave)
typedef int Key;
typedef struct data Item;
struct data {char info[100];Key chave;};

int busca_binaria(Item *v, int l, int r, Key k){
    if(l > r) return -1; // se o elemento não existir no vetor a busca binara retorna -1 para indicar essa condição

    int m = (l + r)/2;

    if( k == key(v[m])) return m;

    if(k < key(v[m])) return busca_binaria(v,l,m-1, k);

    return busca_binaria(v,m+1,r, k);

}

int busca_sequencial(Item *v, int l, int r, Key k){

    for (int i = l; i <= r; i++)
    {
        if(k == key(v[i])) return i;
    }
    return -1;
}




// Item *cria_lista_ordenada(){
//     Item v[] ={
//     {"Item 1", 5},     // chave = 5
//     {"Item 2", 7},     // chave = 7
//     {"Item 3", 12},    // chave = 12
//     {"Item 4", 15},    // chave = 15
//     {"Item 5", 18},    // chave = 18
//     {"Item 6", 22},    // chave = 22
//     {"Item 7", 25},    // chave = 25
//     {"Item 8", 30},    // chave = 30
//     {"Item 9", 37},    // chave = 37
//     {"Item 10", 45}    // chave = 45
//     };
//     return v;
// }




int main(int argc, char const *argv[])
{
    Item  v[] ={
    {"Item 1", 5},     // 0 chave = 5
    {"Item 2", 7},     // 1 chave = 7
    {"Item 3", 12},    // 2 chave = 12
    {"Item 4", 15},    // 3 chave = 15
    {"Item 5", 18},    // 4 chave = 18
    {"Item 6", 22},    // 5 chave = 22
    {"Item 7", 25},    // 6 chave = 25
    {"Item 8", 30},    // 7 chave = 30
    {"Item 9", 37},    // 8 chave = 37
    {"Item 10", 45}    // 9 chave = 45
    };
    int busca = busca_binaria(v,0,9, 25);

    printf("O valor é: %d\n", busca);
    printf("O valor é: %s\n", v[busca].info);
    




    return 0;
}
