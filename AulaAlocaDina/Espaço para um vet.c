#include <stdio.h>
#include <stdlib.h>

int main(void){
	float *num;
	num = malloc(5 * sizeof(float));
	for(int i = 0;i < 5;i++){
		scanf("%f", &num[i]);	
	}
	for(int i = 0;i < 5;i++){
		printf("%.2f\n", num[i]);	
	} 
	return 0;	
}
