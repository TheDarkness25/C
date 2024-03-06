#include <stdio.h>
#include <stdlib.h>

int main(void){
	char *letra;
	letra = malloc(1);
	*letra = 'R';
	printf("%c\n", *letra);
	return 0;	
}
