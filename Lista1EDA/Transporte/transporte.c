#include <stdio.h>

int main(int argc, char const *argv[])
{
    int cl,cb, ch, nl, nb, nh, total;

    scanf("%d %d %d", &cl,&cb, &ch);
    scanf("%d %d %d",&nl, &nb, &nh);

    total=(nl/cl)*(nb/cb)*(nh/ch);
    printf("%d", total);



    return 0;
}
