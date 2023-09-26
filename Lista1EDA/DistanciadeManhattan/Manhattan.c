# include <stdio.h>

int main(int argc, char const *argv[])
{
    int m1, m2, r1, r2, a, b, total;
    scanf("%d %d %d %d",&m1, &m2, &r1, &r2 );
    if(r1>m1){
        a=r1-m1;
    }else{
        a=(-1)*(r1-m1);
    }
    if(r2>m2){
        b=r2-m2;
    }else{
        b=(-1)*(r2-m2);
    }
    total=a+b;
    printf("%d", total);

    return 0;
}

