# TAD (Tipo Abstrato de Dados)

são interfaces, não necessariamente quem vai usar precisa saber como é construido, mas a execução deve ser o que ela fala(fila, pilha, árvore)

## Filas

Uma fila é uma sequencia de dados, onde o primeiro dado a entrar será o primeiro a ser processado (FIFO- Firt In First Out). Pode tanto ser usado em listas encadeadas como em arrays, o único critério é organizar de forma que o primeiro seja porcessado primeiro.

As inserções acontecem no fim e as remoções acontecem no início.

### Sistemas que podem ser usados
`filas de bancos `  
`sistemas de impressoras`  
`sistemas de inscrições`  
`processos de sistemas operacionais`

# Opereções na Fila  
`vazia`  
`tamanho`  
`busca no início`  
`busca no fim`  
`enfileirar`  
`desenfileirar`

# Implementação em Lista Estática
Operações constantes  
`inserção e remoção`

Para manter a complexidade constante é necessária duas variáveis auxiliares para marcar qual o primeira e a ultima posição, dessa forma os elementos não são realmente removidos quando acontece uma remoção mas permite que a posição seja sobreescrita com outro dado. Deve tomar atenção com o transbordamento da fila, uma forma de tratar esse problema é fazendo uma lista circular, se a fila está "cheia" faz ele retornar ao início da fila

O problema--> não dá pra usar uma biblioteca, dessa forma só seria possível usar uma fila, uma ideia pra poder implementar seria usando structs

# Implementação em Lista Encadeadas

A implementação em tempo constante é necessário  o acesso ao primeiro e o último elemento.
