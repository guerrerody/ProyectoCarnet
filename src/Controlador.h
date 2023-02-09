/*
 * Controlador.h
 *
 * Author: Dorieliz Guerrero
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "MRol.h"
#include "VRol.h"
#include "MPersona.h"
#include "VPersona.h"
#include "MEstado.h"
#include "VEstado.h"

class Controlador {
private:
	MRol mr;
	VRol vr;
	MPersona mp;
	VPersona vp;
	MEstado me;
	VEstado ve;

public:
	Controlador();

	// Roles
	void gestionRoles();
	void incluirRol();
	void consultarRol();
	void modificarRol();
	void eliminarRol();
	void imprimirRoles();

	// Personas
	void gestionPersonas();
	void incluirPersona();
	void consultarPersona();
	void modificarPersona();
	void eliminarPersona();
	void imprimirPersonas();

	// Estados
	void gestionEstados();
	void incluirEstado();
	void consultarEstado();
	void modificarEstado();
	void eliminarEstado();
	void imprimirEstados();
};

#endif /* CONTROLADOR_H_ */
