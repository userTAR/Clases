#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	int b;
	int resta;

	printf("Ingrese el primer numero: ");
	scanf("%d", &a);
	if(a<1){
		printf("Reingrese el primer numero: ");
		scanf("%d", &a);
	}
	printf("\n Ingrese el segundo numero: ");
	scanf("%d", &b);
	if(b<1){
		printf("Reingrese el segundo numero: ");
		scanf("%d", &b);
	}
	resta=a-b;
	if(resta<0){
	    printf("El resultado es negativo");
	}
	else{
	    printf("El resultado es positivo");
	}
	return 0;
}
