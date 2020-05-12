#include "Alumno.h"
void hardCodearAlumnos(eAlumno listado[], int tam)
{
  int legajos[5]={1,2,3,4,5};
  int nota1[5]={10,4,9,8,7};
  int nota2[5]={3,2,7,8,9};
  char nombre[5][20] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char mail[5][20] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};;
 // eFecha fechas[5] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
  hardCodearFechas(listado);
  int i;

  for(i=0; i<5; i++)
  {
      listado[i].legajo = legajos[i];
      listado[i].nota1 = nota1[i];
      listado[i].nota2 = nota2[i];
      listado[i].promedio = (float) (listado[i].nota1 + listado[i].nota2)/2;
      //listado[i].fechaNacimiento = fechas[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].email, mail[i]);
      listado[i].estado = OCUPADO;
  }


}

void hardCodearFechas(eAlumno listado[])
{
    int dia[5] = {15,17,18,22,24};
    int mes[5] = {11,9,2,1,1};
    int anio[5] = {1972,1972,1995,2001,2006};

    int i;
    for (i=0;i<5;i++)
    {
       listado[i].fechaNacimiento.dia= dia[i];
        listado[i].fechaNacimiento.mes= mes[i];
        listado[i].fechaNacimiento.anio= anio[i];
    }
}

void inicializarAlumnos(eAlumno listado[], int tam)
{
    int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estado = LIBRE;
  }
}
int buscarLibre(eAlumno listado[], int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if(listado[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}
void cargarUnAlumno(eAlumno listado[], int tam)
{
  int index;

  index = buscarLibre(listado, tam);

  if(index!=-1)
  {
      listado[index] = crearUnAlumno();
  }

  /*....*/

}
void mostrarTodosLosAlumnos(eAlumno listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {
       if(listado[i].estado==OCUPADO)
       {
           mostrarUnAlumno(listado[i]);
       }

   }

}


eAlumno crearUnAlumno (void)
{
  eAlumno miAlumno;


  printf ("Ingrese legajo: ");
  scanf ("%d", &miAlumno.legajo);
  printf ("Ingrese nota 1: ");
  scanf ("%d", &miAlumno.nota1);
  printf ("Ingrese nota 2: ");
  scanf ("%d", &miAlumno.nota2);
  printf ("Ingrese nombre: ");
  fflush (stdin);
  gets(miAlumno.nombre);

  printf ("Ingrese email: ");
  fflush (stdin);
  gets (miAlumno.email);

  miAlumno.fechaNacimiento = getDate();

  miAlumno.promedio = promediarNotasAlumno(miAlumno.nota1,miAlumno.nota2);

  miAlumno.estado = OCUPADO;

  return miAlumno;

}


void mostrarUnAlumno (eAlumno miAlumno)
{
  printf ("%8d %8d %8d\t%8.2f %15s %15s \t[%d/%d/%d]\n", miAlumno.legajo,
                                          miAlumno.nota1,
                                          miAlumno.nota2,
                                          miAlumno.promedio,
                                          miAlumno.nombre,
                                          miAlumno.email,
                                          miAlumno.fechaNacimiento.dia,
                                          miAlumno.fechaNacimiento.mes,
                                          miAlumno.fechaNacimiento.anio);
}

void mostrarAlumnosPromocionados(eAlumno listado[], int tam, int aprobado)
{
   int i;

   for(i=0; i<tam; i++)
   {
       if(listado[i].nota1 >= aprobado && listado[i].nota2 >= aprobado)
       {
            mostrarUnAlumno(listado[i]);
       }

   }
}

float promediarNotasAlumno(int nota1, int nota2)
{
    return (float) (nota1+nota2)/2;
}

void ordenarAlumnosPorNombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }

    }

}

float buscarPromedioMaximo(eAlumno listado[], int tam)
{
    int i;
    float maxPromedio;
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio>maxPromedio || i==0)
        {
            maxPromedio = listado[i].promedio;
        }
    }

    return maxPromedio;
}
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam)
{
    int i;
    float maximo;
    maximo = buscarPromedioMaximo(listado,tam);

    //mostrarAlumnosPromedioMaximo(listado,tam, maximo);

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
            mostrarUnAlumno(listado[i]);
        }
    }
}

void ordenarAlumnosPorPromedio_Nombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listado[i].promedio>listado[j].promedio)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
            else
            {
               if(listado[i].promedio==listado[j].promedio)
               {
                   if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                   {
                        auxAlumno = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxAlumno;
                   }
               }
            }
        }

    }
}
eFecha getDate(void)
{
    eFecha unaFecha;
    printf("Ingrese dia: ");
    scanf("%d", &unaFecha.dia);
    printf("Ingrese mes: ");
    scanf("%d", &unaFecha.mes);
    printf("Ingrese año: ");
    scanf("%d", &unaFecha.anio);
    return unaFecha;
}
