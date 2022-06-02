#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define N 9152

void rotas(double *grafo){
    FILE *f = fopen("tourar9152.tour", "r");
    int a, b, contador=1;
    double soma = 0.0;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    if(a>b){
        soma=soma+grafo[b*N+a];
    }else{
        soma=soma+grafo[a*N+b];
    }
    while (!feof(f)){
        //printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);

        if(a>b){
            soma=soma+grafo[b*N+a];
        }else{
            soma=soma+grafo[a*N+b];
        }

        if(soma<=68638254.213346*0.8){
            contador++;
        }
    }

    printf("\nDistancia total do tour: %f\n",soma);
    printf("\nTotal de cidades visitadas para visitar 80porcento do tour: %d\n",contador);

    fclose(f);
}

double maiorPercurso(double *grafo){
    double maior = 0.0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(grafo[i*N + j]>maior){
                maior = grafo[i*N + j];
            }
        }
    }
    return maior;
}

double menorPercurso(double *grafo){
    double menor = grafo[0*N + 1];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(grafo[i*N + j]<menor && grafo[i*N + j] != 0.0){
                menor = grafo[i*N + j];
            }
        }
    }
    return menor;
}

double medioPercurso(double *grafo){
    int contador = 0;
    double soma = 0.0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(grafo[i*N + j] != 0.0){
                contador++;
                soma = soma + grafo[i*N + j];
            }
        }
    }
    return (soma/((N*(N-1))/2));
}

double distancia(double lat_i, double long_i,double lat_j, double long_j){
    double dist = sqrt(pow(lat_i - lat_j, 2) + pow(long_i - long_j, 2));
    return dist;
}

int main(){
    FILE *arquivo = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    double cidLa[N];
    double cidLg[N];

    /*Inicializa grafo*/
    double *grafo;
    grafo = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo[i*N + j] = 0.;
        }
    }
    

    int k=0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            //grafo[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
            grafo[i*N + j] = distancia(cidLa[i],cidLg[i],cidLa[j],cidLg[j]);
        }
    }
    
    printf("\nA maior distancia entre duas cidades eh: %f\n",maiorPercurso(grafo));

    printf("\nA menor distancia entre duas cidades eh: %f\n",menorPercurso(grafo));

    printf("\nA media distancia entre duas cidades eh: %f\n",medioPercurso(grafo));
    
    rotas(grafo);
}
