#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float peso;

} eDato;

int main()
{
    FILE* pArchivo;

    char miNombre[] = "Ramiro";
    char cadena[50];
    int k = 9;
    int x;
    int vector[] = {1, 2, 3, 4, 5};
    int array[5];

    eDato miDato = {100, "Agustin", 65};
    eDato unDato;

    int i;
    int tamVec;
    int tamArray;

    /**Escritura de Texto*/

    printf("\tARCHIVO DE TEXTO\n\n");

    pArchivo = fopen("miArchivo.txt", "w");

    if(pArchivo != NULL)
    {
        fprintf(pArchivo, "Mi nombre es: %s\nEl dia esta nublado", miNombre);

        fclose(pArchivo);
    }

    /**Lectura de Texto*/

    pArchivo = fopen("miArchivo.txt", "r");

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            fgets(cadena, sizeof(cadena) - 1, pArchivo);
            //printf("%s", cadena);
            fputs(cadena, stdout);
        }

        fclose(pArchivo);
    }

    /**Escritura Binaria*/

    printf("\n\n\tARCHIVO BINARIO\n\n");

    pArchivo = fopen("miArchivo.bin", "wb");

    if(pArchivo != NULL)
    {
        fwrite(&k, sizeof(int), 1, pArchivo);

        tamVec = sizeof(vector) / sizeof(int);

        fwrite(vector, sizeof(int), tamVec, pArchivo);

        fwrite(&miDato, sizeof(eDato), 1, pArchivo);

        fclose(pArchivo);
    }

    /**Lectura Binaria*/

    pArchivo = fopen("miArchivo.bin", "rb");

    if(pArchivo != NULL)
    {
        fread(&x, sizeof(int), 1, pArchivo);

        printf("Numero: %d\n", x);

        tamArray = sizeof(array) / sizeof(int);

        fread(array, sizeof(int), tamArray, pArchivo);

        printf("\nElementos del vector: ");

        for(i = 0; i < tamArray; i++)
        {
            printf("%d ", *(array + i));
        }

        fread(&unDato, sizeof(eDato), 1, pArchivo);

        printf("\n\nLEGAJO\t\tNOMBRE\t\tPESO\n");

        printf("\n%d\t\t%s\t\t%.2f\n", unDato.legajo, unDato.nombre, unDato.peso);

        fclose(pArchivo);
    }

    return 0;
}
