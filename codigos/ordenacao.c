#include <stdlib.h>
#include <stdio.h>
// #include "biblioteca/minhabiblioteca.h"
// typedef int Item;
// typedef int (*Compare)(const void *, const void *);
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A)<=key(B))
#define swap(A,B) {int t =A; A=B; B=t;}
#define compswap(A,B) if(less(A,B)) swap(A, B)

/*
Os algoritmos de ordenação servem para ordenar uma lista de dados, sendo eles arrays ou listas encadeadas. A eficiencia de uma algoritmo de ordenação é muito importante já que dependendo da entrada podem ocorrer problemas como, demora, não realização da tarefa ou estouro de memória.

*/


// void imprime_vetor(int v[],int l, int r){
//     printf("{");
//     for (int i = l; i <= r; i++)
//     {
//     printf("%d ", v[i]);
        
//     }
//     printf("}\n");
    
// }

void selection_sort(int v[], int l, int r){
    // O selectio_sort é um algotmo que tenta achar o elemento baseado na posição ("eu tenho uma posição e quero achar o valor que vai preeencher essa posição")
    int menor; // definição de uma variável para marcar qual o menor indice
    for (int i = l; i < r; i++) // laço que marca a posição 
    {
        menor = i; // a posição de i é iniciada sendo a do menor elemento
        for (int j = i+1;  j <= r; j++)// laço que procura o elemento para colocar na posição
        {
            if (v[j] < v[menor]) menor = j;
            // se o elemento da posição que está sendo verificada for menor que o elemento da posição que era a menor, deve atualizar qual a posição que possui o menor elemento  
        }   
        // o laço j percorre todo o vetor procurando o indice do menor elemento, se ele encontrar uma elemento menor que o elemnto incial(i) então ele troca os dois elementos
        if (i != menor)swap(v[i], v[menor]);
        imprime_vetor(v,l,r);
    }
}



