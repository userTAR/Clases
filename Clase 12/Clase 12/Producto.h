#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int idProducto;
char nombre[20];
int precio;
int stock;
int provedorPrimitivo;
}eProducto;

void hardCodearProducto(eProducto[]);
void imprimirTodosProductos(eProducto[]);

