/** \brief Formaliza el nombre o apellido recibido
 *
 * \param cadena char* Nombre o apellido a ser formalizado
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna -1 si hubo un error (puntero NULL o l�mite inv�lido) y 0 si no
 *
 */
int utn_formatearCadena(char* cadena, int limite);


/** \brief Solicita un n�mero entero al usuario y devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el n�mero m�nimo a ser aceptado
 * \param maximo int Es el n�mero m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el n�mero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un n�mero flotante al usuario y devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo float Es el n�mero m�nimo a ser aceptado
 * \param maximo float Es el n�mero m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el n�mero y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/** \brief Solicita un n�mero double al usuario y devuelve el resultado
 *
 * \param pResultado double* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo double Es el n�mero m�nimo a ser aceptado
 * \param maximo double Es el n�mero m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el n�mero y -1 si no
 *
 */
int utn_getNumeroDouble(double* pResultado, char* mensaje, char* mensajeError, double minimo, double maximo, int reintentos);


/** \brief Solicita una cadena al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo char Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo char Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena alfab�tica al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getAlfabetico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena num�rica al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getStringNumerico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena num�rica flotante al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getStringFlotante(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena alfanum�rica al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getAlfaNumerico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena eMail al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena DNI al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getDNI(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena CUIT al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena tel�fono al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita una cadena de fecha al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es la cantidad m�nima de caracteres a ser aceptada
 * \param maximo int Es la cantidad m�xima de caracteres a ser aceptada
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo la cadena y -1 si no
 *
 */
int utn_getFecha(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un caracter al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo char Es el caracter m�nimo a ser aceptado
 * \param maximo char Es el caracter m�ximo a ser aceptado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el caracter y -1 si no
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


/** \brief Solicita un sexo al usuario y devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param reintentos int Cantidad de reintentos en el caso de error
 *
 * \return int Retorna 0 si se obtuvo el caracter y -1 si no
 *
 */
int utn_getSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos);


/** \brief Verifica si la respuesta es afirmativa
 *
 * \param mensaje char* Texto que pide el valor
 * \param mensajeError char* Texto en caso de error
 *
 * \return int Retorna 1 si la respuesta es 'S', 0 si la respuesta es 'N' o -1 si hubo un error
 *
 */
int utn_respuestaEsAfirmativa(char* mensaje, char* mensajeError);

