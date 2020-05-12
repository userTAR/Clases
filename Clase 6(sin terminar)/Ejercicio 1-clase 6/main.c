#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Mostrar por pantalla el apellido y nombre de una persona, respetando el siguiente formato:
"Scarafilo, Germán Ezequiel". Tener en cuenta: apellido y nombre se ingresan en dos variables
distintas que no pueden ser modificadas. El ingreso de datos no tiene ningún formato en
particular, es decir no se tiene en cuenta mayusculas o minusculas, por lo que su programa
deberá hacerlo para respetar el formato solicitado.*/
char getStr(char[],char[]);


int main()
{
    char nombre[21];
    char apellido[21];
    char nombreYapellido[26];
getStr(nombre,"nombre");
printf("El nombre ingresado es: %s\n",nombre);

getStr(apellido,"apellido");
printf("El apellido ingresado es: %s",apellido);

strcpy(nombreYapellido,strcat(apellido,","));
strcpy(nombreYapellido,strcat(nombreYapellido," "));
strcpy(nombreYapellido,strcat(nombreYapellido,nombre));
printf("\nSu nombre y apellido es %s",nombreYapellido);

}
char getStr(char dato[],char mensaje[])
{
    printf("Ingrese su %s: ",mensaje);
    fflush(stdin);
    gets(dato);
    return dato;
}
/*
Falta convertir toda la palabra a minúscula obligatoriamente y luego convertir la primera letra a Mayúscula
*/
