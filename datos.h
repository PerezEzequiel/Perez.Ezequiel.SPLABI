/** \brief Pide una fecha y guarda el dato obtenido en los parametros recibidos.
 *
 * \param dia int* Puntero recibido para almacenar el dia
 * \param mes int* Puntero recibido para almacenar el mes
 * \param anio int* Puntero recibido para almacenar el anio
 * \return int Devuelve 0 si los punteros son NULL, de lo contrario devuelve 1.
 *
 */
int getFecha(int* dia, int* mes, int* anio);




/** \brief Se encarga de verificar si el largo de la cadena buffer no supera el entero recibido(tamanio de cadena)
 *
 * \param buffer[] char palabra recibida
 * \param tamCadena int cantidad a comparar
 * \return int Devuelve 0 si el largo de la cadena buffer es mayor a el parametro "tamCadena" o, si la cadena buffer es NULL, de lo contrario, devuelve 1.
 *
 */
int validarBuffer(char buffer[],int tamCadena);



/** \brief Se encarga de pedir y validar una cadena
 *
 * \param msg[] char mensaje para pedir la cadena
 * \param msgError[] char mensaje de error, se utiliza si lo que se ingreso, supera el tamanio de el parametro "tam"
 * \param cadena[] char cadena donde se devuelve el dato validado.
 * \param tam int tamanio para  validar el largo.
 * \return int  Devuelve 0 si, los punteros recibidos son NULL, de lo contrario, devuelve 1.
 *
 */
int getString(char msg[],char msgError[],char cadena[], int tam);


/** \brief  Se encarga de pedir un numero telefono.
 *
 * \param msg[] char Mensaje para pedir el telefono.
 * \param msgError[] char Mensaje de error, esto se muestra si, lo que se ingreso supero el tamanio recibido por parametro o si lo que recibio no hay solo numeros.
 * \param cadena[] char cadena donde se devuelve el dato validado
 * \param tam int tamanio para  validar el largo.
 * \return int Devuelve 0 si, los punteros recibidos son NULL, de lo contrario, devuelve 1.
 *
 */
int getTelefono(char msg[],char msgError[],char cadena[], int tam);





/** \brief Valida si lo que hay en la cadena recibida son letras.
 *
 * \param cadena[] char Recibe una cadena de caracteres a analizar.
 * \return int Devuelve 0 si no es un numero o si el parametro recibido es igual a NULL. Si es son todas letras y si el puntero es diferente de NULL, devuelve un 1.
 *
 */
int sonLetras(char cadena[]);



/** \brief Analiza si lo que recibe es una letra o un numero.
 *
 * \param caracterRecibido char Recibe el caracter a analizar.
 * \return int Devuelve 0 si no es una letra, si es una letra, devuelve 1.
 *
 */
int esLetra(char caracterRecibido);







/** \brief Pide y almacena, en un puntero, un caracter.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el caracter.
 * \param caracterRecibido char* Recibe un puntero del caracter para almacenar el dato.
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es caracter.
 * \return int  Devuelve 0 si los parametros son igual a NULL, devuelve 1 si esta todo correcto.
 *
 */
int getChar(char mensaje[],char* caracterRecibido,char mensajeError[]);






/** \brief Se encarga de pedir un dato a traves de la funcion getChar y validar el caracter ingresado con los caracteres recibidos por parametros.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir
 * \param caracterRecibido char* Recibe un puntero del caracter para almacenar el dato
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es caracter.
 * \param mensajeErrorValidacion[] char Mensaje de error, se muestra si el valor del puntero "caracterRecibido" es diferente a los parametros formales "primerCaracter","SegundoCaracter"
 * \param primerCaracter char Recibe un caracter para validar.
 * \param segundoCaracter char Recibe un caracter para validar.
 * \return int Devuelve 0 si los parametros formales "mensaje","caracterRecibido","mensajeError", "mensajeErrorValidacion" son NULL, si esta todo correcto devuelve 1.
 *
 */
int getCaracter(char mensaje[],char* caracterRecibido,char mensajeError[],char mensajeErrorValidacion[],char primerCaracter,char segundoCaracter);


/** \brief Se encarga de pedir un dato a traves de la funcion getInt y validar el rango del valor del entero ingresado con los valores recibidos por parametros.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir
 * \param enteroRecibido int* Recibe un puntero del entero para almacenar el dato
 * \param mensajeError[] char Mensaje de error para mostrar al validar si es caracter.
 * \param mensajeErrorValidacion[] char Mensaje de error, se muestra si el valor del puntero "enteroRecibido" no esta en el rango de los parametros formales "minimo","maximo"
 * \param minimo int Recibe un valor minimo.
 * \param maximo int Recibe un valor maximo.
 * \return int Devuelve 0 si los parametros formales "mensaje","enteroRecibido","mensajeError", "mensajeErrorValidacion" son NULL, si esta todo correcto devuelve 1.
 *
 */
int getEntero(char mensaje[],int* enteroRecibido,char mensajeError[],char mensajeErrorValidacion[],int minimo,int maximo);


/** \brief Se encarga de validar si, el valor recibido esta entre los rangos
 *
 * \param valor int valor a analizar
 * \param minimo int valor minimo
 * \param maximo int valor maximo
 * \return int Devuelve 0 si no esta en el rango, de lo contrario, devuelve 1.
 *
 */
int validarRangoDeEnteros(int valor,int minimo,int maximo);



/** \brief Pide y almacena, en un puntero, un entero.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el entero.
 * \param resultado int* Recibe un puntero del entero donde se va a almacenar el dato.
 * \param mensajeError[] char Mensaje de error, se implementa si, lo que ingreso el usuario, no es un numero.
 * \return int Devuelve 0 si los parametros son NULL, si esta todo correcto devuelve 1.
 *
 */
int getInt(char mensaje[], int* resultado,char mensajeError[]);



/** \brief Pide y almacena, en un puntero, un flotante.
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el entero.
 * \param resultado float* Recibe un puntero del flotante donde se va a almacenar el dato.
 * \param mensajeError[] char Mensaje de error, se implementa si, lo que ingreso el usuario, no es un numero.
 * \return int Devuelve 0 si los parametros son NULL, si esta todo correcto devuelve 1.
 *
 */
int getFloat(char mensaje[], float* resultado,char mensajeError[]);



/** \brief Valida si lo que recibe es un numero.
 *
 * \param numero[] char Recibe una cadena de caracteres a analizar.
 * \return int Devuelve 0 si no es un numero o si el parametro recibido es igual a NULL. Si es un numero y si el puntero es diferente de NULL, devuelve un 1.
 *
 */
int esNumero(char numero[]);

