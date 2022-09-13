#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Empleado.h"
#define PATH_TXT "data.csv"
#define PATH_BIN "data.bin"

int main()
{
    eEmpleado** listaEmpleados = NULL;
    int tam = 10;

    int opcion;
    int flagAnswer;
    int flagClear;
    int flagExit = 0;

    int id = 1;

    listaEmpleados = empleado_newArray(tam);

    if(listaEmpleados != NULL)
    {
        do
        {
            if(!empleado_menuOpciones(&opcion))
            {
                switch(opcion)
                {
                    case 1:
                    case 2:

                        flagAnswer = 0;
                        flagClear = 0;

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            flagAnswer = 1;

                            if(utn_respuestaEsAfirmativa("\nCuidado, se van a sobrescribir los datos. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!empleado_clear(listaEmpleados, tam))
                                {
                                    flagClear = 1;
                                }
                            }

                            else
                            {
                                printf("\nAccion cancelada\n");
                            }
                        }

                        if(!flagAnswer || flagClear)
                        {
                            if(opcion == 1)
                            {
                                if(!empleado_parseFromText(&listaEmpleados, &tam, PATH_TXT, &id))
                                {
                                    printf("\nArchivo de texto leido correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo leer el archivo de texto\n");
                                }
                            }

                            else
                            {
                                if(!empleado_parseFromBin(&listaEmpleados, &tam, PATH_BIN, &id))
                                {
                                    printf("\nArchivo binario leido correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo leer el archivo binario\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nError en la carga\n");
                        }

                        break;

                    case 3:

                        printf("\n");
                        system("pause");
                        system("cls");

                        printf("\tALTA DE EMPLEADO\n");

                        if(!empleado_add(&listaEmpleados, &tam, &id))
                        {
                            printf("\nEmpleado cargado correctamente\n");
                        }

                        else
                        {
                            printf("\nNo se pudo cargar al empleado\n");
                        }

                        break;

                    case 4:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(!empleado_edit(listaEmpleados, tam))
                            {
                                printf("\nEl empleado ha sido modificado\n");
                            }

                            else
                            {
                                printf("\nError en la modificacion\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para modificar\n");
                        }

                        break;

                    case 5:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(!empleado_remove(listaEmpleados, tam))
                            {
                                printf("\nEl empleado ha sido eliminado\n");
                            }

                            else
                            {
                                printf("\nError en la baja\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para eliminar\n");
                        }

                        break;

                    case 6:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(!empleado_mostrarLista(listaEmpleados, tam))
                            {
                                printf("\nLista mostrada correctamente\n");
                            }

                            else
                            {
                                printf("\nNo se pudo mostrar la lista\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para mostrar\n");
                        }

                        break;

                    case 7:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(empleado_mostrarMenuOrdenamiento(listaEmpleados, tam))
                            {
                                printf("\nNo se pudo mostrar el menu de ordenamiento\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para ordenar\n");
                        }

                        break;

                    case 8:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(!empleado_existeArchivo(PATH_TXT, "r") ||
                               utn_respuestaEsAfirmativa("\nCuidado, se va a sobrescribir el archivo de texto. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!empleado_serializeToText(listaEmpleados, tam, PATH_TXT))
                                {
                                    printf("\nArchivo de texto escrito correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo escribir el archivo de texto\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo de texto\n");
                        }

                        break;

                    case 9:

                        if(!empleado_arrayIsEmpty(listaEmpleados, tam))
                        {
                            if(!empleado_existeArchivo(PATH_BIN, "rb") ||
                               utn_respuestaEsAfirmativa("\nCuidado, se va a sobrescribir el archivo binario. Desea continuar? (S/N): ", "Error. Solo S o N: ") == 1)
                            {
                                if(!empleado_serializeToBin(listaEmpleados, tam, PATH_BIN))
                                {
                                    printf("\nArchivo binario escrito correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo escribir el archivo binario\n");
                                }
                            }
                        }

                        else
                        {
                            printf("\nNo hay empleados cargados para guardar en el archivo binario\n");
                        }

                        break;

                    case 10:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
                        {
                            printf("\nHa salido del menu\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 10 || !flagExit);

        empleado_deleteArray(listaEmpleados, tam);
        listaEmpleados = NULL;
    }

    return 0;
}
