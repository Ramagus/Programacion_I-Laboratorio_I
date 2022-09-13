#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1;
    char temp;
    int flagError = 0;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit <= hiLimit)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", message);

                flagError = 1;
            }

            else
            {
                printf("%s\a\a", eMessage);
            }

            fflush(stdin);

        } while((scanf("%d%c", input, &temp) != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;
}

int getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    int retorno = -1;
    char temp;
    int flagError = 0;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit <= hiLimit)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", message);

                flagError = 1;
            }

            else
            {
                printf("%s\a\a", eMessage);
            }

            fflush(stdin);

        } while((scanf("%f%c", input, &temp) != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;
}

int getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int retorno = -1;
    char temp;
    int flagError = 0;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit <= hiLimit)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", message);

                flagError = 1;
            }

            else
            {
                printf("%s\a\a", eMessage);
            }

            fflush(stdin);
            scanf("%c%c", input, &temp);

        } while((temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;
}

int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1;
    int length;
    int flagError = 0;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit <= hiLimit)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", message);

                flagError = 1;
            }

            else
            {
                printf("%s\a\a", eMessage);
            }

            if(fgets(input, hiLimit, stdin) != NULL)
            {
                if(strlen(input) < hiLimit)
                {
                    if(input[strlen(input) - 1] == '\n')
                    {
                        input[strlen(input) - 1] = '\0';
                    }
                }
            }

            length = strlen(input);

        } while(length < lowLimit || length > hiLimit);

        retorno = 0;
    }

    return retorno;
}
