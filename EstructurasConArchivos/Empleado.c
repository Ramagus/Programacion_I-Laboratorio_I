#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

eEmpleado* empleado_newParam(int legajo, char* nombre, char sexo, float salario)
{
    eEmpleado* this = NULL;

    if(nombre != NULL)
    {
        this = empleado_new();

        if(this != NULL && (empleado_setLegajo(this, legajo) || empleado_setNombre(this, nombre) ||
           empleado_setSexo(this, sexo) || empleado_setSalario(this, salario)))
        {
            empleado_delete(this);
            this = NULL;
        }
    }

    return this;
}

eEmpleado* empleado_newParamTxt(char* legajoStr, char* nombreStr, char* sexoStr, char* salarioStr)
{
    eEmpleado* this = NULL;

    if(legajoStr != NULL && nombreStr != NULL && sexoStr != NULL && salarioStr != NULL)
    {
        this = empleado_new();

        if(this != NULL && (empleado_setLegajoTxt(this, legajoStr) || empleado_setNombre(this, nombreStr) ||
           empleado_setSexo(this, *(sexoStr + 0)) || empleado_setSalarioTxt(this, salarioStr)))
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

int empleado_setLegajo(eEmpleado* this, int legajo)
{
    int retorno = -1;

    if(this != NULL && isValidId(legajo))
    {
        this->legajo = legajo;
        retorno = 0;
    }

    return retorno;
}

int empleado_setLegajoTxt(eEmpleado* this, char* legajo)
{
    int retorno = -1;
    int auxLegajo;

    if(this != NULL && isInt(legajo, BUFFER_LEN) == 1)
    {
        auxLegajo = atoi(legajo);

        if(isValidId(auxLegajo))
        {
            this->legajo = auxLegajo;
            retorno = 0;
        }
    }

    return retorno;
}

int empleado_setNombre(eEmpleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && isAlphabetical(nombre, NAME_LEN) == 1)
    {
        strncpy(this->nombre, nombre, NAME_LEN);
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

int empleado_setSalario(eEmpleado* this, float salario)
{
    int retorno = -1;

    if(this != NULL && isValidSalary(salario))
    {
        this->salario = salario;
        retorno = 0;
    }

    return retorno;
}

int empleado_setSalarioTxt(eEmpleado* this, char* salario)
{
    int retorno = -1;
    float auxSalario;

    if(this != NULL && isFloat(salario, BUFFER_LEN) == 1)
    {
        auxSalario = atof(salario);

        if(isValidSalary(auxSalario))
        {
            this->salario = auxSalario;
            retorno = 0;
        }
    }

    return retorno;
}

int empleado_getLegajo(eEmpleado* this, int* legajo)
{
    int retorno = -1;

    if(this != NULL && legajo != NULL)
    {
        *legajo = this->legajo;
        retorno = 0;
    }

    return retorno;
}

int empleado_getLegajoTxt(eEmpleado* this, char* legajo)
{
    int retorno = -1;

    if(this != NULL && legajo != NULL)
    {
        snprintf(legajo, BUFFER_LEN, "%d", this->legajo);
        retorno = 0;
    }

    return retorno;
}

int empleado_getNombre(eEmpleado* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, NAME_LEN);
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

int empleado_getSalario(eEmpleado* this, float* salario)
{
    int retorno = -1;

    if(this != NULL && salario != NULL)
    {
        *salario = this->salario;
        retorno = 0;
    }

    return retorno;
}

int empleado_getSalarioTxt(eEmpleado* this, char* salario)
{
    int retorno = -1;

    if(this != NULL && salario != NULL)
    {
        snprintf(salario, BUFFER_LEN, "%.2f", this->salario);
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

int empleado_inicializar(eEmpleado** lista, int len)
{
    int retorno = -1;
    int i;

    if(lista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            *(lista + i) = NULL;
        }

        retorno = 0;
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

int empleado_mostrarUno(eEmpleado* this)
{
    int retorno = -1;

    int legajo;
    char nombre[NAME_LEN];
    char sexo;
    float salario;

    if(this != NULL && !empleado_getLegajo(this, &legajo) && !empleado_getNombre(this, nombre) &&
       !empleado_getSexo(this, &sexo) && !empleado_getSalario(this, &salario))
    {
        printf("|%-10d|%-20s|%-4c|%-10.2f|\n", legajo, nombre, sexo, salario);

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
        printf("\tLISTA DE EMPLEADOS\n\n");

        printf("*----------*--------------------*----*----------*\n");
        printf("|%-10s|%-20s|%-4s|%-10s|\n", "LEGAJO", "NOMBRE", "SEXO", "SALARIO");
        printf("*----------*--------------------*----*----------*\n");

        for(i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL)
            {
                empleado_mostrarUno(*(lista + i));
            }
        }

        printf("*----------*--------------------*----*----------*\n");

        retorno = 0;
    }

    return retorno;
}

int empleado_parseFromText(eEmpleado** lista, int len, char* path)
{
    int retorno = -1;
    int flagParse = 0;
    int flagDelete;
    int index;

    char buffer[4][BUFFER_LEN];

    FILE* pArchivo = NULL;
    eEmpleado* this = NULL;

    if(lista != NULL && len > 0 && path != NULL)
    {
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL)
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

                if(flagDelete && !empleado_buscarLibre(lista, len, &index))
                {
                    if(fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4)
                    {
                        this = empleado_newParamTxt(buffer[0], buffer[1], buffer[2], buffer[3]);

                        if(this != NULL)
                        {
                            *(lista + index) = this;
                            this = NULL;

                            flagParse = 1;
                        }
                    }
                }

                else
                {
                    break;
                }

            } while(!feof(pArchivo));

            fclose(pArchivo);
            pArchivo = NULL;

            if(flagParse)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}
