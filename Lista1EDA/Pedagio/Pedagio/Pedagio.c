#include <stdio.h>

int main(int argc, char const *argv[])
{
    int l,//Comprimento da estrada
        d,//espaçamento entre pedágios
        k,//custo por km percorrido 
        p;//valor do pedágio

    scanf("%d %d", &l, &d);
    scanf("%d %d", &k, &p);
    
    int quantPed, ped, vKm, total;

    quantPed = l/d; //quantidade de pedagios 
    ped =(quantPed*p);//valor a pagar por passar pelos pedágios
    vKm = (k*l);
    total =(ped +vKm);
    printf("%d\n", total);

    return 0;
}
