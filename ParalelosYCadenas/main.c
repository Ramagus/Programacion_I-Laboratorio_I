#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define LEN 20

int main()
{
    int legajo[T];
    char nombre[T][LEN];
    int auxInt;
    char auxString[LEN];
    int i;
    int j;

    for(i = 0; i < T; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\n");
    }

    for(i = 0; i < T - 1; i++)
    {
        for(j = i + 1; j < T; j++)
        {
            if(legajo[i] > legajo[j])
            {
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                strcpy(auxString, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString);
            }
        }
    }

    for(i = 0; i < T; i++)
    {
        printf("%d\t%s\n", legajo[i], nombre[i]);
    }

    return 0;
}
