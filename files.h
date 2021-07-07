#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

/** \brief Verifica si el path recibido(texto) ya existe.
 *
 * \param path[] char path recibido
 * \return int Retorna 0 si el parametro recibido es NULL o si no existe el path, de lo contrario retorna 1.
 *
 */
int file_verifyPathText(char path[]);


/** \brief Verifica si el path recibido(bin) ya existe.
 *
 * \param path[] char path recibido
 * \return int Retorna 0 si el parametro recibido es NULL o si no existe el path, de lo contrario retorna 1.
 *
 */
int file_verifyPathBinary(char path[]);




/** \brief Pide un path al usuario.
 *
 * \param msg[] char Mensaje recibido.
 * \param path[] char Puntero para almacenar el path ingresado por el usuario.
 * \return int Retorna 0 si, los parametros recibidos son NULL, de lo contrario retorna 1.
 *
 */
int file_getPath(char msg[],char path[]);





/** \brief Pide y valida un path.
 *
 * \param msg[] char Mensaje a mostrar.
 * \param path[] char Path a almacenar.
 * \param textOrBinary int Recibe un 0 si, desea validar para un archivo de texto, 1 si desea validar para un archivo binario.
 * \return int Retorna 0 si, los punteros pasados son NULL o, si el parametro textOrBinary es diferente de 0 o de 1 o, si NO existe el archivo. De lo contrario devuelve 1.
 *
 */
int file_getAndValidatePath(char msg[],char path[],int textOrBinary);




#endif // FILES_H_INCLUDED
