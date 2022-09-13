#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED


#define DESC_LOC 20

typedef struct
{
    int id;
    char descripcion[DESC_LOC];

} eLocalidad;


int eLocalidad_buscarPorId(eLocalidad lista[], int tam, int id, int* indice);
int eLocalidad_hardCodear(eLocalidad lista[], int tam, int* id);
int eLocalidad_mostrarUna(eLocalidad* unaLocalidad);
int eLocalidad_mostrarLista(eLocalidad lista[], int tam);


#endif // LOCALIDAD_H_INCLUDED
