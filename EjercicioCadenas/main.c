/*
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gómez, la salida debería ser:
Gomez, Juan Ignacio
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 25
#define MAX 100

int esAlfabetica(char cadena[], int limite);
int getString(char mensaje[], char mensajeError[], char cadena[], int limite);
int formatearNombre_Y_Apellido(char cadena[], int limite);

int main()
{
    char nombre[TAM];
    char apellido[TAM];
    char apellido_Y_Nombre[MAX];
    //char auxString[MAX];
    ///Con For
    //int i;
    //int len;
    ///Con While
    //int i = 0;

    /*
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString) >= TAM)
    {
        printf("Reingrese su nombre: ");
        fflush(stdin);
        gets(auxString);
    }

    strcpy(nombre, auxString);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString) >= TAM)
    {
        printf("Reingrese su apellido: ");
        fflush(stdin);
        gets(auxString);
    }

    strcpy(apellido, auxString);

    strcpy(apellido_Y_Nombre, apellido);
    strcat(apellido_Y_Nombre, ", ");
    strcat(apellido_Y_Nombre, nombre);

    strlwr(apellido_Y_Nombre);
    apellido_Y_Nombre[0] = toupper(apellido_Y_Nombre[0]);
    */

    ///Sin Length
    /*
    while(apellido_Y_Nombre[i] != '\0')
    {
        if(apellido_Y_Nombre[i] == ' ')
        {
            apellido_Y_Nombre[i + 1] = toupper(apellido_Y_Nombre[i + 1]);
        }

        i++;
    }
    */

    ///Con Length
    /*
    len = strlen(apellido_Y_Nombre);

    for(i = 0; i < len; i++)
    {
        if(isspace(apellido_Y_Nombre[i]))
        {
            apellido_Y_Nombre[i + 1] = toupper(apellido_Y_Nombre[i + 1]);
        }
    }
    */

    //puts(apellido_Y_Nombre);


    getString("Ingrese su nombre: ", "Reingrese su nombre: ", nombre, TAM);
    getString("Ingrese su apellido: ", "Reingrese su apellido: ", apellido, TAM);

    //strncpy(apellido_Y_Nombre, apellido, MAX);
    //strncat(apellido_Y_Nombre, ", ", MAX);
    //strncat(apellido_Y_Nombre, nombre, MAX);

    snprintf(apellido_Y_Nombre, MAX, "%s, %s", apellido, nombre);

    formatearNombre_Y_Apellido(apellido_Y_Nombre, MAX);

    printf("\n");
    fputs(apellido_Y_Nombre, stdout);


    return 0;
}

int esAlfabetica(char cadena[], int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int getString(char mensaje[], char mensajeError[], char cadena[], int limite)
{
    int retorno = -1;
    int len;
    int flag = 0;

    if(mensaje != NULL && mensajeError != NULL && cadena != NULL && limite > 0)
    {
        do
        {
            if(!flag)
            {
                printf("%s", mensaje);
                flag = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            fflush(stdin);
            fgets(cadena, limite, stdin);

        } while(!esAlfabetica(cadena, limite));

        len = strnlen(cadena, limite);

        if(len < limite && cadena[len - 1] == '\n')
        {
            cadena[len - 1] = '\0';
        }

        retorno = 0;
    }

    return retorno;
}

int formatearNombre_Y_Apellido(char cadena[], int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        strlwr(cadena);

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(i == 0 || isspace(cadena[i - 1]))
            {
                cadena[i] = toupper(cadena[i]);
            }
        }

        retorno = 0;
    }

    return retorno;
}
