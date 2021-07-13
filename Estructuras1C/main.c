#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include "Localidad.h"
#define A 5
#define L 3

int main()
{
    eAlumno arrayAlumnos[A];
    eLocalidad arrayLocalidades[L]; //= {{1, "Avellaneda", 1870}, {2, "Wilde", 1875}, {3, "Lanus", 1824}};

    int opcion;
    int respuesta;
    int auxLegajo;

    inicializarAlumnos(arrayAlumnos, A);

    hardCodearAlumnos(arrayAlumnos, A, 3);
    hardCodearLocalidades(arrayLocalidades, L);

    do
    {
        printf("\tMENU\n\n");

        printf("1. Cargar\n");
        printf("2. Mostrar Alumnos\n");
        printf("3. Ordenar\n");
        printf("4. Eliminar\n");
        printf("5. Modificar\n");
        printf("6. Mostrar Alumnos con Localidades\n");
        printf("7. Mostrar Localidades\n");
        printf("8. Mostrar cada alumno de cada localidad\n");
        printf("9. Mostrar Alumnos que viven en Avellaneda\n");
        printf("10. Mostrar Localidad con menos alumnos\n");
        printf("11. Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                cargarListadoAlumnos(arrayAlumnos, A);

                break;

            case 2:

                mostrarListadoAlumnos(arrayAlumnos, A);

                break;

            case 3:

                sortStudentsByNameAndAverage(arrayAlumnos, A);

                break;

            case 4:

                respuesta = eliminarAlumno(arrayAlumnos, A, arrayLocalidades, L);

                switch(respuesta)
                {
                    case 0:

                        printf("\n\nAccion cancelada por el usuario\n");

                        break;

                    case 1:

                        printf("\n\nEl alumno ha sido eliminado\n");

                        break;

                    case -1:

                        printf("\nEl legajo ingresado no existe\n");

                        break;
                }

                break;

            case 5:

                mostrarListadoAlumnosConLocalidad(arrayAlumnos, A, arrayLocalidades, L);

                printf("\nIngrese el legajo del alumno a modificar: ");
                scanf("%d", &auxLegajo);

                respuesta = modificarAlumno(arrayAlumnos, A, auxLegajo, arrayLocalidades, L);

                switch(respuesta)
                {
                    case 0:

                        printf("\n\nAccion cancelada por el usuario\n");

                        break;

                    case 1:

                        printf("\n\nEl alumno ha sido modificado\n");

                        break;

                    case -1:

                        printf("\nEl legajo ingresado no existe\n");

                        break;
                }

                break;

            case 6:

                mostrarListadoAlumnosConLocalidad(arrayAlumnos, A, arrayLocalidades, L);

                break;

            case 7:

                mostrarListadoLocalidades(arrayAlumnos, A, arrayLocalidades, L);

                break;

            case 8:

                mostrarAlumnosPorLocalidad(arrayAlumnos, A, arrayLocalidades, L);

                break;

            case 9:

                mostrarAlumnosDeAvellaneda(arrayAlumnos, A, arrayLocalidades, L);

                break;

            case 10:

                mostrarLocalidadConMenosAlumnos(arrayAlumnos, A, arrayLocalidades, L);

                break;

            case 11:

                printf("\nHa salido del menu\n");

                break;

            default:

                printf("\nError. Elija una opcion correcta\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcion != 11);

    return 0;
}
