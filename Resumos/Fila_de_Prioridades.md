# Fila de Prioridades

- A `Fila de Prioridades` é um tipo especial de fila, onde o elemento do início da fila é o elemento que tem a maior prioridade de saída.
- Fila de Prioridades são implementadas usando árvores binárias, a ideia é que essa árvore seja quase ou totalemente balanceada.
- Muito usadas em mineração de dados e em caminhos em gráfos.


### Como fuciona a ordenação em vetores 
![imagem](https://haskell.pesquisa.ufabc.edu.br/ox-hugo/heaps_01.svg)

## Navegação em FP ou PQ (priority queue)
A implementação em vetores costuma ignorar a posiçao v[0], dessa forma, é possível definir com facilidade o extremo da fila.
-  Sendo k uma posição do vetor;
    - pai de k: k/2;
    - filho esq: 2k;
    - filho dir: 2k+1;

## Manipulação da PQ
- PQinit(int maxN):  cria a fila;
- PQempty(): verifica se está vazia;
- PQinsert(Item v): insere na fila;
- PQdeImax(): remove e retorna o item de maior prioridade;



