#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pVec;
    int* pAux;
    int i;

    printf("Lo inicializo\n\n");

    pVec = (int*) calloc(sizeof(int), 5);

    for(i = 0; i < 5; i++)
    {
        printf("%d\n", *(pVec + i));
    }

    /**Lo libero*/

    free(pVec);

    printf("\nLo cargo\n\n");

    pVec = (int*) malloc(sizeof(int) * 5);

    for(i = 0; i < 5; i++)
    {
        //*(pVec + i) = i + 1;

        printf("Ingrese un numero: ");
        scanf("%d", pVec + i);
    }

    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d\n", *(pVec + i));
    }

    printf("\nAgrego 5 mas\n\n");

    pAux = (int*) realloc(pVec, sizeof(int) * 10);

    if(pAux != NULL)
    {
        pVec = pAux;
    }

    for(i = 5; i < 10; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", pVec + i);
    }

    printf("\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", *(pVec + i));
    }

    printf("\nLo achico\n\n");

    pVec = (int*) realloc(pVec, sizeof(int) * 4);

    for(i = 0; i < 4; i++)
    {
        printf("%d\n", *(pVec + i));
    }

    /**Lo libero*/

    free(pAux);

    return 0;
}
