#include<stdio.h>
#include<stdlib.h>

#define TAM 6

int contador = 0;

void exibeMatriz(int mat[TAM][TAM]){
    printf("\n");
    int i,j;
	for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Contador = %d\n",contador);

}

void preenche(int mat[TAM][TAM], int linha, int coluna){
	mat[linha][coluna] = 1;
	contador++;
	exibeMatriz(mat);
	if(linha<5 && mat[linha+1][coluna]==0){
        //casa inferior
        preenche(mat,linha+1,coluna);
    }else if(linha>0 && mat[linha-1][coluna]==0){
        //casa superior
        preenche(mat,linha-1,coluna);
    }else if(coluna<5 && mat[linha][coluna+1]==0){
        //casa direita
        preenche(mat,linha,coluna+1);
    }else if(coluna>0 && mat[linha][coluna-1]==0){
        //casa esquerda
        preenche(mat,linha,coluna-1);
    }else if(coluna<5 && linha>0 && mat[linha-1][coluna+1]==0){
        //canto superior direito
        preenche(mat,linha-1,coluna+1);
    }else if(coluna>0 && linha>0 && mat[linha-1][coluna-1]==0){
        //canto superior esquerdo
        preenche(mat,linha-1,coluna-1);
    }else if(coluna<5 && linha<5 && mat[linha+1][coluna+1]==0){
        //canto inferior direito
        preenche(mat,linha+1,coluna+1);
    }else if(coluna>0 && linha<5 && mat[linha+1][coluna-1]==0){
        //canto inferior esquerdo
        preenche(mat,linha+1,coluna-1);
    }else{
        exibeMatriz(mat);
    }
}

int main(){
    int mat[TAM][TAM] = {
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,0}
    };
    exibeMatriz(mat);
    preenche(mat,0,5);
    return 0;
}
