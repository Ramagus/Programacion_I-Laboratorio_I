#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Input.h"
#include "Nexo.h"


int ePersona_cargarUno(ePersona* unaPersona, eLocalidad listaL[], int tamL, int* idPersona)
{
    int retorno = -1;
    int indice;

    if(unaPersona != NULL && listaL != NULL && tamL > 0 && idPersona != NULL &&
       !utn_getAlfabetico(unaPersona->nombre, "\nIngrese Nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
       !utn_formatearCadena(unaPersona->nombre, NOMBRE_LEN) &&
       !utn_getSexo(&unaPersona->sexo, "\nIngrese Sexo (F/M): ", "Error. Solo F/M: ", 2) &&
       !utn_getNumero(&unaPersona->edad, "\nIngrese Edad entre 1 y 100: ", "Error. Solo numeros enteros: ", 1, 100, 2) &&
       !utn_getNumeroFlotante(&unaPersona->altura, "\nIngrese Altura: ", "Error. Solo numeros flotantes: ", 1.5, 2.5, 2) &&
       !eLocalidad_mostrarLista(listaL, tamL) &&
       !utn_getNumero(&unaPersona->idLocalidad, "\nIngrese ID de Localidad: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
       !eLocalidad_buscarPorId(listaL, tamL, unaPersona->idLocalidad, &indice))
    {
        unaPersona->id = *idPersona;
        unaPersona->isEmpty = FALSE_PER;

        (*idPersona)++;

        retorno = 0;
    }

    return retorno;
}

int ePersona_cargarEnArray(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona, int* idPersona)
{
    int retorno = -1;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && indicePersona >= 0 && indicePersona < tamP &&
       listaP[indicePersona].isEmpty && idPersona != NULL && !ePersona_cargarUno(&listaP[indicePersona], listaL, tamL, idPersona))
    {
        retorno = 0;
    }

    return retorno;
}

int ePersona_modificar(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona)
{
    int retorno = -1;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && indicePersona >= 0 && indicePersona < tamP &&
       !listaP[indicePersona].isEmpty && !ePersona_mostrarMenuModificaciones(listaP, tamP, listaL, tamL, indicePersona))
    {
        retorno = 0;
    }

    return retorno;
}

