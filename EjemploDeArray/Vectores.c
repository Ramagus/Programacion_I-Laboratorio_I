#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"

void cargarVector(int vector[], int tam)
{
    int i;

    printf("\n\tCarga de datos\n\n");

    for(i = 0; i < tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }

    printf("\n");
}

void ordenarVector(int vector[], int tam)
{
    int i;
    int j;
    int aux;

    printf("\n\tMuestro el vector\n\n");

    for(i = 0; i < tam; i++)
    {
        printf("%d\n", vector[i]);
    }

    printf("\n");

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(vector[i] > vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void mostrarNegativos(int vector[], int tam)
{
    int i;

    printf("\n\tMuestro solo los negativos\n\n");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] < 0)
        {
            printf("%d\n", vector[i]);
        }
    }

    printf("\n");
}

float calcularPromedioPositivos(int vector[], int tam)
{
    int i;
    int sumaDePositivos = 0;
    int contadorDePositivos = 0;
    float promedioPositivos;

    printf("\n\tMuestro solo los positivos\n\n");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] > 0)
        {
            printf("%d\n", vector[i]);

            sumaDePositivos += vector[i];
            contadorDePositivos++;
        }
    }

    printf("\nSuma: %d -- Cantidad: %d\n", sumaDePositivos, contadorDePositivos);

    promedioPositivos = (float) sumaDePositivos / contadorDePositivos;

    return promedioPositivos;
}

void mostrarPromedioPositivos(int vector[], int tam)
{
    float promedioPositivos;

    promedioPositivos = calcularPromedioPositivos(vector, tam);

    printf("\nPromedio de positivos: %.2f\n\n", promedioPositivos);
}

int calcularMaximo(int vector[], int tam)
{
    int i;
    int maximo;

    for(i = 0; i < tam; i++)
    {
        if(i == 0 || vector[i] > maximo)
        {
            maximo = vector[i];
        }
    }

    return maximo;
}

void mostrarMaximo(int vector[], int tam)
{
    int maximo;
    int i;

    maximo = calcularMaximo(vector, tam);

    printf("\nEl maximo: %d\n", maximo);

    printf("Indices: ");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] == maximo)
        {
            printf("%d-", i);
        }
    }

    printf("\n\n");
}

int calcularMinimo(int vector[], int tam)
{
    int i;
    int minimo;

    for(i = 0; i < tam; i++)
    {
        if(i == 0 || vector[i] < minimo)
        {
            minimo = vector[i];
        }
    }

    return minimo;
}

void mostrarMinimo(int vector[], int tam)
{
    int minimo;
    int i;

    minimo = calcularMinimo(vector, tam);

    printf("\nEl minimo: %d\n", minimo);

    printf("Indices: ");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] == minimo)
        {
            printf("%d-", i);
        }
    }

    printf("\n\n");
}
