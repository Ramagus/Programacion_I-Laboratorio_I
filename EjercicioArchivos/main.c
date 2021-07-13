#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50

typedef struct
{
    int legajo;
    char nombre[50];
    char apellido[50];
    float salario;

} eEmpleado;

eEmpleado* new_empleado(void);
eEmpleado* new_empleado_parametros(char* legajoStr, char* nombreStr, char* apellidoStr, char* salarioStr);
int set_legajo(eEmpleado* p, int legajo);
int set_nombre(eEmpleado* p, char nombre[]);
int set_apellido(eEmpleado* p, char apellido[]);
int set_salario(eEmpleado* p, float salario);
int get_legajo(eEmpleado* p, int* legajo);
int get_nombre(eEmpleado* p, char* nombre);
int get_apellido(eEmpleado* p, char* apellido);
int get_salario(eEmpleado* p, float* salario);
int delete_listaEmpleados(eEmpleado* pLista[], int len);
int mostrarEmpleado(eEmpleado* unEmpleado);
int mostrarListaEmpleados(eEmpleado* listaEmpleados[], int len);

int main()
{
    FILE* pArchivo;
    eEmpleado* listaDeEmpleados[LEN];
    eEmpleado* unEmpleado;

    char legajo[10];
    char nombre[50];
    char apellido[50];
    char salario[10];
    int i = 0;

    pArchivo = fopen("data.csv", "r");

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", legajo, nombre, apellido, salario);

        while(!feof(pArchivo))
        {
            fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", legajo, nombre, apellido, salario);

            //printf("%s---%s---%s---%s\n", legajo, nombre, apellido, salario);

            /**Usar setters*/
            //unEmpleado = new_empleado();

            /*if(unEmpleado != NULL)
            {
                unEmpleado->legajo = atoi(legajo);
                strcpy(unEmpleado->nombre, nombre);
                strcpy(unEmpleado->apellido, apellido);
                unEmpleado->salario = atof(salario);
            }*/

            unEmpleado = new_empleado_parametros(legajo, nombre, apellido, salario);

            if(unEmpleado != NULL)
            {
                *(listaDeEmpleados + i) = unEmpleado;
            }

            i++;
        }

        fclose(pArchivo);
    }

    /**Usar getters*/
    /*for(i = 0; i < LEN; i++)
    {
        printf("%d---%s---%s---%.2f\n", listaDeEmpleados[i]->legajo, listaDeEmpleados[i]->nombre,
                                        listaDeEmpleados[i]->apellido, listaDeEmpleados[i]->salario);
    }*/

    mostrarListaEmpleados(listaDeEmpleados, LEN);

    delete_listaEmpleados(listaDeEmpleados, LEN);

    return 0;
}

eEmpleado* new_empleado(void)
{
    eEmpleado* p;

    p = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(p != NULL)
    {
        p->legajo = 0;
        strcpy(p->nombre, "");
        strcpy(p->apellido, "");
        p->salario = 0;
    }

    return p;
}

eEmpleado* new_empleado_parametros(char* legajoStr, char* nombreStr, char* apellidoStr, char* salarioStr)
{
    eEmpleado* p;

    int auxLegajo;
    float auxSalario;

    if(legajoStr != NULL && nombreStr != NULL && apellidoStr != NULL && salarioStr != NULL)
    {
        p = new_empleado();

        auxLegajo = atoi(legajoStr);
        auxSalario = atof(salarioStr);

        if(p != NULL)
        {
            set_legajo(p, auxLegajo);
            set_nombre(p, nombreStr);
            set_apellido(p, apellidoStr);
            set_salario(p, auxSalario);
        }
    }

    return p;
}

int set_legajo(eEmpleado* p, int legajo)
{
    int retorno = -1;

    if(p != NULL && legajo > 0)
    {
        p->legajo = legajo;
        retorno = 0;
    }

    return retorno;
}

int set_nombre(eEmpleado* p, char nombre[])
{
    int retorno = -1;

    if(p != NULL && nombre != NULL)
    {
        strcpy(p->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int set_apellido(eEmpleado* p, char apellido[])
{
    int retorno = -1;

    if(p != NULL && apellido != NULL)
    {
        strcpy(p->apellido, apellido);
        retorno = 0;
    }

    return retorno;
}

int set_salario(eEmpleado* p, float salario)
{
    int retorno = -1;

    if(p != NULL && salario > 0)
    {
        p->salario = salario;
        retorno = 0;
    }

    return retorno;
}

int get_legajo(eEmpleado* p, int* legajo)
{
    int retorno = -1;

    if(p != NULL && legajo != NULL)
    {
        *legajo = p->legajo;
        retorno = 0;
    }

    return retorno;
}

int get_nombre(eEmpleado* p, char* nombre)
{
    int retorno = -1;

    if(p != NULL && nombre != NULL)
    {
        strcpy(nombre, p->nombre);
        retorno = 0;
    }

    return retorno;
}

int get_apellido(eEmpleado* p, char* apellido)
{
    int retorno = -1;

    if(p != NULL && apellido != NULL)
    {
        strcpy(apellido, p->apellido);
        retorno = 0;
    }

    return retorno;
}

int get_salario(eEmpleado* p, float* salario)
{
    int retorno = -1;

    if(p != NULL && salario != NULL)
    {
        *salario = p->salario;
        retorno = 0;
    }

    return retorno;
}

int delete_listaEmpleados(eEmpleado* pLista[], int len)
{
    int retorno = -1;
    int i;

    if(pLista != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            free(pLista + i);
            *(pLista + i) = NULL;
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarEmpleado(eEmpleado* unEmpleado)
{
    int retorno = -1;
    int legajo;
    char nombre[50];
    char apellido[50];
    float salario;

    if(unEmpleado != NULL)
    {
        get_legajo(unEmpleado, &legajo);
        get_nombre(unEmpleado, nombre);
        get_apellido(unEmpleado, apellido);
        get_salario(unEmpleado, &salario);

        printf("%d---%s---%s---%.2f\n", legajo, nombre, apellido, salario);

        retorno = 0;
    }

    return retorno;
}

int mostrarListaEmpleados(eEmpleado* listaEmpleados[], int len)
{
    int retorno = -1;
    int i;

    if(listaEmpleados != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(mostrarEmpleado(*(listaEmpleados + i)))
            {
                break;
            }
        }

        if(i == len)
        {
            retorno = 0;
        }
    }

    return retorno;
}
