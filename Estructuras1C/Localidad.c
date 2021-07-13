#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Localidad.h"
#include "Alumno.h"

int buscarLocalidadPorId(eLocalidad listaDeLocalidades[], int tl, int id)
{
    int i;
    int index = -1;

    if(listaDeLocalidades != NULL && tl > 0)
    {
        for(i = 0; i < tl; i++)
        {
            if(listaDeLocalidades[i].idLocalidad == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

void hardCodearLocalidades(eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int idLocalidad[] = {1, 2, 3};
    char localidad[][30]= {"Avellaneda", "Wilde", "Lanus"};
    //int codigoPostal[] = {1870, 1875, 1824};

    for(i = 0; i < tl; i++)
    {
        listaDeLocalidades[i].idLocalidad = idLocalidad[i];
        strcpy(listaDeLocalidades[i].localidad, localidad[i]);
        //listaDeLocalidades[i].codigoPostal = codigoPostal[i];
    }
}

void mostrarUnaLocalidad(eLocalidad unaLocalidad)
{
    printf("%s\n", unaLocalidad.localidad);
}

void mostrarListadoLocalidades(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int j;
    int index;

    if((listaDeAlumnos != NULL && ta > 0) && (listaDeLocalidades != NULL && tl > 0))
    {
        printf("\nLOCALIDADES\n\n");

        for(i = 0; i < tl; i++)
        {
            index = buscarLocalidadPorId(listaDeLocalidades, tl, listaDeLocalidades[i].idLocalidad);

            for(j = 0; j < ta; j++)
            {
                if(index != -1 && listaDeAlumnos[j].idLocalidad == listaDeLocalidades[i].idLocalidad && listaDeAlumnos[j].estado == OCUPADO)
                {
                    mostrarUnaLocalidad(listaDeLocalidades[index]);
                }
            }
        }
    }
}

void mostrarAlumnosPorLocalidad(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int j;

    if((listaDeAlumnos != NULL && ta > 0) && (listaDeLocalidades != NULL && tl > 0))
    {
        for(i = 0; i < tl; i++)
        {
            //printf("\nLOCALIDAD: ");
            //mostrarUnaLocalidad(listaDeLocalidades[i]);

            printf("\nLOCALIDAD: %s\n", listaDeLocalidades[i].localidad);

            for(j = 0; j < ta; j++)
            {
                if(listaDeAlumnos[j].idLocalidad == listaDeLocalidades[i].idLocalidad && listaDeAlumnos[j].estado == OCUPADO)
                {
                    printf("ALUMNO: %s\n", listaDeAlumnos[j].nombre);
                }
            }
        }
    }
}

void mostrarAlumnosDeAvellaneda(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int j;

    if((listaDeAlumnos != NULL && ta > 0) && (listaDeLocalidades != NULL && tl > 0))
    {
        printf("\nALUMNOS DE AVELLANEDA\n\n");

        for(i = 0; i < ta; i++)
        {
            if(listaDeAlumnos[i].idLocalidad == 1)
            {
                for(j = 0; j < tl; j++)
                {
                    if(listaDeLocalidades[j].idLocalidad == listaDeAlumnos[i].idLocalidad && listaDeAlumnos[i].estado == OCUPADO)
                    {
                        printf("%s\n", listaDeAlumnos[i].nombre);
                    }
                }
            }
        }
    }
}

void mostrarLocalidadConMenosAlumnos(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl)
{
    eAuxLocalidad listaAuxiliar[3];

    int i;
    int j;
    int minimo;

    for(i = 0; i < tl; i++)
    {
        listaAuxiliar[i].contAlumnos = 0;
        listaAuxiliar[i].idLocalidad = listaDeLocalidades[i].idLocalidad;

        for(j = 0; j < ta; j++)
        {
            if(listaDeAlumnos[j].idLocalidad == listaAuxiliar[i].idLocalidad && listaDeAlumnos[j].estado == OCUPADO)
            {
                listaAuxiliar[i].contAlumnos++;
            }
        }

        if(i == 0 || ((minimo == 0 || listaAuxiliar[i].contAlumnos < minimo) && listaAuxiliar[i].contAlumnos > 0))
        {
            minimo = listaAuxiliar[i].contAlumnos;
        }
    }

    if(minimo > 0)
    {
        for(i = 0; i < tl; i++)
        {
            if(listaAuxiliar[i].contAlumnos == minimo)
            {
                for(j = 0; j < tl; j++)
                {
                    if(listaDeLocalidades[j].idLocalidad == listaAuxiliar[i].idLocalidad)
                    {
                        printf("\n\tLocalidad: %s\n", listaDeLocalidades[j].localidad);
                        printf("\nID de Localidad: %d - Cantidad de Alumnos: %d\n", listaAuxiliar[i].idLocalidad, minimo);
                    }
                }
            }
        }
    }
}
