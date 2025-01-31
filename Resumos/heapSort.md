# Heap Sort
- O ``heap-sort`` é um algorítmo de ordenação eficiente e que usa como base a ideia de filas de prioridades para fazer a ordenação.
- A ideia é primeiro ordenar um vetor em formato de fila de prioridades (priority queue- PQ), depois ir realizando "remoções" para q o elemento de maior prioridade seja colocado na ultima posição disponível.
- A partir de uma PQ basta **"remover"** todos os elementos da PQ para que o vetor seja ordenado.
- A parte mais importante vai ser organizar um vetor aleatório como uma PQ.
    - Utilizando a função fixDown é possível ordenar o vetor aleatório como uma PQ e inplace.

```c
void heapsort(Item *v, int l, int r){
    Item *pq = v+l-1;// esse ponteiro serve para não precisar modificar o fixDown, esse vetor auxiliar começa uma posição antes do original
    int n = r-l+1;
    for(int k = n/2; k>=1; k--) fixDown_b(v, k, n);
    while (n>1)
    {
        swap(pq[1], pq[n]);
        fixDown_b(pq, 1, --n);
    }
}
```

```c
void fixDown_b(Item *v,int k, int n){
    while (k*2 <=n)
    {
        int j = k*2; // filho esquerda
        if (j<n && less(v[j], v[j+1])) j++;// filho direita

        if (less(v[k], v[j])) swap(v[k], v[j]);
        k =j;
    }
}
```