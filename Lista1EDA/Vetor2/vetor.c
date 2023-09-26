# include <stdio.h>

int main(int argc, char const *argv[])
{

    int n, menor_valor, posicao_menor;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);  
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            v[i]==menor_valor;
        }else if (v[i]<menor_valor)
        {
            v[i]=menor_valor;
            posicao_menor =i;
        }        
    }
    
    printf("%d", posicao_menor);


    return 0;
}

