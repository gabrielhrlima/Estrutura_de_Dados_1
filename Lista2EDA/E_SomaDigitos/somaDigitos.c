#include <stdio.h>

long int soma(long int n);
 
int main() {
    long int n;
    scanf("%ld", &n);

    long int res= soma(n);
    printf("%ld\n", res);

    return 0;
}

long int soma(long int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + soma(n / 10);
    }
}