int ePersona_mostrarMenuModificaciones(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona)
{
    int retorno = -1;

    char auxNombre[NOMBRE_LEN];
    char auxSexo;
    int auxEdad;
    float auxAltura;
    int auxIdLocalidad;
    int auxIndice;

    char opcion;
    int flagMod = FALSE_PER;
    int flagExit = FALSE_PER;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 &&
       indicePersona >= 0 && indicePersona < tamP && !listaP[indicePersona].isEmpty)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACIONES\n\n");

            printf("A. Nombre\n");
            printf("B. Sexo\n");
            printf("C. Edad\n");
            printf("D. Altura\n");
            printf("E. Localidad\n");
            printf("F. Salir\n");

            if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Solo numeros", 'A', 'F', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el Nombre de la Persona (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !utn_getAlfabetico(auxNombre, "\nIngrese nuevo Nombre: ", "Error. Solo letras: ", 3, NOMBRE_LEN, 2) &&
                           !utn_formatearCadena(auxNombre, NOMBRE_LEN))
                        {
                            strncpy(listaP[indicePersona].nombre, auxNombre, NOMBRE_LEN);

                            flagMod = TRUE_PER;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el Sexo de la Persona (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !utn_getSexo(&auxSexo, "\nIngrese nuevo Sexo (F/M): ", "Error. Solo F/M: ", 2))
                        {
                            listaP[indicePersona].sexo = auxSexo;

                            flagMod = TRUE_PER;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la Edad de la Persona (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !utn_getNumero(&auxEdad, "\nIngrese nueva Edad entre 1 y 100: ", "Error. Solo numeros enteros dentro del rango: ", 1, 100, 2))
                        {
                            listaP[indicePersona].edad = auxEdad;

                            flagMod = TRUE_PER;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la Altura de la Persona (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !utn_getNumeroFlotante(&auxAltura, "\nIngrese nueva Altura: ", "Error. Solo numeros flotantes dentro del rango: ", 1.5, 2.5, 2))
                        {
                            listaP[indicePersona].altura = auxAltura;

                            flagMod = TRUE_PER;
                        }

                        break;

                    case 'E':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el ID de Localidad de la Persona (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !eLocalidad_mostrarLista(listaL, tamL) &&
                           !utn_getNumero(&auxIdLocalidad, "\nIngrese nuevo ID de Localidad: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
                           !eLocalidad_buscarPorId(listaL, tamL, auxIdLocalidad, &auxIndice))
                        {
                            listaP[indicePersona].idLocalidad = auxIdLocalidad;

                            flagMod = TRUE_PER;
                        }

                        break;

                    case 'F':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            flagExit = TRUE_PER;
                        }

                        break;
                }
            }

        } while(opcion != 'F' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ePersona_mostrarUna(ePersona* unaPersona, eLocalidad* unaLocalidad)
{
    int retorno = -1;

    if(unaPersona != NULL && unaLocalidad != NULL)
    {
        printf("|%-10d|%-20s|%-4c|%-4d|%-6.2f|%-20s|\n", unaPersona->id, unaPersona->nombre, unaPersona->sexo,
                                                         unaPersona->edad, unaPersona->altura, unaLocalidad->descripcion);

        retorno = 0;
    }

    return retorno;
}

int ePersona_mostrarLista(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL)
{
    int retorno = -1;
    int indice;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE PERSONAS\n\n");

        printf("*----------*--------------------*----*----*------*--------------------*\n");
        printf("|%-10s|%-20s|%-4s|%-4s|%-6s|%-20s|\n", "ID", "NOMBRE", "SEXO", "EDAD", "ALTURA", "LOCALIDAD");
        printf("*----------*--------------------*----*----*------*--------------------*\n");

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && !eLocalidad_buscarPorId(listaL, tamL, listaP[i].idLocalidad, &indice) &&
               ePersona_mostrarUna(&listaP[i], &listaL[indice]))
            {
                break;
            }
        }

        printf("*----------*--------------------*----*----*------*--------------------*\n");

        if(i == tamP)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ePersona_mostrarPorSexo(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, char sexo)
{
    int retorno = -1;
    int indice;
    int i;
    int flag = FALSE_PER;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && (sexo == 'F' || sexo == 'M'))
    {
        printf("\n");
        system("pause");
        system("cls");

        if(sexo == 'F')
        {
            printf("\tLISTA DE MUJERES\n\n");
        }

        else
        {
            printf("\tLISTA DE HOMBRES\n\n");
        }

        printf("*----------*--------------------*----*----*------*--------------------*\n");
        printf("|%-10s|%-20s|%-4s|%-4s|%-6s|%-20s|\n", "ID", "NOMBRE", "SEXO", "EDAD", "ALTURA", "LOCALIDAD");
        printf("*----------*--------------------*----*----*------*--------------------*\n");

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && listaP[i].sexo == sexo &&
               !eLocalidad_buscarPorId(listaL, tamL, listaP[i].idLocalidad, &indice))
            {
                if(!ePersona_mostrarUna(&listaP[i], &listaL[indice]))
                {
                    flag = TRUE_PER;
                }

                else
                {
                    break;
                }
            }
        }

        printf("*----------*--------------------*----*----*------*--------------------*\n");

        if(i == tamP)
        {
            if(!flag)
            {
                if(sexo == 'F')
                {
                    printf("\nNo hay mujeres para mostrar\n");
                }

                else
                {
                    printf("\nNo hay hombres para mostrar\n");
                }
            }

            retorno = 0;
        }
    }

    return retorno;
}

