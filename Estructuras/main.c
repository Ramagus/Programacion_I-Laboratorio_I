#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#define TAMANIO 6 //10

int main()
{
    eAlumno arrayDeAlumnos[TAMANIO];

    int opcion;
    char auxNombre[50];
    int index;
    int retorno;
    int carga = 0;
    int encontrado = 0;
    int test = 0;

    inicializarAlumnos(arrayDeAlumnos, TAMANIO);

    do
    {
        printf("\tESTRUCTURAS\n\n");

        printf("1. Cargar\n");
        printf("2. Agregar\n");
        printf("3. Mostrar\n");
        printf("4. Buscar\n");
        printf("5. Borrar\n");
        printf("6. Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                if(test == 0 && cargarAlumnosTest(arrayDeAlumnos, TAMANIO) == 0)
                {
                    printf("\nAlumnos de prueba cargados\n");

                    carga = 1;

                    test = 1;
                }

                else
                {
                    printf("\nLos alumnos de prueba ya estan cargados\n");
                }

                break;

            case 2:

                if((test == 0 && contarLugaresLibres(arrayDeAlumnos, TAMANIO) > 5) || test == 1)
                {
                    cargarListado(arrayDeAlumnos, TAMANIO);

                    carga = 1;
                }

                else
                {
                    printf("\nDebe cargar los alumnos de prueba\n");
                }

                break;

            case 3:

                mostrarAlumnos(arrayDeAlumnos, TAMANIO, carga);

                break;

            case 4:

                if(carga == 1)
                {
                    mostrarAlumnos(arrayDeAlumnos, TAMANIO, carga);

                    printf("\nIngrese el nombre del alumno a buscar: ");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);

                    strlwr(auxNombre);
                    auxNombre[0] = toupper(auxNombre[0]);

                    index = buscarAlumnoPorNombre(arrayDeAlumnos, TAMANIO, auxNombre);

                    if(index != -1)
                    {
                        printf("\nAlumno encontrado\n");
                    }

                    else
                    {
                        printf("\nEl nombre ingresado no existe\n");
                    }
                }

                else
                {
                    printf("\nNo hay alumnos cargados\n");
                }

                encontrado = 1;

                break;

            case 5:

                if(carga == 1)
                {
                    if(encontrado == 0)
                    {
                        printf("\nError. Debe ingresar a la opcion de buscar primero\n");
                    }

                    else
                    {
                        retorno = borrarAlumno(arrayDeAlumnos, TAMANIO, auxNombre, index);

                        switch(retorno)
                        {
                            case 1:

                                printf("\n\nEl alumno ha sido eliminado\n");

                                break;

                            case 0:

                                printf("\n\nAccion cancelada por el usuario\n");

                                break;

                            case -1:

                                printf("\nNo se encontro al alumno\n");

                                break;

                            case -2:

                                printf("\nError\n");

                                break;
                        }

                        encontrado = 0;
                    }
                }

                else
                {
                    printf("\nError. No hay alumnos cargados\n");
                }

                break;

            case 6:

                printf("\nHa salido del menu\n");

                break;

            default:

                printf("\nError. Elija una opcion correcta\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcion != 6);

    return 0;
}
