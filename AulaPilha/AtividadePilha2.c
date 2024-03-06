#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha{
	char vet[10];
	int topo1, topo2;
	} TPilha;

void create(TPilha *p){
	p->topo1 = -1;
	p->topo2 = 10;
}
void destroy(TPilha *p){
	p->topo1 = -1;
	p->topo2 = 10;
}

int isfull(TPilha *p){
	if(p->topo1 == p-> topo2 - 1)
		return 1;
	else
		return 0;
}

int isempty(TPilha *p){
	if(p->topo1 == -1 && p->topo2 == 10)
		return 1;
	else
		return 0;
}

void push(TPilha *p, char x, int n){
	if(isfull(p)){
		puts("overflow");
		abort();
		}
	if(n == 1){
	  p->topo1++;
	  p->vet[p->topo1] = x;
	}
	else{
		p->topo2--;
		p->vet[p->topo2] = x;}
}

char pop(TPilha *p, int n){
	if(isempty(p)){
		puts("underflow");
		abort();
		}
	char aux;
    if(n == 1){
		aux = p-> vet[p->topo1];
		p->topo1--;
		return aux;
		}
	else{
		aux = p-> vet[p->topo2];
		p->topo2++;
		return aux;
		}

}

char top(TPilha *p){
	if(isempty(p)){
		puts("underflow");
		abort();
		}
	return p->vet[p->topo1];
}

int main(void){
	TPilha p;
	create(&p);
    push(&p, 'A', 1);
    push(&p, 'B', 1);
    push(&p, 'C', 2);
    push(&p, 'D', 1);
    push(&p, 'E', 2);
    printf("%c\n", pop(&p, 2));
    printf("%c\n", pop(&p, 1));
    printf("%c\n", pop(&p, 2));
    printf("%c\n", pop(&p, 1));
    return 0;
	}
