#include <stdio.h>

int f91(int n);
int main(int argc, char const *argv[])
{
    int N;
   while (1){
        scanf("%d", &N);

        if (N==0)
        {
            break;
        }
        
        int valor =f91(N);

        printf("f91(%d)= %d\n", N, valor );
   }
    return 0;
}

int f91(n){

    if(n>=101){
        return n-10;
    }else{
        return f91(f91(n+11));   
    }
    
}