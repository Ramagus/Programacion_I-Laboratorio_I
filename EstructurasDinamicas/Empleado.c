#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "Empleado.h"
#define BUFFER_LEN 20


static int isInt(char* cadena, int limite);
static int isFloat(char* cadena, int limite);
static int isAlphabetical(char* cadena, int limite);
static int isValidId(int id);
static int isValidSex(char sexo);
static int isValidSalary(float sueldo);

eEmpleado* empleado_new(void)
{
    eEmpleado* this = NULL;

    this = (eEmpleado*) malloc(sizeof(eEmpleado));

    return this;
}

eEmpleado* empleado_newParam(int id, char* nombre, char* apellido, char sexo, float sueldo)
{
    eEmpleado* this = NULL;

    if(nombre != NULL && apellido != NULL)
    {
        this = empleado_new();

        if(this != NULL && (empleado_setId(this, id) || empleado_setNombre(this, nombre) ||
           empleado_setApellido(this, apellido) || empleado_setSexo(this, sexo) || empleado_setSueldo(this, sueldo)))
        {
            empleado_delete(this);
            this = NULL;
        }
    }

    return this;
}

eEmpleado* empleado_newParamStr(char* id, char* nombre, char* apellido, char* sexo, char* sueldo)
{
    eEmpleado* this = NULL;

    if(id != NULL && nombre != NULL && apellido != NULL && sexo != NULL && sueldo != NULL)
    {
        this = empleado_new();

        if(this != NULL && (empleado_setIdTxt(this, id) || empleado_setNombre(this, nombre) ||
           empleado_setApellido(this, apellido) || empleado_setSexo(this, sexo[0]) || empleado_setSueldoTxt(this, sueldo)))
        {
            empleado_delete(this);
            this = NULL;
        }
    }

    return this;
}

int empleado_delete(eEmpleado* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }

    return retorno;
}

int empleado_setId(eEmpleado* this, int id)
{
    int retorno = -1;

    if(this != NULL && isValidId(id))
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int empleado_setIdTxt(eEmpleado* this, char* id)
{
    int retorno = -1;
    int auxId;

    if(this != NULL && isInt(id, BUFFER_LEN) == 1)
    {
        auxId = atoi(id);

        if(isValidId(auxId))
        {
            this->id = auxId;
            retorno = 0;
        }
    }

    return retorno;
}

int empleado_setNombre(eEmpleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && isAlphabetical(nombre, NOMBRE_LEN) == 1)
    {
        strncpy(this->nombre, nombre, NOMBRE_LEN);
        retorno = 0;
    }

    return retorno;
}

int empleado_setApellido(eEmpleado* this, char* apellido)
{
    int retorno = -1;

    if(this != NULL && isAlphabetical(apellido, APELLIDO_LEN) == 1)
    {
        strncpy(this->apellido, apellido, APELLIDO_LEN);
        retorno = 0;
    }

    return retorno;
}

int empleado_setSexo(eEmpleado* this, char sexo)
{
    int retorno = -1;

    if(this != NULL && isValidSex(sexo))
    {
        this->sexo = sexo;
        retorno = 0;
    }

    return retorno;
}

int empleado_setSueldo(eEmpleado* this, float sueldo)
{
    int retorno = -1;

    if(this != NULL && isValidSalary(sueldo))
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int empleado_setSueldoTxt(eEmpleado* this, char* sueldo)
{
    int retorno = -1;
    float auxSueldo;

    if(this != NULL && isFloat(sueldo, BUFFER_LEN) == 1)
    {
        auxSueldo = atof(sueldo);

        if(isValidSalary(auxSueldo))
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }

    return retorno;
}

int empleado_getId(eEmpleado* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int empleado_getIdTxt(eEmpleado* this, char* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        snprintf(id, BUFFER_LEN, "%d", this->id);
        retorno = 0;
    }

    return retorno;
}

int empleado_getNombre(eEmpleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NOMBRE_LEN);
        retorno = 0;
    }

    return retorno;
}

int empleado_getApellido(eEmpleado* this, char* apellido)
{
    int retorno = -1;

    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido, this->apellido, APELLIDO_LEN);
        retorno = 0;
    }

    return retorno;
}

int empleado_getSexo(eEmpleado* this, char* sexo)
{
    int retorno = -1;

    if(this != NULL && sexo != NULL)
    {
        *sexo = this->sexo;
        retorno = 0;
    }

    return retorno;
}

