#include <stdio.h>
 #include <stdlib.h>
 
int contador_pares(char *str, int index) {
    if (str[index] == '\0' || str[index + 2] == '\0') {
        return 0;
    }

    int pares = (str[index] == str[index + 2]) ? 1 : 0;

    return pares + contador_pares(str, index + 1);
}

int main() {
    char str[201];
    scanf("%s", str);
    int pares = contador_pares(str, 0);
    printf("%d\n", pares);
    return 0;
}
