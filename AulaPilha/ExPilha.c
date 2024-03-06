#include <stdio.h>

typedef struct pilha{
	char vet[6];
	int topo;
	} TPilha;

void create(TPilha *p){
	p->topo = -1;
}
void destroy(TPilha *p){
	p->topo = -1;
}

int isfull(TPilha *p){
	if(p->topo == 5)
		return 1;
	else
		return 0;
}

int isempty(TPilha *p){
	if(p->topo == -1)
		return 1;
	else
		return 0;
}

void push(TPilha *p, char x){
	if(isfull(p)){
		puts("overflow");
		abort();
		}
	p->topo++;
	p->vet[p->topo] = x;
}

char pop(TPilha *p){
	if(isempty(p)){
		puts("underflow");
		abort();
		}
	char aux = p->vet[p->topo];
	p->topo--;
	return aux;
}

char top(TPilha *p){
	if(isempty(p)){
		puts("underflow");
		abort();
		}
	return p->vet[p->topo]
}

int main(void){
	TPilha p;
	create(&p);
    push(&p, 'A');
	push(&p, 'B');
	push(&p, 'C');
	printf("%c\n", pop(&p));
	printf("%c\n", pop(&p));	
	return 0;
	}
