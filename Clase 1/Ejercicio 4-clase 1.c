#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/


int main(){
	signed int numero;
	int contador=0;
	int positivos=0;
	int negativos=0;
for(contador;contador<10;contador++){
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	if(numero<0){
	    negativos++;
	}
	else{
	    positivos++;
	}
}
printf("\n La cantidad de positivos es: %d \n La cantidad de negativos es: %d",positivos,negativos);
return 0;
}