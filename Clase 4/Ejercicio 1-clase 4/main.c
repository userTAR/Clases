//PRIMER FORMA DE HACERLO
#include <stdio.h>
int factorial(int);
void main(void)
{
    int numero,resultado;
    printf("\nIngrese numero:");
    scanf("%d",&numero);
    resultado=factorial(numero);
    printf("\nEl factorial de %d es %d",numero,resultado);
}
int factorial(int i)
{
    int retorno;
    if(i==1)
     return 1;
    retorno=i* factorial(i-1);
    return retorno;
}
//SEGUNDA FORMA DE HACERLO
#include <stdio.h>
int factorial(int);
void main(void)
{
    int numero,resultado;
    printf("\nIngrese numero:");
    scanf("%d",&numero);
    resultado=factorial(numero);
    printf("\nEl factorial de %d es %d",numero,resultado);
}
int factorial(int numero)
{
   int resultado=1;
    for(numero;numero>1;numero--){
        resultado=numero*resultado;
    }
    return resultado;
}
