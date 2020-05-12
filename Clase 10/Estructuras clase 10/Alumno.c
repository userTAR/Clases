#include "Alumno.h"
void hardCodearAlumnos(eAlumno listado[], int tam)
{
  int legajos[5]={1,2,3,4,5};
  int nota1[5]={10,4,9,8,7};
  int nota2[5]={3,2,7,8,9};
  char nombre[5][20] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char mail[5][20] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};;
  eFecha fechas[5] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
  int curso[5] = {101,100,101,102,100};
  int i;

  for(i=0; i<5; i++)
  {
      listado[i].legajo = legajos[i];
      listado[i].nota1 = nota1[i];
      listado[i].nota2 = nota2[i];
      listado[i].promedio = (float) (listado[i].nota1 + listado[i].nota2)/2;
      listado[i].fechaNacimiento = fechas[i];
      strcpy(listado[i].nombre, nombre[i]);
      strcpy(listado[i].email, mail[i]);
      listado[i].idCurso = curso[i];
      listado[i].estado = OCUPADO;
  }

    listado[3].estado = LIBRE;

}

void eliminarAlumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<tam;i++)
    {
        if(legajo == listado[i].legajo)
        {
            listado[i].estado=LIBRE;
            break;
        }
    }
}
void modificarALumno(eAlumno listado[], int tam)
{
    int legajo;
    int i;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<tam;i++)
    {
        if(legajo == listado[i].legajo)
        {
           printf("Reingrese EMAIL:");
           fflush(stdin);
           gets(listado[i].email);
            break;
        }
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
      listado[index] = crearUnAlumno();//
      //ASOCIAR UN ALUMNO A UN CURSO
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
  printf ("%8d %8d %8d\t%8.2f %15s %15s [%d/%d/%d]  %d\n", miAlumno.legajo,
                                          miAlumno.nota1,
                                          miAlumno.nota2,
                                          miAlumno.promedio,
                                          miAlumno.nombre,
                                          miAlumno.email,
                                          miAlumno.fechaNacimiento.dia,
                                          miAlumno.fechaNacimiento.mes,
                                          miAlumno.fechaNacimiento.anio,
                                          miAlumno.idCurso);
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

void mostrarAlumnosConSuCurso(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i;//alumnos
    int j;//cursos
    //Tener en cuenta que hay alumnos que pueden estar dados de baja
    //Tener en cuenta que hay cursos que pueden estar dados de baja
    for(i=0; i<sizeAlumnos; i++)
    {
        for(j=0; j<sizeCursos; j++)
        {
            if(listaDeAlumnos[i].idCurso /*FK*/ == listaDeCursos[j].idCurso /*PK*/ && listaDeAlumnos[i].estado!=0)
            {
                printf("%4d %15s %15s %4d\n", listaDeAlumnos[i].legajo, listaDeAlumnos[i].nombre, listaDeCursos[j].descripcion, listaDeCursos[j].duracion);
                break;
            }
        }
    }


}

void mostrarCursosConSusAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i;//Cursos
    int j;//Alumnos

    for(i=0; i<sizeCursos; i++)
    {
        printf("CURSO: %s\n", listaDeCursos[i].descripcion);
        for(j=0; j<sizeAlumnos; j++)
        {
            //Preguntar si el alumno esta disponible
             if(listaDeAlumnos[j].idCurso /*FK*/ == listaDeCursos[i].idCurso /*PK*/)
             {
                  mostrarUnAlumno(listaDeAlumnos[j]);
             }

        }
    }

}

void mostrarCursosPorEleccionDeUsuario(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int curso;
    int i,j;
    for( j=0 ; j<sizeCursos ; j++ )
    {
        printf("%s \t %d",listaDeCursos[j].descripcion,listaDeCursos[j].idCurso);
    }
    printf("Ingrese el ID de un curso: ");
    scanf("%d", &curso);
    printf("Los alumnos correspondientes al ID %d son los siguientes:\n", curso);
     for(i=0; i<sizeAlumnos; i++)
     {
         if(listaDeAlumnos[i].idCurso == curso)
            mostrarUnAlumno(listaDeAlumnos[i]);
     }
}
void mostrarCantidadDeAlumnosJava(eAlumno listaDeAlumnos[],int sizeAlumnos)
{
    int i,cantJava = 0;
    for(i=0;i<sizeAlumnos;i++)
    {
        if(listaDeAlumnos[i].idCurso == 100)
            cantJava++;
    }
    printf("La cantidad de personas que cursan java es:%d \n",cantJava);
}
void cantidadDeHorasTotalesPorCursos(eAlumno listaDeAlumnos[],int sizeAlumnos)
{
    int i,cantJava = 0,cantInkscape = 0, cantOffice = 0;
    for(i=0;i<sizeAlumnos;i++)
    {
        if(listaDeAlumnos[i].idCurso == 100 && listaDeAlumnos[i].estado!=0)
            cantJava++;
        else if(listaDeAlumnos[i].idCurso == 101 && listaDeAlumnos[i].estado!=0)
            cantInkscape++;
        else if(listaDeAlumnos[i].idCurso == 102 && listaDeAlumnos[i].estado!=0)
            cantOffice++;
    }

    cantJava = cantJava * 7;
    cantInkscape = cantInkscape * 10;
    cantOffice = cantOffice * 9;

    printf("La cantidad de horas totales segun alumnos es: \n JAVA:%d \t INKSCAPE:%d \t OFFICE:%d \n",cantJava,cantInkscape,cantOffice);
}
void mostrarPromedioNota2PorEleccionDeUsuario(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int curso;
    int i,j,sumaNota2=0,cantNota2=0;
    for( j=0 ; j<sizeCursos ; j++ )
    {
        printf("%s \t %d \n",listaDeCursos[j].descripcion,listaDeCursos[j].idCurso);
    }
    printf("Ingrese el ID de un curso: ");
    scanf("%d", &curso);
     for(i=0; i<sizeAlumnos; i++)
     {
         if(listaDeAlumnos[i].idCurso == curso)
         {
            cantNota2++;
            sumaNota2 = sumaNota2 + listaDeAlumnos[i].nota2;
         }
     }
    float promedio = (float)sumaNota2/cantNota2;
    printf("El promedio de la nota 2 segun curso elegido previamente: %.2f \n",promedio);
}
