# Estrutura de Dados e Algoritmos

- Apostila de algoritmos de ordenação [apostila](https://brunoribas.com.br/apostila-eda/ordenacao-elementar.html)
- Exercícios de ordenação [apostila](https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html)
- Canal do Bruno Ribas [youtube](https://www.youtube.com/@ProfBrunoRibas)
- Github Bruno Ribas [github](https://github.com/bcribas/benchmark-ordenacao)
- Livro [Algorithms, 4th Edition - Robert Sedgewick e Kevin Wayne](https://algs4.cs.princeton.edu/home/)

## Complexidade de Algoritmos

- A análise de complexidade é uma estimativa da quantidade de iterações que o código realiza
  > #### pode ser resolvido em 3 passos
  >
  > 1. Levar em consideração apenas as repetições do código.
  > 2. Verificar a complexidade das funções/métodos específicos da linguagem(se utilizando).
  > 3. Ignorar as constantes e considerar o termo de maior grau.

### Notação big O

n representa o tamnaho da entrada  
`Complexidade != função custo`

- **O(1)** Contante **_f(n) =x_**

  - Atribuições, comparações simples, operações aritméticas, acesso a memória
  - **Arrays**
    - inserções
    - acesso aleatório direto pelo índice
  - **Listas**
    - inserção antes de um nó específico (lista duplamente encadeadas)
    - inserção depois de um nó específico (lista duplamente encadeadas)
    - remoção de um nó específico (lista duplamente encadeadas)

- **O(n)** Linear **_f(n) = a\*n+b_**
  - Ocorrem cerca de n processos de custo constante
  - n entradas com n saídas
  - laços
  - **Arrays**
    - busca/remoção
  - **Listas**
    - busca sequencial
    - Remoção de um nó específico (simplesmente encadeada)
    - Inserção antes de um nó específico (simplesmente encadeada)
- **O(n<sup>2</sup>)** Quadrática **_f(n) = a*n<sup>2</sup> + b*n + c_**
  - Para cada n ocorre n processos
  - Caracteriza-se pelo alinhamento de iterações (normalmente laços)
- **O(k<sup>n</sup>)**
- **O(log n)** Logarítmica **_f(n) = log(n)_**
  - O custo fica um pouco mais lento a medida que n cresce
  - Buscas em vetores ordenados
- **O(n logn)** "Linearítmica" **_f(n) = nlog(n)_**
  - método da divisão e conquista (mergsort)
  - cada sub-problema é resolvido em tempo linear
- **O(n!)** Fatorial
- **O(n<sup>3</sup>)**

### Análise de Algorítmos

#### Função Custo _f(n)_

_f(n)_ é o valor que mede o os resursos necessários para medir a entrada _n_

- tamanho de vetor
- quantidade de linhas e colunas
- números de registros
- quntidade de vértices

Pode resultar em 3 cenários

|    caso    |      custo       |
| :--------: | :--------------: |
| **melhor** |      menor       |
|  **pior**  |      maior       |
| **médio**  | média dos custos |