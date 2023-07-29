//ARQUIVO .h
#define N 1000

typedef struct elemento {
    int posicao;
} elemento;

typedef struct pilha {
    elemento vagao[N];
    int tamanho;
} pilha;

void criarPilhaVazia(pilha *p);
int push(pilha *p, elemento x);
elemento pop(pilha *p);
int verificador(pilha p);


//ARQUIVO .c
#include <stdio.h>

void criarPilhaVazia(pilha *p) {
    p->tamanho = 0;
}

int push(pilha *p, elemento x) {
    if(p->tamanho==N) {
        return 1;
    } else {
        p->vagao[p->tamanho] = x;
        p->tamanho++;
    }

    return 0;
}

elemento pop(pilha *p) {
    elemento y;

    if(p->tamanho==0) {
        y.posicao = 0;
        return y;
    } else {
        y = p->vagao[(p->tamanho)-1];
        p->tamanho--;

        return y;
    }   
}

int verificador(pilha p) {
    int i;

    for(i=0; i<p.tamanho; i++) {
        if(p.vagao[i].posicao<p.vagao[i+1].posicao) {
            return 1;
        }  
    }

    return 0;
}

void imprimir(pilha p) {
    int i;
    
    printf("\n%d\n", p.tamanho);
    for(i=0; i<p.tamanho; i++) {
        printf("%d ", p.vagao[i].posicao);
    }
}


//PROGRAMA USANDO A TAD (main)
#include <stdio.h>

int main() {
    int n, i;
    pilha p;
    elemento x;

    criarPilhaVazia(&p);
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &x.posicao);
        push(&p, x);
    }

    if(verificador(p)==0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}