#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED


#include "Fecha.h"
#define TRUE_ALM 1
#define FALSE_ALM 0

typedef struct
{
    int id;
    int idPersona;
    int idComida;
    eFecha fecha;
    int isEmpty;

} eAlmuerzo;

int eAlmuerzo_inicializar(eAlmuerzo lista[], int tam);
int eAlmuerzo_buscarLibre(eAlmuerzo lista[], int tam, int* indice);
int eAlmuerzo_arrayIsEmpty(eAlmuerzo lista[], int tam);
int eAlmuerzo_buscarPorId(eAlmuerzo lista[], int tam, int id, int* indice);
int eAlmuerzo_hardCodear(eAlmuerzo lista[], int tam, int* id);
int eAlmuerzo_eliminar(eAlmuerzo lista[], int tam, int indice);

#endif // ALMUERZO_H_INCLUDED
