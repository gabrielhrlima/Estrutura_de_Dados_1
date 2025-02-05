# include <stdio.h>
# include <stdlib.h>
# include "../Biblioteca/myLib.h"

# define MAX 10000
# define VALOR_MAX 5
int aux[MAX];   


void count_sort(Item *v, int l, int r){
//criar o count
int count[VALOR_MAX+1],i;// 0 a 5, 6 posições, count so conta as frequencias
//zerar todas a posições de count
for ( i = 0; i <= VALOR_MAX; i++)
{
    count[i]=0;
}
imprime_Vetor(count,VALOR_MAX+1);
//contar a frequencia dos elementos
for (i = l; i <= r; i++)//percorrendo v
{
    count[v[i]-1] +=1;// count guarda as posições, count[i] guarda quantas vezes o valor i+1 aparece
    //count[v[i]-1]++;
}
imprime_Vetor(count,VALOR_MAX+1);
//comultar os elementos
for ( i = 1; i <=VALOR_MAX; i++)//percorrendo count
{
    count[i] += count[i-1];
}
imprime_Vetor(count,VALOR_MAX+1);
//ordenar em aux 
for (i = r; i >=0; i--)// percorre v de trás para frente
{
    aux[count[v[i]-1]-1] = v[i];
/*
v[i] = elemento de v
v[i]-1 = posição em count do elemento de v
count[v[i]-1]-1 = posição em aux do elemento de v
*/
    count[v[i]-1]--;//decrementa a posição do elemento de v em count
}
imprime_Vetor(aux,r+1);
// copiar de para v
for ( i = 0; i <= r; i++)
{
    v[i] = aux[i-l];
}
imprime_Vetor(v,r+1);
}

int main(int argc, char const *argv[])
{
    Item v[]={5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    imprime_Vetor(v,20);
    count_sort(v,5,19);
    imprime_Vetor(v,20);
    
    return 0;
}
