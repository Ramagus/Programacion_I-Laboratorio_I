#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define NAME_LEN 20


typedef struct
{
    int legajo;
    char nombre[NAME_LEN];
    char sexo;
    float salario;

} eEmpleado;


eEmpleado* empleado_new(void);
eEmpleado* empleado_newParam(int legajo, char* nombre, char sexo, float salario);
eEmpleado* empleado_newParamTxt(char* legajoStr, char* nombreStr, char* sexoStr, char* salarioStr);
int empleado_delete(eEmpleado* this);

int empleado_setLegajo(eEmpleado* this, int legajo);
int empleado_setLegajoTxt(eEmpleado* this, char* legajo);
int empleado_setNombre(eEmpleado* this, char* nombre);
int empleado_setSexo(eEmpleado* this, char sexo);
int empleado_setSalario(eEmpleado* this, float salario);
int empleado_setSalarioTxt(eEmpleado* this, char* salario);

int empleado_getLegajo(eEmpleado* this, int* legajo);
int empleado_getLegajoTxt(eEmpleado* this, char* legajo);
int empleado_getNombre(eEmpleado* this, char* nombre);
int empleado_getSexo(eEmpleado* this, char* sexo);
int empleado_getSalario(eEmpleado* this, float* salario);
int empleado_getSalarioTxt(eEmpleado* this, char* salario);

int empleado_inicializar(eEmpleado** lista, int len);
int empleado_buscarLibre(eEmpleado** lista, int len, int* indice);

int empleado_clear(eEmpleado** lista, int len);
int empleado_mostrarUno(eEmpleado* this);
int empleado_mostrarLista(eEmpleado** lista, int len);

int empleado_parseFromText(eEmpleado** lista, int len, char* path);


#endif // EMPLEADO_H_INCLUDED
