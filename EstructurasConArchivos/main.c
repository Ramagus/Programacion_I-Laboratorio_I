#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#define TAM 30

int main()
{
    eEmpleado* listaDeEmpleados[TAM];

    empleado_inicializar(listaDeEmpleados, TAM);

    empleado_parseFromText(listaDeEmpleados, TAM, "data.csv");

    empleado_mostrarLista(listaDeEmpleados, TAM);

    empleado_clear(listaDeEmpleados, TAM);

    return 0;
}
