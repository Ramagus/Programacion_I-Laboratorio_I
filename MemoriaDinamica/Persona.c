#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

ePersona* new_Persona()
{
    //ePersona unaPersona = {1000, 'M', 1.79};

    ePersona* puntero;

    //puntero = &unaPersona;

    puntero = (ePersona*) calloc(1, sizeof(ePersona));

    //puntero = (ePersona*) malloc(sizeof(ePersona));

    /*if(puntero != NULL)
    {
        puntero->legajo = 0;
        puntero->sexo = '\0';
        puntero->altura = 0;
    }*/

    return puntero;
}

ePersona* new_Persona_Parametros(int legajo, char sexo, float altura)
{
    ePersona* p = new_Persona(); //(ePersona*) malloc(sizeof(ePersona));

    if(p != NULL)
    {
        p->legajo = legajo;
        p->sexo = sexo;
        p->altura = altura;
    }

    return p;
}

void setLegajo(ePersona* unaPersona, int legajo)
{
    if(unaPersona != NULL && legajo > 0)
    {
        unaPersona->legajo = legajo;
    }
}

int getLegajo(ePersona* unaPersona)
{
    return unaPersona->legajo;
}

void delete_Persona(ePersona* unaPersona)
{
    free(unaPersona);
}

void mostrarPersona(ePersona* unaPersona)
{
    printf("%d--%c--%.2f\n", unaPersona->legajo, unaPersona->sexo, unaPersona->altura);
}
