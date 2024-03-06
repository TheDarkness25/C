#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
		char data;
		struct nodo *link;
	} *ptr;

void create(ptr *lista){
	*lista = NULL;
}

int isempty(ptr lista){
	return lista == NULL;	
}

void insere(ptr *lista, char elem){
	ptr aux = malloc(sizeof(struct nodo));
	aux -> data = elem;
	aux -> link = *lista;
	*lista = aux;
}

void insere_fim(ptr *L, char elem){
	ptr aux = malloc(sizeof(struct nodo));
	aux -> data = elem;
	aux -> link = NULL;
	while(*lista != NULL) lista = &(*lista) -> link;
	*lista = aux;   
}

void rem(ptr *lista){
	ptr aux;
	aux = *lista;
	*lista = aux -> link;
	free(aux);
}

void exibe(ptr lista){
	while(lista != NULL){
		printf("%c", lista -> data);
		lista = lista -> link;	
	}
}

int main(void){
	ptr lista = malloc(sizeof(struct nodo));
	lista -> data = 'R';
	ptr aux = malloc(sizeof(struct nodo));
	lista -> link = aux;
	aux -> data = 'A';
	aux -> link = malloc(sizeof(struct nodo));
	aux = aux -> link;
	aux -> data = 'F';
	aux -> link = malloc(sizeof(struct nodo));
	aux = aux -> link;
	aux -> data = 'A';
	aux -> link = NULL;	
	aux = lista;
	while(aux != NULL){
		printf("%c", aux -> data);
		aux = aux -> link;	
	}
	printf("\n");
	ptr ptr1;
	create(&ptr1);
	insere(&ptr1, '5');
	insere(&ptr1, '2');
	insere(&ptr1, 'A'); 
	insere(&ptr1, 'F'); 
	insere(&ptr1, 'A');
	insere(&ptr1, 'R');
	exibe(ptr1);
	printf("\n");	  	
}
