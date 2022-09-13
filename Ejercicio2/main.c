#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(int numero1, int numero2);

int main()
{
    int numero1;
    int numero2;
    int total;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    total = sumarNumeros(numero1, numero2);

    printf("\nEl resultado es: %d\n", total);

    return 0;
}

int sumarNumeros(int numero1, int numero2)
{
    int resultado;

    resultado = numero1 + numero2;

    return resultado;
}
