#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float media(float* valores, size_t n){
    float soma = 0;
    for (size_t i = 0; i < n; i++)
    {
        soma = soma + valores[i];
    }
    float media = soma/n;
    return media;
}

float* gerador(size_t n){
    srand(time(NULL));
    float* res = malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        res[i] = rand()%1000;
    }
    return res;
}

int main(){
    printf("Sequencia Aleatoria\n");
    size_t n = 10;
    float* res = gerador(n);
    for (size_t i = 0; i < n; i++)
    {
        printf("res[%lu]=%f\n",i,res[i]);
    }

    printf("\nA media da sequencia eh: %f\n\n",media(res,n));

    return 0;
}