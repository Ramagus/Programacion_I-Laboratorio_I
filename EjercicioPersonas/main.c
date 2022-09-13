/*
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tienen más de 60 años,
el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
*/

#include <stdio.h>
#include <stdlib.h>
#define PRECIO 600
#define DESC 25

int main()
{
    int numCliente;
    char estadoCivil;
    int edad;
    float tempCorp;
    char sexo;
    int numClienteFemMin;
    int edadFemMin;
    float precioFinalDescuento;
    char respuesta;
    int flag = 0;
    int contViudos = 0;
    int contSesenta = 0;
    float acumPrecios = 0;
    int mitadPasajeros;

    do
    {
        printf("Ingrese numero de cliente: ");
        scanf("%d", &numCliente);

        printf("\nIngrese estado civil (s/c/v): ");
        fflush(stdin);
        scanf("%c", &estadoCivil);

        while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
        {
            printf("Error. Debe ingresar un estado civil valido (s/c/v): ");
            fflush(stdin);
            scanf("%c", &estadoCivil);
        }

        printf("\nIngrese una edad mayor a 17: ");
        scanf("%d", &edad);

        while(edad < 18 || edad > 100)
        {
            printf("Error. Debe Ingresar una edad mayor a 17: ");
            scanf("%d", &edad);
        }

        printf("\nIngrese la temperatura corporal: ");
        scanf("%f", &tempCorp);

        while(tempCorp < 35 || tempCorp > 40)
        {
            printf("Error. Debe Ingresar una temperatura corporal valida: ");
            scanf("%f", &tempCorp);
        }

        printf("\nIngrese el sexo (f/m/o): ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(sexo != 'f' && sexo != 'm' && sexo != 'o')
        {
            printf("Error. Debe Ingresar un sexo valido (f/m/o): ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        if(edad > 60)
        {
            contSesenta++;

            if(estadoCivil == 'v')
	    {
	    	contViudos++;
	    }
        }

        if(sexo == 'f' && estadoCivil == 's' && (flag == 0 || edad < edadFemMin))
        {
            numClienteFemMin = numCliente;
            edadFemMin = edad;

	    flag = 1;
        }

        acumPrecios += PRECIO;

        printf("\n\nDesea ingresar otro pasajero? (s/n): ");
        fflush(stdin);
        scanf("%c", &respuesta);

    } while(respuesta == 's');

    mitadPasajeros = contSesenta * 50 / 100;

    if(contViudos > 0)
    {
        printf("\n\nCantidad de personas con estado viudo de mas de 60 anios: %d\n", contViudos);
    }

    else
    {
        printf("\n\nNo hay personas con estado viudo de mas de 60 anios\n");
    }

    printf("\nNumero de cliente y edad de la mujer soltera mas joven: %d y %d\n", numClienteFemMin, edadFemMin);

    printf("\nViaje total sin descuento: %.2f\n", acumPrecios);

    if(contSesenta > mitadPasajeros)
    {
        precioFinalDescuento = acumPrecios - (acumPrecios * DESC / 100);

        printf("\nPrecio final con descuento: %.2f\n", precioFinalDescuento);
    }

    return 0;
}
