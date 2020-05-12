#include <stdlib.h>
#include "Alumno.h"

#define T 5

int main ()
{
  //tipodedato nombrevariable;

    eAlumno listaAlumnos[T]={{1,8,9,8.5,"Pepe","pepe@gmail.com"},
                             {3,10,10,10,"Fatiga","fatiga@gmail.com"},
                             {2,4,5,4.5,"Coqui","coqui@gmail.com"},
                             {5,10,10,10,"Ana","paola@gmail.com"},
                             {4,10,10,10,"Paola","moni@gmail.com"}};


    //printf("CARGA DE DATOS:\n");
    //cargarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO:\n");
    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE PROMOCIONADOS:\n");
    mostrarAlumnosPromocionados(listaAlumnos, T, 6);
    printf("LISTADO ORDENADO:\n");
    ordenarAlumnosPorNombre(listaAlumnos,T);
    mostrarTodosLosAlumnos(listaAlumnos, T);
    printf("LISTADO DE ALUMNOS CON PROMEDIO MAXIMO:\n");
    mostrarAlumnosConMaximoPromedio(listaAlumnos, T);
    printf("LISTADO ORDENADO POR PROMEDIO:\n");
    ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);
    mostrarTodosLosAlumnos(listaAlumnos, T);
  return 0;
}

