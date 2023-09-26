#include <stdio.h>



char *vencedor(int x);
int main() {
    int n = 1;
    
    while (1) {
        int R;
        scanf("%d", &R);
        
        if (R == 0) {
            break;
        }
        
        char *ganhou = vencedor(R);
        
        // Imprime a saída formatada
        printf("Teste %d\n", n);
        printf("%s\n\n", ganhou);
        
        n++;
    }
    
    return 0;
}

char *vencedor(int x) {
    int aldorodadas = 0, betorodadas = 0;
    
    for (int i = 0; i < x; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        aldorodadas += A;
        betorodadas += B;
    }
    
    if (aldorodadas > betorodadas) {
        return "Aldo";
    } else {
        return "Beto";
    }
}