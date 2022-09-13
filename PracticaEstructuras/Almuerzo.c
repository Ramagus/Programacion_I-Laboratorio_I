#include <stdio.h>
#include <stdlib.h>
#include "Almuerzo.h"

int eAlmuerzo_inicializar(eAlmuerzo lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            lista[i].isEmpty = TRUE_ALM;
        }

        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_buscarLibre(eAlmuerzo lista[], int tam, int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0 && indice != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int eAlmuerzo_arrayIsEmpty(eAlmuerzo lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        retorno = 1;

        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int eAlmuerzo_buscarPorId(eAlmuerzo lista[], int tam, int id, int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0 && id > 0 && indice != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int eAlmuerzo_hardCodear(eAlmuerzo lista[], int tam, int* id)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE_ALM;

    eAlmuerzo auxAlmuerzos[] =
    {
        {0, 20004, 5000, {18, 10, 2021}, FALSE_ALM},
        {0, 20005, 5002, {19, 10, 2021}, FALSE_ALM},
        {0, 20000, 5004, {17, 10, 2021}, FALSE_ALM},
        {0, 20003, 5001, {20, 10, 2021}, FALSE_ALM},
        {0, 20001, 5003, {16, 10, 2021}, FALSE_ALM},
        {0, 20006, 5000, {14, 10, 2021}, FALSE_ALM},
        {0, 20007, 5002, {15, 10, 2021}, FALSE_ALM},
        {0, 20002, 5004, {12, 10, 2021}, FALSE_ALM},
        {0, 20009, 5001, {13, 10, 2021}, FALSE_ALM},
        {0, 20008, 5003, {11, 10, 2021}, FALSE_ALM}
    };

    if(lista != NULL && tam > 0 && id != NULL)
    {
        cant = sizeof(auxAlmuerzos) / sizeof(eAlmuerzo);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                if(!eAlmuerzo_buscarLibre(lista, tam, &indice))
                {
                    lista[indice] = auxAlmuerzos[i];
                    lista[indice].id = *id;

                    (*id)++;

                    flag = TRUE_ALM;
                }

                else
                {
                    break;
                }
            }

            if(flag)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int eAlmuerzo_eliminar(eAlmuerzo lista[], int tam, int indice)
{
    int retorno = -1;

    if(lista != NULL && tam > 0 && indice >= 0 && indice < tam && !lista[indice].isEmpty)
    {
        lista[indice].isEmpty = TRUE_ALM;

        retorno = 0;
    }

    return retorno;
}
