#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 100;
    int* pEntero;
    int* pOtroEntero;

    pEntero = &x;

    //* Operador de inacceso
    //& Operador de direccion
    //-> Estructuras

    if(pEntero != NULL)
    {
        pOtroEntero = pEntero;

        printf("%d\n\n", *pEntero);

        *pEntero = 700;

        printf("%d\n", *pOtroEntero);
    }

    else
    {
        printf("Error\n");
    }

    return 0;
}
