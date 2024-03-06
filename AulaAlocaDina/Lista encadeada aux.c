#include <stdio.h>
#include <stdlib.h>

int main(void){
	typedef struct nodo{
		char data;
		struct nodo *link;
	} *ptr;
	ptr lista = malloc(sizeof(struct nodo));
	lista -> data = 'C';
	ptr aux = malloc(sizeof(struct nodo));
	lista -> link = aux;
	aux -> data = 'A';
	aux -> link = malloc(sizeof(struct nodo));
	aux = aux -> link;
	aux -> data = 'D';
	aux -> link = malloc(sizeof(struct nodo));
	aux = aux -> link;
	aux -> data = 'E';
	aux -> link = NULL;	
	aux = lista;
	while(aux != NULL){
		printf("%c", aux -> data);
		aux = aux -> link;	
	}
	printf("\n");
}
