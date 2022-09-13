#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Producto.h"
#define TAM 10

int main()
{
    int ids[TAM];
    char descripciones[TAM][DESC_LEN];
    int nacionalidades[TAM];
    int tipos[TAM];
    float precios[TAM];
    int isEmpty[TAM];

    char opcion;
    int retornoFuncion;
    int auxOrder;
    int id = 1;
    int flagExit = 0;

    if(!inicializarProductos(isEmpty, TAM))
    {
        hardCodearProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM, &id);

        do
        {
            retornoFuncion = mostrarMenuPrincipal(&opcion);

            if(retornoFuncion == 0)
            {
                switch(opcion)
                {
                    case 'I':

                        retornoFuncion = cargarProducto(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM, &id);

                        switch(retornoFuncion)
                        {
                            case 0:

                                printf("\nProducto ingresado con exito\n");

                                break;

                            case -1:

                                printf("\nEl legajo ingresado ya existe\n");

                                break;

                            case -2:

                                printf("\nNo se cargo correctamente el producto\n");

                                break;

                            case -3:

                                printf("\nNo hay espacio disponible\n");

                                break;

                            case -4:

                                printf("\nError. No se pudo encontrar lugar\n");

                                break;

                            case -5:

                                printf("\nError. No se puede cargar el numero\n");

                                break;
                        }

                        break;

                    case 'J':

                        if(!arrayIsEmpty(isEmpty, TAM))
                        {
                            retornoFuncion = eliminarProducto(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM);

                            switch(retornoFuncion)
                            {
                                case -3:

                                    printf("\nError. No se pudo eliminar al producto\n");

                                    break;

                                case -2:

                                    printf("\nEl ID ingresado no existe\n");

                                    break;

                                case -1:

                                    printf("\nAccion cancelada por el usuario\n");

                                    break;

                                case 0:

                                    printf("\nEl producto ha sido eliminado\n");

                                    break;
                            }
                        }

                        else
                        {
                            printf("\nNo hay productos cargados para eliminar\n");
                        }

                        break;

                    case 'K':

                        if(!arrayIsEmpty(isEmpty, TAM))
                        {
                            retornoFuncion = modificarProducto(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM);

                            switch(retornoFuncion)
                            {
                                case -3:

                                    printf("\nError. No se pudo modificar al producto\n");

                                    break;

                                case -2:

                                    printf("\nEl ID ingresado no existe\n");

                                    break;

                                case -1:

                                    printf("\nAccion cancelada por el usuario\n");

                                    break;

                                case 0:

                                    printf("\nEl producto ha sido modificado\n");

                                    break;
                            }
                        }

                        else
                        {
                            printf("\nNo hay productos cargados para modificar\n");
                        }

                        break;

                    case 'L':

                        if(!arrayIsEmpty(isEmpty, TAM))
                        {
                            if(!mostrarListaProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM))
                            {
                                printf("\nLista mostrada correctamente\n");
                            }

                            else
                            {
                                printf("\nNo se puede mostrar los productos\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay productos para mostrar\n");
                        }

                        break;

                    case 'M':

                        if(!arrayIsEmpty(isEmpty, TAM))
                        {
                            if(!elegirSentidoOrdenamiento(&auxOrder) &&
                               !ordenarProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM, PRECIO, auxOrder) &&
                               !mostrarListaProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM))
                            {
                                printf("\nOrdenamiento y muestra realizados correctamente\n");
                            }

                            else
                            {
                                printf("\nError en el proceso\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay productos para ordenar y mostrar\n");
                        }

                        break;

                    case 'N':

                        if(!arrayIsEmpty(isEmpty, TAM))
                        {
                            if(!elegirSentidoOrdenamiento(&auxOrder) &&
                               !ordenarProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM, DESC, auxOrder) &&
                               !mostrarListaProductos(ids, descripciones, nacionalidades, tipos, precios, isEmpty, TAM))
                            {
                                printf("\nOrdenamiento y muestra realizados correctamente\n");
                            }

                            else
                            {
                                printf("\nError en el proceso\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay productos para ordenar y mostrar\n");
                        }

                        break;

                    case 'O':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            else
            {
                if(retornoFuncion == -1)
                {
                    printf("\nNo se cargo correctamente la opcion\n");
                }

                else
                {
                    printf("\nError. No se puede mostrar el menu\n");
                }

                break;
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 'O' || !flagExit);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
