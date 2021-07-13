#ifndef LOCALIDAD_H
#define LOCALIDAD_H

typedef struct
{
    int idLocalidad;
    char localidad[30];
    //int codigoPostal;

} eLocalidad;

typedef struct
{
    int idLocalidad;
    int contAlumnos;

} eAuxLocalidad;

#include "Alumno.h"

int buscarLocalidadPorId(eLocalidad listaDeLocalidades[], int tl, int id);
void hardCodearLocalidades(eLocalidad listaDeLocalidades[], int tl);
void mostrarUnaLocalidad(eLocalidad unaLocalidad);
void mostrarListadoLocalidades(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);
void mostrarAlumnosPorLocalidad(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);
void mostrarAlumnosDeAvellaneda(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);
void mostrarLocalidadConMenosAlumnos(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);

#endif // LOCALIDAD_H
