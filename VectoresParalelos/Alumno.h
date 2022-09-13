#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED


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


/** \brief Muestra el menú para los vectores paralelos
 *
 * \param op int* Puntero al espacio de memoria donde se guardará el dato validado ingresado
 *
 * \return int 0 si todo OK, -1 si no se cargó el dato o -2 si hubo un error
 *
 */
int mostrarMenuPrincipal(int* op);


/** \brief Indica que cada posición del array está vacía, estableciendo la bandera (isEmpty) en TRUE
 *
 * \param isEmpty[] int Vector de estados a ser analizado
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int inicializarAlumnos(int isEmpty[], int tam);


/** \brief Encuentra la primera posición libre del vector
 *
 * \param isEmpty[] int Vector de estados a ser analizado
 * \param tam int Límite del vector
 *
 * \return int El índice del lugar libre, -1 si no hay lugar libre o -2 si hubo un error
 *
 */
int buscarLibre(int isEmpty[], int tam);


/** \brief Verifica si el estado de cada posicion del array es TRUE
 *
 * \param isEmpty[] int Vector de estados a ser analizado
 * \param tam int Límite del vector
 *
 * \return int (-1) si hubo un error - (1) si es Verdadero - (0) si es Falso
 *
 */
int arrayIsEmpty(int isEmpty[], int tam);


/** \brief Carga algunos datos de alumnos para testear
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int hardCodearAlumnos(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


/** \brief Encuentra un alumno por su legajo
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 * \param legajo int Legajo del alumno a buscar
 *
 * \return int El índice del alumno encontrado, -1 si el legajo no existe o -2 si hubo un error
 *
 */
int buscarAlumnoPorLegajo(int legajos[], int isEmpty[], int tam, int legajo);


/** \brief Calcula el promedio de dos notas de un alumno
 *
 * \param nota1 int Primera nota del alumno
 * \param nota2 int Segunda nota del alumno
 * \param float* promedio Lugar donde se guarda el resultado de la operación
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int calcularPromedio(int nota1, int nota2, float* promedio);


/** \brief Carga un alumno en el lugar disponible encontrado
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si se cargaron los datos, -1 si el nuevo legajo ya existe,
 *            -2 si no se pudieron cargar los datos, -3 si no hay lugar,
 *            -4 si hubo un error en la búsqueda del lugar libre o -5 si hubo un error
 *
 */
int cargarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


/** \brief Elimina un alumno, buscandolo por su legajo y cambiando su bandera (isEmpty) en TRUE
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si el alumno fue eliminado, -1 si el usuario canceló la acción,
 *            -2 si el legajo no existe o -3 si hubo un error
 *
 */
int eliminarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


/** \brief Modifica un alumno, buscandolo por su legajo y cambiando el dato elegido por el usuario
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si el alumno fue eliminado, -1 si no se modificó al alumno,
 *            -2 si el usuario canceló la acción, -3 si el legajo no existe o -4 si hubo un error
 *
 */
int modificarAlumno(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


/** \brief Muestra el menú para la modificación del alumno indicado por el usuario
 *
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param tam int Límite de los vectores
 * \param index int Posición del alumno a modificar
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarMenuModificar(char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int tam, int index);


/** \brief Imprime los datos de un alumno
 *
 * \param legajo int* Legajo del alumno
 * \param nombre[] char Nombre del alumno
 * \param sexo char* Sexo del alumno
 * \param nota1 int* Primera nota del alumno
 * \param nota2 int* Segunda nota del alumno
 * \param promedio float* Promedio del alumno
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarAlumno(int* legajo, char nombre[], char* sexo, int* nota1, int* nota2, float* promedio);


/** \brief Imprime la lista de alumnos
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarListaAlumnos(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


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
int compararInt(int a, int b);


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
int compararFloat(float a, float b);


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
int compararChar(char a, char b);


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
int compararString(char a[], char b[], int length);


/** \brief Intercambia el valor de dos int
 *
 * \param a int* Primer int
 * \param b int* Segundo int
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int swapInt(int* a, int* b);


/** \brief Intercambia el valor de dos float
 *
 * \param a float* Primer float
 * \param b float* Segundo float
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int swapFloat(float* a, float* b);


/** \brief Intercambia el valor de dos char
 *
 * \param a char* Primer char
 * \param b char* Segundo char
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int swapChar(char* a, char* b);


/** \brief Intercambia el valor de dos string
 *
 * \param a[] char Primer string
 * \param b[] char Segundo string
 * \param length int Longitud de String
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int swapString(char a[], char b[], int length);


/** \brief Compara los valores de los datos de dos alumnos
 *
 * \param legajo_A int Primer legajo
 * \param nombre_A[] char Primer nombre
 * \param sexo_A char Primer sexo
 * \param nota1_A int Primera nota 1
 * \param nota2_A int Primera nota 2
 * \param promedio_A float Primer promedio
 * \param legajo_B int Segundo legajo
 * \param nombre_B[] char Segundo nombre
 * \param sexo_B char Segundo sexo
 * \param nota1_B int Segunda nota 1
 * \param nota2_B int Segunda nota 2
 * \param promedio_B float Segundo promedio
 * \param criterio int Criterio de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int compararCriterio(int legajo_A, char nombre_A[], char sexo_A, int nota1_A, int nota2_A, float promedio_A,
                     int legajo_B, char nombre_B[], char sexo_B, int nota1_B, int nota2_B, float promedio_B, int criterio);


/** \brief Ordena los alumnos según el criterio y el sentido de ordenamiento elegidos
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 * \param criterio int Criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int ordenarAlumnosSimpleCriterio(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[],
                                 float promedios[], int isEmpty[], int tam, int criterio, int order);


/** \brief Ordena los alumnos según los criterios y el sentido de ordenamiento elegidos
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 * \param criterio1 int Primer Criterio de ordenamiento
 * \param criterio2 int Segundo Criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int ordenarAlumnosDobleCriterio(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[],
                                float promedios[], int isEmpty[], int tam, int criterio1, int criterio2, int order);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int elegirSentidoOrdenamiento(int* order);


/** \brief Muestra el menú para el tipo de ordenamiento
 *
 * \param legajos[] int Vector de legajos de cada alumno
 * \param nombres[][25] char Matriz de nombres de cada alumno
 * \param sexos[] char Vector de sexos de cada alumno
 * \param notas1[] int Vector de primeras notas de cada alumno
 * \param notas2[] int Vector de segundas notas de cada alumno
 * \param promedios[] float Vector de promedios de cada alumno
 * \param isEmpty[] int Vector de estados de cada alumno
 * \param tam int Límite de los vectores
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarMenuOrdenamiento(int legajos[], char nombres[][NOMBRE_LEN], char sexos[], int notas1[], int notas2[], float promedios[], int isEmpty[], int tam);


#endif // ALUMNO_H_INCLUDED
