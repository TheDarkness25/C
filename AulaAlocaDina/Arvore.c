#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct nodo {
    int data;
    struct nodo *linkE, *linkD;
} nodo;

typedef nodo* ptr;

void create(ptr *raiz) {
    *raiz = NULL;
}

int isempty(ptr raiz) {
    return raiz == NULL;
}

void preordem(ptr raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->data);
        preordem(raiz->linkE);
        preordem(raiz->linkD);
    }
}

void emordem(ptr raiz) {
    if (raiz != NULL) {
        emordem(raiz->linkE);
        printf("%d\n", raiz->data);
        emordem(raiz->linkD);
    }
}

void posordem(ptr raiz) {
    if (raiz != NULL) {
        preordem(raiz->linkE);
        preordem(raiz->linkD);
        printf("%d\n", raiz->data);
    }
}

void inclui(ptr *raiz, int x) {
    if(isempty(*raiz)) {
        *raiz = malloc(sizeof(nodo));
        (*raiz)->data = x;
        (*raiz)->linkE = (*raiz)->linkD = NULL;
    }
    else if (x >(*raiz)->data)
        inclui(&(*raiz)->linkD,x);
    else
        inclui(&(*raiz)->linkE,x);
}

int busca(ptr raiz, int x) {
    if (isempty(raiz)) return 0;
    else if (x == raiz->data) return 1;
    else return busca(raiz->linkE, x) || busca(raiz->linkD, x);
}

int maior(ptr raiz) {
    while (raiz->linkD != NULL) raiz = raiz->linkD;
    return raiz->data;
}

int main(void){
    ptr raiz;
    create(&raiz);
    printf("Inclusao dos elementos: 5,3,9,2,4,10,1 nesta ordem\n");
    inclui(&raiz, 5);
    inclui(&raiz, 3);
    inclui(&raiz, 9);
    inclui(&raiz, 2);
    inclui(&raiz, 4);
    inclui(&raiz, 10);
    inclui(&raiz, 1);
    printf("Pre ordem:\n");
    preordem(raiz);
    printf("Em ordem:\n");
    emordem(raiz);
    printf("Pós ordem:\n");
    posordem(raiz);
    int achou = busca(raiz, 9);
    if(achou == 1)
        printf("Achou!\n");
    else
        printf("Não Achou!\n");
    achou = busca(raiz, 11);
    if(achou == 1)
        printf("Achou!\n");
    else
        printf("Nao Achou!\n");
    printf("Maior elemento: %d\n",maior(raiz));
    printf("Em ordem:\n");
    emordem(raiz);
}
