#include "Producto.h"

void hardCodearProducto(eProducto producto[])
{
    int idProducto[10]={1,11,21,31,41,51,61,71,81,91};
    char nombre[10][20]={"AEROLINEAS","AIRFRANCE","AUSTRAL","LITORAL","CAPITAL","BRITISH","ROJAS","COPA","UNITED","LAN"};
    int precio[10]={50,80,75,45,25,95,75,25,15,45};
    int stock[10]={1,1,1,1,1,1,1,1,1,1};
    int provedorPrimitivo[10]={2,2,12,12,12,12,22,22,22,22};
  int i;
  for(i=0; i<10; i++)
  {
      producto[i].idProducto = idProducto[i];
      strcpy(producto[i].nombre, nombre[i]);
      producto[i].precio = precio[i];
      producto[i].stock = stock[i];
      producto[i].provedorPrimitivo = provedorPrimitivo[i];
  }
}
void imprimirTodosProductos(eProducto producto[])
{
   int i;
    for(i=0;i<10;i++)
    {
    printf("Id producto:%d\t NombreProducto:%s\t PrecioProducto:%d\t StockProducto:%d\n",producto[i].idProducto,
                                    producto[i].nombre,producto[i].precio,producto[i].stock);
    }
}

