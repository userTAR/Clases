#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/


int main(){
	int a;
	int b;
	int multiplicacion;
	int cuadrado;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &a);
	if(a==0){
		printf("Reingrese el primer numero: ");
		scanf("%d", &a);
	}
	printf("\n Ingrese el segundo numero: ");
	scanf("%d", &b);
	if(b==0){
			printf("Reingrese el segundo numero: ");
			scanf("%d", &b);
	}
	multiplicacion=a*b;
	cuadrado=a*a;
	printf("\n El producto de las variables es: %d \n el cuadrado de la variable a es: %d", multiplicacion, cuadrado);
	return 0;
}
