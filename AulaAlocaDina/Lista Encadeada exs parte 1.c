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

// 1) função que recebe uma lista e retorne sua quantidade de elementos:

int quant(ptr lista){
	int cont = 0;
	while(lista != NULL){
		cont++;
		lista = lista -> link;	
	}
	return cont;
}

// 2) função que recebe duas listas e concatene a segunda na primeira:

void concatena(ptr lista, ptr lista1){
	while(lista != NULL){
		if(lista -> link != NULL){
			lista = lista -> link;
		}
		else{
			lista = lista1 -> link;			
		}
	}
}

// 3) função que recebe uma lista ordenada e remova seus elementos duplicados:

void rem_dup(ptr lista){
	char aux1, aux2;
	while(lista != NULL){
		aux1 = lista -> data;
		lista = lista -> link;
		aux2 = lista -> data;
		if(aux1 == aux2){
			free(lista -> link);
			lista = lista -> link;
		}
		else
			lista = lista -> link;	
	}
}

// 4) função que recebe uma lista simples e transforme-a em uma lista circular:

void simples_para_circular(ptr lista){
	if(lista == NULL)return;
		ptr aux = lista;
	while(aux -> link != NULL)aux = aux -> link;
	aux -> link = lista;
}

// 5) função que recebe uma lista circular e retorne sua quantidade de elementos

int quant_circ(ptr lista){
	int cont = 0;
	while(lista -> link != lista){
		cont++;
		lista = lista -> link;	
	}
	return cont;
}

int main(void){
	printf("Eu tentei de verdade :( sorry\n");
}
