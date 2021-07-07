/** \brief Carga en el programa, los datos de un archivo de texto.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayList LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList);



/** \brief Recibe una lista y mapea vacunas en los paises
 *
 * \param pArrayList LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_mapVacunas(LinkedList* pArrayList);


/** \brief Muestra la lista de  paises.
 *
 * \param pArrayList LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */

int controller_ListPaises(LinkedList* pArrayList);




/** \brief Ordena la lista de  paises.
 *
 * \param pListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_sortPais(LinkedList* pArrayList);




/** \brief Guarda la lista(modo texto) en la ruta recibida.
 *
 * \param path char* Ruta recibida.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son NULL, de lo contrario retorna 1.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);





/** \brief Guarda en un archivo de texto los paises exitosos
 *
 * \param char*path ruta recibida
 * \param pArrayList LinkedList* lista recibida
 * \return int Retorna 0 si los punteros son NULL, de lo contrario retorna 1.
 *
 */
int controller_saveFilterExitoso(char*path,LinkedList* pArrayList);


/** \brief Guarda en un archivo de texto los paises en el horno.
 *
 * \param char*path ruta recibida
 * \param pArrayList LinkedList* lista recibida
 * \return int Retorna 0 si los punteros son NULL, de lo contrario retorna 1.
 *
 */
int controller_saveFilterHorno(char*path,LinkedList* pArrayList);



/** \brief Muestra los paises mas castigados
 *
 * \param pListEmployee LinkedList* Lista recibida
 * \return int Retorna 0 si la lista es NULL, de lo contrario retorna 1
 *
 */
int controller_paisCastigado(LinkedList* pListEmployee);
