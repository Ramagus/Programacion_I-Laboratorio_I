#include <stdio.h>
#include <stdlib.h>
#include "SillasDelAula.h"
#define CANTIDAD 5
#define VALOR_INICIAL 0

int main()
{
    int arrayDeSillas[CANTIDAD];
    int arrayDeLegajos[CANTIDAD];
    int arrayDeEdades[CANTIDAD];
    int sillasOcupadas;
    int sillasLibres;
    int primerIndice;

    inicializarArray(arrayDeSillas, arrayDeLegajos, arrayDeEdades, CANTIDAD, VALOR_INICIAL);
    hardcodearSillas(arrayDeSillas, CANTIDAD);
    harcodearLegajos(arrayDeLegajos, CANTIDAD);
    harcodearEdades(arrayDeEdades, CANTIDAD);
    mostrarTodo(arrayDeSillas, arrayDeLegajos, arrayDeEdades, CANTIDAD);
    calcularMinimo(arrayDeSillas, arrayDeLegajos, arrayDeEdades, CANTIDAD);
    calcularMaximo(arrayDeSillas, arrayDeLegajos, arrayDeEdades, CANTIDAD);

    sillasOcupadas = cantidadSillasOcupadas(arrayDeSillas, CANTIDAD, VALOR_INICIAL);
    printf("\n\nLa cantidad de sillas ocupadas es: %d\n", sillasOcupadas);

    sillasLibres = cantidadSillasLibres(arrayDeSillas, CANTIDAD, VALOR_INICIAL);
    printf("\nLa cantidad de sillas libres es: %d\n", sillasLibres);

    primerIndice = indiceDeLaPrimeraSillaLibre(arrayDeSillas, CANTIDAD, VALOR_INICIAL);

    if(primerIndice != -1)
    {
        printf("\nLa primera silla libre esta en el indice: %d\n", primerIndice);
    }

    else
    {
        printf("\nNo hay silla libre\n");
    }

    /*if(ocuparSilla(arrayDeSillas, CANTIDAD, 1, VALOR_INICIAL, 100) == -1)
    {
        printf("\nNo se puede usar esa silla\n");
    }

    else
    {
        printf("\nEsta silla esta disponible\n");
    }*/

    return 0;
}
