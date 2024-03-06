#include<stdio.h>

int PercorreVetor(int v[20], int n, int t){

	for(i=1; i < t; i++){
		if(v[1] == n){
			return 1;
			}
		}
	return 0;
	}

int main(void){
	printf("Estrutura de dados!");
	int v[] = {1, 2, 3, 4, 5, 6};
	int t= 6;
    printf("%d\n", PercorreVetor(v, 5, t));
	return 0;
	}
