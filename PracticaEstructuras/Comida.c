#include <stdio.h>
#include <stdlib.h>
#include "Comida.h"

int eComida_buscarPorId(eComida lista[], int tam, int id, int* indice)
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

int eComida_hardCodear(eComida lista[], int tam, int* id)
{
    int retorno = -1;
    int i;
    int cant;

    eComida auxComidas[] =
    {
        {0, "Milanesa", 345.60},
        {0, "Pizza", 450.20},
        {0, "Ensalada", 510.30},
        {0, "Fideos", 345.70},
        {0, "Hamburguesa", 410.50}
    };

    if(lista != NULL && tam > 0 && id != NULL)
    {
        cant = sizeof(auxComidas) / sizeof(eComida);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                lista[i] = auxComidas[i];
                lista[i].id = *id;

                (*id)++;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eComida_mostrarUna(eComida* unaComida)
{
    int retorno = -1;

    if(unaComida != NULL)
    {
        printf("|%-10d|%-20s|%-10.2f|\n", unaComida->id, unaComida->descripcion, unaComida->precio);

        retorno = 0;
    }

    return retorno;
}

int eComida_mostrarLista(eComida lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE COMIDAS\n\n");

        printf("*----------*--------------------*----------*\n");
        printf("|%-10s|%-20s|%-10s|\n", "ID", "DESCRIPCION", "PRECIO");
        printf("*----------*--------------------*----------*\n");

        for(i = 0; i < tam; i++)
        {
            if(eComida_mostrarUna(&lista[i]))
            {
                break;
            }
        }

        printf("*----------*--------------------*----------*\n");

        if(i == tam)
        {
            retorno = 0;
        }
    }

    return retorno;
}
