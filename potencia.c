#include<stdio.h>

int pot(int x, int n){
    if(n==0){
        return 1; 
    }else{
        return x * pot(x,n-1);
    }
}

int main()
{
    int x;
    int n;
    printf("Digite um numero: ");
    scanf("%d",&x);
    printf("Digite a potencia a elevar: ");
    scanf("%d",&n);
    printf("Resultado = %d",pot(x,n));    
    return 0;
}
