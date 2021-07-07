#ifndef VACUNA_H_INCLUDED
#define VACUNA_H_INCLUDED
#include "LinkedList.h"


typedef struct
{
    int id;
    char nombre[20];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
}ePais;


/** \brief Crea en la memoria una nueva estructura pais.
 *
 * \return ePais* Retorna un puntero a la memoria obtenida.
 *
 */
ePais* pais_new();


/** \brief Crea en la memoria una estructura con datos recibidos por parametro.
 *
 * \param idStr char* Id recibido
 * \param nombreStr char* Nombre recibido
 * \param vac1DosisStr char* 1 dosis
 * \param vac2DosisStr char* 2 dosis
 * \param sinVacunarStr char* Sin vacunas
 * \return ePais* Retorna NULL si, no se pudieron setear los datos o si no se pudo conseguir memoria, de lo contrario, retorna un puntero a la memoria obtenida.
 *
 */
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1DosisStr,char* vac2DosisStr,char* sinVacunarStr);

/** \brief Setea el id recibido en el puntero a pais recibido.
 *
 * \param this ePais* Puntero a empleado.
 * \param id int Id a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el id recibido es igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int pais_setId(ePais* this,int id);


/** \brief Obtiene del pais recibido, su id.
 *
 * \param this ePais* Puntero a empleado.
 * \param id int* Puntero a id.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int pais_getId(ePais* this,int* id);




/** \brief Setea el Nombre recibido en el puntero pais recibido.
 *
 * \param this ePais* Puntero a pais.
 * \param nombre char* Nombre a setear.
 * \return int Devuelve 0 si, los punteros son igual a NULL o, si el nombre contiene mas/igual de 20 caracteres. Si pudo setear correctamente devuelve 1.
 *
 */
int pais_setNombre(ePais* this,char* nombre);


/** \brief Obtiene del pais recibido, su nombre.
 *
 * \param this ePais* Puntero a empleado.
 * \param nombre char* Puntero a almacenar.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int pais_getNombre(ePais* this,char* nombre);





/** \brief Setea la 1 dosis recibida en el puntero a pais recibido.
 *
 * \param this ePais* Puntero a empleado.
 * \param vac1Dosis int dosis a a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el id recibido es igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int pais_setVac1Dosis(ePais* this,int vac1Dosis);



/** \brief Obtiene del pais recibido, su 1 dosis.
 *
 * \param this ePais* Puntero a empleado.
 * \param vac1Dosis int* Puntero a 1 dosis.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int pais_getVac1Dosis(ePais* this,int* vac1Dosis);



/** \brief Setea la 2 dosis recibida en el puntero a pais recibido.
 *
 * \param this ePais* Puntero a empleado.
 * \param vac2Dosis int dosis a a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el id recibido es igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int pais_setVac2Dosis(ePais* this,int vac2Dosis);



/** \brief Obtiene del pais recibido, su 2 dosis.
 *
 * \param this ePais* Puntero a empleado.
 * \param vac2Dosis int* Puntero a 1 dosis.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int pais_getVac2Dosis(ePais* this,int* vac2Dosis);


/** \brief Setea el numero de sin vacunar recibido en el puntero a pais recibido.
 *
 * \param this ePais* Puntero a empleado.
 * \param sinVacunar int dosis a a setear.
 * \return int Devuelve 0 si, el puntero es igual a NULL o si el id recibido es igual o menor a 0. Si pudo setear correctamente devuelve 1.
 *
 */
int pais_setSinVacunar(ePais* this,int sinVacunar);


/** \brief Obtiene del pais recibido, la gente sin vacunar.
 *
 * \param this ePais* Puntero a empleado.
 * \param sinVacunar int* Puntero a 1 dosis.
 * \return int Retorna 0 si, los punteros son diferente de NULL, de lo contrario retorna 1.
 *
 */
int pais_getSinVacunar(ePais* this,int* sinVacunar);


/** \brief Muestra un pais
 *
 * \param paisRecibida ePais* pais recibido
 * \return int Devuelve 0 si, el pais recibido es NULL, de lo contrario devuelve 1
 *
 */
int mostrarPais(ePais* paisRecibida);

/** \brief Muestra la lista de paises
 *
 * \param lista LinkedList* Lista recibida
 * \return int  * \return int Devuelve 0 si, la lista recibida es NULL, de lo contrario devuelve 1
 *
 */
int mostrarPaises(LinkedList* lista);

/** \brief Calcula y devuelve vacunas y sin vacunar aleatorios
 *
 * \param vacunaRecibida void* Elemento recibido
 * \return void* Devuelve NULL si, el puntero recibido es igual a NULL, de lo contrario devuelve el elemento con los numeros calculados.
 *
 */
void* aleatorioVacunas(void* vacunaRecibida);


/** \brief Determina si el pais esta en el horno
 *
 * \param p void* Elemento recibido
 * \return int Retorna 0 si no esta en el horno de lo contrario retorna 1
 *
 */
int filterPaisHorno(void* p);

/** \brief Determina si el pais es exitoso
 *
 * \param p void* Elemento recibido
 * \return int Retorna 0 si no es exitoso de lo contrario retorna 1
 *
 */
int filterPaisExitoso(void* p);


/** \brief Compara dos paises por su primera dosis
 *
 * \param p1 void* elemento 1
 * \param void*p2 elemento 2
 * \return int Retorna 0 si son iguales, 1 si, p1>p2 y -1 si p2<p1
 *
 */
int pais_cmp1dosis(void* p1,void*p2);


#endif // VACUNA_H_INCLUDED
