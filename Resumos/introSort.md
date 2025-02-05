# Intro Sort

A ideia do ``introsort`` é usar os algorítimos que já foram criados, essa junção tem o objetivo de tanto garantir uma ordenação inplace (se utilizar o heapsort) e efieciente ``nlogn``, o introsort garante a complexidade limitando o número de iterações que o o quicksort realiza, como o quick no seu pior caso pode ser n<sup>2</sup>, o introsort tenta pular esse caso definindo um número máximo de recursões que o quick pode fazer antes de mudar para outro algoritmo de ordenação, normalmente é usado o`` heapsort ``por ele ser um algoritmo inplace e o ``insertionsort`` que em pequenas quantidade é muito eficiente.

```c
void intro(Item *v, int l, int r, int maxdepth){
    if(r-l<=15){// esse valor pode variar
        return;
    }else if (maxdepth ==0){// quantidade maxima de recursões
        heapsort(v,l,r);
        return;
    }else{
        //quick sort
        compswap(v[(l + r) / 2], v[r]);
        compswap(v[l], v[(l + r) / 2]);
        compswap(v[r], v[(l + r) / 2]);
        int j = separa_2(v,l,r);
        intro(v,l,j-1,maxdepth-1);
        intro(v,j+1,r,maxdepth-1);
    }
}

```

```c
void intro_sort(Item *v, int l, int r){
    int maxdepth = 2 * ((int)log2((double)(r - l + 1)));// quantidade de recursões que o quicksort vai fazer
    intro(v,l,r,maxdepth);
    insertion_sort(v,l,r);
}
```