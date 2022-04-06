/*
 * parser.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Funciones.h"
int parser_FromText(FILE* pFile, LinkedList* pArrayListeEmergencia);
int parser_FromBinary(FILE* pFile , LinkedList* pArrayListeEmergencia);



#endif /* PARSER_H_ */
