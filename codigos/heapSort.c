# include <stdio.h>
# include <stdlib.h>
# include "../Biblioteca/myLib.h"

void fixDown_b(Item *v,int k, int n){
    printf("FixDown: k=%d, n=%d\n", k, n);
    // imprime_Vetor(v, n+1);
    while (k*2 <=n)
    {
        // imprime_Vetor(v, n+1);
       
        int j = k*2; // filho esquerda
        if (j<n && less(v[j], v[j+1])) j++;// filho direita

        if (less(v[k], v[j])) {
        swap(v[k], v[j]);
        imprime_Vetor(v, n+1);
        }
        k =j;
       
    }
}

void heapsort(Item *v, int l, int r){
    Item *pq = v+l-1;
    int n = r-l+1;
    printf("Concerta\n");
    for(int k = n/2; k>=1; k--) fixDown_b(v, k, n);
    imprime_Vetor(v, n+1);  
    printf("Remove\n");
    while (n>1)
    {
        swap(pq[1], pq[n]);
        fixDown_b(pq, 1, --n);
    }
}

int main(int argc, char const *argv[])
{

    int v[] = {12, 8, 9, 7, 6, 3, 5, 3, 4, 1, 10};
    imprime_Vetor(v, 11);
    heapsort(v, 0, 10);
    imprime_Vetor(v, 11);

    return 0;
}
