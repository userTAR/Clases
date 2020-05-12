#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
  int dia;
  int mes;
  int anio;
}eFecha;



typedef struct
{
  int legajo;//PK
  int nota1;
  int nota2;
  float promedio;
  char nombre[20];
  char email[20];
  eFecha fechaNacimiento;

  int idCurso;//FK
  int estado;
} eAlumno;

void eliminarAlumno(eAlumno listado[], int tam);
void modificarALumno(eAlumno listado[], int tam);
void inicializarAlumnos(eAlumno listado[], int tam);
void hardCodearAlumnos(eAlumno listado[], int tam);
int buscarLibre(eAlumno listado[], int tam);
void cargarUnAlumno(eAlumno listado[], int tam);
void mostrarTodosLosAlumnos(eAlumno listado[], int tam);
void mostrarAlumnosPromocionados(eAlumno listado[], int tam, int aprobado);
void mostrarUnAlumno (eAlumno miAlumno);
eAlumno crearUnAlumno (void);
float promediarNotasAlumno(int nota1, int nota2);
void ordenarAlumnosPorNombre(eAlumno listado[], int tam);
float buscarPromedioMaximo(eAlumno listado[], int tam);
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam);
void ordenarAlumnosPorPromedio_Nombre(eAlumno listado[], int tam);
eFecha getDate(void);

