#include <stdlib.h>
#include "Alumno.h"
#define T 6


int main ()
{
    eAlumno listaAlumnos[T];/* ={{1,8,9,8.5,"Pepe","pepe@gmail.com",{10,5,1999},OCUPADO},
                             {3,10,10,10,"Fatiga","fatiga@gmail.com",{7,3,1990},OCUPADO},
                             {2,4,5,4.5,"Coqui","coqui@gmail.com",{5,7,1997},OCUPADO},
                             {5,10,10,10,"Ana","paola@gmail.com",{18,2,2000},LIBRE},
                             {4,10,10,10,"Paola","moni@gmail.com",{4,8,1999},OCUPADO}};*/

    int opcion;

    inicializarAlumnos(listaAlumnos,T);
    hardCodearAlumnos(listaAlumnos,T);
    do
    {
        printf("1.Cargar un ALUMNO\n");
        printf("2.Eliminar un ALUMNO\n");
        printf("3.Modificar un ALUMNO\n");
        printf("4.Listar ALUMNOS\n");
        printf("5.Ordenar ALUMNOS\n");
        printf("10.SALIR\n");
        printf("ELIJA UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("CARGA DE DATOS:\n");
                cargarUnAlumno(listaAlumnos, T);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                printf("LISTADO:\n");
                mostrarTodosLosAlumnos(listaAlumnos, T);
            break;
            case 5:
                printf("LISTADO ORDENADO:\n");
                ordenarAlumnosPorNombre(listaAlumnos,T);
            break;
        }

    }while(opcion!=10);


   /*printf("LISTADO DE PROMOCIONADOS:\n");
    mostrarAlumnosPromocionados(listaAlumnos, T, 6);

    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE ALUMNOS CON PROMEDIO MAXIMO:\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos, T);
    printf("LISTADO ORDENADO POR PROMEDIO:\n");
    ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);
    mostrarTodosLosAlumnos(listaAlumnos, T);*/
  return 0;
}
