#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Persona.h"

int ePersona_inicializar(ePersona lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            lista[i].isEmpty = TRUE_PER;
        }

        retorno = 0;
    }

    return retorno;
}

int ePersona_hardCodear(ePersona lista[], int tam, int* id)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE_PER;

    ePersona auxPersonas[] =
    {
        {0, "Juan", 'M', 23, 1.65, 1001, FALSE_PER},
        {0, "Pedro", 'M', 21, 1.67, 1002, FALSE_PER},
        {0, "Sofia", 'F', 28, 1.9, 1000, FALSE_PER},
        {0, "Miguel", 'M', 32, 1.78, 1001, FALSE_PER},
        {0, "Valentina", 'F', 45, 1.75, 1001, FALSE_PER},
        {0, "Camila", 'F', 29, 1.7, 1003, FALSE_PER},
        {0, "Andrea", 'F', 39, 1.65, 1004, FALSE_PER},
        {0, "Luis", 'M', 23, 1.73, 1002, FALSE_PER},
        {0, "Diego", 'M', 28, 1.69, 1004, FALSE_PER},
        {0, "Analia", 'F', 27, 1.68, 1001, FALSE_PER}
    };

    if(lista != NULL && tam > 0 && id != NULL)
    {
        cant = sizeof(auxPersonas) / sizeof(ePersona);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                if(!ePersona_buscarLibre(lista, tam, &indice))
                {
                    lista[indice] = auxPersonas[i];
                    lista[indice].id = *id;

                    (*id)++;

                    flag = TRUE_PER;
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

int ePersona_arrayIsEmpty(ePersona lista[], int tam)
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

int ePersona_buscarLibre(ePersona lista[], int tam, int* indice)
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

int ePersona_buscarPorId(ePersona lista[], int tam, int id, int* indice)
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

int ePersona_elegirCriterioOrdenamiento(int* criterio)
{
    int retorno = -1;
	char opcion;

    if(criterio != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. ID\n");
        printf("B. Nombre\n");
        printf("C. Sexo\n");
        printf("D. Edad\n");
        printf("E. Altura\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID;

                    break;

                case 'B':

                    *criterio = NOMBRE;

                    break;

                case 'C':

                    *criterio = SEXO;

                    break;

                case 'D':

                    *criterio = EDAD;

                    break;

                case 'E':

                    *criterio = ALTURA;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int ePersona_elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
    char option;

    if(order != NULL)
    {
		printf("\n");
		system("pause");
		system("cls");

		printf("\tSENTIDO DE ORDENAMIENTO\n\n");
		printf("A. Orden Ascendente\n");
		printf("B. Orden Descendente\n");

		if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
		{
			switch(option)
			{
				case 'A':

					*order = UP;

					break;

				case 'B':

					*order = DOWN;

					break;
			}

			retorno = 0;
		}
    }

    return retorno;
}

int ePersona_compararInt(int a, int b)
{
    int retorno = -2;

    if(a > 0 && b > 0)
    {
        if(a < b)
        {
            retorno = -1;
        }

        else if(a == b)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ePersona_compararFloat(float a, float b)
{
    int retorno = -2;

    if(a > 0 && b > 0)
    {
        if(a < b)
        {
            retorno = -1;
        }

        else if(a == b)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ePersona_compararChar(char a, char b)
{
    int retorno = -2;

    if(a != '\0' && b != '\0')
    {
        if(a < b)
        {
            retorno = -1;
        }

        else if(a == b)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ePersona_compararString(char a[], char b[], int length)
{
    int retorno = -2;
    int auxCmp;

    if(a != NULL && b != NULL && length > 0)
    {
        auxCmp = strncmp(a, b, length);

        if(auxCmp < 0)
        {
            retorno = -1;
        }

        else if(auxCmp == 0)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ePersona_swap(ePersona* a, ePersona* b)
{
    int retorno = -1;
    ePersona temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int ePersona_compararCriterio(ePersona* a, ePersona* b, int criterio)
{
    int retorno = -3;

    if(a != NULL && b != NULL && criterio >= 0)
    {
        switch(criterio)
        {
            case ID:

                retorno = ePersona_compararInt(a->id, b->id);

                break;

            case NOMBRE:

                retorno = ePersona_compararString(a->nombre, b->nombre, NOMBRE_LEN);

                break;

            case SEXO:

                retorno = ePersona_compararChar(a->sexo, b->sexo);

                break;

            case EDAD:

                retorno = ePersona_compararInt(a->edad, b->edad);

                break;

            case ALTURA:

                retorno = ePersona_compararFloat(a->altura, b->altura);

                break;
        }
    }

    return retorno;
}

int ePersona_ordenar(ePersona lista[], int tam, int criterio1, int criterio2, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int auxCmp;
    int flagSwap;

    if(lista != NULL && tam > 0 && criterio1 >= 0 && criterio2 >= 0 &&
       criterio1 != criterio2 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE_PER;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!lista[i].isEmpty && !lista[i + 1].isEmpty)
                {
                    auxCmp = ePersona_compararCriterio(&lista[i], &lista[i + 1], criterio1);

                    if(auxCmp + !auxCmp * ePersona_compararCriterio(&lista[i], &lista[i + 1], criterio2) == order - !order &&
                       !ePersona_swap(&lista[i], &lista[i + 1]))
                    {
                        flagSwap = TRUE_PER;
                    }
                }
            }

            auxTam--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int ePersona_eliminar(ePersona lista[], int tam, int indice)
{
    int retorno = -1;

    if(lista != NULL && tam > 0 && indice >= 0 && indice < tam && !lista[indice].isEmpty)
    {
        lista[indice].isEmpty = TRUE_PER;

        retorno = 0;
    }

    return retorno;
}