int mostrarPersonasLocalidad(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indiceLocalidad)
{
    int retorno = -1;
    int i;
    int flag = FALSE_PER;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && indiceLocalidad >= 0 && indiceLocalidad < tamL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE PERSONAS POR LOCALIDAD\n");

        printf("\n\n\tPersonas de Localidad: %s\n\n", listaL[indiceLocalidad].descripcion);

        printf("*----------*--------------------*----*----*------*--------------------*\n");
        printf("|%-10s|%-20s|%-4s|%-4s|%-6s|%-20s|\n", "ID", "NOMBRE", "SEXO", "EDAD", "ALTURA", "LOCALIDAD");
        printf("*----------*--------------------*----*----*------*--------------------*\n");

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && listaP[i].idLocalidad == listaL[indiceLocalidad].id)
            {
                ePersona_mostrarUna(&listaP[i], &listaL[indiceLocalidad]);
                flag = TRUE_PER;
            }
        }

        if(flag)
        {
            printf("*----------*--------------------*----*----*------*--------------------*\n");
        }

        else
        {
            printf("\nNo hay Personas en esta Localidad\n");
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarPersonasAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL)
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0)
    {
        for(i = 0; i < tamL; i++)
        {
            mostrarPersonasLocalidad(listaP, tamP, listaL, tamL, i);
        }

        retorno = 0;
    }

    return retorno;
}

int calcularPersonaSexoMasVieja(ePersona lista[], int tam, int* mayorEdad, char sexo)
{
    int retorno = -1;
    int flag = FALSE_PER;
    int i;

    if(lista != NULL && tam > 0 && mayorEdad != NULL && (sexo == 'F' ||sexo == 'M'))
    {
        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].sexo == sexo &&
               (!flag || lista[i].edad > *mayorEdad))
            {
                *mayorEdad = lista[i].edad;
                flag = TRUE_PER;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarNombreSexoMasEdad(ePersona lista[], int tam, char sexo)
{
    int retorno = -1;
    int flag = FALSE_PER;
    int mayorEdad;
    int i;

    if(lista != NULL && tam > 0 && (sexo == 'F' || sexo == 'M') &&
       !calcularPersonaSexoMasVieja(lista, tam, &mayorEdad, sexo))
    {
        printf("\n");
        system("pause");
        system("cls");

        if(sexo == 'F')
        {
            printf("\tMUJERES DE MAYOR EDAD\n\n");
        }

        else
        {
            printf("\tVARONES DE MAYOR EDAD\n\n");
        }

        for(i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].sexo == sexo && lista[i].edad == mayorEdad)
            {
                printf("-> %s\n", lista[i].nombre);
                flag = TRUE_PER;
            }
        }

        if(!flag)
        {
            if(sexo == 'F')
            {
                printf("\nNo hay mujeres para mostrar\n");
            }

            else
            {
                printf("\nNo hay varones para mostrar\n");
            }
        }

        retorno = 0;
    }

    return retorno;
}

int contarPersonasLocalidad(ePersona listaP[], int tamP, int idLocalidad, int* contador)
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && idLocalidad > 0 && contador != NULL)
    {
        *contador = 0;

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && listaP[i].idLocalidad == idLocalidad)
            {
                (*contador)++;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int informarCantidadesPersonasLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL)
{
    int retorno = -1;
    int contador;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\t\tCANTIDAD DE PERSONAS DE CADA LOCALIDAD\n\n");

        for(i = 0; i < tamL; i++)
        {
            printf("\tLocalidad: %s\n\n", listaL[i].descripcion);

            if(!contarPersonasLocalidad(listaP, tamP, listaL[i].id, &contador))
            {
                if(contador > 0)
                {
                    printf("--> Cantidad: %d\n\n", contador);
                }

                else
                {
                    printf("\nNo hay Personas en esta Localidad\n");
                }
            }
        }

        retorno = 0;
    }

    return retorno;
}

int contarPersonasAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int contadores[])
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && contadores != NULL)
    {
        for(i = 0; i < tamL; i++)
        {
            contarPersonasLocalidad(listaP, tamP, listaL[i].id, &contadores[i]);
        }

        retorno = 0;
    }

    return retorno;
}

