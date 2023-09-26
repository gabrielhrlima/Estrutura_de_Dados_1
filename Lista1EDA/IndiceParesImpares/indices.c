#include <stdio.h>

int main(int argc, char const *argv[])
{
    
int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);  
    }
    int par[n], impar[n], j=0, k=0;

    for (int i = 0; i < n; i++)
    {
        if (v[i]%2==0)
        {
            par[j]=i;
            j++;
        }else{
            impar[k]=i;
            k++;
        }
    }
    
    for (int i = 0; i < j; i++)
    {
        printf("%d ", par[i]);
    }
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", impar[i]);
    }




    return 0;
}
