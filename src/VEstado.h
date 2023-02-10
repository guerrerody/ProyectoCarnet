/*
 * VEstado.h
 *
 *  Created on: Jan 29, 2023
 *      Author: jsayago77
 */

#ifndef VEstado_H_
#define VEstado_H_

#include "MEstado.h"
#include "VGeneral.h"

class VEstado: public VGeneral { //Clase vista para manejar lo que se ve por pantalla
public:
	VEstado();
	virtual ~VEstado();

	int menuEstado(); //Sub-menu para elegir una opcion (Incluir,buscar, modificar)
	void imprimirListaEstados(MEstado &rol); //Reporte de la lista despues de incluir Estados
	void imprimirEstado(InfoEstado infoEstado); //Imprimir los datos del nodo
};

#endif /* VEstado_H_ */
