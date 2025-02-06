# Count Sort

O count_sort é um algoritmo de ordenação que não é baseado em comparaações, ele é eficiente para odernar números inteiros dentor de um intervalo.

### Passos
A = [3,2,4,7,4,7,1,2,3]  


#### Contagem de valores(frequência)
C (count) guarda as frequências de cada elemento, ele deve ter o tamanho (quantidade de posições) igual ao valor do maior elemento. 
- Exemplo: como C deriva de A, então C deve ter 7 posições disponíveis (0-6).

C = [1,2,2,2,0,0,2]

#### Acumulação de valores
O veto C é tranformado em um vetor que guarda a quantidade de valores que vem antes de cada posição.


C = [1,2,2,2,0,0,2]  
C = [1,3,5,7,7,7,9]


|Vantagens|Desvantagens|
|--|--|
|mais rápido em vetores pequenos|não funciona com números negativos e flutuantes|
|estável|alto consumo de memória|
|util em valores inteiros limitados|NÃO É IN-PLACE|

## IDEIA PRINCIPAL

O valor de A indica a posição em C e o valor em C indica a posição em B.