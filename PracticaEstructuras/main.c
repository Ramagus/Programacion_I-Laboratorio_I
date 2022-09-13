#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Nexo.h"
#define TAM_P 20
#define TAM_L 5
#define TAM_C 5
#define TAM_A 20

int main()
{
    ePersona listaPersonas[TAM_P];
    eLocalidad listaLocalidades[TAM_L];
    eComida listaComidas[TAM_C];
    eAlmuerzo listaAlmuerzos[TAM_A];

    int opcion;
    int auxIdPersona;
    int auxIdLocalidad;
    int auxIdAlmuerzo;
    int indicePersona;
    int indiceLocalidad;
    int indiceComida;
    int indiceAlmuerzo;
    int auxOrder;

    int flagExit = 0;

    int idPersona = 20000;
    int idLocalidad = 1000;
    int idComida = 5000;
    int idAlmuerzo = 50000;

    if(!ePersona_inicializar(listaPersonas, TAM_P) && !eAlmuerzo_inicializar(listaAlmuerzos, TAM_A))
    {
        ePersona_hardCodear(listaPersonas, TAM_P, &idPersona);
        eLocalidad_hardCodear(listaLocalidades, TAM_L, &idLocalidad);
        eComida_hardCodear(listaComidas, TAM_C, &idComida);
        eAlmuerzo_hardCodear(listaAlmuerzos, TAM_A, &idAlmuerzo);

        do
        {
            if(!mostrarMenu(&opcion))
            {
                switch(opcion)
                {
                    case 1:

                        if(!ePersona_buscarLibre(listaPersonas, TAM_P, &indicePersona))
                        {
                            printf("\n");
                            system("pause");
                            system("cls");

                            printf("\tALTA DE PERSONA\n");

                            if(!ePersona_cargarEnArray(listaPersonas, TAM_P, listaLocalidades, TAM_L, indicePersona, &idPersona))
                            {
                                printf("\nPersona cargada correctamente\n");
                            }

                            else
                            {
                                printf("\nError en el alta\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay espacio disponible\n");
                        }

                        break;

                    case 2:

                        if(!ePersona_arrayIsEmpty(listaPersonas, TAM_P))
                        {
                            if(!ePersona_mostrarLista(listaPersonas, TAM_P, listaLocalidades, TAM_L) &&
                               !utn_getNumero(&auxIdPersona, "\nIngrese el ID de la Persona a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
                               !ePersona_buscarPorId(listaPersonas, TAM_P, auxIdPersona, &indicePersona) &&
                               !eLocalidad_buscarPorId(listaLocalidades, TAM_L, listaPersonas[indicePersona].idLocalidad, &indiceLocalidad))
                            {
                                printf("\n");
                                system("pause");
                                system("cls");

                                printf("\tBAJA DE PERSONA\n\n");

                                printf("*----------*--------------------*----*----*------*--------------------*\n");
                                printf("|%-10s|%-20s|%-4s|%-4s|%-6s|%-20s|\n", "ID", "NOMBRE", "SEXO", "EDAD", "ALTURA", "LOCALIDAD");
                                printf("*----------*--------------------*----*----*------*--------------------*\n");
                                ePersona_mostrarUna(&listaPersonas[indicePersona], &listaLocalidades[indiceLocalidad]);
                                printf("*----------*--------------------*----*----*------*--------------------*\n");

                                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a esta Persona? (S/N): ", "Error. Solo S/N: ") == 1 &&
                                   !ePersona_eliminar(listaPersonas, TAM_P, indicePersona))
                                {
                                    printf("\nPersona eliminada correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo eliminar a la Persona\n");
                                }
                            }

                            else
                            {
                                printf("\nError en la baja\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Personas para eliminar\n");
                        }

                        break;

                    case 3:

                        if(!ePersona_arrayIsEmpty(listaPersonas, TAM_P))
                        {
                            if(!ePersona_mostrarLista(listaPersonas, TAM_P, listaLocalidades, TAM_L) &&
                               !utn_getNumero(&auxIdPersona, "\nIngrese el ID de la Persona a modificar: ", "Error. Solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
                               !ePersona_buscarPorId(listaPersonas, TAM_P, auxIdPersona, &indicePersona) &&
                               !eLocalidad_buscarPorId(listaLocalidades, TAM_L, listaPersonas[indicePersona].idLocalidad, &indiceLocalidad))
                            {
                                printf("\n");
                                system("pause");
                                system("cls");

                                printf("\tMODIFICACION DE PERSONA\n\n");

                                printf("*----------*--------------------*----*----*------*--------------------*\n");
                                printf("|%-10s|%-20s|%-4s|%-4s|%-6s|%-20s|\n", "ID", "NOMBRE", "SEXO", "EDAD", "ALTURA", "LOCALIDAD");
                                printf("*----------*--------------------*----*----*------*--------------------*\n");
                                ePersona_mostrarUna(&listaPersonas[indicePersona], &listaLocalidades[indiceLocalidad]);
                                printf("*----------*--------------------*----*----*------*--------------------*\n");

                                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a esta Persona? (S/N): ", "Error. Solo S/N: ") == 1 &&
                                   !ePersona_modificar(listaPersonas, TAM_P, listaLocalidades, TAM_L, indicePersona))
                                {
                                    printf("\nPersona modificada correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo modificar a la Persona\n");
                                }
                            }

                            else
                            {
                                printf("\nError en la modificacion\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Personas para modificar\n");
                        }

                        break;

                    case 4:

                        if(!ePersona_arrayIsEmpty(listaPersonas, TAM_P))
                        {
                            if(!ePersona_elegirSentidoOrdenamiento(&auxOrder) && !ePersona_ordenar(listaPersonas, TAM_P, NOMBRE, ALTURA, auxOrder))
                            {
                                printf("\nOrdenamiento realizado correctamente\n");
                            }

                            else
                            {
                                printf("\nError en el ordenamiento\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Personas para ordenar\n");
                        }

                        break;

                    case 5:

                        if(!ePersona_arrayIsEmpty(listaPersonas, TAM_P))
                        {
                            if(!ePersona_mostrarLista(listaPersonas, TAM_P, listaLocalidades, TAM_L))
                            {
                                printf("\nMuestra realizada correctamente\n");
                            }

                            else
                            {
                                printf("\nError en la muestra\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Personas para mostrar\n");
                        }

                        break;

                    case 6:

                        if(!ePersona_mostrarPorSexo(listaPersonas, TAM_P, listaLocalidades, TAM_L, 'F'))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 7:

                        if(!eLocalidad_mostrarLista(listaLocalidades, TAM_L))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 8:

                        if(!eLocalidad_mostrarLista(listaLocalidades, TAM_L) &&
                           !utn_getNumero(&auxIdLocalidad, "\nIngrese ID de Localidad: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
                           !eLocalidad_buscarPorId(listaLocalidades, TAM_L, auxIdLocalidad, &indiceLocalidad) &&
                           !mostrarPersonasLocalidad(listaPersonas, TAM_P, listaLocalidades, TAM_L, indiceLocalidad))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 9:

                        if(!mostrarPersonasAllLocalidades(listaPersonas, TAM_P, listaLocalidades, TAM_L))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 10:

                        if(!mostrarNombreSexoMasEdad(listaPersonas, TAM_P, 'M'))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 11:

                        if(!informarCantidadesPersonasLocalidades(listaPersonas, TAM_P, listaLocalidades, TAM_L))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 12:

                        if(!mostrarLocalidadMenosHabitada(listaPersonas, TAM_P, listaLocalidades, TAM_L))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 13:

                        if(!eLocalidad_mostrarLista(listaLocalidades, TAM_L) &&
                           !utn_getNumero(&auxIdLocalidad, "\nIngrese ID de Localidad: ", "Error. Solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
                           !eLocalidad_buscarPorId(listaLocalidades, TAM_L, auxIdLocalidad, &indiceLocalidad) &&
                           !informarPromedioAlturaLocalidad(listaPersonas, TAM_P, listaLocalidades, TAM_L, indiceLocalidad))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 14:

                        if(!mostrarLocalidadMenorPromedio(listaPersonas, TAM_P, listaLocalidades, TAM_L))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 15:

                        if(!eComida_mostrarLista(listaComidas, TAM_C))
                        {
                            printf("\nMuestra realizada correctamente\n");
                        }

                        else
                        {
                            printf("\nError en la muestra\n");
                        }

                        break;

                    case 16:

                        if(!eAlmuerzo_buscarLibre(listaAlmuerzos, TAM_A, &indiceAlmuerzo))
                        {
                            printf("\n");
                            system("pause");
                            system("cls");

                            printf("\tALTA DE ALMUERZO\n");

                            if(!eAlmuerzo_cargarEnArray(listaAlmuerzos, TAM_A, listaPersonas, TAM_P, listaLocalidades, TAM_L, listaComidas, TAM_C, indiceAlmuerzo, &idAlmuerzo))
                            {
                                printf("\nAlmuerzo cargado correctamente\n");
                            }

                            else
                            {
                                printf("\nError en el alta\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay espacio disponible\n");
                        }

                        break;

                    case 17:

                        if(!eAlmuerzo_arrayIsEmpty(listaAlmuerzos, TAM_A))
                        {
                            if(!eAlmuerzo_mostrarLista(listaAlmuerzos, TAM_A, listaPersonas, TAM_P, listaComidas, TAM_C) &&
                               !utn_getNumero(&auxIdAlmuerzo, "\nIngrese el ID del Almuerzo a eliminar: ", "Error. Solo numeros enteros dentro del rango: ", 50000, 60000, 2) &&
                               !eAlmuerzo_buscarPorId(listaAlmuerzos, TAM_A, auxIdAlmuerzo, &indiceAlmuerzo) &&
                               !ePersona_buscarPorId(listaPersonas, TAM_P, listaAlmuerzos[indiceAlmuerzo].idPersona, &indicePersona) &&
                               !eComida_buscarPorId(listaComidas, TAM_C, listaAlmuerzos[indiceAlmuerzo].idComida, &indiceComida))
                            {
                                printf("\n");
                                system("pause");
                                system("cls");

                                printf("\tBAJA DE ALMUERZO\n\n");

                                printf("*----------*--------------------*--------------------*----------*\n");
                                printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "PERSONA", "COMIDA", "FECHA");
                                printf("*----------*--------------------*--------------------*----------*\n");
                                eAlmuerzo_mostrarUno(&listaAlmuerzos[indiceAlmuerzo], &listaPersonas[indicePersona], &listaComidas[indiceComida]);
                                printf("*----------*--------------------*--------------------*----------*\n");

                                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este Almuerzo? (S/N): ", "Error. Solo S/N: ") == 1 &&
                                   !eAlmuerzo_eliminar(listaAlmuerzos, TAM_A, indiceAlmuerzo))
                                {
                                    printf("\nAlmuerzo eliminado correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo eliminar al Almuerzo\n");
                                }
                            }

                            else
                            {
                                printf("\nError en la baja\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Almuerzos para eliminar\n");
                        }

                        break;

                    case 18:

                        if(!eAlmuerzo_arrayIsEmpty(listaAlmuerzos, TAM_A))
                        {
                            if(!eAlmuerzo_mostrarLista(listaAlmuerzos, TAM_A, listaPersonas, TAM_P, listaComidas, TAM_C) &&
                               !utn_getNumero(&auxIdAlmuerzo, "\nIngrese el ID del Almuerzo a modificar: ", "Error. Solo numeros enteros dentro del rango: ", 50000, 60000, 2) &&
                               !eAlmuerzo_buscarPorId(listaAlmuerzos, TAM_A, auxIdAlmuerzo, &indiceAlmuerzo) &&
                               !ePersona_buscarPorId(listaPersonas, TAM_P, listaAlmuerzos[indiceAlmuerzo].idPersona, &indicePersona) &&
                               !eComida_buscarPorId(listaComidas, TAM_C, listaAlmuerzos[indiceAlmuerzo].idComida, &indiceComida))
                            {
                                printf("\n");
                                system("pause");
                                system("cls");

                                printf("\tMODIFICACION DE ALMUERZO\n\n");

                                printf("*----------*--------------------*--------------------*----------*\n");
                                printf("|%-10s|%-20s|%-20s|%-10s|\n", "ID", "PERSONA", "COMIDA", "FECHA");
                                printf("*----------*--------------------*--------------------*----------*\n");
                                eAlmuerzo_mostrarUno(&listaAlmuerzos[indiceAlmuerzo], &listaPersonas[indicePersona], &listaComidas[indiceComida]);
                                printf("*----------*--------------------*--------------------*----------*\n");

                                if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este Almuerzo? (S/N): ", "Error. Solo S/N: ") == 1 &&
                                   !eAlmuerzo_modificar(listaAlmuerzos, TAM_A, listaPersonas, TAM_P, listaLocalidades, TAM_L, listaComidas, TAM_C, indiceAlmuerzo))
                                {
                                    printf("\nAlmuerzo modificado correctamente\n");
                                }

                                else
                                {
                                    printf("\nNo se pudo modificar a la Persona\n");
                                }
                            }

                            else
                            {
                                printf("\nError en la modificacion\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Almuerzos para modificar\n");
                        }

                        break;

                    case 19:

                        if(!ePersona_arrayIsEmpty(listaPersonas, TAM_P) &&
                           !eAlmuerzo_arrayIsEmpty(listaAlmuerzos, TAM_A))
                        {
                            if(!eAlmuerzo_mostrarLista(listaAlmuerzos, TAM_A, listaPersonas, TAM_P, listaComidas, TAM_C))
                            {
                                printf("\nMuestra realizada correctamente\n");
                            }

                            else
                            {
                                printf("\nError en la muestra\n");
                            }
                        }

                        else
                        {
                            printf("\nNo hay Almuerzos para mostrar\n");
                        }

                        break;

                    case 20:

                        if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S/N: ") == 1)
                        {
                            printf("\nHa salido del menu\n");

                            flagExit = 1;
                        }

                        break;
                }
            }

            printf("\n");
            system("pause");
            system("cls");

        } while(opcion != 20 || !flagExit);
    }

    else
    {
        printf("Error en la inicializacion\n");
    }

    return 0;
}
