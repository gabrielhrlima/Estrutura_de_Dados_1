# TAD (Tipo Abstrato de Dados)

São interfaces, não necessariamente quem vai usar precisa saber como é construido, mas a execução deve ser o que ela fala(fila, pilha, árvore)

## Filas (FIFO)

Uma fila é uma sequencia de dados, onde o primeiro dado a entrar será o primeiro a ser processado (FIFO- Firt In First Out). Pode tanto ser usado em listas encadeadas como em arrays, o único critério é organizar de forma que o primeiro seja porcessado primeiro.

As inserções acontecem no fim e as remoções acontecem no início.

### Sistemas que podem ser usados
`filas de bancos `  
`sistemas de impressoras`  
`sistemas de inscrições`  
`processos de sistemas operacionais`

### Opereções na Fila  
`vazia`  
`tamanho`  
`busca no início`  
`busca no fim`  
`enfileirar`  
`desenfileirar`

### <u>**Implementação em Lista Estática**</u>
### Operações constantes  
`inserção e remoção`

Para manter a complexidade constante é necessária duas variáveis auxiliares para marcar qual o primeira e a ultima posição, dessa forma os elementos não são realmente removidos quando acontece uma remoção mas permite que a posição seja sobreescrita com outro dado. Deve tomar atenção com o transbordamento da fila, uma forma de tratar esse problema é fazendo uma lista circular, se a fila está "cheia" faz ele retornar ao início da fila

O problema--> não dá pra usar uma biblioteca, dessa forma só seria possível usar uma fila, uma ideia pra poder implementar seria usando structs

### <u>**Implementação em Lista Encadeada**</u>

A implementação em tempo constante é necessário  o acesso ao primeiro e o último elemento.


## Pilhas (LIFO)

A idea da pilha é que a primero item a entrar é o ultimo a ser processado, é a mesma ideia que é usada para realizar chamadas recursivas. A pilha segue o modelo (Last In First Out)

### Operações na pilha
``criar``  
``vazia``  
``empilhar``  
``desempilhar``  
``espiar``  

### Prolblemas que podem ser revolvidos com pilhas
``refazer ou desfazer alguma coisa``  
``histórico dos navegadores``  
``recursão``    
``busca em profundidade``  
``backtracking``  
``inversão de string``  
``balanceamento de simbolos``  
``ìdentificador de expressões``  

### <u>**Implementação em Lista Estática**</u>

Assim como na fila, a pilha em listas estáticas dependem de variáveis auxiliares para marcar qual a posição que está o último elemento adicionado na pilha. Quando acontece uma remoção o elemento não é realmente removido mas a posição onde ele estava fica disponível para ser sobreescrita.

### <u>**Implementação em Lista Encadeada**</u>

Nas lista encadeadas a pilha funciona como uma remoção e adição sempre do início da lista, não é necessário a cabeça ter um ponteiro pra o ultimo elemento da lista.