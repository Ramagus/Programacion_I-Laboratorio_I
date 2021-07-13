#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Alumno.h"
#include "Localidad.h"

void inicializarAlumnos(eAlumno listaDeAlumnos[], int ta)
{
    int i;

    if(listaDeAlumnos != NULL && ta > 0)
    {
        for(i = 0; i < ta; i++)
        {
            listaDeAlumnos[i].estado = LIBRE;
        }
    }
}

int buscarLibre(eAlumno listaDeAlumnos[], int ta)
{
    int indice = -1;
    int i;

    if(listaDeAlumnos != NULL && ta > 0)
    {
        for(i = 0; i < ta; i++)
        {
            if(listaDeAlumnos[i].estado != OCUPADO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int buscarAlumnoPorLegajo(eAlumno listaDeAlumnos[], int ta, int legajo)
{
    int i;
    int index = -1;

    if(listaDeAlumnos != NULL && ta > 0)
    {
        for(i = 0; i < ta; i++)
        {
            if(listaDeAlumnos[i].legajo == legajo && listaDeAlumnos[i].estado == OCUPADO)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

void hardCodearAlumnos(eAlumno listaDeAlumnos[], int ta, int cantHardCode)
{
    int i;

    int legajo[] = {101, 102, 105};
    char nombre[][29] = {"Juan", "Maria Josefina", "Maria"};
    float promedio[] = {6.66, 4, 7.66};
    int localidad[] = {3, 1, 2};

    if(listaDeAlumnos != NULL && ta > 0 && cantHardCode > 0 && cantHardCode <= ta)
    {
        for(i = 0; i < ta; i++)
        {
            listaDeAlumnos[i].legajo = legajo[i];
            strcpy(listaDeAlumnos[i].nombre, nombre[i]);
            listaDeAlumnos[i].promedio = promedio[i];
            listaDeAlumnos[i].idLocalidad = localidad[i];

            listaDeAlumnos[i].estado = OCUPADO;
        }
    }
}

eAlumno cargarAlumno(eAlumno listaDeAlumnos[], int ta)
{
    eAlumno miAlumno;

    int indice;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);

    indice = buscarAlumnoPorLegajo(listaDeAlumnos, ta, miAlumno.legajo);

    if(indice == -1)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", miAlumno.nombre);

        printf("Ingrese promedio: ");
        scanf("%f", &miAlumno.promedio);

        printf("Ingrese ID de localidad: ");
        scanf("%d", &miAlumno.idLocalidad);

        miAlumno.estado = OCUPADO;
    }

    else
    {
        miAlumno.legajo = 0;
        strcpy(miAlumno.nombre, "");
        miAlumno.promedio = 0;
        miAlumno.idLocalidad = 0;

        miAlumno.estado = LIBRE;
    }

    return miAlumno;
}

void cargarListadoAlumnos(eAlumno listaDeAlumnos[], int ta)
{
    int indice;

    indice = buscarLibre(listaDeAlumnos, ta);

    printf("\nIndice: %d\n\n", indice);

    if(indice != -1)
    {
        //Hay lugar
        listaDeAlumnos[indice] = cargarAlumno(listaDeAlumnos, ta);

        if(listaDeAlumnos[indice].legajo == 0)
        {
            printf("\nEl legajo ingresado ya existe\n");
        }

        else
        {
            printf("\nAlumno cargado\n");
        }
    }

    else
    {
        printf("No hay espacio disponible\n");
    }
}

void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%-d\t\t%-16s\t%-.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
}

void mostrarListadoAlumnos(eAlumno listaDeAlumnos[], int ta)
{
    int i;

    if(listaDeAlumnos != NULL && ta > 0)
    {
        printf("\nLEGAJO\t\tNOMBRE\t\t\tPROMEDIO\n\n");

        for(i = 0; i < ta; i++)
        {
            if(listaDeAlumnos[i].estado == OCUPADO)
            {
                mostrarUnAlumno(listaDeAlumnos[i]);
            }
        }
    }
}

void mostrarUnAlumnoConLocalidad(eAlumno unAlumno, eLocalidad unaLocalidad)
{
    printf("%-d\t\t%-16s\t%-8.2f\t%-s\n", unAlumno.legajo, unAlumno.nombre, unAlumno.promedio, unaLocalidad.localidad);
}

void mostrarListadoAlumnosConLocalidad(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int index;

    if((listaDeAlumnos != NULL && ta > 0) && (listaDeLocalidades != NULL && tl > 0))
    {
        printf("\nLEGAJO\t\tNOMBRE\t\t\tPROMEDIO\tLOCALIDAD\n\n");

        for(i = 0; i < ta; i++)
        {
            index = buscarLocalidadPorId(listaDeLocalidades, tl, listaDeAlumnos[i].idLocalidad);

            if(index != -1 && listaDeAlumnos[i].estado == OCUPADO)
            {
                mostrarUnAlumnoConLocalidad(listaDeAlumnos[i], listaDeLocalidades[index]);
            }
        }
    }
}

int eliminarAlumno(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    int legajo;
    char respuesta;
    int quePaso = -1;
    int indexAlumno;
    int indexLocalidad;

    mostrarListadoAlumnosConLocalidad(listaDeAlumnos, ta, listaDeLocalidades, tl);

    printf("\nIngrese el legajo del alumno a eliminar: ");
    scanf("%d", &legajo);

    indexAlumno = buscarAlumnoPorLegajo(listaDeAlumnos, ta, legajo);

    if(indexAlumno != -1)
    {
        indexLocalidad = buscarLocalidadPorId(listaDeLocalidades, tl, listaDeAlumnos[indexAlumno].idLocalidad);

        if(indexLocalidad != -1)
        {
            printf("\nLEGAJO\t\tNOMBRE\t\t\tPROMEDIO\tLOCALIDAD\n\n");

            mostrarUnAlumnoConLocalidad(listaDeAlumnos[indexAlumno], listaDeLocalidades[indexLocalidad]);

            printf("\nEsta seguro de que desea eliminar a este alumno? (S/N): ");
            respuesta = toupper(getche());

            while(respuesta != 'S' && respuesta != 'N')
            {
                printf("\nError. Solo S/N: ");
                respuesta = toupper(getche());
            }

            if(respuesta == 'S')
            {
                listaDeAlumnos[indexAlumno].estado = LIBRE;
                quePaso = 1;
            }

            else if(respuesta == 'N')
            {
                quePaso = 0;
            }
        }
    }

    return quePaso;
}

int modificarAlumno(eAlumno listaDeAlumnos[], int ta, int legajo, eLocalidad listaDeLocalidades[], int tl)
{
    int indexAlumno;
    int indexLocalidad;
    int quePaso = -1;
    char respuesta;

    eAlumno aux;

    indexAlumno = buscarAlumnoPorLegajo(listaDeAlumnos, ta, legajo);

    if(indexAlumno != -1)
    {
        indexLocalidad = buscarLocalidadPorId(listaDeLocalidades, tl, listaDeAlumnos[indexAlumno].idLocalidad);

        if(indexLocalidad != -1)
        {
            aux = listaDeAlumnos[indexAlumno];

            printf("\nLEGAJO\t\tNOMBRE\t\t\tPROMEDIO\tLOCALIDAD\n\n");

            mostrarUnAlumnoConLocalidad(aux, listaDeLocalidades[indexLocalidad]);

            printf("\nIngrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux.nombre);

            printf("\nEsta seguro de que desea modificar a este alumno? (S/N): ");
            respuesta = toupper(getche());

            while(respuesta != 'S' && respuesta != 'N')
            {
                printf("\nError. Solo S/N: ");
                respuesta = toupper(getche());
            }

            if(respuesta == 'S')
            {
                listaDeAlumnos[indexAlumno] = aux;
                quePaso = 1;
            }

            else if(respuesta == 'N')
            {
                quePaso = 0;
            }
        }
    }

    return quePaso;
}

void sortStudentsByNameAndAverage(eAlumno listaDeAlumnos[], int ta)
{
    int i;
    int j;
    eAlumno aux;

    for(i = 0; i < ta - 1; i++)
    {
        for(j = i + 1; j < ta; j++)
        {
            if(strcmp(listaDeAlumnos[i].nombre, listaDeAlumnos[j].nombre) > 0)
            {
                aux = listaDeAlumnos[i];
                listaDeAlumnos[i] = listaDeAlumnos[j];
                listaDeAlumnos[j] = aux;
            }

            else if(strcmp(listaDeAlumnos[i].nombre, listaDeAlumnos[j].nombre) == 0)
            {
                if(listaDeAlumnos[i].promedio > listaDeAlumnos[j].promedio)
                {
                    aux = listaDeAlumnos[i];
                    listaDeAlumnos[i] = listaDeAlumnos[j];
                    listaDeAlumnos[j] = aux;
                }
            }
        }
    }
}
