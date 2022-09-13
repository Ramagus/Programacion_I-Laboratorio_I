#include <stdio.h>
#include <stdlib.h>

/*Crear un proyecto donde se pide ingresar 5 valores de dinero, siendo el maximo importe en dolares.

    P(Peso) = 505
    L(Libra) = 50
    D(Dolar) = -500
    B(Bitcoin) = 88
    P(Peso) = 100

Luego, validar el tipo de dinero, y calcular el promedio y el porcentaje de pesos ingresados.*/

int main()
{
    int dinero;
    char tipo;
    int i;
    int maximoImporteEnDolares;
    int esElPrimerDolar = 0;
    int acumuladorPesos = 0;
    int contadorPesos = 0;
    float promedioPesos;
    float porcentajePesos;

    for(i = 0; i < 5; i++)
    {
        printf("Ingrese la cantidad de dinero: ");
        scanf("%d", &dinero);

        printf("\nIngrese el tipo de dinero: ");
        fflush(stdin);
        scanf("%c", &tipo);

        while(tipo != 'P' && tipo != 'L' && tipo != 'D' && tipo != 'B')
        {
            printf("Error. Ingrese un tipo de dinero valido: ");
            fflush(stdin);
            scanf("%c", &tipo);
        }

        if(tipo == 'D')
        {
            if(esElPrimerDolar == 0 || dinero > maximoImporteEnDolares)
            {
                maximoImporteEnDolares = dinero;
                esElPrimerDolar = 1;
            }
        }

        else if(tipo == 'P')
        {
            acumuladorPesos += dinero;
            contadorPesos++;
        }

        printf("\n");
    }

    promedioPesos = (float) acumuladorPesos / contadorPesos;
    porcentajePesos = ((float) contadorPesos * i) / 100;

    printf("\nEl maximo importe en dolares es: %d", maximoImporteEnDolares);
    printf("\nEl promedio de pesos es: %.2f", promedioPesos);
    printf("\nEl porcentaje de pesos es: %.2f\n", porcentajePesos);

    return 0;
}
