#include "Provedor.h"

void hardCodearProveedores(eProveedor provedor[])
{


    int idProvedor[4]={2,12,22,32};
    char nombre[4][20]={"orq1","orq2","orq3","orq4"};
    char localidad[4][20]={"a","b","c","d"};

  int i;
  for(i=0; i<4; i++)
  {
      provedor[i].idProvedor= idProvedor[i];
      strcpy(provedor[i].nombre, nombre[i]);
      strcpy(provedor[i].localidad, localidad[i]);
  }
}

void imprimirTodosProvedores(eProveedor provedor[])
{
    int i;
    for(i=0;i<4;i++)
    {
    printf("IdProvedor:%d\tLocalidadProvedor:%s\tNombreProvedor:%s\n",provedor[i].idProvedor
                                    ,provedor[i].localidad,provedor[i].nombre);
    }
}
