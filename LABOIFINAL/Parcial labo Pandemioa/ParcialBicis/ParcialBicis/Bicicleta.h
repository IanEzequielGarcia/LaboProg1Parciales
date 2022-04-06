#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id_bike;
    char nombre[128];
    char tipo[10];
    int tiempo;
}eBicicleta;


/** \brief Guarda espacio en memoria para un pais
 *
 * \return Puntero al espacio guardado
 *
 */
eBicicleta* Bicicleta_new();


/** \brief Carga los nuevos parametros de bicicleta
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param tipoStr char*
 * \param tiempo char*
 * \return nueva bicicleta
 *
 */
eBicicleta* Bicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempo);

int Bicicleta_setIdBike(eBicicleta* this, int id);

int Bicicleta_setNombreDuenio(eBicicleta* this, char * nombre);

int Bicicleta_setTipo(eBicicleta* this, char * tipo);

int Bicicleta_setTiempo(eBicicleta* this, int tiempo);

void Bicicleta_borrar(eBicicleta* this);


/** \brief Asigna el id
 *
 * \param this eBicicleta*
 * \param id int*
 * \return int error [1] si hubo error, [0] si no hubo error
 *
 */
int Bicicleta_getIdBike(eBicicleta* this, int* id);

int Bicicleta_getNombre(eBicicleta* this, char* nombre);

int Bicicleta_getTipo(eBicicleta* this, char* tipo);

int Bicicleta_getTiempo(eBicicleta* this, int* tiempo);

int ShowBici(LinkedList* pList, int index);

int bicicleta_getTiempoRandom(void);

void* bicicleta_setTiempoRandom(void* bici);

int bicicleta_filtrarPorTipo(void* bici, char * tipo);

LinkedList* Bicicleta_NewListFilterByTipo(LinkedList* this, int (*pFuncFilter)(void*,char *));

int bicicleta_ordenarPorTipoTiempo(void * elemA, void * elemB);
#endif // BICICLETA_H_INCLUDED
