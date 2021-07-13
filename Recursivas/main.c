#include <stdio.h>
#include <stdlib.h>

/** \brief Calcula el factorial de un número
 *
 * \param num Es el numéro al cual se le va a calcular el factorial
 *
 * \return Devuelve (-1) si el número pasado como parámetro es negativo
 *         o el resultado del factorial
 *
 */
unsigned long int factorial(int num);

int main()
{
    int numero;
    unsigned long int resultado;

    printf("Ingrese el numero a calcular: ");
    scanf("%d", &numero);

    resultado = factorial(numero);

    if(resultado == -1)
    {
        printf("\nNo se puede calcular el factorial de un numero negativo\n");
    }

    else
    {
        printf("\nEl factorial de %d es: %lu\n", numero, resultado);
    }

    return 0;
}

unsigned long int factorial(int num)
{
    /**FUNCION CON FOR*/

    /*unsigned long int resultado;
    int i;

    if(num < 0)
    {
        resultado = -1;
    }

    else
    {
        resultado = 1;

        for(i = num; i >= 1; i--)//for(i = 1; i <= num; i++)
        {
            resultado *= i;
        }
    }*/

    /**FUNCION RECURSIVA*/

    unsigned long int resultado;

    if(num < 0)
    {
        resultado = -1;
    }

    else if(num == 0)
    {
        resultado = 1;
    }

    else
    {
        resultado = num * factorial(num - 1);
    }

    return resultado;
}
