#include<stdio.h>
#include<stdlib.h>

float modulo(int x, float x1){
    float quadrado = x1*x1;
    if(quadrado>x){
        return (quadrado-x);
    }else{
        return (x-quadrado);
    }
}

float raiz(int x, float x0, float e){

    if(modulo(x,x0)<=e){
        return x0;
    }else{
        float expressao = ((x0*x0)+x)/(2*x0);
        return raiz(x,expressao,e);
    }
}


int main(){
    printf("#####\n");
    printf("A raiz eh %.3f",raiz(13,7,0.001));
    printf("\n#####\n");
    return 0;
}
