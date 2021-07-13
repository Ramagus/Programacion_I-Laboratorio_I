#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    ePersona* puntero = new_Persona_Parametros(1000, 'M', 1.98);

    setLegajo(puntero, 1001);

    if(puntero != NULL)
    {
        printf("La persona es:\n\n");

        if(getLegajo(puntero) > 1000)
        {
            mostrarPersona(puntero);
        }

        delete_Persona(puntero);
    }

    return 0;
}
