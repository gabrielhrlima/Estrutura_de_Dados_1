#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if(a<b && b<c && c<d && d<e ){
        printf("C");
    }else if (a>b && b>c && c>d && d>e){
        printf("D");
    }else{
        printf("N");
    }
    


    return 0;
}
