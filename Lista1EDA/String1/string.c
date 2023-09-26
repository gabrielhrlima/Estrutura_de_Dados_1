#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[1000];
    int tam=0;
    scanf("%s", str);

    while (str[tam]!= '\0')
    {
        tam ++;
    }
    printf("%d", tam);
    return 0;
}
