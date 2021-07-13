#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Estructuras.h"

void inicializarAlumnos(eAlumno listado[], int cantidad)
{
    int i;

    if(listado != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            listado[i].estaVacio = 1;
        }
    }
}

int dameElIndiceLibre(eAlumno listado[], int cantidad)
{
    int i;
    int indiceLibre = -1;

    if(listado != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(listado[i].estaVacio == 1)
            {
                indiceLibre = i;
                break;
            }
        }
    }

    return indiceLibre;
}

int cargarAlumnosTest(eAlumno listado[], int cantidad)
{
    int retorno = -1;
    int i = 0;
    int indice;
    int cantHardCode;
    int flag = 0;

    int legajoAux[] = {555, 888, 444, 666, 111};
    int notasAux[] = {10, 2, 9, 4, 6};
    char nombreAux[][50] = {"Juan", "Pedro", "Maria", "Julieta", "Pepe"};

    if(listado != NULL && cantidad > 0)
    {
        cantHardCode = sizeof(legajoAux) / sizeof(int);

        if(cantHardCode <= cantidad)
        {
            while(i < cantHardCode)
            {
                indice = dameElIndiceLibre(listado, cantidad);

                if(indice > -1)
                {
                    listado[indice].legajo = legajoAux[i];
                    listado[indice].nota = notasAux[i];
                    strcpy(listado[indice].nombre, nombreAux[i]);

                    listado[indice].estaVacio = 0;

                    flag = 1;
                }

                else
                {
                    break;
                }

                i++;
            }

            if(flag == 1)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

eAlumno agregarAlumno(eAlumno listado[], int cantidad)
{
    eAlumno unAlumno;

    int indice;

    printf("Ingrese legajo: ");
    scanf("%d", &unAlumno.legajo);

    indice = buscarAlumnoPorLegajo(listado, cantidad, unAlumno.legajo);

    if(indice == -1)
    {
        printf("Ingrese nota: ");
        scanf("%d", &unAlumno.nota);

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", unAlumno.nombre);

        strlwr(unAlumno.nombre);
        unAlumno.nombre[0] = toupper(unAlumno.nombre[0]);

        unAlumno.estaVacio = 0;
    }

    else
    {
        unAlumno.estaVacio = 1;
    }

    return unAlumno;
}

void cargarListado(eAlumno listado[], int cantidad)
{
    int indice;

    if(listado != NULL && cantidad > 0)
    {
        indice = dameElIndiceLibre(listado, cantidad);

        printf("\nIndice: %d\n\n", indice);

        if(indice != -1)
        {
            listado[indice] = agregarAlumno(listado, cantidad);

            if(listado[indice].estaVacio == 0)
            {
                printf("\nAlumno cargado\n");
            }

            else
            {
                printf("\nEl legajo ingresado ya existe\n");
            }
        }

        else
        {
            printf("No hay espacio disponible\n");
        }
    }
}

void mostrarUnAlumno(eAlumno alguno)
{
    printf("%d\t\t", alguno.legajo);
    printf("%s\t\t", alguno.nombre);
    printf("%d\n", alguno.nota);
}

void mostrarAlumnos(eAlumno listado[], int cantidad, int tieneAlumnos)
{
    int i;

    if(listado != NULL && cantidad > 0)
    {
        if(tieneAlumnos == 1)
        {
            printf("\nLEGAJO\t\tNOMBRE\t\tNOTA\n\n");

            for(i = 0; i < cantidad; i++)
            {
                if(listado[i].estaVacio == 0)
                {
                    mostrarUnAlumno(listado[i]);
                }
            }
        }

        else
        {
            printf("\nNo hay alumnos para mostrar\n");
        }
    }
}

int buscarAlumnoPorLegajo(eAlumno listado[], int cantidad, int legajo)
{
    int i;
    int indiceLegajo = -1;

    if(listado != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(listado[i].legajo == legajo && listado[i].estaVacio == 0)
            {
                indiceLegajo = i;
                break;
            }
        }
    }

    return indiceLegajo;
}

int buscarAlumnoPorNombre(eAlumno listado[], int cantidad, char nombre[])
{
    int i;
    int indiceNombre = -1;

    if(listado != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(strcmp(listado[i].nombre, nombre) == 0 && listado[i].estaVacio == 0)
            {
                indiceNombre = i;
                break;
            }
        }
    }

    return indiceNombre;
}

int borrarAlumno(eAlumno listado[], int cantidad, char nombre[], int indice)
{
    int borrar = -2;
    char respuesta;

    if(listado != NULL && cantidad > 0)
    {
        if(indice != -1)
        {
            printf("\nLEGAJO\t\tNOMBRE\t\tNOTA\n\n");
            mostrarUnAlumno(listado[indice]);

            printf("\nEsta seguro que quiere eliminar a este alumno?: ");
            respuesta = toupper(getche());

            while(respuesta != 'S' && respuesta != 'N')
            {
                printf("\nError. Solo S/N: ");
                respuesta = toupper(getche());
            }

            if(respuesta == 'S')
            {
                listado[indice].estaVacio = 1;
                borrar = 1;
            }

            else if(respuesta == 'N')
            {
                borrar = 0;
            }
        }

        else
        {
            borrar = -1;
        }
    }

    return borrar;
}

int contarLugaresLibres(eAlumno listado[], int cantidad)
{
    int contador = -1;
    int i;

    if(listado != NULL && cantidad > 0)
    {
        contador = 0;

        for(i = 0; i < cantidad; i++)
        {
            if(listado[i].estaVacio == 1)
            {
                contador++;
            }
        }
    }

    return contador;
}
