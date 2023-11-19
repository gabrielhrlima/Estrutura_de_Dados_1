#include <stdio.h>
#include <string.h>


char* troca(char str[], int index, int tam){
    if (index== (tam))
    {
        return str;
    }else
    {
        if (str[index]=='x')
        {
            str[index]='y';
        }
        index++;
        troca(str, index, tam);
    }
}

int main(int argc, char const *argv[])
{
    char str[80];
    gets(str);
    int tam= strlen(str);
    printf("%s", troca( str, 0, tam));




    return 0;
}
