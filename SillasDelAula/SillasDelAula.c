#include <stdio.h>
#include <stdlib.h>
#include "SillasDelAula.h"

void inicializarArray(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad, int valorInicial)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
       arrayDeSillas[i] = valorInicial;
       arrayDeLegajos[i] = valorInicial;
       arrayDeEdades[i] = valorInicial;
    }
}

void hardcodearSillas(int arrayDeSillas[], int cantidad)
{
    int otroArrayDeSillas[] = {55, 11, 22, 33, 44};
    int i;

    for(i = 0; i < cantidad; i++)
    {
        arrayDeSillas[i] = otroArrayDeSillas[i];
    }
}

void harcodearLegajos(int arrayDeLegajos[], int cantidad)
{
    int otroArrayDeLegajos[] = {100, 300, 200, 500, 400};
    int i;

    for(i = 0; i < cantidad; i++)
    {
        arrayDeLegajos[i] = otroArrayDeLegajos[i];
    }
}

void harcodearEdades(int arrayDeEdades[], int cantidad)
{
    int otroArrayDeEdades[] = {18, 19, 81, 91, 98};
    int i;

    for(i = 0; i < cantidad; i++)
    {
        arrayDeEdades[i] = otroArrayDeEdades[i];
    }
}

void mostrarTodo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad)
{
    int i, j;
    int auxSillas, auxLegajos, auxEdades;

    for(i = 0; i < cantidad - 1; i++)
    {
        for(j = i + 1; j < cantidad; j++)
        {
            if(arrayDeSillas[i] > arrayDeSillas[j])
            {
                auxSillas = arrayDeSillas[i];
                arrayDeSillas[i] = arrayDeSillas[j];
                arrayDeSillas[j] = auxSillas;
            }

            if(arrayDeLegajos[i] > arrayDeLegajos[j])
            {
                auxLegajos = arrayDeLegajos[i];
                arrayDeLegajos[i] = arrayDeLegajos[j];
                arrayDeLegajos[j] = auxLegajos;
            }

            if(arrayDeEdades[i] > arrayDeEdades[j])
            {
                auxEdades = arrayDeEdades[i];
                arrayDeEdades[i] = arrayDeEdades[j];
                arrayDeEdades[j] = auxEdades;
            }
        }
    }

    printf("Silla\t\tLegajo\t\tEdad\n");

    for(i = 0; i < cantidad; i++)
    {
        printf("\n%d", arrayDeSillas[i]);
        printf("\t\t%d", arrayDeLegajos[i]);
        printf("\t\t%d", arrayDeEdades[i]);
    }
}

void calcularMinimo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad)
{
    int i;
    int minimoSillas;
    int minimoLegajos;
    int minimoEdades;

    printf("\n\nSilla del mas joven\tLegajo del mas joven\tEdad del mas joven\n");

    for(i = 0; i < cantidad; i++)
    {
        if(i == 0 || arrayDeSillas[i] < minimoSillas || arrayDeLegajos[i] < minimoLegajos || arrayDeEdades[i] < minimoEdades)
        {
            minimoSillas = arrayDeSillas[i];
            minimoLegajos = arrayDeLegajos[i];
            minimoEdades = arrayDeEdades[i];
        }
    }

    printf("\n%d", minimoSillas);
    printf("\t\t\t%d", minimoLegajos);
    printf("\t\t\t%d", minimoEdades);
}

void calcularMaximo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad)
{
    int i;
    int maximoSillas;
    int maximoLegajos;
    int maximoEdades;

    printf("\n\nSilla del mas viejo\tLegajo del mas viejo\tEdad del mas viejo\n");

    for(i = 0; i < cantidad; i++)
    {
        if(i == 0 || arrayDeSillas[i] > maximoSillas || arrayDeLegajos[i] > maximoLegajos || arrayDeEdades[i] > maximoEdades)
        {
            maximoSillas = arrayDeSillas[i];
            maximoLegajos = arrayDeLegajos[i];
            maximoEdades = arrayDeEdades[i];
        }
    }

    printf("\n%d", maximoSillas);
    printf("\t\t\t%d", maximoLegajos);
    printf("\t\t\t%d", maximoEdades);
}

int estaLibre(int arrayDeSillas[], int cantidad, int indice, int valorInicial)
{
    int retorno = -1;

    if(arrayDeSillas != NULL && cantidad > 0 && (indice > -1 && indice < cantidad))
    {
        retorno = 0;

        if(arrayDeSillas[indice] == valorInicial)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ocuparSilla(int arrayDeSillas[], int cantidad, int indice, int valorInicial, int legajo)
{
    int retorno = -1;
    int estaLibreLaSilla;

    if(arrayDeSillas != NULL && cantidad > 0 && (indice > -1 && indice < cantidad))
    {
        estaLibreLaSilla = estaLibre(arrayDeSillas, cantidad, indice, valorInicial);

        if(estaLibreLaSilla == 1)
        {
            arrayDeSillas[indice] = legajo;
            retorno = 0;
        }
    }

    return retorno;
}

int cantidadSillasOcupadas(int arrayDeSillas[], int cantidad, int valorInicial)
{
    int i;
    int contador = 0;

    for(i = 0; i < cantidad; i++)
    {
        if(arrayDeSillas[i] != valorInicial)
        {
            contador++;
        }
    }

    return contador;
}

int cantidadSillasLibres(int arrayDeSillas[], int cantidad, int valorInicial)
{
    int i;
    int contador = 0;

    for(i = 0; i < cantidad; i++)
    {
        if(arrayDeSillas[i] == valorInicial)
        {
            contador++;
        }
    }

    return contador;
}

int indiceDeLaPrimeraSillaLibre(int arrayDeSillas[], int cantidad, int valorInicial)
{
    int i;
    int retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(arrayDeSillas[i] == valorInicial)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
