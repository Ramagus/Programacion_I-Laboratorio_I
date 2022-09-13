#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int main()
{
    int edad;
    float precio;
    char continuar;
    char nombre[100];
    int r;

    printf("\tFUNCION getInt\n\n");

    r = getInt(&edad, "Ingrese su edad: ", "Rango valido [1 - 100]: ", 1, 100);

    if(r == 0)
    {
        printf("\nUsted tiene: %d a%cos\n\n", edad, 164);
    }

    else
    {
        printf("\nNo se pudo cargar el dato correctamente\n\n");
    }

    system("pause");
    system("cls");

    printf("\tFUNCION getFloat\n\n");

    r = getFloat(&precio, "Ingrese un precio: ", "Rango valido [1 - 10000]: ", 1, 10000);

    if(r == 0)
    {
        printf("\nEl precio ingresado es: $%.2f\n\n", precio);
    }

    else
    {
        printf("\nNo se pudo cargar el dato correctamente\n\n");
    }

    system("pause");
    system("cls");

    printf("\tFUNCION getChar\n\n");

    r = getChar(&continuar, "Ingrese opcion [A][B][C]: ", "Solo [A][B][C]: ", 'A', 'C');

    if(r == 0)
    {
        printf("\nContinuar: %c\n\n", continuar);
    }

    else
    {
        printf("\nNo se pudo cargar el dato correctamente\n\n");
    }

    system("pause");
    system("cls");

    printf("\tFUNCION getString\n\n");

    r = getString(nombre, "Ingrese un nombre: ", "El largo debe ser entre 3 y 50: ", 3, 50);

    if(r == 0)
    {
        printf("\nEl nombre ingresado es: %s\n\n", nombre);
    }

    else
    {
        printf("\nNo se pudo cargar el dato correctamente\n\n");
    }

    system("pause");
    system("cls");

    return 0;
}
