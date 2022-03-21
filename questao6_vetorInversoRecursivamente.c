#include<stdio.h>
#include<stdlib.h>

int posicao = 0;

int* inverso(int vet[], int tamanho){
    if(tamanho<=posicao){
        return vet;
    }else{
        int aux = vet[tamanho-1];
        vet[tamanho-1] = vet[posicao];
        vet[posicao] = aux;
        posicao++;
        return inverso(vet, --tamanho);
    }
}

void exibeVetor(int vet[], int tamanho){
    printf("{ ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ",vet[i]);
    printf("}");
}


int main(){
    int vet[] = {10,20,30,40};
    int tamanho = (sizeof(vet)/sizeof(vet[0]));
    printf("\nVetor Original: ");
    exibeVetor(vet,tamanho);
    printf("\nVetor Invertido: ");
    exibeVetor(inverso(vet,tamanho),tamanho);
    printf("\n");
    return 0;
}