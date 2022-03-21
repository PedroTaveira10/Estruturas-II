#include<stdio.h>

int fatorial(int n){
    if(n==0){
        return 1;
    }else{
        return n*fatorial(n-1);
    }
}

int main()
{
    int x;
    printf("Digite o numero que quer saber o fatorial: ");
    scanf("%d",&x);
    printf("O fatorial de %d eh: %d",x,fatorial(x));
    return 0;
}
