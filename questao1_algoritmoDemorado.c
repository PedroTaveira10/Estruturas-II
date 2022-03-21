#include<stdio.h>
#include <time.h>

int algoritmoDemorado ( int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            for ( int k = 0; k < n; k++) {
                for ( int l = 0; l < n; l++) {
                soma = i + j + k + l;
                }
            }
        }
    }
    return soma ;
 }

int main(){

    clock_t t;

    printf("\n\n####Inicio da execucao###\n");
    t = clock();
    algoritmoDemorado(200);
    t = clock()-t;
    printf("***Executou***\n");
    printf("####Fim da execucao###\n\n");
    printf("Tempo de execucao: %lf milisegundos\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;

}