# Algoritmos de Ordenação
## Algoritmos de Ordenação Elementar
## Selection Sort

- O `selection_sort` é um algoritmo que tenta achar o elemento baseado na posição ("eu tenho uma posição e quero achar o valor que vai preencher essa posição").  
- É composto por dois `for`: o primeiro (`i`) é o responsável por marcar qual a posição que vai ser colocada o menor elemento. O segundo `for` (`j`) é quem vai percorrer o vetor a partir da posição (`i`).
- Se o elemento da posição que está sendo verificada for menor que o elemento da posição que era a menor, deve atualizar qual a posição que possui o menor elemento.
```c
void selection_sort(int v[], int l, int r) {
    
    int menor; 
    for (int i = l; i < r; i++) { 
        menor = i; 
        for (int j = i + 1; j <= r; j++) { 
            if (v[j] < v[menor]) menor = j;     
        }   
        if (i != menor) swap(v[i], v[menor]);
    }
}
```

### Complexidade
```c
void selection_sort(int v[], int l, int r) {
    
    int menor; ------------------------------------ constante
    for (int i = l; i < r; i++) { ----------------- realiza n comparações  O(n)
        menor = i; -------------------------------- constante
        for (int j = i + 1; j <= r; j++) { -------- a cada passagem de i o tamanho que j executa vai diminuir
            if (v[j] < v[menor]) menor = j;         (n-1), (n2), (n-3),...,0 -> (n+0)*n/2 == n*n/2 == (n^2)/2  -> O(n^2)
        }   
        if (i != menor) swap(v[i], v[menor]);
    }
}

Função custo = f(n) = (n^2)/2 + n
```

| Análise       | Resultado |
|:--------------|:---------:|
| Melhor caso   | O(n<sup>2</sup>)    |
| Pior caso     | O(n<sup>2</sup>)   |
| Caso médio    | O(n<sup>2</sup>)    |
| É adaptativo  | Não       |
| É estável     | Não       |
| É in-place    | Sim       |
|Função custo | _f(n) =_ n<sup>2</sup>/2|


## Bubble Sort
- O `bubble_sort` é um algoritmo de ordenação que tem a intenção de achar o maior elemento do vetor e posicionar ele na posição mais a direita.
- Depois de achar o elemento mais a direira ele faz um ``r--``.
- É um pouco melhor que o selection_sort porque ele pode avaliar se o vetor já está ordenado.

```c
void bubble_sort(int v[], int l, int r){
    int swap =1; 
   while (r>l && swap) 
   {
        swap = 0;
        for (int j = l; j+1 <= r; j++) 
        {
            if (v[j]>v[j+1]){ 
                swap(v[j], v[j+1]);
                swap =1;
            }
        } 
        r--;
    }    
}
```

### Complexidade

```c
void bubble_sort(int v[], int l, int r){
    int swap =1; ----------------------------- constante
   while (r>l && swap) ----------------------- realiza no máximo n vezes
   {
        swap = 0;
        for (int j = l; j+1 <= r; j++)-------- toda vez que realiza um while o tamanho do for diminui 
        {                                        (n-1), (n-2), (n-3),...,0 = (n + 0)*n/2 = n^2/2
            if (v[j]>v[j+1]){ ---------------- pode realizar no maximo
        {                                        (n-1), (n-2), (n-3),...,0 = (n + 0)*n/2 = n^2/2
                swap(v[j], v[j+1]);                   
                swap =1;
            }
        } 
        r--;
    }    
}

Função custo = f(n) = n^2/2 + n^2/2 + n
                       n^2 +n
```

| Análise       | Resultado | Descrição|
|:--------------|:---------:|:-|
| Melhor caso   | O(n)      |vetor ordenado|
| Pior caso     | O(n<sup>2</sup>)    ||
| Caso médio    | O(n<sup>2</sup>)    ||
| É adaptativo  | Sim       ||
| É estável     | Sim       ||
| É in-place    | Sim       ||
|Função custo | _f(n) =_ n<sup>2</sup>/2 +n|

## Insertion Sort 

- O `insertion_sort` é um algoritmo que tem como maior característica ordenar todos os elementos a esquerda do elemento que está sendo verificado.
- Sempre que `i` é incrementado `j` posiciona i na posição correta, dessa forma ele mantem a ordenação, como ele realiza uma comparação com o imediatamente menor ele vai "abrindo espaço" para poder alocar o elemento selecionado na posição correta.

