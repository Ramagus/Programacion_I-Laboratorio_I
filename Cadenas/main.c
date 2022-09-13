#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char palabra[10];
    char otraPalabra[100];
    int largoCad;
    //int comp;

    printf("Ingrese una palabra: ");
    fflush(stdin);
    //gets(palabra);
    scanf("%[^\n]", palabra);
    //fgets(palabra, 10, stdin);

    /*char letra = 'P';
    letra = tolower(letra);*/

    /*char letra = 'p';
    letra = toupper(letra);*/

    //strupr(palabra);
    //strlwr(palabra);

    strcat(palabra, otraPalabra);

    printf("\n%s\n", palabra);

    //strcpy(palabra, otraPalabra);

    /*comp = stricmp(palabra, otraPalabra);

    printf("\nLa comparacion es: %d\n", comp);*/

    largoCad = strlen(palabra);

    //palabra[largoCad - 1] = '\0';

    printf("\nEl largo de la cadena es: %d\n", largoCad);

    return 0;
}
