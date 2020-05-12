#include "Alumno.h"

void hardCodearAlumnos(eAlumno listado[], int tam)
{
  int legajos[6]={1,2,3,4,5,6};
  int nota1[6]={10,4,9,8,7,8};
  int nota2[6]={3,2,7,8,9,7};
  char nombre[6][20] = {"Juan","Maria","Ana","Pedro","Luisa","Octavio"};
  char mail[6][20] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com","Octupus@Slack.com"};;
  eFecha fechas[6] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
  int curso[6] = {101,100,101,102,100,100};
  int i;

  for(i=0; i<6; i++)
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
    listado[5].estado = LIBRE;

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
           fgets(listado[i].email,20,stdin);
           listado[i].email[strlen(listado[i].email)-1]='\0';

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
  fgets(miAlumno.nombre,50,stdin);
      miAlumno.nombre[strlen(miAlumno.nombre)-1]='\0';

  printf ("Ingrese email: ");
  fflush (stdin);
  fgets (miAlumno.email,50,stdin);
    miAlumno.email[strlen(miAlumno.email)-1]='\0';

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

