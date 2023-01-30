/*
 * VRol.h
 *
 * Author: Dorieliz Guerrero
 */

#ifndef VROL_H_
#define VROL_H_

#include "MRol.h"
#include "VGeneral.h"

class VRol: public VGeneral { //Clase vista para manejar lo que se ve por pantalla
public:
	VRol();
	virtual ~VRol();

	int menuRol(); //Sub-menu para elegir una opcion (Incluir,buscar, modificar)
	void imprimirListaRoles(MRol &rol); //Reporte de la lista despues de incluir roles
	void imprimirRol(InfoRol infoRol); //Imprimir los datos del nodo
};

#endif /* VROL_H_ */
