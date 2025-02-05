# include <stdio.h>
# include <stdlib.h>
# include "../Biblioteca/myLib.h"
# include <math.h>
# include <time.h>
#define N 10000 // Tamanho do vetor

void intro(Item *v, int l, int r, int maxdepth){
    if(r-l<=15){
        return;
    }else if (maxdepth ==0){// quantidade maxima de recursões
        heapsort(v,l,r);
        printf("heap\n");
        return;
    }else{
        //quick sort
        printf("quick\n");
        compswap(v[(l + r) / 2], v[r]);
        compswap(v[l], v[(l + r) / 2]);
        compswap(v[r], v[(l + r) / 2]);
        int j = separa_2(v,l,r);
        intro(v,l,j-1,maxdepth-1);
        intro(v,j+1,r,maxdepth-1);
    }
}

void intro_sort(Item *v, int l, int r){
   int maxdepth = 2 * ((int)log2((double)(r - l + 1)));// quantidade de recursões que o quicksort vai fazer
   printf("%d\n",maxdepth);
    intro(v,l,r,maxdepth);
    insertion_sort(v,l,r);
}




// int main(int argc, char const *argv[])
// {
//     Item v[]={9, 10, 3, 5, 6, 8, 2, 1, 4, 50, 30, 20, 40, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};
//     imprime_Vetor(v,34);
//     into_sort(v,0,33);
//     imprime_Vetor(v,34);    

//     // gcc codigos/introSort.c Biblioteca/mylib.c -o a -lm

    

//     return 0;
// }
int main(int argc, char const *argv[]) {
    Item v[N];
    srand(time(NULL));

    // Preenchendo o vetor com valores aleatórios
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 100000; // Números aleatórios entre 0 e 99.999
    }

    printf("Vetor original (primeiros 20 valores):\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    intro_sort(v, 0, N - 1);

    printf("Vetor ordenado (primeiros 20 valores):\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}