int empleado_getSueldo(eEmpleado* this, float* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}

int empleado_getSueldoTxt(eEmpleado* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        snprintf(sueldo, BUFFER_LEN, "%.2f", this->sueldo);
        retorno = 0;
    }

    return retorno;
}

int empleado_getNombreCompleto(eEmpleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        snprintf(nombre, NOMBRE_LEN + APELLIDO_LEN, "%s %s", this->nombre, this->apellido);
        retorno = 0;
    }

    return retorno;
}

int empleado_getSexoFull(eEmpleado* this, char* sexo)
{
    int retorno = -1;

    if(this != NULL && sexo != NULL)
    {
        if(this->sexo == 'F')
        {
            strncpy(sexo, "Femenino", BUFFER_LEN);
        }

        else
        {
            strncpy(sexo, "Masculino", BUFFER_LEN);
        }

        retorno = 0;
    }

    return retorno;
}

static int isInt(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isFloat(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isAlphabetical(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]) && cadena[i] != '-')
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int isValidId(int id)
{
    int retorno = 0;

    if(id >= 1 && id <= 10000)
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidSex(char sexo)
{
    int retorno = 0;

    if(sexo == 'F' || sexo == 'M')
    {
        retorno = 1;
    }

    return retorno;
}

static int isValidSalary(float sueldo)
{
    int retorno = 0;

    if(sueldo >= 10000 && sueldo <= 500000)
    {
        retorno = 1;
    }

    return retorno;
}

eEmpleado** empleado_newArray(int len)
{
    eEmpleado** pArray = NULL;

    if(len > 0)
    {
        pArray = (eEmpleado**) malloc(sizeof(eEmpleado*) * len);

        if(pArray != NULL && empleado_inicializar(pArray, 0, len))
        {
            empleado_deleteArray(pArray, len);
            pArray = NULL;
        }
    }

    return pArray;
}

int empleado_inicializar(eEmpleado** lista, int inicio, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && inicio >= 0 && len > 0 && inicio < len)
    {
        for(i = inicio; i < len; i++)
        {
            *(lista + i) = NULL;
        }

        retorno = 0;
    }

    return retorno;
}

