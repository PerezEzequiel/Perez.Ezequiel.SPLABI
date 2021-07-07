#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Muestra un menu y devuelve la respuesta
 *
 * \param opciones[] char opciones recibidas
 * \param pRespuesta char* respuesta obtenida
 * \return void
 *
 */
void mostrarMenuChar(char opciones[],char* pRespuesta);


/** \brief Muestra un menu y devuelve la respuesta
 *
 * \param opciones[] char  opciones recibidas
 * \param pRespuesta int*  respuesta obtenida
 * \return void
 *
 */
void mostrarMenuInt(char opciones[],int* pRespuesta);

#endif // MENU_H_INCLUDED
