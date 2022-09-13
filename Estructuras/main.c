#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Alumno.h"
#define TAM 10

int main()
{
    eAlumno lista[TAM];

    int opcion;
    int retornoFuncion;
    int flagHardCode = 0;
    int flagExit = 0;

    if(!eAlumno_inicializar(lista, TAM))
    {
        do
        {
            retornoFuncion = eAlumno_mostrarMenuPrincipal(&opcion);

            if(retornoFuncion == 0)
            {
                switch(opcion)
                {
                    case 1:

                        retornoFuncion = eAlumno_cargar(lista, TAM);

                        switch(retornoFuncion)
                        {
                            case 0:

                                printf("\nAlumno ingresado con exito\n");

                                break;

                            case -1:

                                printf("\nEl legajo ingresado ya existe\n");

                                break;

                            case -2:

                                printf("\nNo se cargo correctamente el alumno\n");

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

                    case 2:

                        if(!eAlumno_arrayIsEmpty(lista, TAM))
                        {
                            retornoFuncion = eAlumno_eliminar(lista, TAM);

                            switch(retornoFuncion)
                            {
                                case -3:

                                    printf("\nError. No se pudo eliminar al alumno\n");

                                    break;

                                case -2:

                                    printf("\nEl legajo ingresado no existe\n");

                                    break;

                                case -1:

                                    printf("\nAccion cancelada por el usuario\n");

                                    break;

                                case 0:

                                    printf("\nEl alumno ha sido eliminado\n");

                                    break;
                            }
                        }

                        else
                        {
                            printf("\nNo hay alumnos cargados para eliminar\n");
                        }

                        break;

                    case 3:

                        if(!eAlumno_arrayIsEmpty(lista, TAM))
                        {
                            retornoFuncion = eAlumno_modificar(lista, TAM);

                            switch(retornoFuncion)
                            {
                                case -3:

                                    printf("\nError. No se pudo modificar al alumno\n");

                                    break;

                                case -2:

                                    printf("\nEl legajo ingresado no existe\n");

                                    break;

                                case -1:

                                    printf("\nAccion cancelada por el usuario\n");

                                    break;

                                case 0:

                                    printf("\nEl alumno ha sido modificado\n");

                                    break;
                            }
                        }

                        else
                        {
                            printf("\nNo hay alumnos cargados para modificar\n");
                        }

                        break;

                    case 4:

                        if(!eAlumno_arrayIsEmpty(lista, TAM))
                        {
                            if(eAlumno_mostrarMenuOrdenamiento(lista, TAM))
                            {
                                printf("\nNo se pudo mostrar el menu de ordenamiento\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay alumnos para ordenar\n");
                        }

                        break;

                    case 5:

                        if(!eAlumno_arrayIsEmpty(lista, TAM))
                        {
                            if(!eAlumno_mostrarLista(lista, TAM))
                            {
                                printf("\nLista mostrada correctamente\n");
                            }

                            else
                            {
                                printf("\nNo se puede mostrar los alumnos\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay alumnos para mostrar\n");
                        }

                        break;

                    case 6:

                        if(!flagHardCode)
                        {
                            if(!eAlumno_hardCodear(lista, TAM))
                            {
                                printf("\nAlta forzada realizada correctamente\n");

                                flagHardCode = 1;
                            }

                            else
                            {
                                printf("\nError en el alta forzada\n");
                            }
                        }

                        else
                        {
                            printf("\nYa se ha realizado el alta forzada\n");
                        }

                        break;

                    case 7:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            else if(retornoFuncion == -1)
            {
                printf("\nNo se cargo correctamente la opcion\n");
            }

            else
            {
                printf("\nError. No se puede mostrar el menu\n");
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 7 || !flagExit);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
