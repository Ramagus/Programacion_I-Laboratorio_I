#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

} eFecha;


/** \brief Carga los datos de una fecha
 *
 * \param unaFecha eFecha* Puntero a una fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eFecha_cargar(eFecha* unaFecha);


/** \brief Verifica si los datos de una fecha son correctos
 *
 * \param dia int Día de la fecha
 * \param mes int Mes de la fecha
 * \param anio int Año de la fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eFecha_validar(int dia, int mes, int anio);


/** \brief Verifica si el año de la fecha es bisiesto
 *
 * \param anio int Año de la fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eFecha_esBisiesto(int anio);


/** \brief Muestra los datos de una fecha
 *
 * \param unaFecha eFecha* Puntero a una fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eFecha_mostrar(eFecha* unaFecha);


/** \brief Compara los valores de dos int
 *
 * \param a long int Primer long int
 * \param b long int Segundo long int
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
int eFecha_compararLongInt(long int a, long int b);


/** \brief Compara los valores de dos Fechas
 *
 * \param a eFecha* Primera Fecha
 * \param b eFecha* Segunda Fecha
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si la primera Fecha es menor a la segunda Fecha
 *             ( 0) si ambas Fechas son iguales
 *             ( 1) si la primera Fecha es mayor a la segunda Fecha
 *
 */
int eFecha_comparar(eFecha* a, eFecha* b);


#endif /* FECHA_H_ */
