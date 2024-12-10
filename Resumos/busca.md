# Busca 

## Busca sequencial

- A `busca sequencial` tem a ideia de ir percorrendo um vetor seguinda uma ordem crescente até encontrar o elemento desejado.
- Se encontrar ele retorna a ``posição do elemento``.
- Se não encontrar ele retorna ``-1``

```c
#define key(A) (A.chave)
typedef int Key; // tipo da chave
typedef struct data Item; 
struct data {char info[100];Key chave;};

int busca_sequencial(Item *v, int l, int r, Key k){
    for (int i = l; i <= r; i++)
    {
        if(k == key(v[i])) return i;
    }
    return -1;
}
```
### Complexidade

| Análise       | Resultado ||
|:--------------|:---------:|:-|
| Melhor caso   | O(1)      |O primeiro elemento|
| Pior caso     | O(n) - (n+1)   |Ultimo elemento|
| Caso médio    | O(n) - (n+1)/2     |Mais ou menos a metade do vetor|
| Pesquisa sem sucesso     | O(n) - (n+1)   ||
| Listas encadeadas | O(n)      ||
| Vetores não ordenados  | O(n)      ||
| Vetores ordenados    | O(log(n))     ||


## Busca Binária

- A `busca binária` tem a ideia de receber um vetor ordendado e ir dividindo o vetor na metade, comparando o valor da chave do elemento desejado com o elemento do meio do vetor.
- Funciona de forma recursiva, se a chave do elemento for menor que a chave do elemento do meio ele chama a busca binária para a porção a esquerda do meio e a mesma lógica se a chave for maior que o meio.
- Se o elemento não for encontrado, retorna ``-1``.
- Se o elemento for encontrado, retorna a ``posição do elemento``

```c
#define key(A) (A.chave)
typedef int Key; // tipo da chave
typedef struct data Item; 
struct data {char info[100];Key chave;};

int busca_binaria(Item *v, int l, int r, Key k){
    if(l > r) return -1; // O elemento não foi encontrado
    int m = (l + r)/2;
    if( k == key(v[m])) return m; 
    if(k < key(v[m])) return busca_binaria(v,l,m-1, k);
    return busca_binaria(v,m+1,r, k);

}


```
| **Análise**          | **Resultado**        | **Descrição**                                                                                                                                                                   |
|:---------------------|:---------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Melhor caso**      | \( O(1) \)           | Ocorre quando o elemento procurado está exatamente na posição do meio na primeira iteração.                                                                                   |
| **Pior caso**        | \( O(\log_2(n)) \)   | Ocorre quando o algoritmo precisa dividir o vetor até que reste apenas um elemento (ou descubra que ele não está presente).                                                   |
| **Caso médio**       | \( O(\log_2(n)) \)   | Em média, o elemento é encontrado após percorrer metade das divisões do vetor, mas a ordem de crescimento continua a mesma do pior caso.                                       |
| **Pesquisa sem sucesso** | \( O(\log_2(n)) \)   | Semelhante ao pior caso, pois o algoritmo divide o vetor até não haver mais elementos no intervalo.                                                                           |
| **Listas encadeadas** | \( O(n) \)          | A busca binária **não funciona eficientemente em listas encadeadas**, já que não há acesso direto ao elemento do meio (requer percorrer a lista até o índice desejado).       |
| **Vetores não ordenados** | **Não aplicável** | A busca binária **não funciona** em vetores desordenados, pois a premissa básica do algoritmo é que o vetor esteja ordenado.                                                  |
| **Vetores ordenados**   | \( O(\log_2(n)) \) | A busca binária é altamente eficiente em vetores ordenados devido ao acesso direto ao elemento do meio e ao particionamento constante.                                        |

