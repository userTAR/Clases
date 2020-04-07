/* ingresar números hasta que el usuario lo decida.
Informar:
cantidad de numeros pares
cantidad de numeros positivos y negativos
promedio de todos los numeros
maximo y minimo */
#include <stdio.h>

int main()
{
    int numero;
    int pares=0;
    int positivos=0;
    int negativos=0;
    int sumaNumeros=0;
    int cantNumeros=0;
    float promedio;
    int maximo;
    int minimo;

    char seguir='s';

        while(seguir=='s'){
            printf("Ingrese un numero: ");
            scanf("%d",&numero);
            sumaNumeros+=numero;
            if(numero%2==0){
                pares++;
            }
            if(numero>0){
                positivos++;
            }
            else if(numero<0){
                negativos++;
            }
            if(cantNumeros==0||numero>maximo){
                maximo=numero;
            }
            else if(cantNumeros==0||numero<minimo){
                minimo=numero;
            }
            cantNumeros++;
            printf("\nSi desea seguir ingresando numeros ingrese la letra s");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    promedio=(float)sumaNumeros/cantNumeros;
    printf("\nLa cantidad de numeros pares es: %d",pares);
    printf("\nLa cantidad de numeros positivos es: %d",positivos);
    printf("\nLa cantidad de numeros negativos es: %d",negativos);
    printf("\nEl numero maximo es: %d",maximo);
    printf("\nEl numero minimo es: %d",minimo);
    printf("\nEl promedio de la suma de los numeros y la cantidad de numeros ingresados es: %.1f",promedio);
    return 0;
}

