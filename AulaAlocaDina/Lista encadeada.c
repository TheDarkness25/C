#include <stdio.h>
#include <stdlib.h>

int main(void){
	typedef struct nodo{
		char data;
		struct nodo *link;
	} *ptr;

	ptr lista = malloc(sizeof(struct nodo));
	lista -> data = 'C';
	lista -> link = malloc(sizeof(struct nodo));
	lista -> link -> data = 'A';
	lista -> link -> link = malloc(sizeof(struct nodo));
	lista -> link -> link -> data = 'D';
	lista -> link -> link -> link = malloc(sizeof(struct nodo));
	lista -> link -> link -> link -> data = 'E';
	lista -> link -> link -> link -> link = NULL;
			
}
