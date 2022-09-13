#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


#define DESC_LEN 20
#define MAX 10
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 1000
#define MAC 1001
#define IPAD 1002
#define ACCESORIOS 1003
#define ID 0
#define DESC 1
#define NAC 2
#define TIPO 3
#define PRECIO 4


/** \brief Muestra el menu para los vectores paralelos
 *
 * \param op char* Puntero al espacio de memoria donde se guardará el dato validado ingresado
 *
 * \return int 0 si todo OK, -1 si no se cargó el dato o -2 si hubo un error
 *
 */
int mostrarMenuPrincipal(char* op);


/** \brief Indica que cada posición del array está vacía, estableciendo la bandera (isEmpty) en TRUE
 *
 * \param isEmpty[] int Vector de estados a ser analizado
 * \param tam int Límite del vector
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int inicializarProductos(int isEmpty[], int tam);


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


/** \brief Carga algunos datos de productos para testear
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param descripciones[][20] char Matriz de descripciones de cada producto
 * \param nacionalidades[] int Vector de nacionalidades de cada producto
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 * \param id int* ID del producto a cargar
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int hardCodearProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int* id);


/** \brief Encuentra un producto por su ID
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 * \param id int ID del producto a buscar
 *
 * \return int El índice del producto encontrado, -1 si el ID no existe o -2 si hubo un error
 *
 */
int buscarProductoPorId(int ids[], int isEmpty[], int tam, int id);


/** \brief Establece la Nacionalidad elegida
 *
 * \param nacionalidad int* Lugar donde se guardará la nacionalidad elegida
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int elegirNac(int* nacionalidad);


/** \brief Establece el Tipo elegido
 *
 * \param tipo int* Lugar donde se guardará el tipo elegido
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int elegirTipo(int* tipo);


/** \brief Carga un producto en el lugar disponible encontrado
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param descripciones[][20] char Matriz de descripciones de cada producto
 * \param nacionalidades[] int Vector de nacionalidades de cada producto
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 * \param id int* ID del producto a cargar
 *
 * \return int 0 si se cargaron los datos, -1 si el nuevo legajo ya existe,
 *            -2 si no se pudieron cargar los datos, -3 si no hay lugar,
 *            -4 si hubo un error en la búsqueda del lugar libre o -5 si hubo un error
 *
 */
int cargarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int* id);


/** \brief Elimina un producto, buscandolo por su ID y cambiando su bandera (isEmpty) en TRUE
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param descripciones[][20] char Matriz de descripciones de cada producto
 * \param nacionalidades[] int Vector de nacionalidades de cada producto
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 *
 * \return int 0 si el producto fue eliminado, -1 si el usuario canceló la acción,
 *            -2 si el ID no existe o -3 si hubo un error
 *
 */
int eliminarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam);


/** \brief Modifica un producto, buscandolo por su ID y cambiando el dato elegido por el usuario
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param descripciones[][20] char Matriz de descripciones de cada producto
 * \param nacionalidades[] int Vector de nacionalidades de cada producto
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 *
 * \return int 0 si el producto fue eliminado, -1 si no se modificó al producto,
 *            -2 si el usuario canceló la acción, -3 si el ID no existe o -4 si hubo un error
 *
 */
int modificarProducto(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam);


/** \brief Muestra el menu para la modificación del producto indicado por el usuario
 *
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param tam int Límite de los vectores
 * \param index int Posición del producto a modificar
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarMenuModificar(int tipos[], float precios[], int tam, int index);


/** \brief Carga la descripción de una Nacionalidad
 *
 * \param nacionalidad int Número de Nacionalidad del producto
 * \param descripcion[] char Descripción de Nacionalidad a ser cargada
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int cargarDescNac(int nacionalidad, char descripcion[]);


/** \brief Carga la descripción de un Tipo
 *
 * \param tipo int Número de Tipo del producto
 * \param descripcion[] char Descripción de Tipo a ser cargada
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int cargarDescTipo(int tipo, char descripcion[]);


/** \brief Imprime los datos de un producto
 *
 * \param id int* ID del producto
 * \param descripcion[] char Descripción del producto
 * \param nacionalidad int* Nacionalidad del producto
 * \param tipo int* Tipo del producto
 * \param precio float* Precio del producto
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarProducto(int* id, char descripcion[], int* nacionalidad, int* tipo, float* precio);


/** \brief Imprime la lista de productos
 *
 * \param ids[] int Vector de IDs de cada producto
 * \param descripciones[][20] char Matriz de descripciones de cada producto
 * \param nacionalidades[] int Vector de nacionalidades de cada producto
 * \param tipos[] int Vector de tipos de cada producto
 * \param precios[] float Vector de precios de cada producto
 * \param isEmpty[] int Vector de estados de cada producto
 * \param tam int Límite de los vectores
 *
 * \return int 0 si todo OK, o -1 si hubo un error
 *
 */
int mostrarListaProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error
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
 * \return int (-2) si hubo un error
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
 * \return int (-2) si hubo un error
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
 * \return int (-2) si hubo un error
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


/** \brief Compara los valores de los datos de dos productos
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
int compararCriterio(int id_A, char descripcion_A[], int nacionalidad_A, int tipo_A, float precio_A,
                     int id_B, char descripcion_B[], int nacionalidad_B, int tipo_B, float precio_B, int criterio);


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
int ordenarProductos(int ids[], char descripciones[][DESC_LEN], int nacionalidades[], int tipos[], float precios[], int isEmpty[], int tam, int criterio, int order);


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


#endif // PRODUCTO_H_INCLUDED