int calcularLocalidadMenosHabitada(int contadores[], int tamL, int* minimo)
{
    int retorno = -1;
    int i;

    if(contadores != NULL && tamL > 0 && minimo != NULL)
    {
        for(i = 0; i < tamL; i++)
        {
            if(i == 0 || contadores[i] < *minimo)
            {
                *minimo = contadores[i];
            }
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarLocalidadMenosHabitada(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL)
{
    int retorno = -1;
    int contadores[5];
    int minimo;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 &&
       !contarPersonasAllLocalidades(listaP, tamP, listaL, tamL, contadores) &&
       !calcularLocalidadMenosHabitada(contadores, tamL, &minimo))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLOCALIDADES CON MENOS HABITANTES\n\n");

        for(i = 0; i < tamL; i++)
        {
            if(contadores[i] == minimo)
            {
                printf("--> %s\n\n", listaL[i].descripcion);
            }
        }

        printf("*** Cantidad minima: %d\n", minimo);

        retorno = 0;
    }

    return retorno;
}

int acumularAlturasLocalidad(ePersona listaP[], int tamP, int idLocalidad, float* acumAlturas)
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && idLocalidad > 0 && acumAlturas != NULL)
    {
        *acumAlturas = 0;

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && listaP[i].idLocalidad == idLocalidad)
            {
                (*acumAlturas) += listaP[i].altura;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int informarPromedioAlturaLocalidad(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indiceLocalidad)
{
    int retorno = -1;
    float acumAlturas;
    int contador;
    float promedio;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && indiceLocalidad >= 0 && indiceLocalidad < tamL &&
       !acumularAlturasLocalidad(listaP, tamP, listaL[indiceLocalidad].id, &acumAlturas) &&
       !contarPersonasLocalidad(listaP, tamP, listaL[indiceLocalidad].id, &contador))
    {
        if(contador > 0)
        {
            promedio = acumAlturas / contador;

            printf("\n--** Promedio de Alturas de %s: %g\n", listaL[indiceLocalidad].descripcion, promedio);
        }

        else
        {
            printf("\nNo hay personas en %s\n", listaL[indiceLocalidad].descripcion);
        }

        retorno = 0;
    }

    return retorno;
}

int acumularEdadesLocalidad(ePersona listaP[], int tamP, int idLocalidad, int* acumEdades)
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && idLocalidad > 0 && acumEdades != NULL)
    {
        *acumEdades = 0;

        for(i = 0; i < tamP; i++)
        {
            if(!listaP[i].isEmpty && listaP[i].idLocalidad == idLocalidad)
            {
                (*acumEdades) += listaP[i].edad;
            }
        }

        retorno = 0;
    }

    return retorno;
}

int promediarEdadesLocalidad(ePersona listaP[], int tamP, int idLocalidad, float* promedio)
{
    int retorno = -1;
    int acumEdades;
    int contador;

    if(listaP != NULL && tamP > 0 && idLocalidad > 0 && promedio != NULL &&
       !acumularEdadesLocalidad(listaP, tamP, idLocalidad, &acumEdades) &&
       !contarPersonasLocalidad(listaP, tamP, idLocalidad, &contador) && contador > 0)
    {
        *promedio = (float) acumEdades / contador;

        retorno = 0;
    }

    return retorno;
}

int promediarEdadesAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, float promedios[])
{
    int retorno = -1;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && promedios != NULL)
    {
        for(i = 0; i < tamL; i++)
        {
            promediarEdadesLocalidad(listaP, tamP, listaL[i].id, &promedios[i]);
        }

        retorno = 0;
    }

    return retorno;
}

int calcularMenorPromedio(float promedios[], int tamL, float* minimo)
{
    int retorno = -1;
    int i;

    if(promedios != NULL && tamL > 0 && minimo != NULL)
    {
        for(i = 0; i < tamL; i++)
        {
            if(i == 0 || promedios[i] < *minimo)
            {
                *minimo = promedios[i];
            }
        }

        retorno = 0;
    }

    return retorno;
}

