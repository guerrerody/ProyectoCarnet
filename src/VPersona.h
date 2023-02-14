/*
 * VPersona.h
 *
 *  Created on: Jan 29, 2023
 *      Author: guerrerody
 */

#ifndef VPERSONA_H_
#define VPERSONA_H_

#include "MPersona.h"
#include "VGeneral.h"

class VPersona: public VGeneral { //Clase vista para manejar lo que se ve por pantalla
public:
	VPersona();
	virtual ~VPersona();

	int menuPersona(); //Sub-menu para elegir una opcion (Incluir,buscar, modificar)
	void imprimirListaPersonas(string rol, MPersona &personas); //Reporte de la lista despues de incluir personas
	void imprimirPersona(string rol, InfoPersona infoPersona); //Imprimir los datos del nodo
};

#endif /* VPERSONA_H_ */