int empleado_arrayIsEmpty(eEmpleado** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        retorno = 1;

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int empleado_buscarLibre(eEmpleado** lista, int len, int* indice)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && indice != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) == NULL)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int empleado_buscarPorId(eEmpleado** lista, int len, int id, int* indice)
{
    int retorno = -1;
    int auxId;
    int i;

    if(lista != NULL && len > 0 && id > 0 && indice != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL && !empleado_getId(*(lista + i), &auxId) && auxId == id)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int empleado_getArraySize(eEmpleado** lista, int len, int* size)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0 && size != NULL)
    {
        *size = 0;

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                (*size)++;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int empleado_getEmptyIndex(eEmpleado*** lista, int* len, int* indice)
{
    int retorno = -1;
    int size;

    if(lista != NULL && len != NULL && *len > 0 && indice != NULL && !empleado_getArraySize(*lista, *len, &size) &&
       (size < *len || !empleado_agrandarArray(lista, len, *len + 10)) && !empleado_buscarLibre(*lista, *len, indice))
    {
        retorno = 0;
    }

    return retorno;
}

int empleado_add(eEmpleado*** lista, int* len, int* id)
{
    int retorno = -1;
    int index;

    char auxNombre[NOMBRE_LEN];
    char auxApellido[APELLIDO_LEN];
    char auxSexo;
    float auxSueldo;

    eEmpleado* this = NULL;

    if(lista != NULL && len != NULL && *len > 0 && id != NULL &&
       !utn_getAlfabetico(auxNombre, "\nIngrese nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
       !utn_formatearCadena(auxNombre, NOMBRE_LEN) &&
       !utn_getAlfabetico(auxApellido, "\nIngrese apellido: ", "Error. Solo letras: ", 3, APELLIDO_LEN, 2) &&
       !utn_formatearCadena(auxApellido, APELLIDO_LEN) &&
       !utn_getSexo(&auxSexo, "\nIngrese sexo (F/M): ", "Error. Solo F/M: ", 2) &&
       !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo entre 10000 y 500000: ",
                                          "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2))
    {
        this = empleado_newParam(*id, auxNombre, auxApellido, auxSexo, auxSueldo);

        if(this != NULL && !empleado_getEmptyIndex(lista, len, &index))
        {
            *(*lista + index) = this;

            (*id)++;

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_edit(eEmpleado** lista, int len)
{
    int retorno = -1;
    int auxId;
    int index;

    if(lista != NULL && len > 0 && !empleado_mostrarLista(lista, len) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del empleado a modificar: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !empleado_buscarPorId(lista, len, auxId, &index))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tMODIFICACION DE EMPLEADO\n\n");

        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");
        printf("|%-10s|%-15s|%-15s|%-25s|%-4s|%-10s|%-10s|\n", "ID", "NOMBRE", "APELLIDO", "NOMBRE COMPLETO", "SEXO", "SEXO FULL", "SUELDO");
        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");
        empleado_mostrarUno(*(lista + index));
        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");

        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
           !empleado_mostrarMenuModificacion(*(lista + index)))
        {
            retorno = 0;
        }
    }

    return retorno;
}

int empleado_mostrarMenuModificacion(eEmpleado* this)
{
    int retorno = -1;

    char auxNombre[NOMBRE_LEN];
    char auxApellido[APELLIDO_LEN];
    char auxSexo;
    float auxSueldo;

    char opcion;

    int flagMod = 0;
    int flagExit = 0;

    if(this != NULL)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACION DE EMPLEADO\n\n");

            printf("A. Nombre\n");
            printf("B. Apellido\n");
            printf("C. Sexo\n");
            printf("D. Sueldo\n");
            printf("E. Salir\n");

            if(!utn_getCaracter(&opcion, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el nombre del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxNombre, "\nIngrese nuevo nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
                           !utn_formatearCadena(auxNombre, NOMBRE_LEN) && !empleado_setNombre(this, auxNombre))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el apellido del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getAlfabetico(auxApellido, "\nIngrese nuevo apellido: ", "Error. Solo letras: ", 3, APELLIDO_LEN, 2) &&
                           !utn_formatearCadena(auxApellido, APELLIDO_LEN) && !empleado_setApellido(this, auxApellido))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el sexo del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getSexo(&auxSexo, "\nIngrese nuevo sexo (F/M): ", "Error. Solo F/M: ", 2) && !empleado_setSexo(this, auxSexo))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el sueldo del empleado? (S/N): ", "Error. Solo S o N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxSueldo, "\nIngrese nuevo sueldo entre 10000 y 500000: ",
                                                              "Error. Solo numeros flotantes dentro del rango: ", 10000, 500000, 2) &&
                           !empleado_setSueldo(this, auxSueldo))
                        {
                            flagMod = 1;
                        }

                        break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = 1;
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

int empleado_remove(eEmpleado** lista, int len)
{
    int retorno = -1;
    int auxId;
    int index;

    if(lista != NULL && len > 0 && !empleado_mostrarLista(lista, len) &&
       !utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10000, 2) &&
       !empleado_buscarPorId(lista, len, auxId, &index))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tBAJA DE EMPLEADO\n\n");

        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");
        printf("|%-10s|%-15s|%-15s|%-25s|%-4s|%-10s|%-10s|\n", "ID", "NOMBRE", "APELLIDO", "NOMBRE COMPLETO", "SEXO", "SEXO FULL", "SUELDO");
        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");
        empleado_mostrarUno(*(lista + index));
        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");

        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este empleado? (S/N): ", "Error. Solo S o N: ") == 1)
        {
            empleado_delete(*(lista + index));

            *(lista + index) = NULL;

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_mostrarUno(eEmpleado* this)
{
    int retorno = -1;

    int id;
    char nombre[NOMBRE_LEN];
    char apellido[APELLIDO_LEN];
    char nombreCompleto[BUFFER_LEN];
    char sexo;
    char sexoFull[BUFFER_LEN];
    float sueldo;

    if(this != NULL && !empleado_getId(this, &id) && !empleado_getNombre(this, nombre) &&
       !empleado_getApellido(this, apellido) && !empleado_getNombreCompleto(this, nombreCompleto) &&
       !empleado_getSexo(this, &sexo) && !empleado_getSexoFull(this, sexoFull) &&
       !empleado_getSueldo(this, &sueldo))
    {
        printf("|%-10d|%-15s|%-15s|%-25s|%-4c|%-10s|%-10.2f|\n", id, nombre, apellido, nombreCompleto, sexo, sexoFull, sueldo);

        retorno = 0;
    }

    return retorno;
}

int empleado_mostrarLista(eEmpleado** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE EMPLEADOS\n\n");

        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");
        printf("|%-10s|%-15s|%-15s|%-25s|%-4s|%-10s|%-10s|\n", "ID", "NOMBRE", "APELLIDO", "NOMBRE COMPLETO", "SEXO", "SEXO FULL", "SUELDO");
        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                empleado_mostrarUno(*(lista + i));
            }
        }

        printf("*----------*---------------*---------------*-------------------------*----*----------*----------*\n");

        retorno = 0;
    }

    return retorno;
}

