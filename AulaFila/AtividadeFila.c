#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Coloque aqui o código da sua fila compatível com o código passado em aula e o tipo TFila
typedef struct fila{
    char vet[7];
    int front, rear;
} TFila;

int next(int n){
    if(n < 6)
        return n + 1;
    else
        return 0;
}

void create(TFila *f){
    f->rear = f->front = 0;
}

void destroy(TFila *f){
    f->front = f->rear;
}

int isfull(TFila *f){
    if(next(f->rear) == f->front)
        return 1;
    else
        return 0;
}

int isempty(TFila *f){
    if(f->rear == f->front)
        return 1;
    else
        return 0;
}

void store(TFila *f, char x){
    if(isfull(f)){
        puts("Overflow");
        abort();
    }
    f->vet[f->rear] = x;
    f->rear = next(f->rear);
}

char retrieve(TFila *f){
    if(isempty(f)){
        puts("Underflow");
        abort();
    }
    char aux = f->vet[f->front];
    f->front = next(f->front);
    return aux;
}

typedef struct filaprior {
    TFila f1, f2, f3;
} TFilaPrior;

void cria(TFilaPrior *fp) {
    TFila f1, f2, f3;
    create(&fp->f1);
    create(&fp->f2);
    create(&fp->f3);
}

void inclui(TFilaPrior *fp, char elem, int p) {
    if(p == 3){
        store(&fp->f1, elem);
    }
    if(p == 2){
        store(&fp->f2, elem);
    }
    else{
        store(&fp->f3, elem);
    }
}

char retira(TFilaPrior *fp) {
    while(!isempty(&fp->f1)){
        printf("%c\n", retrieve(&fp->f1));
    }
    while(!isempty(&fp->f2)){
        printf("%c\n", retrieve(&fp->f2));
    }
    while(!isempty(&fp->f3)){
        printf("%c\n", retrieve(&fp->f3));
    }
    return ' ';
}

int main(void) {
  TFilaPrior fp1;
  cria(&fp1);
  inclui(&fp1,'A',1);
  inclui(&fp1,'B',2);
  inclui(&fp1,'C',3);
  inclui(&fp1,'D',1);
  inclui(&fp1,'E',2);
  char elem = retira(&fp1);
  printf("%c ",elem);
  elem = retira(&fp1);
  printf("%c ",elem);
  elem = retira(&fp1);
  printf("%c ",elem);
  elem = retira(&fp1);
  printf("%c ",elem);
  elem = retira(&fp1);
  printf("%c ",elem);
  return 0;
}
