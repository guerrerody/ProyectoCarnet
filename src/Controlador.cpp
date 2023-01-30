/*
 * Controlador.cpp
 *
 * Author: Dorieliz Guerrero
 */

#include "Controlador.h"

Controlador::Controlador() {
}

void Controlador::gestionRoles() {
	int opc;
	do {
		opc = vr.menuRol();
		switch (opc) {
		case 1:
			incluirRol();
			break;
		case 2:
			consultarRol();
			break;
		case 3:
			modificarRol();
			break;
		case 4:
			eliminarRol();
			break;
		case 5:
			imprimirRoles();
			break;
		}
	} while (opc != 6);
}

void Controlador::incluirRol() {
	InfoRol rol;

	vr.Limpiar();
	vr.ImprimirEncabezado("      INCLUIR ROL", "   ================");
	vr.ImprimirLineasBlanco(1);

	rol.codigo = vr.LeerNro("Código: ");
	if (mr.BuscarRol(rol.codigo) != NULL) {
		vr.ImprimirMensaje("EL ROL YA EXISTE\n\n");
	} else {
		rol.nombre = vr.LeerString("Nombre: ");
		rol.descripcion = vr.LeerString("Descripción: ");
		rol.precioCarnet = vr.LeerNroDecimal("Precio Carnet: ");

		mr.IncluirRol(rol);

		vr.ImprimirMensaje("\nEL ROL SE INCLUYO SATISFACTORIAMENTE\n");
	}
	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::consultarRol() {
	InfoRol rol;

	vr.Limpiar();
	vr.ImprimirEncabezado("      CONSULTAR ROL", "   ================");
	vr.ImprimirLineasBlanco(1);

	rol.codigo = vr.LeerNro("Código: ");
	Nodo<InfoRol> *ptrRol = mr.BuscarRol(rol.codigo);

	if (ptrRol == NULL) {
		vr.ImprimirMensaje("ROL NO ENCONTRADO\n\n");
		vr.ImprimirLineasBlanco(1);
		vr.Pausa();
	} else {
		vr.imprimirRol(ptrRol->ObtInfo());
	}
}

void Controlador::modificarRol() {
	InfoRol rol;

	vr.Limpiar();
	vr.ImprimirEncabezado("      MODIFICAR ROL", "   ================");
	vr.ImprimirLineasBlanco(1);

	rol.codigo = vr.LeerNro("Código: ");
	Nodo<InfoRol> *ptrRol = mr.BuscarRol(rol.codigo);

	if (ptrRol == NULL) {
		vr.ImprimirMensaje("EL ROL NO EXISTE\n\n");
	} else {
		rol.nombre = vr.LeerString("Nombre: ");
		rol.descripcion = vr.LeerString("Descripción: ");
		rol.precioCarnet = vr.LeerNroDecimal("Precio Carnet: ");

		mr.ModificarRol(rol);

		vr.ImprimirMensaje("\nEL ROL SE MODIFICO SATISFACTORIAMENTE\n");
	}

	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::imprimirRoles() {
	vr.imprimirListaRoles(mr);
}

void Controlador::eliminarRol() {


}

void Controlador::gestionPersonas() {
	int opc;
		do {
			opc = vp.menuPersona();
			switch (opc) {
			case 1:
				incluirPersona();
				break;
			case 2:
				consultarPersona();
				break;
			case 3:
				modificarPersona();
				break;
			case 4:
				eliminarPersona();
				break;
			case 5:
				imprimirPersonas();
				break;
			}
		} while (opc != 6);

}
void Controlador::incluirPersona(){

}
void Controlador::consultarPersona(){

}
void Controlador::modificarPersona(){

}
void Controlador::eliminarPersona(){

}
void Controlador::imprimirPersonas(){
	vp.imprimirListaPersonas(mp);

}

