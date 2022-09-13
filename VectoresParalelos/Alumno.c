#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Alumno.h"

int mostrarMenuPrincipal(int* op)
{
    int retorno = -2;

    if(op != NULL)
    {
        retorno = -1;

        printf("\tVECTORES PARALELOS\n\n");

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

int inicializarAlumnos(int isEmpty[], int tam)
{
    int retorno = -1;
    int i;

    if(isEmpty != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            isEmpty[i] = TRUE;
        }

        retorno = 0;
    }

    return retorno;
}

int buscarLibre(int isEmpty[], int tam)
{
    int indice = -2;
    int i;

    if(isEmpty != NULL && tam > 0)
    {
        indice = -1;

        for(i = 0; i < tam; i++)
        {
            if(isEmpty[i])
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int arrayIsEmpty(int isEmpty[], int tam)
{
    int retorno = -1;
    int i;

    if(isEmpty != NULL && tam > 0)
    {
        retorno = 1;

        for(i = 0; i < tam; i++)
        {
            if(!isEmpty[i])
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int hardCodearAlumnos(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE;

    int auxLegajos[] = {11000, 10045, 18456, 18700, 14380};
    char auxNombres[][NOMBRE_LEN] = {"Juana", "Norma", "Mario", "Sofia", "Andres"};
    char auxSexos[] = {'F', 'F', 'M', 'F', 'M'};
    int auxNotas1[] = {2, 9, 10, 10, 6};
    int auxNotas2[] = {4, 5, 8, 10, 9};

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
    {
        cant = sizeof(auxSexos);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                indice = buscarLibre(isEmpty, tam);

                if(indice > -1)
                {
                    legajos[indice] = auxLegajos[i];
                    strncpy(nombres[indice], auxNombres[i], NOMBRE_LEN);
                    sexos[indice] = auxSexos[i];
                    notas1[indice] = auxNotas1[i];
                    notas2[indice] = auxNotas2[i];
                    calcularPromedio(notas1[indice], notas2[indice], &promedios[indice]);

                    isEmpty[indice] = FALSE;

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

int buscarAlumnoPorLegajo(int legajos[], int isEmpty[], int tam, int legajo)
{
    int retorno = -2;
    int i;

    if(legajos != NULL && isEmpty != NULL && tam > 0 && legajo > 0)
    {
        retorno = -1;

        for(i = 0; i < tam; i++)
        {
            if(!isEmpty[i] && legajos[i] == legajo)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int calcularPromedio(int nota1, int nota2, float* promedio)
{
    int retorno = -1;

    if(nota1 >= 1 && nota1 <= 10 && nota2 >= 1 && nota2 <= 10 && promedio != NULL)
    {
        *promedio = (float) (nota1 + nota2) / 2;

        retorno = 0;
    }

    return retorno;
}

int cargarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -5;
    int indiceLibre;
    int indiceLegajo;

    int auxLegajo;
    char auxNombre[NOMBRE_LEN];
    char auxSexo;
    int auxNota1;
    int auxNota2;
    float auxPromedio;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
    {
        retorno = -4;

        indiceLibre = buscarLibre(isEmpty, tam);

        if(indiceLibre != -1)
        {
            retorno = -3;

            if(indiceLibre != 2)
            {
                retorno = -2;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tALTA DE ALUMNO\n");

                if(!utn_getNumero(&auxLegajo, "\nIngrese legajo entre 10000 y 20000: ", "Error. Solo numeros enteros del 10000 al 20000: ", 10000, 20000, 2))
                {
                    retorno = -1;

                    indiceLegajo = buscarAlumnoPorLegajo(legajos, isEmpty, tam, auxLegajo);

                    if(indiceLegajo == -1 &&
                       !utn_getAlfabetico(auxNombre, "\nIngrese nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
                       !utn_formatearCadena(auxNombre, NOMBRE_LEN) &&
                       !utn_getSexo(&auxSexo, "\nIngrese sexo (F/M): ", "Error. Solo F/M: ", 2) &&
                       !utn_getNumero(&auxNota1, "\nIngrese nota 1 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2) &&
                       !utn_getNumero(&auxNota2, "\nIngrese nota 2 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2) &&
                       !calcularPromedio(auxNota1, auxNota2, &auxPromedio))
                    {
                        legajos[indiceLibre] = auxLegajo;
                        strncpy(nombres[indiceLibre], auxNombre, NOMBRE_LEN);
                        sexos[indiceLibre] = auxSexo;
                        notas1[indiceLibre] = auxNota1;
                        notas2[indiceLibre] = auxNota2;
                        promedios[indiceLibre] = auxPromedio;

                        isEmpty[indiceLibre] = FALSE;
                        retorno = 0;
                    }
                }
            }
        }
    }

    return retorno;
}

int eliminarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -3;
    int auxLegajo;
    int indice;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
    {
        retorno = -2;

        if(!mostrarListaAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, isEmpty, tam) &&
           !utn_getNumero(&auxLegajo, "\nIngrese el legajo del alumno a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 10000, 20000, 2))
        {
            indice = buscarAlumnoPorLegajo(legajos, isEmpty, tam, auxLegajo);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tBAJA DE ALUMNO\n\n");

                printf("*----------*--------------------*----*------*------*------------------*\n");
                printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS");
                printf("*----------*--------------------*----*------*------*------------------*\n");
                mostrarAlumno(&legajos[indice], nombres[indice], &sexos[indice], &notas1[indice], &notas2[indice], &promedios[indice]);
                printf("*----------*--------------------*----*------*------*------------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este alumno (S/N)?: ", "Error. Solo S/N: ") == 1)
                {
                    isEmpty[indice] = TRUE;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int modificarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -3;
    int auxLegajo;
    int indice;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
    {
        retorno = -2;

        if(!mostrarListaAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, isEmpty, tam) &&
           !utn_getNumero(&auxLegajo, "\nIngrese el legajo del alumno a modificar: ", "Error. Solo numeros enteros dentro del rango: ", 10000, 20000, 2))
        {
            indice = buscarAlumnoPorLegajo(legajos, isEmpty, tam, auxLegajo);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tMODIFICACION DE ALUMNO\n\n");

                printf("*----------*--------------------*----*------*------*------------------*\n");
                printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS");
                printf("*----------*--------------------*----*------*------*------------------*\n");
                mostrarAlumno(&legajos[indice], nombres[indice], &sexos[indice], &notas1[indice], &notas2[indice], &promedios[indice]);
                printf("*----------*--------------------*----*------*------*------------------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este alumno (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                   !mostrarMenuModificar(nombres, sexos, notas1, notas2, promedios, tam, indice))
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int mostrarMenuModificar(char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int tam, int index)
{
    int retorno = -1;

    char auxNombre[NOMBRE_LEN];
    char auxSexo;
    int auxNota1;
    int auxNota2;

    char opcion;

    int flagMod = FALSE;
    int flagNota = FALSE;
    int flagExit = FALSE;

    if(nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && tam > 0 && index >= 0 && index < tam)
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
            printf("E. Salir\n");

            if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Elija una opcion correcta: ", 'A', 'E', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(!utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2))
                        {
                            strncpy(nombres[index], auxNombre, NOMBRE_LEN);

                            flagMod = TRUE;
                        }

                        break;

                    case 'B':

                        if(!utn_getSexo(&auxSexo, "\nIngrese nuevo sexo: ", "Error. Solo F o M: ", 2))
                        {
                            sexos[index] = auxSexo;

                            flagMod = TRUE;
                        }

                        break;

                    case 'C':
                    case 'D':

                        if(opcion == 'C')
                        {
                            if(!utn_getNumero(&auxNota1, "\nIngrese nueva nota 1 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
                            {
                                notas1[index] = auxNota1;

                                flagNota = TRUE;
                            }
                        }

                        else
                        {
                            if(!utn_getNumero(&auxNota2, "\nIngrese nueva nota 2 entre 1 y 10: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
                            {
                                notas2[index] = auxNota2;

                                flagNota = TRUE;
                            }
                        }

                        if(flagNota && !calcularPromedio(notas1[index], notas2[index], &promedios[index]))
                        {
                            flagMod = TRUE;
                        }

                        break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(opcion != 'E' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int mostrarAlumno(int* legajo, char nombre[], char* sexo, int* nota1, int* nota2, float* promedio)
{
    int retorno = -1;

    if(legajo != NULL && nombre != NULL && sexo != NULL && nota1 != NULL && nota2 != NULL && promedio != NULL)
    {
        printf("|%-10d|%-20s|%-4c|%-6d|%-6d|%-18g|\n", *legajo, nombre, *sexo, *nota1, *nota2, *promedio);

        retorno = 0;
    }

    return retorno;
}

int mostrarListaAlumnos(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -1;
    int i;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE ALUMNOS\n\n");

        printf("*----------*--------------------*----*------*------*------------------*\n");
        printf("|%-10s|%-20s|%-4s|%-6s|%-6s|%-18s|\n", "LEGAJO", "NOMBRE", "SEXO", "NOTA 1", "NOTA 2", "PROMEDIO DE NOTAS");
        printf("*----------*--------------------*----*------*------*------------------*\n");

        for(i = 0; i < tam; i++)
        {
            if(!isEmpty[i] && mostrarAlumno(&legajos[i], nombres[i], &sexos[i], &notas1[i], &notas2[i], &promedios[i]))
            {
                break;
            }
        }

        printf("*----------*--------------------*----*------*------*------------------*\n");

        if(i == tam)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int compararInt(int a, int b)
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

int compararFloat(float a, float b)
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

int compararChar(char a, char b)
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

int compararString(char a[], char b[], int length)
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

int swapInt(int* a, int* b)
{
    int retorno = -1;
    int temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int swapFloat(float* a, float* b)
{
    int retorno = -1;
    float temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int swapChar(char* a, char* b)
{
    int retorno = -1;
    char temp;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        retorno = 0;
    }

    return retorno;
}

int swapString(char a[], char b[], int length)
{
    int retorno = -1;
    char temp[50];

    if(a != NULL && b != NULL && length > 0)
    {
        strncpy(temp, a, length);
        strncpy(a, b, length);
        strncpy(b, temp, length);

        retorno = 0;
    }

    return retorno;
}

int compararCriterio(int legajo_A, char nombre_A[], char sexo_A, int nota1_A, int nota2_A, float promedio_A,
                     int legajo_B, char nombre_B[], char sexo_B, int nota1_B, int nota2_B, float promedio_B, int criterio)
{
    int retorno = -3;

    if(legajo_A > 0 && nombre_A != NULL && sexo_A != '\0' && nota1_A > 0 && nota2_A > 0 && promedio_A > 0 &&
       legajo_B > 0 && nombre_B != NULL && sexo_B != '\0' && nota1_B > 0 && nota2_B > 0 && promedio_B > 0 && criterio >= 0)
    {
        switch(criterio)
        {
            case LEGAJO:

                retorno = compararInt(legajo_A, legajo_B);

                break;

            case NOMBRE:

                retorno = compararString(nombre_A, nombre_B, NOMBRE_LEN);

                break;

            case SEXO:

                retorno = compararChar(sexo_A, sexo_B);

                break;

            case NOTA_1:

                retorno = compararInt(nota1_A, nota1_B);

                break;

            case NOTA_2:

                retorno = compararInt(nota2_A, nota2_B);

                break;

            case PROMEDIO:

                retorno = compararFloat(promedio_A, promedio_B);

                break;
        }
    }

    return retorno;
}

int ordenarAlumnosSimpleCriterio(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[],
                                 float promedios[], int isEmpty[], int tam, int criterio, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int flagSwap;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL &&
       isEmpty != NULL && tam > 0 && criterio >= 0 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!isEmpty[i] && !isEmpty[i + 1] &&
                   compararCriterio(legajos[i], nombres[i], sexos[i], notas1[i], notas2[i], promedios[i],
                                    legajos[i + 1], nombres[i + 1], sexos[i + 1], notas1[i + 1], notas2[i + 1], promedios[i + 1], criterio) == order - !order &&
                   !swapInt(&legajos[i], &legajos[i + 1]) && !swapString(nombres[i], nombres[i + 1], NOMBRE_LEN) && !swapChar(&sexos[i], &sexos[i + 1]) &&
                   !swapInt(&notas1[i], &notas1[i + 1]) && !swapInt(&notas2[i], &notas2[i + 1]) && !swapFloat(&promedios[i], &promedios[i + 1]))
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

int ordenarAlumnosDobleCriterio(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[],
                                float promedios[], int isEmpty[], int tam, int criterio1, int criterio2, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int auxCmp;
    int flagSwap;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL &&
       isEmpty != NULL && tam > 0 && criterio1 >= 0 && criterio2 >= 0 && criterio1 != criterio2 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!isEmpty[i] && !isEmpty[i + 1])
                {
                    auxCmp = compararCriterio(legajos[i], nombres[i], sexos[i], notas1[i], notas2[i], promedios[i],
                                              legajos[i + 1], nombres[i + 1], sexos[i + 1], notas1[i + 1], notas2[i + 1], promedios[i + 1], criterio1);

                    if(auxCmp + !auxCmp * compararCriterio(legajos[i], nombres[i], sexos[i], notas1[i], notas2[i], promedios[i],
                       legajos[i + 1], nombres[i + 1], sexos[i + 1], notas1[i + 1], notas2[i + 1], promedios[i + 1], criterio2) == order - !order &&
                       !swapInt(&legajos[i], &legajos[i + 1]) && !swapString(nombres[i], nombres[i + 1], NOMBRE_LEN) && !swapChar(&sexos[i], &sexos[i + 1]) &&
                       !swapInt(&notas1[i], &notas1[i + 1]) && !swapInt(&notas2[i], &notas2[i + 1]) && !swapFloat(&promedios[i], &promedios[i + 1]))
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

int elegirCriterioOrdenamiento(int* criterio)
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

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'F', 2))
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
            }

            retorno = 0;
        }
    }

    return retorno;
}

int elegirSentidoOrdenamiento(int* order)
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

int mostrarMenuOrdenamiento(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam)
{
    int retorno = -1;
    int auxCriterio1;
    int auxCriterio2;
    int auxOrder;
	char opcion;

    if(legajos != NULL && nombres != NULL && sexos != NULL && notas1 != NULL && notas2 != NULL && promedios != NULL && isEmpty != NULL && tam > 0)
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

                    if(!arrayIsEmpty(isEmpty, tam))
                    {
                        if(!elegirCriterioOrdenamiento(&auxCriterio1) && !elegirSentidoOrdenamiento(&auxOrder) &&
                           !ordenarAlumnosSimpleCriterio(legajos, nombres, sexos, notas1, notas2, promedios, isEmpty, tam, auxCriterio1, auxOrder))
                        {
                            printf("\nOrdenamiento realizado correctamente\n");
                        }

                        else
                        {
                            printf("\nNo se pudo realizar el ordenamiento\n");
                        }
                    }

                    else
                    {
                        printf("\nNo hay alumnos para ordenar por simple criterio\n");
                    }

                    break;

                case 'B':

                    if(!arrayIsEmpty(isEmpty, tam))
                    {
                        if(!elegirCriterioOrdenamiento(&auxCriterio1) && !elegirCriterioOrdenamiento(&auxCriterio2) && !elegirSentidoOrdenamiento(&auxOrder) &&
                           !ordenarAlumnosDobleCriterio(legajos, nombres, sexos, notas1, notas2, promedios, isEmpty, tam, auxCriterio1, auxCriterio2, auxOrder))
                        {
                            printf("\nOrdenamiento realizado correctamente\n");
                        }

                        else
                        {
                            printf("\nNo se pudo realizar el ordenamiento\n");
                        }
                    }

                    else
                    {
                        printf("\nNo hay alumnos para ordenar por doble criterio\n");
                    }

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}