```c
// Otimizado
void insertion_sort(int v[], int l, int r){
    int elem, i, j; 
    for ( i = l+1; i <= r; i++) 
    {
        elem = v[i]; 
        for ( j = i; j > l && elem <v[j-1] ; j--)
        {
            v[j] = v[j-1];        
        }
        v[j] =elem;         
    }
}
// Tradicional
void insertion_sort(int *v, int l, int r){
    for (int i = l+1; i <= r ; i++)
    {
        for (int j = i; j >l && v[j]<v[j-1]; j--)
        {
            swap(v[j], v[j-1]);
        }
    }
}
```
### Complexidade
```c
void insertion_sort(int v[], int l, int r){
    int elem, i, j; 
    for ( i = l+1; i <= r; i++) ------------------------- realiza n-1 verificações O(n)
    {
        elem = v[i]; 
        for ( j = i; j > l && elem <v[j-1] ; j--) ------- toda vez ele  realiza uma quantidade voltas até elem achar sua posição
        {
            v[j] = v[j-1];        
        }
        v[j] =elem;         
    }
}
Função custo =  
f (n) ≈ f(**n−1**)``+n−1``  
 ≈ f(n−2)+(**n−1**)_−1``+n−1``_  
 ≈ f(n−2)+(**n−1**)+_n−2_  
 ≈ f(n−3)+(n−2)−1+(n−1)+n−2  
 ≈ f(n−3)+(n−2)+(n−1)+n−3  
 ≈ f(n−i)+(n−i +1)+(n−i +2)+...+(n−2)+(n−1)+n−i  
 ≈ ...  
 ≈ f(0)+1+2+...+(n−2)+(n−1)+n−n  
 ≈ (1+(n−1))∗n/2  
 ≈ n<sup>2</sup>/2
```
| Análise       | Resultado |Descrição|
|:--------------|:---------:|:-|
| Melhor caso   | O(n)      |vetor ordenado, não realiza as comparações|
| Pior caso     | O(n<sup>2</sup>/2)    ||
| Caso médio    | O(n<sup>2</sup>/4)    |faz uma quantidade reduzida de comparações|
| É adaptativo  | Sim       ||
| É estável     | Sim       ||
| É in-place    | Sim       ||
|Função custo | _f(n) =_ n<sup>2</sup>/2|

## Shell Sort

- O ``shell_sort`` é um algoritmo baseado no `insertion_sort`, ele funciona com a mesma ideia, mas com a diferença que ele ordena os elemento em uma distancia ``h`` que é definida anteriormente.
- A cada cilco completo pelo vetor, o h é diminuido e começa tudo novamente, dessa forma o vetor vai ficando cada vez mais ordenado, até chegar em um ponto que h é igual a 1 e se torna um insertion_sort.
- Uma das dificuldades é definir qual o tamanho de h.

```c
void shell_sort(int *v, int l, int r){
    int h; 
    int elem, i, j; 
    while (h < (r-l+1)/3) // calculando o h máximo 
    {                       // para vetores muito grande pode ser feita alterações nesse laço (r-l+1)/9???
        h = (3*h)+1;
    }
    while (h>=1) 
    {
        //INSERTION SORT OTIMIZADO E COM O DESLOCAMENTO h
        for ( i = l+h; i <= r; i++) 
        {
            elem = v[i]; 
            for ( j = i; j >= l+h && elem <v[j-h] ; j-=h)
            {
                v[j] = v[j-h]; 
            }
            v[j] =elem; 
        }
        h = h/3;
    }
}
```
### Complexidade
* O `shell_sort` é muito sensível a entrada.
* Foram tirados dados de forma empírica mas não existe uma prova matemática que prove a complexidade do shell_sort



| Análise       | Resultado ||
|:--------------|:---------:|:-|
| Melhor caso com pior h  | O(nlog<sup>2</sup>n)      ||
| Pior caso com pior h     | O(n<sup>2</sup>)    ||
| Pior caso     | O(n<sup>3/2</sup>)    ||
| Melhor caso com um bom h  | O(nlogn)      ||
| Caso médio    |Não existe uma prova metemática    ||
| É adaptativo  | Sim       ||
| É estável     | Não     ||
| É in-place    | Sim       ||

## Algoritmos de Ordenação Eficientes
- *Linearítmicos* - O(nlog(n)) - melhor custo quando a ordenação é feita pelo velor da chave.
- *Linear* - O(n) - melhor custo quando a comparação é feita na estrutura da chave.
## Merge Sort
- Método da divisão e conquista, ordena duas partes menores e realiza a junção.
- Esse algoritmo é composto por duas funções, o `merge_sort` que divide o vetor em subvetores e o `merge` que intercala os dois subvetores de forma ordenada
- **Abordagem _Top-Down_**

