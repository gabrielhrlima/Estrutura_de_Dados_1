# include <stdio.h>

int main(int argc, char const *argv[])
{
    int quant_leituras, capacidade, entrada, saida, quant_passageiros, excesso=0;
    
    scanf("%d %d", &quant_leituras, &capacidade);

    for (int i = 0; i <quant_leituras ; i++){
        scanf("%d %d", &saida, &entrada );
        
        quant_passageiros-=saida;
        quant_passageiros+=entrada;

        if (quant_passageiros>capacidade){
            excesso++;
        }
    }
    
    if(excesso>0){
        printf("S\n");
    }else{
        printf("N");
    }




    return 0;
}
