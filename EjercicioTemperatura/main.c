/*
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit,
validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua
para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit
se hacen en otra biblioteca.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Temperatura.h"
#include "Conversion.h"

int main()
{
    float temp;

    float tempConvCel;
    float tempConvFah;

    int opcion;

    printf("Tipos de temperatura:\n");
    printf("1-Celsius\n");
    printf("2-Fahrenheit\n");

    printf("\nIngrese un tipo de temperatura: ");
    scanf("%d", &opcion);

    while(opcion != 1 && opcion != 2)
    {
        printf("Error. Ingrese un tipo valido: ");
        scanf("%d", &opcion);
    }

    switch(opcion)
    {
        case 1:

            printf("\nIngrese una temperatura entre 0 y 100: ");
            scanf("%f", &temp);

            if(validarRangoTemp(temp, 0, 100))
            {
                tempConvFah = convertirCelsius_A_Fahrenheit(temp);

                printf("\nLa temperatura de Celsius a Fahrenheit es: %g\n", tempConvFah);
            }

            else
            {
                printf("\nError. La temperatura Celsius debe ser entre 0 y 100\n");
            }

            break;

        case 2:

            printf("\nIngrese una temperatura entre 32 y 212: ");
            scanf("%f", &temp);

            if(validarRangoTemp(temp, 32, 212))
            {
                tempConvCel = convertirFahrenheit_A_Celsius(temp);

                printf("\nLa temperatura de Fahrenheit a Celsius es: %g\n", tempConvCel);
            }

            else
            {
                printf("\nError. La temperatura Fahrenheit debe ser entre 32 y 212\n");
            }

            break;
    }

    return 0;
}