int empleado_sortSimpleCriterion(eEmpleado** lista, int len, int (*pFunc)(eEmpleado*, eEmpleado*), int order)
{
    int retorno = -1;
    int i;
    int auxLen;
    int flagSwap;

    if(lista != NULL && len > 0 && pFunc != NULL && (order == UP || order == DOWN))
    {
        auxLen = len;

        do
        {
            flagSwap = 0;

            for(i = 0; i < auxLen - 1; i++)
            {
                if(*(lista + i) != NULL && *(lista + (i + 1)) != NULL &&
                   pFunc(*(lista + i), *(lista + (i + 1))) == order - !order &&
                   !empleado_swap(&(*(lista + i)), &(*(lista + (i + 1)))))
                {
                    flagSwap = 1;
                }
            }

            auxLen--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int empleado_sortDoubleCriterion(eEmpleado** lista, int len, int (*pFunc1)(eEmpleado*, eEmpleado*), int (*pFunc2)(eEmpleado*, eEmpleado*), int order)
{
    int retorno = -1;
    int i;
    int auxLen;
    int auxCmp;
    int flagSwap;

    if(lista != NULL && len > 0 && pFunc1 != NULL && pFunc2 != NULL && pFunc1 != pFunc2 && (order == UP || order == DOWN))
    {
        auxLen = len;

        do
        {
            flagSwap = 0;

            for(i = 0; i < auxLen - 1; i++)
            {
                if(*(lista + i) != NULL && *(lista + (i + 1)) != NULL)
                {
                    auxCmp = pFunc1(*(lista + i), *(lista + (i + 1)));

                    if(auxCmp + !auxCmp * pFunc2(*(lista + i), *(lista + (i + 1))) == order - !order &&
                       !empleado_swap(&(*(lista + i)), &(*(lista + (i + 1)))))
                    {
                        flagSwap = 1;
                    }
                }
            }

            auxLen--;

        } while(flagSwap);

        retorno = 0;
    }

    return retorno;
}

int empleado_elegirCriterioOrdenamiento(int (**pFunc)(eEmpleado*, eEmpleado*))
{
    int retorno = -1;
    char opcion;

    if(pFunc != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tCRITERIO DE ORDENAMIENTO\n\n");

        printf("A. ID\n");
        printf("B. Nombre\n");
        printf("C. Apellido\n");
        printf("D. Sexo\n");
        printf("E. Sueldo\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *pFunc = empleado_compararPorId;

                    break;

                case 'B':

                    *pFunc = empleado_compararPorNombre;

                    break;

                case 'C':

                    *pFunc = empleado_compararPorApellido;

                    break;

                case 'D':

                    *pFunc = empleado_compararPorSexo;

                    break;

                case 'E':

                    *pFunc = empleado_compararPorSueldo;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
    char opcion;

    if(order != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tSENTIDO DE ORDENAMIENTO\n\n");

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

int empleado_compararInt(int a, int b)
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

int empleado_compararFloat(float a, float b)
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

int empleado_compararChar(char a, char b)
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

int empleado_compararString(char* a, char* b, int length)
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

int empleado_compararPorId(eEmpleado* a, eEmpleado* b)
{
    int retorno = -3;

    int id1;
    int id2;

    if(a != NULL && b != NULL && !empleado_getId(a, &id1) && !empleado_getId(b, &id2))
    {
        retorno = empleado_compararInt(id1, id2);
    }

    return retorno;
}

int empleado_compararPorNombre(eEmpleado* a, eEmpleado* b)
{
    int retorno = -3;

    char nombre1[NOMBRE_LEN];
    char nombre2[NOMBRE_LEN];

    if(a != NULL && b != NULL && !empleado_getNombre(a, nombre1) && !empleado_getNombre(b, nombre2))
    {
        retorno = empleado_compararString(nombre1, nombre2, NOMBRE_LEN);
    }

    return retorno;
}

int empleado_compararPorApellido(eEmpleado* a, eEmpleado* b)
{
    int retorno = -3;

    char apellido1[APELLIDO_LEN];
    char apellido2[APELLIDO_LEN];

    if(a != NULL && b != NULL && !empleado_getApellido(a, apellido1) && !empleado_getApellido(b, apellido2))
    {
        retorno = empleado_compararString(apellido1, apellido2, APELLIDO_LEN);
    }

    return retorno;
}

int empleado_compararPorSexo(eEmpleado* a, eEmpleado* b)
{
    int retorno = -3;

    char sexo1;
    char sexo2;

    if(a != NULL && b != NULL && !empleado_getSexo(a, &sexo1) && !empleado_getSexo(b, &sexo2))
    {
        retorno = empleado_compararChar(sexo1, sexo2);
    }

    return retorno;
}

int empleado_compararPorSueldo(eEmpleado* a, eEmpleado* b)
{
    int retorno = -3;

    float sueldo1;
    float sueldo2;

    if(a != NULL && b != NULL && !empleado_getSueldo(a, &sueldo1) && !empleado_getSueldo(b, &sueldo2))
    {
        retorno = empleado_compararFloat(sueldo1, sueldo2);
    }

    return retorno;
}

int empleado_swap(eEmpleado** a, eEmpleado** b)
{
    int retorno = -1;
    eEmpleado* temp = NULL;

    if(a != NULL && b != NULL)
    {
        temp = *a;
        *a = *b;
        *b = temp;

        temp = NULL;
        retorno = 0;
    }

    return retorno;
}

int empleado_agrandarArray(eEmpleado*** lista, int* len, int newLen)
{
    int retorno = -1;
    eEmpleado** pAux = NULL;

    if(lista != NULL && len != NULL && newLen > 0 && *len > 0 && *len < newLen)
    {
        pAux = (eEmpleado**) realloc(*lista, sizeof(eEmpleado*) * newLen);

        if(pAux != NULL && !empleado_inicializar(pAux, *len, newLen))
        {
            *lista = pAux;
            *len = newLen;

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_clear(eEmpleado** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                empleado_delete(*(lista + i));

                *(lista + i) = NULL;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int empleado_deleteArray(eEmpleado** lista, int len)
{
    int retorno = -1;

    if(lista != NULL && len > 0 && !empleado_clear(lista, len))
    {
        free(lista);

        retorno = 0;
    }

    return retorno;
}

int empleado_parseFromText(eEmpleado*** lista, int* len, char* path, int* id)
{
    int retorno = -1;
    int flagParse = 0;
    int flagDelete;
    int index;
    int auxId;

    char buffer[5][BUFFER_LEN];

    FILE* pFile = NULL;
    eEmpleado* this = NULL;

    if(lista != NULL && len != NULL && *len > 0 && path != NULL && id != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            do
            {
                this = empleado_new();
                flagDelete = 0;

                if(!empleado_delete(this))
                {
                    this = NULL;
                    flagDelete = 1;
                }

                if(flagDelete && !empleado_getEmptyIndex(lista, len, &index))
                {
                    if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]) == 5)
                    {
                        this = empleado_newParamStr(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

                        if(this != NULL)
                        {
                            auxId = atoi(buffer[0]);

                            if(auxId > *id)
                            {
                                *id = auxId + 1;
                            }

                            *(*lista + index) = this;
                            this = NULL;

                            flagParse = 1;
                        }
                    }
                }

                else
                {
                    break;
                }

            } while(!feof(pFile));

            fclose(pFile);
            pFile = NULL;

            if(flagParse)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int empleado_parseFromBin(eEmpleado*** lista, int* len, char* path, int* id)
{
    int retorno = -1;
    int flag = 0;
    int index;
    int auxId;

    FILE* pFile = NULL;
    eEmpleado* this = NULL;

    if(lista != NULL && len != NULL && *len > 0 && path != NULL && id != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            do
            {
                this = empleado_new();

                if(this != NULL)
                {
                    index = -1;

                    if(!empleado_getEmptyIndex(lista, len, &index) && fread(this, sizeof(eEmpleado), 1, pFile) == 1)
                    {
                        if(!empleado_getId(this, &auxId) && auxId > *id)
                        {
                            *id = auxId + 1;
                        }

                        *(*lista + index) = this;
                        this = NULL;

                        flag = 1;
                    }

                    else
                    {
                        empleado_delete(this);
                        this = NULL;

                        if(index == -1)
                        {
                            break;
                        }
                    }
                }

                else
                {
                    break;
                }

            } while(!feof(pFile));

            fclose(pFile);
            pFile = NULL;

            if(flag)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int empleado_serializeToText(eEmpleado** lista, int len, char* path)
{
    int retorno = -1;
    int i;

    char buffer[5][BUFFER_LEN];

    FILE* pFile = NULL;

    if(lista != NULL && len > 0 && path != NULL)
    {
        pFile = fopen(path, "w");

        if(pFile != NULL)
        {
            fprintf(pFile, "id,nombre,apellido,sexo,sueldo\n");

            for(i = 0; i < len; i++)
            {
                if(*(lista + i) != NULL && !empleado_getIdTxt(*(lista + i), buffer[0]) &&
                   !empleado_getNombre(*(lista + i), buffer[1]) && !empleado_getApellido(*(lista + i), buffer[2]) &&
                   !empleado_getSexo(*(lista + i), &buffer[3][0]) && !empleado_getSueldoTxt(*(lista + i), buffer[4]))
                {
                    fprintf(pFile, "%s,%s,%s,%s,%s\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                }
            }

            fclose(pFile);
            pFile = NULL;

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_serializeToBin(eEmpleado** lista, int len, char* path)
{
    int retorno = -1;
    int i;

    FILE* pFile = NULL;

    if(lista != NULL && len > 0 && path != NULL)
    {
        pFile = fopen(path, "wb");

        if(pFile != NULL)
        {
            for(i = 0; i < len; i++)
            {
                if(*(lista + i) != NULL && fwrite(*(lista + i), sizeof(eEmpleado), 1, pFile) != 1)
                {
                    break;
                }
            }

            fclose(pFile);
            pFile = NULL;

            retorno = 0;
        }
    }

    return retorno;
}

int empleado_existeArchivo(char* path, char* mode)
{
    int retorno = -1;

    FILE* pFile = NULL;

    if(path != NULL && mode != NULL)
    {
        retorno = 0;

        pFile = fopen(path, mode);

        if(pFile != NULL)
        {
            retorno = 1;

            fclose(pFile);
            pFile = NULL;
        }
    }

    return retorno;
}

int empleado_mostrarMenuOrdenamiento(eEmpleado** lista, int len)
{
    int retorno = -1;
    int order;
    char opcion;

    int (*pFunc1)(eEmpleado*, eEmpleado*) = NULL;
    int (*pFunc2)(eEmpleado*, eEmpleado*) = NULL;

    if(lista != NULL && len > 0)
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

                    if(!empleado_elegirCriterioOrdenamiento(&pFunc1) && !empleado_elegirSentidoOrdenamiento(&order) &&
                       !empleado_sortSimpleCriterion(lista, len, pFunc1, order))
                    {
                        printf("\nOrdenamiento realizado correctamente\n");
                    }

                    else
                    {
                        printf("\nNo se pudo realizar el ordenamiento\n");
                    }

                    break;

                case 'B':

                    if(!empleado_elegirCriterioOrdenamiento(&pFunc1) && !empleado_elegirCriterioOrdenamiento(&pFunc2) &&
                       !empleado_elegirSentidoOrdenamiento(&order) && !empleado_sortDoubleCriterion(lista, len, pFunc1, pFunc2, order))
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

int empleado_menuOpciones(int* opcion)
{
    int retorno = -1;

    if(opcion != NULL)
    {
        printf("\tMENU PRINCIPAL\n\n");

        printf("1. Cargar Empleados desde archivo de texto (data.csv)\n");
        printf("2. Cargar Empleados desde archivo binario (data.bin)\n");
        printf("3. Alta de Empleado\n");
        printf("4. Modificacion de Empleado\n");
        printf("5. Baja de Empleado\n");
        printf("6. Listar Empleados\n");
        printf("7. Ordenar Empleados\n");
        printf("8. Guardar Empleados en archivo de texto (data.csv)\n");
        printf("9. Guardar Empleados en archivo binario (data.bin)\n");
        printf("10. Salir\n");

        if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Solo numeros enteros dentro del rango: ", 1, 10, 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}
