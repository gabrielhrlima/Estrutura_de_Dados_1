#include <stdio.h>

int main(int argc, char const *argv[])
{
    float A, G, Ra, Rg, a, b;
    

    scanf("%f %f %f %f",&A, &G, &Ra, &Rg );

    a =A/Ra;
    b=G/Rg;
    if (a<b)
    {
        printf("A");
    }else{
        printf("G");
    }
    return 0;
}
