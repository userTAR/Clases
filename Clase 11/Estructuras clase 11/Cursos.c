#include "Cursos.h"

void mostrarTodosLosCursos(eCurso listadoDeCursos[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%4d %15s %d\n", listadoDeCursos[i].idCurso, listadoDeCursos[i].descripcion, listadoDeCursos[i].duracion);
    }
}
