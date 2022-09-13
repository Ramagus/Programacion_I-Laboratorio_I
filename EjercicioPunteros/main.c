#include <stdio.h>
#include <stdlib.h>

int cargarVector(int* vector, int tam);
int mostrarVector(int* vector, int tam);

int main()
{
    int vector[5];

    cargarVector(vector, 5);

    if(mostrarVector(vector, 5) == -1)
    {
        printf("Hubo un error");
    }

    return 0;
}

int cargarVector(int* vector, int tam)
{
    int retorno = -1;
    int i;

    if(vector != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", vector + i); //&vector[i]
        }

        retorno = 0;
    }

    return retorno;

}

int mostrarVector(int* vector, int tam)
{
    int retorno = -1;
    int i;

    if(vector != NULL && tam > 0)
    {
        printf("\n");

        for(i = 0; i < tam; i++)
        {
            printf("%d\n", *(vector + i)); //vector[i]
        }

        retorno = 0;
    }

    return retorno;
}
