#ifndef ALUMNO_H
#define ALUMNO_H
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int idLocalidad;
    int estado;

} eAlumno;

#include "Localidad.h"

void inicializarAlumnos(eAlumno listaDeAlumnos[], int ta);
int buscarLibre(eAlumno listaDeAlumnos[], int ta);
int buscarAlumnoPorLegajo(eAlumno listaDeAlumnos[], int ta, int legajo);
void hardCodearAlumnos(eAlumno listaDeAlumnos[], int ta, int cantHardCode);
eAlumno cargarAlumno(eAlumno listaDeAlumnos[], int ta);
void cargarListadoAlumnos(eAlumno listaDeAlumnos[], int ta);
void mostrarUnAlumno(eAlumno miAlumno);
void mostrarListadoAlumnos(eAlumno listaDeAlumnos[], int ta);
void mostrarUnAlumnoConLocalidad(eAlumno unAlumno, eLocalidad unaLocalidad);
void mostrarListadoAlumnosConLocalidad(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);
int eliminarAlumno(eAlumno listaDeAlumnos[], int ta, eLocalidad listaDeLocalidades[], int tl);
int modificarAlumno(eAlumno listaDeAlumnos[], int ta, int legajo, eLocalidad listaDeLocalidades[], int tl);
void sortStudentsByNameAndAverage(eAlumno listaDeAlumnos[], int ta);

#endif // ALUMNO_H