int mostrarLocalidadMenorPromedio(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL)
{
    int retorno = -1;
    float promedios[] = {0, 0, 0, 0, 0};
    float minimo;
    int i;

    if(listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 &&
       !promediarEdadesAllLocalidades(listaP, tamP, listaL, tamL, promedios) &&
       !calcularMenorPromedio(promedios, tamL, &minimo))
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLOCALIDADES CON MENOR PROMEDIO DE EDADES\n\n");

        for(i = 0; i < tamL; i++)
        {
            if(promedios[i] == minimo)
            {
                printf("--> %s\n\n", listaL[i].descripcion);
            }
        }

        printf("*** Cantidad minima: %g\n", minimo);

        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_cargarUno(eAlmuerzo* unAlmuerzo, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int* idAlmuerzo)
{
    int retorno = -1;
    int indiceP;
    int indiceC;

    if(unAlmuerzo != NULL && listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && listaC != NULL && tamC > 0 && idAlmuerzo != NULL &&
       !ePersona_mostrarLista(listaP, tamP, listaL, tamL) &&
       !utn_getNumero(&unAlmuerzo->idPersona, "\nIngrese ID de Persona: ", "Error. Solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
       !ePersona_buscarPorId(listaP, tamP, unAlmuerzo->idPersona, &indiceP) &&
       !eComida_mostrarLista(listaC, tamC) &&
       !utn_getNumero(&unAlmuerzo->idComida, "\nIngrese ID de Comida: ", "Error. Solo numeros enteros dentro del rango: ", 5000, 6000, 2) &&
       !eComida_buscarPorId(listaC, tamC, unAlmuerzo->idComida, &indiceC) &&
       !eFecha_cargar(&unAlmuerzo->fecha))
    {
        unAlmuerzo->id = *idAlmuerzo;
        unAlmuerzo->isEmpty = FALSE_ALM;

        (*idAlmuerzo)++;

        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_cargarEnArray(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo, int* idAlmuerzo)
{
    int retorno = -1;

    if(listaA != NULL && tamA > 0 && listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && listaC != NULL && tamC > 0 &&
       indiceAlmuerzo >= 0 && indiceAlmuerzo < tamA && listaA[indiceAlmuerzo].isEmpty && idAlmuerzo != NULL &&
       !eAlmuerzo_cargarUno(&listaA[indiceAlmuerzo], listaP, tamP, listaL, tamL, listaC, tamC, idAlmuerzo))
    {
        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_modificar(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo)
{
    int retorno = -1;

    if(listaA != NULL && tamA > 0 && listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && listaC != NULL && tamC > 0 &&
       indiceAlmuerzo >= 0 && indiceAlmuerzo < tamA && !listaP[indiceAlmuerzo].isEmpty &&
       !eAlmuerzo_mostrarMenuModificaciones(listaA, tamA, listaP, tamP, listaL, tamL, listaC, tamC, indiceAlmuerzo))
    {
        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_mostrarMenuModificaciones(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo)
{
    int retorno = -1;

    int auxIdPersona;
    int auxIdComida;
    eFecha auxFecha;

    int auxIndiceP;
    int auxIndiceC;

    char opcion;
    int flagMod = FALSE_ALM;
    int flagExit = FALSE_ALM;

    if(listaA != NULL && tamA > 0 && listaP != NULL && tamP > 0 && listaL != NULL && tamL > 0 && listaC != NULL && tamC > 0 &&
       indiceAlmuerzo >= 0 && indiceAlmuerzo < tamA && !listaP[indiceAlmuerzo].isEmpty)
    {
        do
        {
            printf("\n");
            system("pause");
            system("cls");

            printf("\tMENU DE MODIFICACIONES\n\n");

            printf("A. ID Persona\n");
            printf("B. ID Comida\n");
            printf("C. Fecha\n");
            printf("D. Salir\n");

            if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Solo numeros", 'A', 'D', 2))
            {
                switch(opcion)
                {
                    case 'A':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el ID de Persona del Almuerzo (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !ePersona_mostrarLista(listaP, tamP, listaL, tamL) &&
                           !utn_getNumero(&auxIdPersona, "\nIngrese nuevo ID de Persona: ", "Error. Solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
                           !ePersona_buscarPorId(listaP, tamP, auxIdPersona, &auxIndiceP))
                        {
                            listaA[indiceAlmuerzo].idPersona = auxIdPersona;

                            flagMod = TRUE_ALM;
                        }

                        break;

                    case 'B':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el ID de Comida del Almuerzo (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !eComida_mostrarLista(listaC, tamC) &&
                           !utn_getNumero(&auxIdComida, "\nIngrese nuevo ID de Comida: ", "Error. Solo numeros enteros dentro del rango: ", 5000, 6000, 2) &&
                           !eComida_buscarPorId(listaC, tamC, auxIdComida, &auxIndiceC))
                        {
                            listaA[indiceAlmuerzo].idComida = auxIdComida;

                            flagMod = TRUE_ALM;
                        }

                        break;

                    case 'C':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la Fecha del Almuerzo (S/N)?: ", "Error. Solo S/N: ") == 1 &&
                           !eFecha_cargar(&auxFecha))
                        {
                            listaA[indiceAlmuerzo].fecha = auxFecha;

                            flagMod = TRUE_ALM;
                        }

                        break;

                    case 'D':

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            flagExit = TRUE_ALM;
                        }

                        break;
                }
            }

        } while(opcion != 'D' || !flagExit);

        if(flagMod)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int eAlmuerzo_mostrarUno(eAlmuerzo* unAlmuerzo, ePersona* unaPersona, eComida* unaComida)
{
    int retorno = -1;

    if(unAlmuerzo != NULL && unaPersona != NULL && unaComida != NULL)
    {
        printf("|%-10d|%-20s|%-20s|", unAlmuerzo->id, unaPersona->nombre, unaComida->descripcion);

        eFecha_mostrar(&unAlmuerzo->fecha);

        printf("|\n");

        retorno = 0;
    }

    return retorno;
}

int eAlmuerzo_mostrarLista(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eComida listaC[], int tamC)
{
    int retorno = -1;
    int indiceP;
    int indiceC;
    int i;

    if(listaA != NULL && tamA > 0 && listaP != NULL && tamP > 0 && listaC != NULL && tamC > 0)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tLISTA DE ALMUERZOS\n\n");

        printf("*----------*--------------------*--------------------*----------*\n");
        printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "PERSONA", "COMIDA", "FECHA");
        printf("*----------*--------------------*--------------------*----------*\n");

        for(i = 0; i < tamA; i++)
        {
            if(!listaA[i].isEmpty &&
               !ePersona_buscarPorId(listaP, tamP, listaA[i].idPersona, &indiceP) &&
               !eComida_buscarPorId(listaC, tamC, listaA[i].idComida, &indiceC) &&
               eAlmuerzo_mostrarUno(&listaA[i], &listaP[indiceP], &listaC[indiceC]))
            {
                break;
            }
        }

        printf("*----------*--------------------*--------------------*----------*\n");

        if(i == tamA)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int mostrarMenu(int* opcion)
{
    int retorno = -1;

    if(opcion != NULL)
    {
        printf("\tABM Personas\n\n");

        printf("1. Alta Persona\n");
        printf("2. Baja Persona\n");
        printf("3. Modificacion Persona\n");
        printf("4. Ordenar Personas\n");
        printf("5. Listar Personas\n");
        printf("6. Listar Mujeres\n");
        printf("7. Listar Localidades\n");
        printf("8. Mostrar Personas de una Localidad\n");
        printf("9. Mostrar Personas por Localidad\n");
        printf("10. Mostrar Varones con mayor Edad\n");
        printf("11. Informar cantidad de Personas por Localidad\n");
        printf("12. Mostrar Localidad menos habitada\n");
        printf("13. Informar promedio de Altura de una Localidad\n");
        printf("14. Informar menor promedio de Edades de una Localidad\n");
        printf("15. Listar Comidas\n");
        printf("16. Alta Almuerzo\n");
        printf("17. Baja Almuerzo\n");
        printf("18. Modificacion Almuerzo\n");
        printf("19. Listar Almuerzos\n");
        printf("20. Salir\n");

        if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 20, 2))
        {
            retorno = 0;
        }
    }

    return retorno;
}
