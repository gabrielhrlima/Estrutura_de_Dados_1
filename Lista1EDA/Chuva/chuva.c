#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, A;
    scanf("%d", &n);
    int m1[n][n], m2[n][n], final[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A);
            m1[i][j]=A;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A);
            m2[i][j]=A;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           final[i][j]=m1[i][j]+m2[i][j]; 
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
           printf("%d ", final[i][j]); 
        }
        
    }


    return 0;
}
