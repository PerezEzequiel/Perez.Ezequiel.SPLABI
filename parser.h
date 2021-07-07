#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea un archivo recibido(texto).
 *
 * \param pFile FILE* Archivo recibido.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);




/** \brief Parsea un archivo recibido(binario).
 *
 * \param pFile FILE* Archivo recibido.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
