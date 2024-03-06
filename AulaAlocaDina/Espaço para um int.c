#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *num;
	num = malloc(sizeof(int));
	*num = 110921;
	printf("%d\n", *num);
	return 0;	
}
