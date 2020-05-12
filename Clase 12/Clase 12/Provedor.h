#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int idProvedor;
char nombre[20];
char localidad[20];
}eProveedor;

void hardCodearProveedores(eProveedor[]);
void imprimirTodosProvedores(eProveedor[]);
