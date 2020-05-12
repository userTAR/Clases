#include <stdio.h>
#define T 10


void cargarNumeros(int [], int tam);
float calcularPromedio(int [], int tam);
int calcularMaximo(int [], int tam);
void mostrarNumeros(int pepe[], int tam);
void inicializarArray(int miArray[], int tam);
int CantidadDeCargados(int miArray[], int tam);
int SumaDeElementos(int miArray[], int tam); //char tipo
int sumaNegativos(int vector[],int tam);
int sumaPositivos(int vector[],int tam);
int calcularNegativos(int vector[],int tam);
int calcularPositivos(int vector[],int tam);
int calcularImpares(int vector[],int tam);
int calcularPares(int vector[],int tam);
int calcularMinimo(int vector[],int tam);

/*
primos
validaciones
*/
int
main ()
{
  int numeros[T];
  int pares;
  int impares;
  int maximo;
  int minimo;
  int positivos;
  int negativos;
  float promedioPositivos;
  float promedioNegativos;
  float promedio;

  inicializarArray(numeros, T);
  cargarNumeros(numeros, T);


  promedio = calcularPromedio(numeros,T);
  printf("\nEl promedio es: %f", promedio);

  maximo = calcularMaximo(numeros,T);
  printf ("\nEl maximo es: %d\n", maximo);

  minimo = calcularMinimo(numeros,T);
  printf("\nEl minimo es: %d",minimo);

  pares=calcularPares(numeros,T);
  printf("\nLa cantidad de pares es: %d",pares);

  impares=calcularImpares(numeros,T);
  printf("\nLa cantidad de impares es: %d",impares);

  positivos=calcularPositivos(numeros,T);
  printf("\nLa cantidad de positivos es: %d",positivos);

  promedioPositivos=((float)calcularPositivos(numeros,T))/sumaPositivos(numeros,T);
  printf("\nEl promedio de los positivos es: %f",promedioPositivos);

  negativos=calcularNegativos(numeros,T);
  printf("\nLa cantidad de negativos es: %d",negativos);

  promedioNegativos=((float)calcularNegativos(numeros,T))/sumaNegativos(numeros,T);
  printf("\nEl promedio de los negativos es %f", promedioNegativos);

  mostrarNumeros(numeros, T);

  return 0;
}
int sumaNegativos(int vector[],int tam)
{
    int i;
    int sumaNegativos=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]<0)
            sumaNegativos++;
    }
    return sumaNegativos;
}
int sumaPositivos(int vector[],int tam)
{
    int i;
    int sumaPositivos=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]>-1)
            sumaPositivos++;
    }
    return sumaPositivos;
}
int calcularNegativos(int vector[],int tam)
{
    int i;
    int negativos=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]<0)
            negativos++;
    }
    return negativos;
}
int calcularPositivos(int vector[],int tam)
{
    int i;
    int positivos=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]>-1)
            positivos++;
    }
    return positivos;
}
int calcularImpares(int vector[],int tam)
{
    int i;
    int impares=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]%2==1)
            impares++;
    }
return impares;
}

int calcularPares(int vector[],int tam)
{
    int i;
    int pares=0;
    for(i=0;i<tam;i++)
    {
        if(vector[i]%2==0)
            pares++;
    }
return pares;
}
int calcularMinimo(int vector[],int tam)
{
     int i;
    int minimo ;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] < minimo || i == 0)
    	{
    	  minimo = vector[i];
    	}
    }


    return minimo;
}

int SumaDeElementos(int miArray[], int tam)
{
    int i;
    int AcumuladorDeCargados=0;
    for (i = 0; i < tam; i++)
    {
        if(miArray[i]!=-1)
        {
            AcumuladorDeCargados=AcumuladorDeCargados+miArray[i];
        }
    }
    return AcumuladorDeCargados;
}

int CantidadDeCargados(int miArray[], int tam)
{
    int i;
    int contadorDeCargados=0;
    for (i = 0; i < tam; i++)
    {
        if(miArray[i]!=-1)
        {
            contadorDeCargados++;
        }
    }
    return contadorDeCargados;
}
void cargarNumeros(int vector[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
      printf ("Ingrese un numero: ");
      scanf ("%d", &vector[i]);
    }
}

void inicializarArray(int miArray[], int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
      miArray[i]=-1;
    }

}
float calcularPromedio(int vector[], int tam)
{
    return  (float)SumaDeElementos(vector,tam)/CantidadDeCargados(vector,tam);
}

int calcularMaximo(int vector[], int tam)
{

    int i;
    int maximo;


  for (i = 0; i < tam; i++)
    {
      if (vector[i] > maximo || i == 0)
    	{
    	  maximo = vector[i];
    	}
    }


    return maximo;

}

void mostrarNumeros(int vector[], int tam)
{
    int i;
    printf("\nLos numeros ingresados son:\n");
      for (i = 0; i < tam; i++)
    {

      printf ("%d\n", vector[i]);
    }

}
