#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto-provedor.h"

void main()
{
int eleccion;
printf("Ingrese opcion 1 o 2: ");
scanf("%d",&eleccion);
eProducto arrayProducto[10];
eProveedor arrayProveedor[4];

hardCodearProducto(arrayProducto);
hardCodearProveedores(arrayProveedor);
switch(eleccion)
{
    case 1:
        mostrarTodosLosProvedoresConProductos(arrayProducto,arrayProveedor,10,4);
        break;
    case 2:
        mostrarProvedoresConMasProductos(arrayProducto,arrayProveedor,10,4);
        break;
}

}

