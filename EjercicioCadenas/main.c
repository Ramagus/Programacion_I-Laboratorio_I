#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char apellido[15] = "QUINTANA";
    char nombre[15];
    char apellidoNombre[31];
    char auxString[1000];
    int i;
    int len;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString) > 14)
    {
        printf("Reingrese su nombre: ");
        fflush(stdin);
        gets(auxString);
    }

    strcpy(nombre, auxString);

    strcpy(apellidoNombre, apellido);
    strcat(apellidoNombre, ", ");
    strcat(apellidoNombre, nombre);

    strlwr(apellidoNombre);
    apellidoNombre[0] = toupper(apellidoNombre[0]);

    /*
    isspace
    isdigit
    isalpha
    */

    len = strlen(apellidoNombre);

    for(i = 0; i < len; i++)
    {
        if(isspace(apellidoNombre[i]))
        {
            apellidoNombre[i + 1] = toupper(apellidoNombre[i + 1]);
        }
    }

    puts(apellidoNombre);

    return 0;
}
