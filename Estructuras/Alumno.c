#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Alumno.h"

int eAlumno_mostrarMenuPrincipal(int* op)
{
    int retorno = -2;

    if(op != NULL)
    {
        retorno = -1;

        printf("\tESTRUCTURAS\n\n");

        printf("1. Alta Alumno\n");
        printf("2. Baja Alumno\n");
        printf("3. Modificar Alumno\n");
        printf("4. Ordenar Alumnos\n");
        printf("5. Listar Alumnos\n");
        printf("6. Alta Forzada de Alumnos\n");
        printf("7. Salir\n");

        if(!utn_getNumero(op, "\nElija una opcion: ", "Error. Elija una opcion correcta: ", 1, 7, 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}

int eAlumno_inicializar(eAlumno lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            lista[i].isEmpty = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

int eAlumno_buscarLibre(eAlumno lista[], int tam)
{
    int indice = -2;
    int i;

    if(lista != NULL && tam > 0)
    {
        indice = -1;

        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int eAlumno_arrayIsEmpty(eAlumno lista[], int tam)
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

int eAlumno_hardCodear(eAlumno lista[], int tam)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE;

    eAlumno auxAlumnos[] =
    {
        {2233, "Juana", 'F', 10, 8, 0, {23, 4, 2012}, FALSE},
        {1122, "Raul", 'M', 4, 8, 0, {21, 12, 2018}, FALSE},
        {8654, "Mario", 'M', 9, 7, 0, {4, 12, 2017}, FALSE},
        {9943, "Gabriela", 'F', 2, 2, 0, {5, 12, 2018}, FALSE},
        {1023, "Joaquin", 'M', 7, 5, 0, {19, 9, 2021}, FALSE},
        {6678, "Irene", 'F', 10, 7, 0, {4, 11, 2020}, FALSE},
        {2145, "Viviana", 'F', 4, 9, 0, {7, 12, 2018}, FALSE},
        {4532, "Hernan", 'M', 5, 6, 0, {18, 2, 2019}, FALSE}
    };

    if(lista != NULL && tam > 0)
    {
        cant = sizeof(auxAlumnos) / sizeof(eAlumno);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                indice = eAlumno_buscarLibre(lista, tam);

                if(indice > -1)
                {
                    lista[indice] = auxAlumnos[i];

                    eAlumno_calcularPromedio(lista[indice].nota1, lista[indice].nota2, &lista[indice].promedio);

                    flag = TRUE;
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

int eAlumno_buscarPorLegajo(eAlumno lista[], int tam, int legajo)
{
    int retorno = -2;
    int i;

    if(lista != NULL && tam > 0 && legajo > 0)
    {
        retorno = -1;

        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].legajo == legajo)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int eAlumno_calcularPromedio(int nota1, int nota2, float* promedio)
{
    int retorno = -1;

    if(nota1 >= 1 && nota1 <= 10 && nota2 >= 1 && nota2 <= 10 && promedio != NULL)
    {
        *promedio = (float) (nota1 + nota2) / 2;

        retorno = 0;
    }

    return retorno;
}

int eAlumno_cargar(eAlumno lista[], int tam)
{
    int retorno = -5;
    int indiceLibre;
    int indiceLegajo;

    eAlumno auxAlumno;

    if(lista != NULL && tam > 0)
    {
        retorno = -4;

        indiceLibre = eAlumno_buscarLibre(lista, tam);

        if(indiceLibre != -1)
        {
            retorno = -3;

            if(indiceLibre != -2)
            {
                retorno = -2;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tALTA DE ALUMNO\n");

                if(!utn_getNumero(&auxAlumno.legajo, "\nIngrese legajo entre 1000 y 10000: ", "Error. Solo numeros enteros del 1000 al 10000: ", 1000, 10000, 2))
                {
                    retorno = -1;

                    indiceLegajo = eAlumno_buscarPorLegajo(lista, tam, auxAlumno.legajo);

                    if(indiceLegajo == -1 &&
                       !utn_getAlfabetico(auxAlumno.nombre, "\nIngrese nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
                       !utn_formatearCadena(auxAlumno.nombre, NOMBRE_LEN) &&
                       !utn_getSexo(&auxAlumno.sexo, "\nIngrese sexo (F/M): ", "Error. Solo F/M: ", 2) &&
                       !utn_getNumero(&auxAlumno.nota1, "\nIngrese nota 1 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2) &&
                       !utn_getNumero(&auxAlumno.nota2, "\nIngrese nota 2 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2) &&
                       !eAlumno_calcularPromedio(auxAlumno.nota1, auxAlumno.nota2, &auxAlumno.promedio) &&
                       !eFecha_cargar(&auxAlumno.fechaIngreso))
                    {
                        auxAlumno.isEmpty = FALSE;

                        lista[indiceLibre] = auxAlumno;

                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

int eAlumno_eliminar(eAlumno lista[], int tam)
{
    int retorno = -3;
    int auxLegajo;
    int indice;

    if(lista != NULL && tam > 0)
    {
        retorno = -2;

        if(!eAlumno_mostrarLista(lista, tam) &&
           !utn_getNumero(&auxLegajo, "\nIngrese el legajo del alumno a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 10000, 2))
        {
            indice = eAlumno_buscarPorLegajo(lista, tam, auxLegajo);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tBAJA DE ALUMNO\n\n");

                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");
                printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|%-16s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS", "FECHA DE INGRESO");
                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");
                eAlumno_mostrar(&lista[indice]);
                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este alumno (S/N)?: ", "Error. Solo S/N: ") == 1)
                {
                    lista[indice].isEmpty = TRUE;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int eAlumno_modificar(eAlumno lista[], int tam)
{
    int retorno = -3;
    int auxLegajo;
    int indice;

    if(lista != NULL && tam > 0)
    {
        retorno = -2;

        if(!eAlumno_mostrarLista(lista, tam) &&
           !utn_getNumero(&auxLegajo, "\nIngrese el legajo del alumno a modificar: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 10000, 2))
        {
            indice = eAlumno_buscarPorLegajo(lista, tam, auxLegajo);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tMODIFICACION DE ALUMNO\n\n");

                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");
                printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|%-16s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS", "FECHA DE INGRESO");
                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");
                eAlumno_mostrar(&lista[indice]);
                printf("*----------*--------------------*----*------*------*------------------*----------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este alumno (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                   !eAlumno_mostrarMenuModificar(lista, tam, indice))
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int eAlumno_mostrarMenuModificar(eAlumno lista[], int tam, int index)
{
    int retorno = -1;

    char auxNombre[NOMBRE_LEN];
    char auxSexo;
    int auxNota1;
    int auxNota2;
    eFecha auxFechaIngreso;

    char opcion;

    int flagMod = FALSE;
    int flagNota = FALSE;
    int flagExit = FALSE;

    if(lista != NULL && tam > 0 && index >= 0 && index < tam)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMODIFICAR ALUMNO\n\n");
            printf("A. Nombre\n");
            printf("B. Sexo\n");
            printf("C. Nota 1\n");
            printf("D. Nota 2\n");
            printf("E. Fecha\n");
            printf("F. Salir\n");

            if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Elija una opcion correcta: ", 'A', 'F', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(!utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2))
                        {
                            strncpy(lista[index].nombre, auxNombre, NOMBRE_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'B':

                        if(!utn_getSexo(&auxSexo, "\nIngrese nuevo sexo: ", "Error. Solo F o M: ", 2))
                        {
                            lista[index].sexo = auxSexo;

                            flagMod = TRUE;
                        }

                        break;

                    case 'C':
                    case 'D':

                        if(opcion == 'C')
                        {
                            if(!utn_getNumero(&auxNota1, "\nIngrese nueva nota 1 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
                            {
                                lista[index].nota1 = auxNota1;

                                flagNota = TRUE;
                            }
                        }

                        else
                        {
                            if(!utn_getNumero(&auxNota2, "\nIngrese nueva nota 2 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
                            {
                                lista[index].nota2 = auxNota2;

                                flagNota = TRUE;
                            }
                        }

                        if(flagNota && !eAlumno_calcularPromedio(lista[index].nota1, lista[index].nota2, &lista[index].promedio))
                        {
                            flagMod = TRUE;
                        }

                        break;

                    case 'E':

                        if(!eFecha_cargar(&auxFechaIngreso))
                        {
                            lista[index].fechaIngreso = auxFechaIngreso;

                            flagMod = TRUE;
                        }

                        break;

                    case 'F':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(opcion != 'F' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int eAlumno_mostrar(eAlumno* unAlumno)
{
    int retorno = -1;

    if(unAlumno != NULL)
    {
        printf("|%-10d|%-20s|%-4c|%-6d|%-6d|%-18g|", unAlumno->legajo, unAlumno->nombre, unAlumno->sexo, unAlumno->nota1, unAlumno->nota2, unAlumno->promedio);

        eFecha_mostrar(&unAlumno->fechaIngreso);
        printf("%-6c|\n", ' ');

        retorno = 0;
    }

    return retorno;
}

int eAlumno_mostrarLista(eAlumno lista[], int tam)
{
    int retorno = -1;
    int i;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE ALUMNOS\n\n");

        printf("*----------*--------------------*----*------*------*------------------*----------------*\n");
        printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|%-16s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS", "FECHA DE INGRESO");
        printf("*----------*--------------------*----*------*------*------------------*----------------*\n");

        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && eAlumno_mostrar(&lista[i]))
            {
                break;
            }
        }

        printf("*----------*--------------------*----*------*------*------------------*----------------*\n");

        if(i == tam)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int eAlumno_compararInt(int a, int b)
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

int eAlumno_compararFloat(float a, float b)
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

int eAlumno_compararChar(char a, char b)
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

int eAlumno_compararString(char a[], char b[], int length)
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

int eAlumno_swap(eAlumno* a, eAlumno* b)
{
    int retorno = -1;
    eAlumno temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int eAlumno_compararCriterio(eAlumno* alumno_A, eAlumno* alumno_B, int criterio)
{
    int retorno = -3;

    if(alumno_A != NULL && alumno_B != NULL && criterio >= 0)
    {
        switch(criterio)
        {
            case LEGAJO:

                retorno = eAlumno_compararInt(alumno_A->legajo, alumno_B->legajo);

                break;

            case NOMBRE:

                retorno = eAlumno_compararString(alumno_A->nombre, alumno_B->nombre, NOMBRE_LEN);

                break;

            case SEXO:

                retorno = eAlumno_compararChar(alumno_A->sexo, alumno_B->sexo);

                break;

            case NOTA_1:

                retorno = eAlumno_compararInt(alumno_A->nota1, alumno_B->nota1);

                break;

            case NOTA_2:

                retorno = eAlumno_compararInt(alumno_A->nota2, alumno_B->nota2);

                break;

            case PROMEDIO:

                retorno = eAlumno_compararFloat(alumno_A->promedio, alumno_B->promedio);

                break;

            case FECHA:

                retorno = eFecha_comparar(&alumno_A->fechaIngreso, &alumno_B->fechaIngreso);

                break;
        }
    }

    return retorno;
}

int eAlumno_ordenarSimpleCriterio(eAlumno lista[], int tam, int criterio, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int flagSwap;

    if(lista != NULL && tam > 0 && criterio >= 0 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!lista[i].isEmpty && !lista[i + 1].isEmpty &&
                   eAlumno_compararCriterio(&lista[i], &lista[i + 1], criterio) == order - !order &&
                   !eAlumno_swap(&lista[i], &lista[i + 1]))
                {
                    flagSwap = TRUE;
                }
            }

            auxTam--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int eAlumno_ordenarDobleCriterio(eAlumno lista[], int tam, int criterio1, int criterio2, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int auxCmp;
    int flagSwap;

    if(lista != NULL && tam > 0 && criterio1 >= 0 && criterio2 >= 0 && criterio1 != criterio2 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!lista[i].isEmpty && !lista[i + 1].isEmpty)
                {
                    auxCmp = eAlumno_compararCriterio(&lista[i], &lista[i + 1], criterio1);

                    if(auxCmp + !auxCmp * eAlumno_compararCriterio(&lista[i], &lista[i + 1], criterio2) == order - !order &&
                       !eAlumno_swap(&lista[i], &lista[i + 1]))
                    {
                        flagSwap = TRUE;
                    }
                }
            }

            auxTam--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int eAlumno_elegirCriterioOrdenamiento(int* criterio)
{
    int retorno = -1;
	char opcion;

    if(criterio != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. Legajo\n");
        printf("B. Nombre\n");
        printf("C. Sexo\n");
        printf("D. Nota 1\n");
        printf("E. Nota 2\n");
        printf("F. Promedio\n");
        printf("G. Fecha\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'G', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = LEGAJO;

                    break;

                case 'B':

                    *criterio = NOMBRE;

                    break;

                case 'C':

                    *criterio = SEXO;

                    break;

                case 'D':

                    *criterio = NOTA_1;

                    break;

                case 'E':

                    *criterio = NOTA_2;

                    break;

                case 'F':

                    *criterio = PROMEDIO;

                    break;

                case 'G':

                    *criterio = FECHA;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eAlumno_elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
	char opcion;

    if(order != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tSENTIDO DE ORDENAMIENTO\n\n");
        printf("A. Orden Ascendente\n");
        printf("B. Orden Descendente\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(opcion)
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

int eAlumno_mostrarMenuOrdenamiento(eAlumno lista[], int tam)
{
    int retorno = -1;
    int auxCriterio1;
    int auxCriterio2;
    int auxOrder;
	char opcion;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tMENU DE ORDENAMIENTO\n\n");
        printf("A. Simple Criterio\n");
        printf("B. Doble Criterio\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(opcion)
            {
                case 'A':

                    if(!eAlumno_elegirCriterioOrdenamiento(&auxCriterio1) && !eAlumno_elegirSentidoOrdenamiento(&auxOrder) &&
                       !eAlumno_ordenarSimpleCriterio(lista, tam, auxCriterio1, auxOrder))
                    {
                        printf("\nOrdenamiento realizado correctamente\n");
                    }

                    else
                    {
                        printf("\nNo se pudo realizar el ordenamiento\n");
                    }

                    break;

                case 'B':

                    if(!eAlumno_elegirCriterioOrdenamiento(&auxCriterio1) && !eAlumno_elegirCriterioOrdenamiento(&auxCriterio2) &&
                       !eAlumno_elegirSentidoOrdenamiento(&auxOrder) && !eAlumno_ordenarDobleCriterio(lista, tam, auxCriterio1, auxCriterio2, auxOrder))
                    {
                        printf("\nOrdenamiento realizado correctamente\n");
                    }

                    else
                    {
                        printf("\nNo se pudo realizar el ordenamiento\n");
                    }

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}
