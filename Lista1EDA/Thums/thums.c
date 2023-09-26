#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        if (i%2!=0)
        {
            printf("THUMS THUMS THUMS\n");
        }else
        {
           printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
    }

    return 0;
}
