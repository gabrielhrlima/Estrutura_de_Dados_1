# include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[1000];

    scanf("%s", string);

    int tam =0;

    while (string[tam] !='\0')
    {
        tam++;
    }
    
   for (int i = tam -1; i >=0; i--)
   {
        printf("%c", string[i]);
   }
   
    




    return 0;
}
