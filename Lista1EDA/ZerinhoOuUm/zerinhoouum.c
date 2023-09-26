#include <stdio.h>
 
int main(int argc, char const *argv[])
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a == b && b== c){
        printf("empate");
    } else if (a==b && b!=c){
        printf("C");
    }else if (a==c && b!=c){
        printf("B");
    }else if (b==c && c!=a){
        printf("A");
    }
    
    return 0;
}
