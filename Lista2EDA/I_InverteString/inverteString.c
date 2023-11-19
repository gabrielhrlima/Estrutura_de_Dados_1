#include <stdio.h>
#include <string.h>


void inverte(char str[], int tam){

    if (tam==0)
    {
        return;
    }else
    {
        printf("%c", str[tam-1]);
        inverte(str, tam-1);
    }
}

int main(int argc, char const *argv[])
{
    char str[500];
    gets(str);
    int tam = strlen(str);
    inverte(str, tam);
    return 0;
}
