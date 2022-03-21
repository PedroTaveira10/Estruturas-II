#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

char* normalizarString(char string[]){
    int tam = strlen(string);
    char stringNormalizada[tam];
    for (int i = 0, posicao = 0; i < tam; i++, posicao++) {
        if (string[posicao]==' ' || string[posicao]==',' || string[posicao]=='.') {
            posicao++;
        }
        string[i] = tolower(string[posicao]);
    }
    return string;
}

void ehPalindromo(char string[]){
    normalizarString(string);
    char* stringNormalizada = normalizarString(string);
    int tam = strlen(stringNormalizada);
    int flag = 0;
    for(int i=0;i<tam;i++){
        if(stringNormalizada[i] != stringNormalizada[tam-i-1]){
            flag=1;
            break;
        }
    }
    if(flag){
        printf("\nNao eh palindromo");
    }else{
        printf("\nEh palindromo");
    }
}

int main(){
    char stringteste[500];
    printf("Digite uma string: \n");
    gets(stringteste);
    ehPalindromo(stringteste);
    return 0;
}