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
}

void ordenarVector(int vector[], int tam)
{
    int i;
    int j;
    int aux;

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

void mostrarVector(int vector[], int tam)
{
    int i;

    printf("\n\tMuestro el vector\n\n");

    for(i = 0; i < tam; i++)
    {
        printf("%d\n", vector[i]);
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
}

void mostrarPositivos(int vector[], int tam)
{
    int i;

    printf("\n\tMuestro solo los positivos\n\n");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] > 0)
        {
            printf("%d\n", vector[i]);
        }
    }
}

float calcularPromedioPositivos(int vector[], int tam)
{
    int i;
    int sumaDePositivos = 0;
    int contadorDePositivos = 0;
    float promedioPositivos;

    for(i = 0; i < tam; i++)
    {
        if(vector[i] > 0)
        {
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

    printf("\nPromedio de positivos: %.2f\n", promedioPositivos);
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
    int i;
    int maximo;
    int flag = 0;

    maximo = calcularMaximo(vector, tam);

    printf("\nEl maximo: %d\n", maximo);

    printf("\nIndices: ");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] == maximo)
        {
            if(flag)
            {
                printf(" - ");
            }

            printf("%d", i);
            flag = 1;
        }
    }

    printf("\n");
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
    int i;
    int minimo;
    int flag = 0;

    minimo = calcularMinimo(vector, tam);

    printf("\nEl minimo: %d\n", minimo);

    printf("\nIndices: ");

    for(i = 0; i < tam; i++)
    {
        if(vector[i] == minimo)
        {
            if(flag)
            {
                printf(" - ");
            }

            printf("%d", i);
            flag = 1;
        }
    }

    printf("\n");
}
