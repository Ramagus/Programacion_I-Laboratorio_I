#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Producto.h"

int mostrarMenuPrincipal(char* op)
{
    int retorno = -2;

    if(op != NULL)
    {
        retorno = -1;

        printf("\tMENU PRINCIPAL\n\n");

        printf("I. Alta Producto\n");
        printf("J. Baja Producto\n");
        printf("K. Modificar Producto\n");
        printf("L. Listar Productos\n");
        printf("M. Listado Ordenado de Productos por Precio\n");
        printf("N. Listado Ordenado de Productos por Descripcion\n");
        printf("O. Salir\n");

        if(!utn_getCaracter(op, "\nElija una opcion: ", "Error. Elija una opcion correcta: ", 'I', 'O', 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}

int inicializarProductos(int isEmpty[], int tam)
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

int hardCodearProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int* id)
{
    int retorno = -1;
    int indice;
    int i;
    int cant;
    int flag = FALSE;

    char auxDescripciones[][DESC_LEN] = {"iPhone 11", "iPhone 12", "Mac Pro", "iPad Pro", "iPod Touch"};
    int auxNacionalidades[] = {OTRO, EEUU, EEUU, OTRO, CHINA};
    int auxTipos[] = {IPHONE, IPHONE, MAC, IPAD, ACCESORIOS};
    float auxPrecios[] = {190000, 250000, 140000, 500000, 400000};

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL && isEmpty != NULL && tam > 0 && id != NULL)
    {
        cant = sizeof(auxTipos) / sizeof(int);

        if(cant <= tam)
        {
            for(i = 0; i < cant; i++)
            {
                indice = buscarLibre(isEmpty, tam);

                if(indice > -1)
                {
                    ids[indice] = *id;
                    strncpy(descripciones[indice], auxDescripciones[i], DESC_LEN);
                    nacionalidades[indice] = auxNacionalidades[i];
                    tipos[indice] = auxTipos[i];
                    precios[indice] = auxPrecios[i];

                    isEmpty[indice] = FALSE;

                    (*id)++;

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

int buscarProductoPorId(int ids[], int isEmpty[], int tam, int id)
{
    int retorno = -2;
    int i;

    if(ids != NULL && isEmpty != NULL && tam > 0 && id > 0)
    {
        retorno = -1;

        for(i = 0; i < tam; i++)
        {
            if(!isEmpty[i] && ids[i] == id)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int elegirNac(int* nacionalidad)
{
    int retorno = -1;
    char opcion;

    if(nacionalidad != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tNACIONALIDADES\n\n");
        printf("A. EEUU\n");
        printf("B. China\n");
        printf("C. Otro\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'C', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *nacionalidad = EEUU;

                    break;

                case 'B':

                    *nacionalidad = CHINA;

                    break;

                case 'C':

                    *nacionalidad = OTRO;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int elegirTipo(int* tipo)
{
    int retorno = -1;
    char opcion;

    if(tipo != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tTIPOS\n\n");
        printf("A. iPhone\n");
        printf("B. Mac\n");
        printf("C. iPad\n");
        printf("D. Accesorios\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *tipo = IPHONE;

                    break;

                case 'B':

                    *tipo = MAC;

                    break;

                case 'C':

                    *tipo = IPAD;

                    break;

                case 'D':

                    *tipo = ACCESORIOS;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int cargarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int* id)
{
    int retorno = -5;
    int indice;
    char auxDescripcion[DESC_LEN];
    int auxNacionalidad;
    int auxTipo;
    float auxPrecio;

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL && isEmpty != NULL && tam > 0 && id != NULL)
    {
        retorno = -4;

        indice = buscarLibre(isEmpty, tam);

        if(indice != -1)
        {
            if(indice == -2)
            {
                retorno = -3;
            }

            else
            {
                retorno = -2;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tALTA DE PRODUCTO\n");

                if(!utn_getAlfaNumerico(auxDescripcion, "\nIngrese descripcion: ", "Error. Solo letras y/o numeros: ", 3, DESC_LEN, 2) &&
                   !elegirNac(&auxNacionalidad) && !elegirTipo(&auxTipo) &&
                   !utn_getNumeroFlotante(&auxPrecio, "\nIngrese precio entre 1 y 1000000: ", "Error. Solo numeros flotantes entre 1 y 1000000: ", 1, 1000000, 2))
                {
                    retorno = -1;

                    ids[indice] = *id;
                    strncpy(descripciones[indice], auxDescripcion, DESC_LEN);
                    nacionalidades[indice] = auxNacionalidad;
                    tipos[indice] = auxTipo;
                    precios[indice] = auxPrecio;

                    isEmpty[indice] = FALSE;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int eliminarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam)
{
    int retorno = -3;
    int auxId;
    int indice;

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL && isEmpty != NULL && tam > 0)
    {
        retorno = -2;

        if(!mostrarListaProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, tam) &&
           !utn_getNumero(&auxId, "\nIngrese el ID del producto a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 1, 100, 2))
        {
            indice = buscarProductoPorId(ids, isEmpty, tam, auxId);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tBAJA DE PRODUCTO\n\n");

                printf("*----------*--------------------*--------------------*----------*----------*\n");
                printf("|%-10s|%-20s|%-20s|%-10s|%-10s|\n", "ID", "DESCRIPCION", "NACIONALIDAD", "TIPO", "PRECIO");
                printf("*----------*--------------------*--------------------*----------*----------*\n");
                mostrarProducto(&ids[indice], descripciones[indice], &nacionalidades[indice], &tipos[indice], &precios[indice]);
                printf("*----------*--------------------*--------------------*----------*----------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este producto (S/N)?: ", "Error. Solo S/N: ") == 1)
                {
                    isEmpty[indice] = TRUE;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int modificarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam)
{
    int retorno = -3;
    int auxId;
    int indice;

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL && isEmpty != NULL && tam > 0)
    {
        retorno = -2;

        if(!mostrarListaProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, tam) &&
           !utn_getNumero(&auxId, "\nIngrese el legajo del alumno a modificar: ", "Error. Solo numeros enteros del 100 al 500: ", 100, 500, 2))
        {
            indice = buscarProductoPorId(ids, isEmpty, tam, auxId);

            if(indice > -1)
            {
                retorno = -1;

                printf("\n");
                system("pause");
                system("cls");

                printf("\tMODIFICACION DE PRODUCTO\n\n");

                printf("*----------*--------------------*--------------------*----------*----------*\n");
                printf("|%-10s|%-20s|%-20s|%-10s|%-10s|\n", "ID", "DESCRIPCION", "NACIONALIDAD", "TIPO", "PRECIO");
                printf("*----------*--------------------*--------------------*----------*----------*\n");
                mostrarProducto(&ids[indice], descripciones[indice], &nacionalidades[indice], &tipos[indice], &precios[indice]);
                printf("*----------*--------------------*--------------------*----------*----------*\n");

                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este producto (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                   !mostrarMenuModificar(tipos, precios, tam, indice))
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int mostrarMenuModificar(int tipos[], float precios[], int tam, int index)
{
    int retorno = -1;
    int auxTipo;
    float auxPrecio;
    char opcion;
    int flagMod = FALSE;
    int flagExit = FALSE;

    if(tipos != NULL && precios != NULL && tam > 0 && index >= 0 && index < tam)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMODIFICAR PRODUCTO\n\n");
            printf("A. Tipo\n");
            printf("B. Precio\n");
            printf("C. Salir\n");

            if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Elija una opcion correcta: ", 'A', 'C', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(!utn_getNumero(&auxTipo, "\nIngrese nuevo tipo: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 1003, 2))
                        {
                            tipos[index] = auxTipo;

                            flagMod = TRUE;
                        }

                        break;

                    case 'B':

                        if(!utn_getNumeroFlotante(&auxPrecio, "\nIngrese nuevo precio entre 1 y 1000000: ", "Error. Solo numeros flotantes entre 1 y 1000000: ", 1, 1000000, 2))
                        {
                            precios[index] = auxPrecio;

                            flagMod = TRUE;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu de modificacion\n");

                            flagExit = TRUE;
                        }

                        break;
                }
            }

        } while(opcion != 'C' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int cargarDescNac(int nacionalidad, char descripcion[])
{
    int retorno = -1;

    if(nacionalidad > 0 && descripcion != NULL)
    {
        switch(nacionalidad)
        {
            case EEUU:

                strncpy(descripcion, "EEUU", DESC_LEN);

                break;

            case CHINA:

                strncpy(descripcion, "China", DESC_LEN);

                break;

            case OTRO:

                strncpy(descripcion, "Otro", DESC_LEN);

                break;
        }

        retorno = 0;
    }

    return retorno;
}

int cargarDescTipo(int tipo, char descripcion[])
{
    int retorno = -1;

    if(tipo > 0 && descripcion != NULL)
    {
        switch(tipo)
        {
            case IPHONE:

                strncpy(descripcion, "iPhone", DESC_LEN);

                break;

            case MAC:

                strncpy(descripcion, "Mac", DESC_LEN);

                break;

            case IPAD:

                strncpy(descripcion, "iPad", DESC_LEN);

                break;

            case ACCESORIOS:

                strncpy(descripcion, "Accesorios", DESC_LEN);

                break;
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarProducto(int* id, char descripcion[], int* nacionalidad, int* tipo, float* precio)
{
    int retorno = -1;
    char descNac[DESC_LEN];
    char descTipo[DESC_LEN];

    if(id != NULL && descripcion != NULL && nacionalidad != NULL && tipo != NULL && precio != NULL &&
       !cargarDescNac(*nacionalidad, descNac) && !cargarDescTipo(*tipo, descTipo))
    {
        printf("|%-10d|%-20s|%-20s|%-10s|%-10.2f|\n", *id, descripcion, descNac, descTipo, *precio);

        retorno = 0;
    }

    return retorno;
}

int mostrarListaProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam)
{
    int retorno = -1;
    int i;

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL && isEmpty != NULL && tam > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE PRODUCTOS\n\n");

        printf("*----------*--------------------*--------------------*----------*----------*\n");
        printf("|%-10s|%-20s|%-20s|%-10s|%-10s|\n", "ID", "DESCRIPCION", "NACIONALIDAD", "TIPO", "PRECIO");
        printf("*----------*--------------------*--------------------*----------*----------*\n");

        for(i = 0; i < tam; i++)
        {
            if(!isEmpty[i] && mostrarProducto(&ids[i], descripciones[i], &nacionalidades[i], &tipos[i], &precios[i]))
            {
                break;
            }
        }

        printf("*----------*--------------------*--------------------*----------*----------*\n");

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

int compararCriterio(int id_A, char descripcion_A[], int nacionalidad_A, int tipo_A, float precio_A,
                     int id_B, char descripcion_B[], int nacionalidad_B, int tipo_B, float precio_B, int criterio)
{
    int retorno = -3;

    if(id_A > 0 && descripcion_A != NULL && nacionalidad_A > 0 && tipo_A > 0 && precio_A > 0 &&
       id_B > 0 && descripcion_B != NULL && nacionalidad_B > 0 && tipo_B > 0 && precio_B > 0 && criterio >= 0)
    {
        switch(criterio)
        {
            case ID:

                retorno = compararInt(id_A, id_B);

                break;

            case DESC:

                retorno = compararString(descripcion_A, descripcion_B, DESC_LEN);

                break;

            case NAC:

                retorno = compararInt(nacionalidad_A, nacionalidad_B);

                break;

            case TIPO:

                retorno = compararInt(tipo_A, tipo_B);

                break;

            case PRECIO:

                retorno = compararFloat(precio_A, precio_B);

                break;
        }
    }

    return retorno;
}

int ordenarProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int criterio, int order)
{
    int retorno = -1;
    int i;
    int auxTam;
    int flagSwap;

    if(ids != NULL && descripciones != NULL && nacionalidades != NULL && tipos != NULL && precios != NULL &&
       isEmpty != NULL && tam > 0 && criterio >= 0 && (order == UP || order == DOWN))
    {
        auxTam = tam;

        do
        {
            flagSwap = FALSE;

            for(i = 0; i < auxTam - 1; i++)
            {
                if(!isEmpty[i] && !isEmpty[i + 1] &&
                   compararCriterio(ids[i], descripciones[i], nacionalidades[i], tipos[i], precios[i],
                                    ids[i + 1], descripciones[i + 1], nacionalidades[i + 1], tipos[i + 1], precios[i + 1], criterio) == order - !order &&
                   !swapInt(&ids[i], &ids[i + 1]) && !swapString(descripciones[i], descripciones[i + 1], DESC_LEN) &&
                   !swapInt(&nacionalidades[i], &nacionalidades[i + 1]) && !swapInt(&tipos[i], &tipos[i + 1]) && !swapFloat(&precios[i], &precios[i + 1]))
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
        printf("A. ID\n");
        printf("B. Descripcion\n");
        printf("C. Nacionalidad\n");
        printf("D. Tipo\n");
        printf("E. Precio\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'E', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID;

                    break;

                case 'B':

                    *criterio = DESC;

                    break;

                case 'C':

                    *criterio = NAC;

                    break;

                case 'D':

                    *criterio = TIPO;

                    break;

                case 'E':

                    *criterio = PRECIO;

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
