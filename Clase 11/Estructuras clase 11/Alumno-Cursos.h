#include "Alumno.h"
#include "Cursos.h"

typedef struct
{
    int idCurso;
    int cantidadAlumnos;
} Alumno_Curso;

void mostrarAlumnosConSuCurso(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos);
void mostrarCursosConSusAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos);
void mostrarCursoConMasAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos);
void mostrarCursosPorEleccionDeUsuario(eAlumno[], int, eCurso[], int);
