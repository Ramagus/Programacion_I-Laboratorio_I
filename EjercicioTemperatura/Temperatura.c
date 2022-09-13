#include "Temperatura.h"

int validarRangoTemp(float temperatura, float min, float max)
{
    int retorno = 0;

    if(temperatura > min && temperatura < max)
    {
        retorno = 1;
    }

    return retorno;
}
