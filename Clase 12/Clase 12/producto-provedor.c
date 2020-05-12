#include "producto-provedor.h"

void mostrarTodosLosProvedoresConProductos(eProducto producto[],eProveedor provedor[],int tamProducto,int tamProvedor)
{
int i,j;
int contador;
for(i=0;i<tamProvedor;i++)
{
    contador=0;
    printf("El provedor %s de id:%d tiene los siguientes productos:\n",provedor[i].nombre,provedor[i].idProvedor);
    for(j=0;j<tamProducto;j++)
    {
        if(provedor[i].idProvedor == producto[j].provedorPrimitivo)
        {
            contador++;
            printf("Nombre:%s $:%d  ID:%d\n",producto[j].nombre,producto[j].precio,producto[j].idProducto);
        }
    }
    printf("El proveedor %s tiene asociado %d productos\n",provedor[i].nombre, contador);
}
}
void mostrarProvedoresConMasProductos(eProducto producto[],eProveedor provedor[],int tamProducto,int tamProvedor)
{
int i,j;
int contador,flag=0,indiceMax,maximo;
for(i=0;i<tamProvedor;i++)
{
    contador=0;
    for(j=0;j<tamProducto;j++)
    {
        if(provedor[i].idProvedor == producto[j].provedorPrimitivo)
            contador++;
    }
    if(flag==0||contador>maximo)
    {
        maximo = contador;
        indiceMax = i;
        flag = 1;
    }
}
printf("El provedor con mas productos asociados es %s con id:%d",provedor[indiceMax].nombre, provedor[indiceMax].idProvedor);
}
