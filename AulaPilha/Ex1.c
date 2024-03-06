// Implementando pilhas com alocação estática sequencial (vetores)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha {
	       char vet[6];
	       int topo;
        } TPilha;

void create(TPilha *p) {
  p->topo = -1;
}

int isfull(TPilha *p) {
  if (p->topo == 5)
    return 1;
  else
    return 0;
}

int isempty(TPilha *p) {
  if (p->topo == -1)
    return 1;
  else
    return 0;
}

void push(TPilha *p, char x)
{
  if (isfull(p)) {    
    printf("overflow\n");
    abort();
  }
  p->topo++;
  p->vet[p->topo] = x;
}

char pop(TPilha *p) 
{    
  char aux;
  if (isempty(p)) {
    printf("underflow\n");
    abort();
  }
  aux = p->vet[p->topo];
  p->topo--;
  return aux;
}

void destroy(TPilha *p) {
  p->topo = -1;
}

// rotina que inverte o string inteiro
void inverte(char s[]) {
  int i, tam;
  TPilha p;
  create(&p);
  tam = strlen(s);
  for (i = 0; i < tam; i++)
    push(&p, s[i]);
  for (i = 0; !isempty(&p); i++)
    s[i] = pop(&p);
}

// rotina que verifica se o string passado é palíndromo
int palindroma(char s[ ]) {

    char s2[30];
    int i, tam, iguais = 0;
    printf("Digite a palavra: ");
    scanf("%s", s);
    tam = strlen(s);

    for(i = 0; i < strlen(s); i++){
        s2[i] = s[tam - 1];
        tam--;
    }

    s2[i] = '0';
    tam = strlen(s);
    
    for(i = 0; i < tam; i++){
        if(s[i] == s2[i])
            iguais++;
    }

    if(tam == iguais)
        printf ("1\n");
    else
        printf("0\n");

    return 0;
} 

// rotina que inverte o string palavra a palavra
int invfrase() {

    char frase [100];
    char frase2[100];
    int b,c,d,f,i,j;

    printf("Digite uma frase: ");
    gets(frase);
    c=0;d=0;
    f=strlen(frase);

    for(i=0;i<f;i++){
        if(frase[i]==' ')
            d++;      
    }

    if(d==0 && f > 0){
        for(i=f-1;i>=0;i--){ 
            printf("%c",frase[i]);
        }
    }

    if(d>0){
        frase2[0]=' ';
        for(i=0;i<f;i++){frase2[i+1]=frase[i];}
        frase2[f+1]='.';
        for(i=1;i<=f+1;i++){
            if(frase2[i]==' ' || frase2[i]=='.'){
                c=i-1;
                while(frase2[c]!=' '){
                    printf("%c",frase2[c]); 
                    c--;
                }
                printf(" ");
            }
        }
    }
    gets(frase);
    return 0;
}

int main(void) {
  char nome[]="teste";
  invfrase(nome);
  palindroma(nome);
  return 0;
  // coloque aqui os seus testes 
}