void bubble_sort(int v[], int l, int r){
    // O bubble_sort é um algortimo que tem a intenção de achar o maior elemento e posicionar ele na ultima posição, com a adição de uma variável de controle, é possível fazer com que ele se torne adaptativo e reduza a verificação caso ele já esteja ordenado.
    int aux =r;
   int swap =1; // definição de uma variável de controle
   while (r>l && swap) // Em quanto o elemento mais a esquerda for maior que o mais a direita
   {
    swap = 0;
    for (int j = l; j+1 <= r; j++) // "flutua" o mior elemento para a posição mais a esquerda
    {
        if (v[j]>v[j+1]){ 
            swap(v[j], v[j+1]);
            swap =1;
        }
    } 
    r--;
    imprime_vetor(v, l, aux);
   }    
}
void imprime_Vetor(int v[], int tam ){
    printf("Vetor auxiliar [");
    for (int i = 0; i <tam ; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

// INSERTION_SORT OTIMIZADO
void insertion_sort(int v[], int l, int r){
    int elem, i, j; // definição de variáveis auxiliares
    for ( i = l+1; i <= r; i++) // percorre o vetor de forma crescente, i é o ponto onde tudo que está a esquerda já está pseudo-ordenado
    {
        elem = v[i]; // valor que será usado como marcador de com quem será comparado
        for ( j = i; j > l && elem <v[j-1] ; j--)// se o elemento de v[j-1] for maior q o elemento, tudo q está a direita de elem vai estar ordenado, e o elem será inserido na posição j
        {
            v[j] = v[j-1];// dessa forma ele abre espaço para a inserção do elem 
            imprime_vetor(v,l,r);
        }
        v[j] =elem; 
            imprime_vetor(v,l,r);
    }
}

// INSERTION_SORT OTIMIZADO
// void insertion_sort(int *v, int l, int r){
//     for (int i = l+1; i <= r ; i++)
//     {
//         for (int j = i; j >l && v[j]<v[j-1]; j--)
//         {
//             swap(v[j], v[j-1]);
//         }
//     }
// }


void shell_sort(int *v, int l, int r){
    int h; // quantidade de pulos 
    int elem, i, j; 
    while (h < (r-l+1)/3) // calculando o h máximo 
    {                       // para vetores muito grande pode ser feita alterações nesse laço (r-l+1)/9???
        h = (3*h)+1;
    }
    while (h>=1)// enquanto o h for maior que 1 ele vai dividir h por 3 (h/3)
    {
        printf("h = %d\n", h);
        //INSERTION SORT OTIMIZADO
    for ( i = l+h; i <= r; i++) 
    {
        elem = v[i]; 
        for ( j = i; j >= l+h && elem <v[j-h] ; j-=h)
        {
            v[j] = v[j-h]; 
            imprime_vetor(v,l,r);
        }
        v[j] =elem; 
        imprime_vetor(v,l,r);
    }
    h = h/3;
    }
}


void merge(int v[], int l, int r, int meio){
    //declaração das variáveis auxiliares
    int i = l, j= meio+1, k=0, tam = (r-l+1); 
    //criação do vetor auxiliar
    int *v2 = malloc(sizeof(int)*tam);// cria um vetor do tipo int com tam posições 
    //intercalar
    while (i<=meio && j<=r)// definição dos limites de cada subvetor
    {
        imprime_vetor(v,l,r);
        if (v[i] <= v[j]) // se o elemento a esquerda for maior que o elemento a direita
        {
            v2[k++] = v[i++];// copia o elemento da esqueda no vetor auxiliar v[i]
            imprime_vetor(v,l,r);
        imprime_Vetor(v2,tam);
        }else// senão
        {
            v2[k++] = v[j++];// copia o elemento da direira v[j]
            imprime_vetor(v,l,r);
        imprime_Vetor(v2,tam);
        }
    }
    // se restar algum elemento 
    while (i<=meio)// copia os elementos restantes a esquerda
    {
        v2[k++] = v[i++];
        imprime_Vetor(v2,tam);
    }
    while (j<=r)// copia o elementos restante a direita
    {
        v2[k++] = v[j++];
        imprime_Vetor(v2,tam);
    }

    k = 0;// zerando a variável que percorre o vetor auxiliar
    // copia o vetor auxilar, que já está ordendado, no vetor original 
    for ( i = l; i <=r; i++)
    {
        v[i] = v2[k++];
    }
    imprime_vetor(v,l,r);
    free(v2); //libera o espaço da memória
}

void merge_sort(int v[], int l, int r){
    imprime_vetor(v,l,r);
    if(l>=r) return ;
    int meio = (r+l)/2;
    merge_sort(v, l, meio); // ordena começando pela esquerda
    merge_sort(v, meio+1, r); // ordena a parte a direita
    merge(v,l,r,meio);
}


/*
as principais limitações do artigos estão ligados ao método das análises, o mesmo pesquisador foi colocar para avaliar uma mesma categoria com o auxilio do guia e treinamentos realizados previamente. Uma forma de resolver esse problema seia colocar pelo menos dois pesquisadores para avaliar cada categoria.

Outro ponto a ser considerado é a forma que foi feita a validação dos resultados, os pesquisadores apresentavam seus resultados a um pesquisador sênior e esse pesquisador avalia os resultados.

Outra limitação é que esse artigo avalia apenas as versões dos aplicativos na época que a pesquisa foi realizada, podendo sofrer alterações.

Por fim, talvez a maior limitação é que não teve nenhuma pessoa do espéctro autista na equipe de pesquisadores para avaliar os aplicativos, então os dados acabam por ser interpretações do GAIA



*/


#define key_2(A) (A.chave)
typedef int Key;
typedef struct data Item; 
struct data {char info[100];Key chave;};


                // 0               1               2
// Item v[] =[{"Jorge", 13},{"Lucas", 15},{"Mario", 20}];

// int v[] =[ 10, 48, 50]
//                                           13
int busca_binaria(Item v[],int l, int r, Key k ){ // k é a chave do elemento buscado
    // se o elemento for encontrado a busca binaria deve retornar a posiçãodo elemento
    // Senão ela deve retornar -1 indicando que o elemento não pertence ao veto
    if(r<l) return -1;

    int m = (r+l)/2; // posição do meio do vetor

    // verifica se o elemento do meio é o desejado
    // se ele for encontrado é essa a parte de retorna a posição
    if (k == key_2(v[m])) return m;
         // v[m].chave

    // se a chave do elemento for menor que o elemento do meio, faz a busca na parte a esquerda do meio
    if(k < key_2(v[m])) return busca_binaria(v, l, m-1, k);
    // se a chave do elemento for maio que o elemento do meio, faz a busca na parte a direira do meio
   return busca_binaria(v, m+1,r, k);
}


/*
    A ideia do quick_sort é ordenar um elemento por vez, colocando ele na suap posição final e garantindo que todos os elementos a sua esquerda são menores ou iguais a ele e que todos os elementos a sua direita são maiores que ele.
    

*/

     

int separa(int v[], int l, int r){
    int pivo = v[r];
    int j=l; // posição onde pode ser colocado o próximo elemento menor que o elemento 
    // k é a posição onde foi achado o ultimo menor elemento menor que o pivõ
    for ( int k=l ; k < r; k++)
    {
        imprime_vetor(v,l,r);
        if (v[k]<=pivo)// esse if só acontece se k achar um elemento menor que o pivo
        {
            swap(v[k],v[j]);
            j++;
        imprime_vetor(v,l,r);
        }
    }
    // agora j guarda a posição onde o pivô deve ficar, na ultima posição possível de ser guardado um elemento menor que o pivô
    swap(v[j], v[r]); // coloca o pivô na posição correta
        imprime_vetor(v,l,r);

    return j; // retorna a posição do pivô
}


// [30, 20, 50, 45, 10, 15]

// i= -1, 0
// j= 5, 4, 3
// pivo =10



int separa_2(int v[], int l, int r){
    printf("separa\n");
    int i =l-1;
    int j = r; 
    int pivo = v[r];
    imprime_vetor(v,l,r);
    while (i < j) // enquanto os limites não se cruzaram
    {               // se l = 0, i =-1, se o j for igual a -1 ele retorna sem precisar colocar um return, isso significa que o vetor está ordenado
        // procurando os elementos maiores
        while( v[++i]<pivo); // procura a posição do maior elemento que pode ser trocado por um menor
        imprime_vetor(v,l,r);
        printf("maior %d\n", v[i]);
        while( pivo < v[--j] && j>l); // procura a posição do menor que pode ser trocado contando de forma decrescente 
        imprime_vetor(v,l,r);
        printf("menor %d\n", v[j]);
        if(i<j) swap(v[i],v[j]);   // se os dois marcadores não se cruzaram
        imprime_vetor(v,l,r);
    }
    swap(v[i], v[r]);
    return i;
}





void quick_sort(int v[], int l, int r){
    printf("Quick\n");
    imprime_vetor(v,l,r);
    if(r<=l) return; // se r for menor ou igual a l significa que o elemento já está ordenado, e na posição final 
    int j;
    j = separa_2(v,l,r); // j é posição do pivô q já está na posição final, com os menores a esquerda e os maiores a direita
    quick_sort(v,l,j-1); // ordena a primeira parte do vetor
    quick_sort(v, j+1, r); // ordena a segunda parte do vetor
}


// com mediana de 3
void quick_sort_m(int v[], int l, int r){
    printf("Quick\n");
    imprime_vetor(v,l,r);
    if(r<=l) return; // se r for menor ou igual a l significa que o elemento já está ordenado, e na posição final 
    int j,m = (l+r)/2;

    compswap(v[m],v[l]);
    



    j = separa_2(v,l,r); // j é posição do pivô q já está na posição final, com os menores a esquerda e os maiores a direita
    quick_sort(v,l,j-1); // ordena a primeira parte do vetor
    quick_sort(v, j+1, r); // ordena a segunda parte do vetor
}






int main(int argc, char const *argv[])
{
    
    // // SELECTION
    // int vetor[] = {3,2,4,6,1,5};
    // int size = sizeof(vetor) / sizeof(vetor[0]);
    // printf("o tamanho é %d\n", size);
    // imprime_vetor(vetor,0, size-1);
    // selection_sort(vetor,0,size-1);
    // printf("\n vetor depois do selection:");
    // imprime_vetor(vetor,0, size-1);
    
    // // BUBBLE
    // int vetorb[] = {6,4,8,12,2,10};
    // // int vb[]={1,2,3,4,5,6,7,8,9,10};
    // int sizeb = sizeof(vetorb) / sizeof(vetorb[0]);
    // // int sizeb1 = sizeof(vb) / sizeof(vb[0]);
    // printf("o tamanho é %d\n", sizeb);
    // imprime_vetor(vetorb,0, sizeb-1);
    // bubble_sort(vetorb,0,sizeb-1);
    // printf("\n vetorb depois do bubble:");
    // imprime_vetor(vetorb,0, sizeb-1);


    // // INSERTION
    // int vi[] = {29, 10, 14, 37, 13, 18, 12, 25, 6, 20, 
    //              22, 19, 9, 27, 17, 3, 8, 11, 5, 1};

    // // int vb[]={1,2,3,4,5,6,7,8,9,10};
    // int sizei = sizeof(vi) / sizeof(vi[0]);
    // // int sizeb1 = sizeof(vb) / sizeof(vb[0]);
    // printf("o tamanho é %d\n", sizei);
    // imprime_vetor(vi,0, sizei-1);
    // insertion_sort(vi,0,sizei-1);
    // printf("\n vi depois do insertion:");
    // imprime_vetor(vi,0, sizei-1);
    
    // // SHELL
    // int vi[] = {29, 10, 14, 37, 13, 18, 12, 25, 6, 20, 
    //              22, 19, 9, 27, 17, 3, 8, 11, 5, 1};

    // // int vb[]={1,2,3,4,5,6,7,8,9,10};
    // int sizei = sizeof(vi) / sizeof(vi[0]);
    // // int sizeb1 = sizeof(vb) / sizeof(vb[0]);
    // printf("o tamanho é %d\n", sizei);
    // imprime_vetor(vi,0, sizei-1);
    // shell_sort(vi,0,sizei-1);
    // printf("\n vi depois do shell:");
    // imprime_vetor(vi,0, sizei-1);
   
    // // MERGE
    // int vi[] = {29, 10, 14, 37, 13, 18, 12, 25, 6, 20, 
    //              22, 19, 9, 27, 17, 3, 8, 11, 5, 1};

    // // int vb[]={1,2,3,4,5,6,7,8,9,10};
    // int sizei = sizeof(vi) / sizeof(vi[0]);
    // // int sizeb1 = sizeof(vb) / sizeof(vb[0]);
    // printf("o tamanho é %d\n", sizei);
    // imprime_vetor(vi,0, sizei-1);
    // merge_sort(vi,0,sizei-1);
    // printf("\n vi depois do merge:");
    // imprime_vetor(vi,0, sizei-1);
    
    // QUICK
    // int vi[] = {30, 20, 50, 45, 10, 15};
    // // int vi[] = {29, 10, 14, 37, 13, 18, 12, 25, 6, 20, 
    // //              22, 19, 9, 27, 17, 3, 8, 11, 5, 1};

    // // int vb[]={1,2,3,4,5,6,7,8,9,10};
    // int sizei = sizeof(vi) / sizeof(vi[0]);
    // // int sizeb1 = sizeof(vb) / sizeof(vb[0]);
    // printf("o tamanho é %d\n", sizei);
    // imprime_vetor(vi,0, sizei-1);
    // quick_sort(vi,0,sizei-1);
    // printf("\n vi depois do quick:");
    // imprime_vetor(vi,0, sizei-1);
    // return 0;

    // 




}
