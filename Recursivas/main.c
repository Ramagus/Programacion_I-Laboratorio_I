#include <stdio.h>
#include <stdlib.h>


/** \brief Calcula el factorial de un número de forma iterativa
 *
 * \param n int Es el numéro al cual se le va a calcular el factorial
 * \param pResultado unsigned long int* Lugar donde se va a guardar el resultado del factorial
 *
 * \return int Devuelve (-1) si hubo un error
 *                      ( 0) si está todo ok
 *
 */
int factIter(int n, unsigned long int* pResultado);


/** \brief Calcula el factorial de un número de forma recursiva
 *
 * \param n int Es el numéro al cual se le va a calcular el factorial
 *
 * \return unsigned long int Devuelve (-1) si el número pasado como parámetro es negativo
 *                                     o el resultado del factorial
 *
 */
unsigned long int factRec(int n);


/** \brief Solicita un número al usuario y lo valida
 *
 * \param input Se carga el número ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 *
 * \return Si obtuvo el número [0] si no [-1]
 *
 */
int getInt(int* input, char message[], char eMessage[]);


int main()
{
    int num;
    unsigned long int resultado;

    printf("\tFACTORIAL\n\n");

    if(!getInt(&num, "Ingrese el numero a calcular: ", "Error. Solo numeros enteros: "))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tFACTORIAL ITERATIVO\n\n");

        if(factIter(num, &resultado))
        {
            printf("No se puede calcular el factorial de un numero negativo\n");
        }

        else
        {
            printf("%d! = %lu\n", num, resultado);
        }

        printf("\n");
        system("pause");
        system("cls");

        printf("\tFACTORIAL RECURSIVO\n\n");

        resultado = factRec(num);

        if(resultado == -1)
        {
            printf("No se puede calcular el factorial de un numero negativo\n");
        }

        else
        {
            printf("%d! = %lu\n", num, resultado);
        }
    }

    else
    {
        printf("Error");
    }

    return 0;
}

int factIter(int n, unsigned long int* pResultado)
{
    int retorno = -1;
    int i;

    if(n >= 0 && pResultado != NULL)
    {
        *pResultado = 1;

        for(i = 2; i <= n; i++)
        {
            (*pResultado) *= i;
        }

        retorno = 0;
    }

    return retorno;
}

unsigned long int factRec(int n)
{
    unsigned long int retorno;

    if(n < 0)
    {
        retorno = -1;
    }

    else if(n == 0)
    {
        retorno = 1;
    }

    else
    {
        retorno = n * factRec(n - 1);
    }

    return retorno;
}

int getInt(int* input, char message[], char eMessage[])
{
    int retorno = -1;
    char temp;
    int flagError = 0;

    if(input != NULL && message != NULL && eMessage != NULL)
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
                printf("%s", eMessage);
            }

            fflush(stdin);

        } while((scanf("%d%c", input, &temp) != 2 || temp != '\n'));

        retorno = 0;
    }

    return retorno;
}
