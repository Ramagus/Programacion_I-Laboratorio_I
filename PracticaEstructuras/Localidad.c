#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Localidad.h"

int eLocalidad_buscarPorId(eLocalidad lista[], int tam, int id, int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0 && id > 0 && indice != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int eLocalidad_hardCodear(eLocalidad lista[], int tam, int* id)
{
    int retorno = -1;
    int i;
    int cant;

    eLocalidad auxLocalidades[] =
    {
        {0, "Avellaneda"},
        {0, "Bernal"},
        {0, "Quilmes"},
        {0, "Lanus"},
        {0, "Sarandi"}
    };

    if(lista != NULL && tam > 0 && id != NULL)
    {
        cant = sizeof(auxLocalidades) / sizeof(eLocalidad);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                lista[i] = auxLocalidades[i];
                lista[i].id = *id;

                (*id)++;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eLocalidad_mostrarUna(eLocalidad* unaLocalidad)
{
    int retorno = -1;

    if(unaLocalidad != NULL)
    {
        printf("|%-10d|%-20s|\n", unaLocalidad->id, unaLocalidad->descripcion);

        retorno = 0;
    }

    return retorno;
}

int eLocalidad_mostrarLista(eLocalidad lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE LOCALIDADES\n\n");

        printf("*----------*--------------------*\n");
        printf("|%-10s|%-20s|\n", "ID", "DESCRIPCION");
        printf("*----------*--------------------*\n");

        for(i = 0; i < tam; i++)
        {
            if(eLocalidad_mostrarUna(&lista[i]))
            {
                break;
            }
        }

        printf("*----------*--------------------*\n");

        if(i == tam)
        {
            retorno = 0;
        }
    }

    return retorno;
}
