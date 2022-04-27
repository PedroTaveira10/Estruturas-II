#include<stdio.h>
#include "aluno.c"

typedef struct node {
    Aluno A;
    struct node* esq;
    struct node* dir;
}*No;


typedef No noRaiz;

/*Cria estrutura tipo nó da pilha*/
typedef struct nopilha Nopilha;
struct nopilha{
    noRaiz no;
    Nopilha* prox;
};

/*cria estrutura do tipo Pilha*/
typedef struct{
    Nopilha* topo;
} Pilha;

//Grupo 01;
noRaiz criarArvore();
noRaiz criarArvore(Aluno);
void nivelIter(noRaiz);

//Grupo 02
void preordemRec(noRaiz);
void inordemRec(noRaiz);
void posordemRec(noRaiz);
Aluno buscar(noRaiz, Aluno);

//Grupo 03
int inserir(noRaiz, Aluno);
int inserirEmLote(noRaiz, Aluno*, int);

//Grupo 04
int remover(noRaiz, Aluno);

//Grupo 05
void deletarArvore(noRaiz);

//Grupo 06
void preordemIter(noRaiz);
void empilhar(Pilha *p, noRaiz no);
noRaiz desempilha(Pilha *p);
int pilhaVazia(Pilha *p);

//Grupo 07
void inordemIter(noRaiz);

//Grupo 08
void posordemIter(noRaiz);

//Grupo 09
int altura(noRaiz);
int alturaDoNo(noRaiz, Aluno);

//Grupo 10
void valoresEntre(int idA, int idB);

//Grupo 11 - Professor
int tempoDeBusca();
int tempoDeRemocao();
int tempoDeInsercao();


int main( )
{
    Aluno K = criarAluno(10, "Kennedy Lopes\0", 9.);
    No raiz = malloc(sizeof(struct node));
    raiz->esq = 0;
    raiz->dir = 0;
    raiz->A = K;

    Aluno B = criarAluno(12, "Francisco\0", 9.);
    Aluno C = criarAluno(15, "Pedro\0", 8.);
    Aluno D = criarAluno(8, "Henrique\0", 7.);
    Aluno V = criarAluno(20, "Vinicius Lopes", 8.9);
    Aluno T = criarAluno(21, "Thiago", 6.5);

    noRaiz r = criarArvore(B);
    r->dir = criarArvore(C);
    r->esq = criarArvore(D);
    r->esq->dir = criarArvore(K);
    r->dir->esq = criarArvore(V);
    r->dir->dir = criarArvore(T);

    printf("\nPreOrdem Recursiva\n");
    preordemRec(r);
    printf("\nPreOrdem Iterativo\n");
    preordemIter(r);
}

noRaiz criarArvore(Aluno A){
    noRaiz raiz = (No) malloc(sizeof(struct node));
    raiz->A = A;
    raiz->dir = 0;
    raiz->esq = 0;
    return raiz;
}

void preordemRec(noRaiz raiz){
    if(raiz != 0){
        printf("%s\n", raiz->A->nome);
        preordemRec(raiz->esq);
        preordemRec(raiz->dir);   
    }
}

void empilhar(Pilha *p, noRaiz no){
    Nopilha *novo = (Nopilha*) malloc(sizeof(Nopilha));
    novo->no = no;
    novo->prox = p->topo;
    p->topo = novo;
}

noRaiz desempilhar(Pilha *p){
    noRaiz nr = p->topo->no;
    p->topo = p->topo->prox;
    return nr;
}

int pilhaVazia(Pilha *p){
    if(p->topo == NULL) return 1;
    return 0;
}

void preordemIter(noRaiz raiz){
    int i=0;
    Pilha p;
    p.topo = NULL;

    do{
        if(raiz!=NULL){
            printf("%s\n", raiz->A->nome);
            if(raiz->dir!=NULL){
                empilhar(&p,raiz->dir);
            }
            raiz = raiz->esq;
        }else if(pilhaVazia(&p)){
            i = 1;
        }else{
            raiz = desempilhar(&p);
        }
    }while(i==0);

}
