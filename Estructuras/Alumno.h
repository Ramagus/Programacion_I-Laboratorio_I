#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED


#include "Fecha.h"
#define NOMBRE_LEN 20
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define LEGAJO 0
#define NOMBRE 1
#define SEXO 2
#define NOTA_1 3
#define NOTA_2 4
#define PROMEDIO 5
#define FECHA 6


typedef struct
{
    int legajo;
    char nombre[NOMBRE_LEN];
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;

} eAlumno;


/** \brief Muestra el menú para las estructuras
 *
 * \param op int* Puntero al espacio de memoria donde se guardará el dato validado ingresado
 *
 * \return int 0 si todo OK, -1 si no se cargó el dato o -2 si hubo un error
 *
 */
int eAlumno_mostrarMenuPrincipal(int* op);


/** \brief Indica que cada posición del array está vacía, estableciendo la bandera (isEmpty) en TRUE
 *
 * \param lista[] eAlumno Vector de alumnos a ser analizado
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_inicializar(eAlumno lista[], int tam);


/** \brief Encuentra la primera posición libre del vector
 *
 * \param lista[] eAlumno Vector de Alumnos a ser analizado
 * \param tam int Límite del vector
 *
 * \return int El índice del lugar libre, -1 si no hay lugar libre o -2 si hubo un error
 *
 */
int eAlumno_buscarLibre(eAlumno lista[], int tam);


/** \brief Verifica si el estado de cada posicion del array es TRUE
 *
 * \param lista[] eAlumno Vector de Alumnos a ser analizado
 * \param tam int Límite del vector
 *
 * \return int (-1) si hubo un error - (1) si es Verdadero - (0) si es Falso
 *
 */
int eAlumno_arrayIsEmpty(eAlumno lista[], int tam);


/** \brief Carga algunos datos de alumnos para testear
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_hardCodear(eAlumno lista[], int tam);


/** \brief Encuentra un alumno por su legajo
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 * \param legajo int Legajo del alumno a buscar
 *
 * \return int El índice del alumno encontrado, -1 si el legajo no existe o -2 si hubo un error
 *
 */
int eAlumno_buscarPorLegajo(eAlumno lista[], int tam, int legajo);


/** \brief Calcula el promedio de dos notas de un alumno
 *
 * \param nota1 int Primera nota del alumno
 * \param nota2 int Segunda nota del alumno
 * \param float* promedio Lugar donde se guarda el resultado de la operación
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_calcularPromedio(int nota1, int nota2, float* promedio);


/** \brief Carga un alumno en el lugar disponible encontrado
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si se cargaron los datos, -1 si el nuevo legajo ya existe,
 *            -2 si no se pudieron cargar los datos, -3 si no hay lugar,
 *            -4 si hubo un error en la búsqueda del lugar libre o -5 si hubo un error
 *
 */
int eAlumno_cargar(eAlumno lista[], int tam);


/** \brief Elimina un alumno, buscandolo por su legajo y cambiando su bandera (isEmpty) en TRUE
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si el alumno fue eliminado, -1 si el usuario canceló la acción,
 *            -2 si el legajo no existe o -3 si hubo un error
 *
 */
int eAlumno_eliminar(eAlumno lista[], int tam);


/** \brief Modifica un alumno, buscandolo por su legajo y cambiando el dato elegido por el usuario
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si el alumno fue eliminado, -1 si no se modificó al alumno,
 *            -2 si el usuario canceló la acción, -3 si el legajo no existe o -4 si hubo un error
 *
 */
int eAlumno_modificar(eAlumno lista[], int tam);


/** \brief Muestra el menú para la modificación del alumno indicado por el usuario
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 * \param index int Posición del alumno a modificar
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_mostrarMenuModificar(eAlumno lista[], int tam, int index);


/** \brief Imprime los datos de un alumno
 *
 * \param unAlumno eAlumno* Un Alumno
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_mostrar(eAlumno* unAlumno);


/** \brief Imprime la lista de alumnos
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_mostrarLista(eAlumno lista[], int tam);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
int eAlumno_compararInt(int a, int b);


/** \brief Compara los valores de dos float
 *
 * \param a float Primer float
 * \param b float Segundo float
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer float es menor al segundo float
 *             ( 0) si ambos float son iguales
 *             ( 1) si el primer float es mayor al segundo float
 *
 */
int eAlumno_compararFloat(float a, float b);


/** \brief Compara los valores de dos char
 *
 * \param a char Primer char
 * \param b char Segundo char
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer char es menor al segundo char en su valor
 *             ( 0) si ambos char son iguales
 *             ( 1) si el primer char es mayor al segundo char en su valor
 *
 */
int eAlumno_compararChar(char a, char b);


/** \brief Compara los valores de dos string
 *
 * \param a[] char Primer string
 * \param b[] char Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
int eAlumno_compararString(char a[], char b[], int length);


/** \brief Intercambia los valores de dos alumnos
 *
 * \param a eAlumno* Primer Alumno
 * \param b eAlumno* Segundo Alumno
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_swap(eAlumno* a, eAlumno* b);


/** \brief Compara los valores de los datos de dos alumnos
 *
 * \param alumno_A eAlumno* Primer Alumno
 * \param alumno_B eAlumno* Segundo Alumno
 * \param criterio int Criterio de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_compararCriterio(eAlumno* alumno_A, eAlumno* alumno_B, int criterio);


/** \brief Ordena los alumnos según el criterio y el sentido de ordenamiento elegidos
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 * \param criterio int Criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_ordenarSimpleCriterio(eAlumno lista[], int tam, int criterio, int order);


/** \brief Ordena los alumnos según los criterios y el sentido de ordenamiento elegidos
 *
 * \param lista[] eAlumno Vector de Alumnos
 * \param tam int Límite del vector
 * \param criterio1 int Primer Criterio de ordenamiento
 * \param criterio2 int Segundo Criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_ordenarDobleCriterio(eAlumno lista[], int tam, int criterio1, int criterio2, int order);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_elegirSentidoOrdenamiento(int* order);


/** \brief Muestra el menú para el tipo de ordenamiento
 *
 * \param lista[] eAlumno Vector de alumnos
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int eAlumno_mostrarMenuOrdenamiento(eAlumno lista[], int tam);


#endif // ALUMNO_H_INCLUDED
