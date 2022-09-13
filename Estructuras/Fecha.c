#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Fecha.h"


int eFecha_cargar(eFecha* unaFecha)
{
	int retorno = -1;

	eFecha aux;

	if(unaFecha != NULL)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tFECHA\n");

		if(!utn_getNumero(&aux.dia, "\nIngrese dia de la fecha entre 1 y 31: ", "Error. Ingrese solo numeros enteros entre 1 y 31: ", 1, 31, 2) &&
		   !utn_getNumero(&aux.mes, "\nIngrese mes de la fecha entre 1 y 12: ", "Error. Ingrese solo numeros enteros entre 1 y 12: ", 1, 12, 2) &&
		   !utn_getNumero(&aux.anio, "\nIngrese anio de la fecha entre 1 y 9999: ", "Error. Ingrese solo numeros enteros entre 1 y 9999: ", 1, 9999, 2) &&
		   !eFecha_validar(aux.dia, aux.mes, aux.anio))
		{
			*unaFecha = aux;
			retorno = 0;
		}
	}

	return retorno;
}

int eFecha_validar(int dia, int mes, int anio)
{
	int retorno = -1;
	int diaMaximo;

	if(dia >= 1 && mes >= 1 && mes <= 12 && anio >= 1 && anio <= 9999)
	{
		switch(mes)
		{
			case 4:
			case 6:
			case 9:
			case 11:

				diaMaximo = 30;

				break;

			case 2:

				if(eFecha_esBisiesto(anio))
				{
					diaMaximo = 29;
				}

				else
				{
					diaMaximo = 28;
				}

				break;

			default:

				diaMaximo = 31;
		}

		if(dia <= diaMaximo)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int eFecha_esBisiesto(int anio)
{
	int retorno = -1;

	if(anio >= 1 && anio <= 9999)
	{
		retorno = 0;

		if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eFecha_mostrar(eFecha* unaFecha)
{
	int retorno = -1;

	if(unaFecha != NULL)
	{
		printf("%02d/%02d/%d", unaFecha->dia, unaFecha->mes, unaFecha->anio);

		retorno = 0;
	}

	return retorno;
}

int eFecha_compararLongInt(long int a, long int b)
{
    int retorno = -2;

    if(a > 0 && b > 0)
    {
        if(a < b)
        {
            retorno = -1;
        }

        else if(a == b)
        {
            retorno = 0;
        }

        else
        {
            retorno = 1;
        }
    }

    return retorno;
}

int eFecha_comparar(eFecha* a, eFecha* b)
{
    int retorno = -3;
    long int auxFecha1;
    long int auxFecha2;

    if(a != NULL && b != NULL)
    {
        auxFecha1 = a->anio * 10000 + a->mes * 100 + a->dia;
        auxFecha2 = b->anio * 10000 + b->mes * 100 + b->dia;

        retorno = eFecha_compararLongInt(auxFecha1, auxFecha2);
    }

    return retorno;
}
