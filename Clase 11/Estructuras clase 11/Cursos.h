#include <stdio.h>
#include <string.h>
typedef struct
{
int idCurso;//PK
char descripcion[50];
int duracion;
int estado;
}eCurso;



void mostrarTodosLosCursos(eCurso[], int);
