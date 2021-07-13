#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unNumero;
    float otroNumero;
    float suma;
    char letra;

    printf("Ingrese un numero entero: ");
    scanf("%d", &unNumero);

    printf("Ingrese un numero con coma: ");
    scanf("%f", &otroNumero);

    printf("\nLos numeros son: %d y %.2f\n", unNumero, otroNumero);

    suma = unNumero + otroNumero;
    printf("\nLa suma es: %.2f\n\n", suma);

    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf("%c", &letra);

    printf("\nLa letra es: %c\n", letra);

    return 0;
}
