#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED


#define DESC_COM 20

typedef struct
{
    int id;
    char descripcion[DESC_COM];
    float precio;

} eComida;


int eComida_buscarPorId(eComida lista[], int tam, int id, int* indice);
int eComida_hardCodear(eComida lista[], int tam, int* id);
int eComida_mostrarUna(eComida* unaComida);
int eComida_mostrarLista(eComida lista[], int tam);


#endif // COMIDA_H_INCLUDED
