#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define NOMBRE_LEN 20
#define APELLIDO_LEN 20
#define UP 1
#define DOWN 0

typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    char apellido[APELLIDO_LEN];
    char sexo;
    float sueldo;

} eEmpleado;


eEmpleado* empleado_new(void);
eEmpleado* empleado_newParam(int id, char* nombre, char* apellido, char sexo, float sueldo);
eEmpleado* empleado_newParamStr(char* id, char* nombre, char* apellido, char* sexo, char* sueldo);

int empleado_delete(eEmpleado* this);

int empleado_setId(eEmpleado* this, int id);
int empleado_setIdTxt(eEmpleado* this, char* id);
int empleado_setNombre(eEmpleado* this, char* nombre);
int empleado_setApellido(eEmpleado* this, char* apellido);
int empleado_setSexo(eEmpleado* this, char sexo);
int empleado_setSueldo(eEmpleado* this, float sueldo);
int empleado_setSueldoTxt(eEmpleado* this, char* sueldo);

int empleado_getId(eEmpleado* this, int* id);
int empleado_getIdTxt(eEmpleado* this, char* id);
int empleado_getNombre(eEmpleado* this, char* nombre);
int empleado_getApellido(eEmpleado* this, char* apellido);
int empleado_getSexo(eEmpleado* this, char* sexo);
int empleado_getSueldo(eEmpleado* this, float* sueldo);
int empleado_getSueldoTxt(eEmpleado* this, char* sueldo);
int empleado_getNombreCompleto(eEmpleado* this, char* nombre);
int empleado_getSexoFull(eEmpleado* this, char* sexo);

eEmpleado** empleado_newArray(int len);

int empleado_inicializar(eEmpleado** lista, int inicio, int len);
int empleado_arrayIsEmpty(eEmpleado** lista, int len);
int empleado_buscarLibre(eEmpleado** lista, int len, int* indice);
int empleado_buscarPorId(eEmpleado** lista, int len, int id, int* indice);
int empleado_getArraySize(eEmpleado** lista, int len, int* size);
int empleado_getEmptyIndex(eEmpleado*** lista, int* len, int* indice);

int empleado_add(eEmpleado*** lista, int* len, int* id);
int empleado_edit(eEmpleado** lista, int len);
int empleado_mostrarMenuModificacion(eEmpleado* this);
int empleado_remove(eEmpleado** lista, int len);

int empleado_mostrarUno(eEmpleado* this);
int empleado_mostrarLista(eEmpleado** lista, int len);

int empleado_sortSimpleCriterion(eEmpleado** lista, int len, int (*pFunc)(eEmpleado*, eEmpleado*), int order);
int empleado_sortDoubleCriterion(eEmpleado** lista, int len, int (*pFunc1)(eEmpleado*, eEmpleado*), int (*pFunc2)(eEmpleado*, eEmpleado*), int order);
int empleado_elegirCriterioOrdenamiento(int (**pFunc)(eEmpleado*, eEmpleado*));
int empleado_elegirSentidoOrdenamiento(int* order);
int empleado_compararInt(int a, int b);
int empleado_compararFloat(float a, float b);
int empleado_compararChar(char a, char b);
int empleado_compararString(char* a, char* b, int length);
int empleado_compararPorId(eEmpleado* a, eEmpleado* b);
int empleado_compararPorNombre(eEmpleado* a, eEmpleado* b);
int empleado_compararPorApellido(eEmpleado* a, eEmpleado* b);
int empleado_compararPorSexo(eEmpleado* a, eEmpleado* b);
int empleado_compararPorSueldo(eEmpleado* a, eEmpleado* b);
int empleado_swap(eEmpleado** a, eEmpleado** b);

int empleado_agrandarArray(eEmpleado*** lista, int* len, int newLen);

int empleado_clear(eEmpleado** lista, int len);
int empleado_deleteArray(eEmpleado** lista, int len);

int empleado_parseFromText(eEmpleado*** lista, int* len, char* path, int* id);
int empleado_parseFromBin(eEmpleado*** lista, int* len, char* path, int* id);

int empleado_serializeToText(eEmpleado** lista, int len, char* path);
int empleado_serializeToBin(eEmpleado** lista, int len, char* path);

int empleado_existeArchivo(char* path, char* mode);

int empleado_mostrarMenuOrdenamiento(eEmpleado** lista, int len);
int empleado_menuOpciones(int* opcion);

#endif // EMPLEADO_H_INCLUDED
