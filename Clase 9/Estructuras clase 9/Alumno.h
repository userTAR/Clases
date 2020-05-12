#include <stdio.h>
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
  int legajo;
  int nota1;
  int nota2;
  float promedio;
  char nombre[20];
  char email[20];
  eFecha fechaNacimiento;
  int estado;
} eAlumno;


void inicializarAlumnos(eAlumno listado[], int tam);
void hardCodearAlumnos(eAlumno listado[], int tam);
void hardCodearFechas(eAlumno listado[]);
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
