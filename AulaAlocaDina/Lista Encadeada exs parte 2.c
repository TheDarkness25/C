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

//Para os exs de Deque:

typedef int TIPOCHAVE;
typedef struct {
	TIPOCHAVE chave;
} REGISTRO;

typedef struct auxElem {
	REGISTRO reg;
	struct auxElem* ant;
	struct auxElem* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
	PONT cabeca;
} DEQUE;

void createDeque(DEQUE* d) {
	d -> cabeca = (PONT) malloc(sizeof(ELEMENTO));
	d -> cabeca -> prox = d -> cabeca;
	d -> cabeca -> ant = d -> cabeca;
}
// 6) Função de deque com lista simples
// a) inclusão

void inserirDeque(DEQUE* d, REGISTRO reg) {
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo -> reg = reg;
	novo -> prox = d -> cabeca;
	novo -> ant = d -> cabeca -> ant;
	d -> cabeca -> ant = novo;
}

// b) remoção

void removeDeque(DEQUE* d, REGISTRO* reg){
	if (d -> cabeca -> prox == d -> cabeca) abort();
	PONT apagar = d -> cabeca -> prox;
	*reg = apagar -> reg;
	d -> cabeca -> prox = apagar -> prox;
	apagar -> prox -> ant = d -> cabeca;
	free(apagar);
}

// 7) Função de deque com lista simples
// a) inclusão

void inserirDequeD(DEQUE* d, REGISTRO reg) {
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo -> reg = reg;
	novo -> prox = d -> cabeca;
	novo -> ant = d -> cabeca -> ant;
	d -> cabeca -> ant = novo;
	novo -> ant -> prox = novo;
}

// b) remoção

void removeDequeD(DEQUE* d, REGISTRO* reg){
	if (d -> cabeca -> prox == d -> cabeca) abort();
	PONT apagar = d -> cabeca -> prox;
	*reg = apagar -> reg;
	d -> cabeca -> prox = apagar -> prox;
	apagar -> prox -> ant = d -> cabeca;
	free(apagar);
}

// 8) Função que receba duas listas ordenadas e exiba a intercalação crescente de seus elementos

void interCres(ptr lista, ptr lista1){
		while(lista != NULL){
			while(lista1 != NULL){
				while(lista -> data < lista1 -> data){
					lista = lista -> link;
				}
				lista = lista1 -> link;
				while(lista1 -> data < lista -> data){
					lista = lista1 -> link;
					lista1 = lista1 -> link;
				}
				lista = lista -> link;
				lista1 = lista1 -> link;	
		}
		lista = lista -> link;	
	}
}

// 09) Função que recebe duas lista ordenadas e devolva uma nova lista com a intercalação crescente das duas 

void interCresNew(ptr lista, ptr lista1){
	ptr lista3;
	create(&lista3);	
	while(lista != NULL){
			while(lista1 != NULL){
				while(lista -> data < lista1 -> data){
					lista3 = lista -> link;
					lista = lista -> link;
				}
				lista3 = lista1 -> link;
				while(lista1 -> data < lista -> data){
					lista3 = lista1 -> link;
					lista1 = lista1 -> link;
				}
				lista3 = lista -> link;
				lista1 = lista1 -> link;	
		}
		lista = lista -> link;	
	}
}

// 10) Função nodo cabeça
// a) incluir

int incluirCabeça(ptr *lista, char elem){
	ptr cabeca = malloc(sizeof(struct nodo));
	ptr aux = malloc(sizeof(struct nodo));
	aux -> data = elem;
	aux -> link = *lista;
	*lista = aux;
	return cabeca -> data += 1;
}

// b) remove

int removeCabeça(ptr *lista, char elem){
	ptr cabeca = malloc(sizeof(struct nodo));
	ptr aux;
	aux = *lista;
	*lista = aux -> link;
	free(aux);
	return cabeca -> data -= 1;
}


int main(void){
	printf("Eu tentei de verdade :( sorry\n");
}
