//QUESTÃO 4:

#include <stdio.h>

int fatorial(int n, int k){
  if(k == n && n == 0){
    printf("%d", 1);
  }else{
    int a = n-1;
    int b = k-1;
    int c = n+1;
    int d = k;
    printf("(%d  %d) + (%d  %d)", a, b, c, d );
  }
  return 0;
}

int main() {
    int n, k;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    printf("%d", fatorial(n, k));
    return 0;
}