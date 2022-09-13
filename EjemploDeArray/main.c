#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"
#define T 10

int main()
{
    int vectorDeNumeros[T] = {10, -5, 10, -6, -1, -4, 10, 5, 4, -6};
    int opcion;

    do
    {
        printf("\tMENU\n\n");

        printf("1. Cargar numeros\n");
        printf("2. Mostrar todo\n");
        printf("3. Mostrar negativos\n");
        printf("4. Mostrar promedio positivos\n");
        printf("5. Mostrar maximo\n");
        printf("6. Mostrar minimo\n");
        printf("7. Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                cargarVector(vectorDeNumeros, T);

                break;

            case 2:

                ordenarVector(vectorDeNumeros, T);
                mostrarVector(vectorDeNumeros, T);

                break;

            case 3:

                mostrarNegativos(vectorDeNumeros, T);

                break;

            case 4:

                mostrarPositivos(vectorDeNumeros, T);
                mostrarPromedioPositivos(vectorDeNumeros, T);

                break;

            case 5:

                mostrarMaximo(vectorDeNumeros, T);

                break;

            case 6:

                mostrarMinimo(vectorDeNumeros, T);

                break;

            case 7:

                printf("\nUsted ha salido del menu\n");

                break;

            default:

                printf("\nError. Ingrese una opcion valida\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcion != 7);

    return 0;
}
