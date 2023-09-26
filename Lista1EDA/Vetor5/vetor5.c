# include <stdio.h>

void buscar(int v[], int x, int n);
int main(int argc, char const *argv[])
{
    int n, escolha;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);  
    }

    scanf("%d", &escolha);

    buscar(v, escolha, n);

    return 0;
}

void buscar(int v[], int x, int n){

int a=0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]==x)
        {
            a++;
        }
    }
    if (a>0)
    {
        printf("pertence");
    }else
    {
        printf("nao pertence");
    }
    
        


}