```c
void merge_sort(int v[], int l, int r){
    if(l>=r) return ;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v,l,r,m);
}

void merge(int v[], int l, int r, int m){
    int i = l;
    int j= m+1;
    int k=0;
    int tam = (r-l+1); 
    int *v2 = malloc(sizeof(int)*tam);
    while (i<=m && j<=r)
    {
        if (v[i] <= v[j]) 
        {
            v2[k++] = v[i++];
        }else
        {
            v2[k++] = v[j++];
        }
    }
    while (i<=m) v2[k++] = v[i++];
    while (j<=r) v2[k++] = v[j++];
    k = 0;
    for ( i = l; i <=r; i++)
    {
        v[i] = v2[k++];
    }
    free(v2);
}
```
### Complexidade
```c
void merge_sort(int v[], int l, int r){
    if(l>=r) return ;
    int m = (r+l)/2;
    merge_sort(v, l, m); ------------------------------- n/2 sempre divide o valor de n na metade
    merge_sort(v, m+1, r); ----------------------------- n/2
    merge(v,l,r,m);//n
}

void merge(int v[], int l, int r, int m){
    int i = l;
    int j= m+1;
    int k=0;
    int tam = (r-l+1); 
    int *v2 = malloc(sizeof(int)*tam);
    while (i<=m && j<=r) -------------------------------- n realiza a mesma quantidade de comparações que o tamanho do vetor
    {
        if (v[i] <= v[j]) 
        {
            v2[k++] = v[i++];
        }else
        {
            v2[k++] = v[j++];
        }
    }
    while (i<=m) v2[k++] = v[i++];
    while (j<=r) v2[k++] = v[j++];
    k = 0;
    for ( i = l; i <=r; i++)
    {
        v[i] = v2[k++];
    }
    free(v2);
}
```

| Análise       | Resultado ||
|:--------------|:---------:|:-|
| Melhor caso   | O(n)      ||
| Pior caso     | O(nlog(n))||
| Caso médio    | O(nlog(n))||
| É adaptativo  | Sim       ||
| É estável     | Sim       ||
| É in-place    | Não       ||

## Quick Sort
- O ``quick_sort ``um dos algoritmos de ordenação mais utilizados e estudados.
- Método dividir e conquistar, ``particiona`` em subvetores menores e ordena eles de forma independente.
- Escolhe um elemento ``pivô`` e organiza o vetor de forma que todos os elementos menores que ele fique a esquerda do pivô e todos os elementos maiores que ele fiquem a direita.
- O quick_sort é parecido com o merge porque tambem tem a sua alma em uma função secundária o separa ou _partition_

```c
void quick_sort(int v[], int l, int r){
    if(r<=l) return;  
    int j;
    j = separa(v,l,r); 
    quick_sort(v,l,j-1); 
    quick_sort(v, j+1, r);
}
int separa_Sedgewick(int v[], int l, int r){
    printf("separa\n");
    int i =l-1;
    int j = r; 
    int pivo = v[r];
    while (i < j) // os marcadores não se cruzaram
    {             
        // procura o maior elemento
        while( v[++i]<pivo); 
        // procura o menor elemento
        while( pivo < v[--j] && j>l); 
        if(i<j) swap(v[i],v[j]);   
    }
    // posiciona o pivo depois do ultimo menor
    // o primeiro maior vai pra a posição mais a direita
    swap(v[i], v[r]);
    return i;
}
int separa_Cormem(int v[], int l, int r){
    int pivo = v[r];
    int j=l;
    // k é a posição onde foi achado o ultimo menor elemento menor que o pivõ
    for ( int k=l ; k < r; k++)
    {
        if (v[k]<=pivo)
        {
            swap(v[k],v[j]);
            j++;
        }
    }
    swap(v[j], v[r]); // coloca o pivô na posição correta
    return j; // retorna a posição do pivô
}
```
### Complexidade

```c
void quick_sort(int v[], int l, int r){
    if(r<=l) return;  
    int j;
    j = separa(v,l,r); ------------------------ n
    quick_sort(v,l,j-1); ---------------------- f(n/2) melhor caso
    quick_sort(v, j+1, r); -------------------- f(n/2) 
}
int separa_Sedgewick(int v[], int l, int r){
    printf("separa\n");
    int i =l-1;
    int j = r; 
    int pivo = v[r];
    while (i < j) 
    {             
        while( v[++i]<pivo); ----------------------- l até pivo 
        while( pivo < v[--j] && j>l); -------------- r até pivo
        if(i<j) swap(v[i],v[j]); ------------------- até r-l comparações
    }
    swap(v[i], v[r]); ------------------------------ 1
    return i;
                                                     função custo => f(n)~2n + 1
}

int separa_Cormem(int v[], int l, int r){
    int pivo = v[r];
    int j=l;
    for ( int k=l ; k < r; k++)
    {
        if (v[k]<=pivo)
        {
            swap(v[k],v[j]);
            j++;
        }
    }
    swap(v[j], v[r]); 
    return j; 
}
```
| Análise       | Resultado | Sedgewick|
|:--------------|:---------:|:-|
| Melhor caso   | O(nlog(n))  ||
| Pior caso     | O(n<sup>2</sup>)| Muito itens iguais, quase ordenados, reverso|
| Caso médio    | O(nlog(n))||
| É adaptativo  | Não       |Pode cair nos piores casos|
| É estável     | Não       ||
| É in-place    |        |Como possui somente recurão ele é proporcional a log(n)|