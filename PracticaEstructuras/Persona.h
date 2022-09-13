#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED


#define NOMBRE_LEN 20
#define TRUE_PER 1
#define FALSE_PER 0
#define UP 1
#define DOWN 0
#define ID 0
#define NOMBRE 1
#define SEXO 2
#define EDAD 3
#define ALTURA 4


typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    char sexo;
    int edad;
    float altura;
    int idLocalidad;
    int isEmpty;

} ePersona;


int ePersona_inicializar(ePersona lista[], int tam);
int ePersona_hardCodear(ePersona lista[], int tam, int* id);
int ePersona_arrayIsEmpty(ePersona lista[], int tam);
int ePersona_buscarLibre(ePersona lista[], int tam, int* indice);
int ePersona_buscarPorId(ePersona lista[], int tam, int id, int* indice);
int ePersona_elegirCriterioOrdenamiento(int* criterio);
int ePersona_elegirSentidoOrdenamiento(int* order);
int ePersona_compararInt(int a, int b);
int ePersona_compararFloat(float a, float b);
int ePersona_compararChar(char a, char b);
int ePersona_compararString(char a[], char b[], int length);
int ePersona_swap(ePersona* a, ePersona* b);
int ePersona_compararCriterio(ePersona* a, ePersona* b, int criterio);
int ePersona_ordenar(ePersona lista[], int tam, int criterio1, int criterio2, int order);
int ePersona_eliminar(ePersona lista[], int tam, int indice);

#endif // ALUMNO_H_INCLUDED
