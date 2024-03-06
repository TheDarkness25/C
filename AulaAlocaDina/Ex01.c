#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *x;
	x = malloc(sizeof(int));
	*x = 123;
	printf("%d\n", *x); //quando for só x (sem o *) mostra o endereço da area de memória
	int *y;
	y = x; //os dois apontam para mesma area!
	printf("%d\n", *y);
	*x = 10;
	printf("%d\n", *y);
	y = malloc(sizeof(int));
	*y = 25;
	printf("%d\n", *x);
	*x = *y;
	*x = 40;
	printf("%d\n", *y);
	free(x); //Note que a função free(ponteiro_x) libera a área de memória apontada por ponteiro_x.
	free(y); //Entretanto, o ponteiro_x ainda continua apontando para a área que já foi liberada.
	x = NULL; //Por isso é uma prática recomendada colocar NULL no ponteiro após liberar a área de
	y = NULL; // memória por ele.
	return 0;
}
