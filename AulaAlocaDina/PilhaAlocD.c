#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
          char data;
          struct nodo *link;
        } *ptr;

void create(ptr *lista) {
     *lista = NULL;        
}

void push(ptr *lista, char elem) {
	ptr aux = malloc(sizeof(struct nodo));
	aux -> data = elem;
	aux -> link = *lista;
	*lista = aux;  
}

char pop(ptr *lista) {
    ptr aux;
	char r;
	aux = *lista;
	*lista = aux -> link;
	r = aux -> data;
	free(aux);  
	return r;    
}

char top(ptr lista) {
     if(lista == NULL) abort();
	else return lista -> data;      
}

void exibe(ptr lista) {
     	while(lista != NULL){
		printf("%c", lista -> data);
		lista = lista -> link;	
	}       
}
 
int main(void) {
    printf("\nTestando a pilha...\n");
    ptr p;
    create(&p);
    printf("\npush E\n");
    push(&p,'E');
    printf("\npush T\n");
    push(&p,'T');
    printf("\npush S\n");
    push(&p,'S');
    printf("\npush E\n");
    push(&p,'E');
    printf("\nExibe Pilha\n");
    exibe(p);
    printf("\npush T\n");
    push(&p,'T');
    printf("\nExibe Pilha\n");
    exibe(p);
    printf("\nPop\n");
    char ch=pop(&p);
    printf("\nRetirado: %c\n",ch);
    printf("\nExibe Pilha\n");
    exibe(p);
    printf("\nTop\n");
    ch=top(p);
    printf("\nRecebido da Top: %c\n",ch);
    printf("\nExibe Pilha\n");
    exibe(p);
    printf("\nPop\n");
    ch=pop(&p);
    printf("\nRetirado: %c\n",ch);
    printf("\nExibe Pilha\n");
    exibe(p);
	printf("\n");
    return 0;
} 
