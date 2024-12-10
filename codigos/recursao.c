#include <stdio.h>
#include <stdlib.h>


/*
A ideia da função resursiva é que possa ser aproveitada a mesma ideia até chagar em uma condição de parada 





*/

int fatorial(int num){
    printf("num = %d -->", num);
    if(num <=1)return 1;

    return num * fatorial(num-1);
}

int fibonacci(int num){
    printf(" num = %d", num);
    if(num ==0 ) return 0;
    if(num ==1) return 1;

    return fibonacci(num - 1) + fibonacci(num-2); 
}


void imprime_decrescente(int n){
    if (n == 0)
    {
        printf("%d \n", n);
    }else
    {
        printf("%d ", n);
        imprime_decrescente(n-1);
    }
    
    
}
void imprime_crescente(int a){
    if (a ==0)
    {
        printf("%d ", a);
    }else{
        imprime_crescente(a -1);
        printf("%d ", a);
    }

    
}

int potencia(int b, int e){
    if(e == 1) return b;
    return b * potencia(b,e-1);
}


int main(int argc, char const *argv[])
{
    // int a = fatorial(3);
    // printf("a = %d\n", a);
    
    // int a = fibonacci(4);
    // printf(" a = %d\n", a);
    
    // imprime_decrescente(10);
    // imprime_crescente(10);

    int a = potencia(3,3);
    printf(" a = %d\n", a);
    
    return 0;
}

