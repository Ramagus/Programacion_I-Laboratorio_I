#ifndef NEXO_H_INCLUDED
#define NEXO_H_INCLUDED


#include "Persona.h"
#include "Localidad.h"
#include "Comida.h"
#include "Almuerzo.h"


int ePersona_cargarUno(ePersona* unaPersona, eLocalidad listaL[], int tamL, int* idPersona);
int ePersona_cargarEnArray(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona, int* idPersona);
int ePersona_modificar(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona);
int ePersona_mostrarMenuModificaciones(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indicePersona);
int ePersona_mostrarUna(ePersona* unaPersona, eLocalidad* unaLocalidad);
int ePersona_mostrarLista(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL);
int ePersona_mostrarPorSexo(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, char sexo);
int mostrarPersonasLocalidad(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indiceLocalidad);
int mostrarPersonasAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL);
int calcularPersonaSexoMasVieja(ePersona lista[], int tam, int* mayorEdad, char sexo);
int mostrarNombreSexoMasEdad(ePersona lista[], int tam, char sexo);
int contarPersonasLocalidad(ePersona listaP[], int tamP, int idLocalidad, int* contador);
int informarCantidadesPersonasLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL);
int contarPersonasAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int contadores[]);
int calcularLocalidadMenosHabitada(int contadores[], int tamL, int* minimo);
int mostrarLocalidadMenosHabitada(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL);
int acumularAlturasLocalidad(ePersona listaP[], int tamP, int idLocalidad, float* acumAlturas);
int informarPromedioAlturaLocalidad(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, int indiceLocalidad);
int acumularEdadesLocalidad(ePersona listaP[], int tamP, int idLocalidad, int* acumEdades);
int promediarEdadesLocalidad(ePersona listaP[], int tamP, int idLocalidad, float* promedio);
int promediarEdadesAllLocalidades(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, float promedios[]);
int calcularMenorPromedio(float promedios[], int tamL, float* minimo);
int mostrarLocalidadMenorPromedio(ePersona listaP[], int tamP, eLocalidad listaL[], int tamL);
int eAlmuerzo_cargarUno(eAlmuerzo* unAlmuerzo, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int* idAlmuerzo);
int eAlmuerzo_cargarEnArray(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo, int* idAlmuerzo);
int eAlmuerzo_modificar(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo);
int eAlmuerzo_mostrarMenuModificaciones(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eLocalidad listaL[], int tamL, eComida listaC[], int tamC, int indiceAlmuerzo);
int eAlmuerzo_mostrarUno(eAlmuerzo* unAlmuerzo, ePersona* unaPersona, eComida* unaComida);
int eAlmuerzo_mostrarLista(eAlmuerzo listaA[], int tamA, ePersona listaP[], int tamP, eComida listaC[], int tamC);
int mostrarMenu(int* opcion);


#endif // NEXO_H_INCLUDED
