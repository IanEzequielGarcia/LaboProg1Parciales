#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


/** \brief Carga los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int cargarTexto(char* path , LinkedList* pLista);


/** \brief Lista a los paises
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int mostrarPaises(LinkedList* pLista);


/** \brief Guarda los datos de los paises en el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int guardarComoTexto(char* path, LinkedList* pLista);


/** \brief Ordena los paises
 *
 * \param pLista LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int ordenarPaises(LinkedList* pLista);


/** \brief Ordena los paises en los mas catigados por la cantidad de muertos
 *
 * \param this LinkedList*
 * \return listaMap LinkedList*
 *
 */
LinkedList* paisesMasCatigados(LinkedList* this);

#endif // CONTROLLER_H_INCLUDED
