#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int isFull(TFila *f){
	return next(f->rear) == f->front;
	}

int isEmpty(TFila *f){
	return f->rear == f->front;
	}

void store(TFila *f, char x){
	if(isFull(f)){
		puts("overflow");
		abort();
		}
	f->vet[f->rear] = x;
	f->rear = next(f->rear);
	}

char retrieve(TFila *f){
	if(isEmpty(f)){
		puts("underflow");
		abort();
		}
	char aux = f->vet[f->front];
	f->front = next(f->front);
	return aux;
	}

void isolaLetra(char s[]){
	TFila f;
	int i = 0, tam = strlen(s);
	create(&f);
	while(!isFull(&f) && i < tam)
		store(&f, s[i++]);
	i = 0;
	while(!isEmpty(&f)){
		s[i++] = '[';
		s[i++] = retrieve(&f);
		s[i++] = ']';
		}
	s[i] = '\0';
	}

int main(void){
	TFila f1;
	create(&f1);
	store(&f1,'A');
	store(&f1,'B');
	
	if(isEmpty(&f1))
		printf("Fila vazia!\n");
	else
		printf("Fila nao vazia!\n");
	

	store(&f1,'C');
	store(&f1,'D'); 
	store(&f1,'E');   

    if(isFull(&f1))
		printf("Fila cheio!\n");
	else
		printf("Fila nao esta cheia!\n");

	store(&f1,'F'); 
	store(&f1,'G'); 
	}

