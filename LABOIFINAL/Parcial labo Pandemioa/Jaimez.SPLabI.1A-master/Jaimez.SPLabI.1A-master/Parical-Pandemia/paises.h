#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}ePais;


/** \brief Guarda espacio en memoria para un pais
 *
 * \return Puntero al espacio guardado
 *
 */
ePais* nuevo_Pais();


/** \brief Carga los nuevos parametros de paises
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param recuperadosStr char*
 * \param infectadosStr char*
 * \param muertosStr char*
 * \return nuevo pais
 *
 */
ePais* paisesParametros(char* idStr, char* nombreStr, char* recuperadosStr, char* infectadosStr, char* muertosStr);


/** \brief Borra un pais
 *
 * \param this ePais*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int borrar_pais(ePais* this);


/** \brief Carga el id
 *
 * \param this ePais*
 * \param id int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_setId(ePais* this, int id);


/** \brief Carga el nombre
 *
 * \param this ePais*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_setNombre(ePais* this, char* nombre);


/** \brief Carga el numero de recuperados
 *
 * \param this ePais*
 * \param recuperados int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_setRecuperados(ePais* this, int recuperados);


/** \brief Carga la cantidad de infectados
 *
 * \param this ePais*
 * \param infectados int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_setInfectados(ePais* this, int infectados);


/** \brief Carga la cantidad de muertos
 *
 * \param this ePais*
 * \param muertos int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_setMuertos(ePais* this, int muertos);


/** \brief Asigna el id a un pais
 *
 * \param this ePais*
 * \param id int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_getId(ePais* this, int* id);


/** \brief Asigna el nombre a un pais
 *
 * \param this ePais*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_getNombre(ePais* this, char* nombre);


/** \brief Asigna el numero de recuperados a un pais
 *
 * \param this ePais*
 * \param recuperados int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_getRecuperados(ePais* this, int* recuperados);


/** \brief Asigna la cantidad de infectados a un pais
 *
 * \param this ePais*
 * \param infectados int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_getInfectados(ePais* this, int* infectados);


/** \brief Asigna la cantidad de muertos a un pais
 *
 * \param this ePais*
 * \param muertos int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int pais_getMuertos(ePais* this, int* muertos);


/** \brief Muestra un pais si la lista no esta vacia
 *
 * \param pLista LinkedList*
 * \param indice int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int mostrarPais(LinkedList* pLista, int indice);


/** \brief Asigna cantidad aleatoria a recuperados
 *
 * \param void
 * \return aleatorio int
 *
 */
int cantidad_getRecuperados(void);


/** \brief Asigna cantidad aleatoria a infectados
 *
 * \param void
 * \return aleatorio int
 *
 */
int cantidad_getInfectados(void);


/** \brief Asigna cantidad aleatoria a muertos
 *
 * \param void
 * \return aleatorio int
 *
 */
int cantidad_getMuertos(void);


/** \brief Carga cantidad aleatoria a recuperados
 *
 * \param recuperados void*
 * \return recuperado
 *
 */
void* set_cantRecuperados(void* recuperados);


/** \brief Carga cantidad aleatoria a infectados
 *
 * \param infectados void*
 * \return infectado
 *
 */
void* set_cantInfectados(void* infectados);


/** \brief Carga cantidad aleatoria a muertos
 *
 * \param muertos void*
 * \return muerto
 *
 */
void* set_cantMuertos(void* muertos);


/** \brief Filtra los paises mas exitosos
 *
 * \param paisExitoso void*
 * \return int auxReturn
 *
 */
int filtrarxExitosos(void* paisExitoso);


/** \brief Filtra los paises mas perjudicados
 *
 * \param paisPerjudicado void*
 * \return int auxReturn
 *
 */
int filtrarxPerjudicados(void* paisPerjudicado);


/** \brief Ordena los paises por la cantidad que infectados de manera descendente
 *
 * \param x void*
 * \param y void*
 * \return int cambio
 *
 */
int ordenarPaisxInfectados(void* x, void* y);

#endif // PAISES_H_INCLUDED
