/*
 * VRol.cpp
 *
 * Author: Dorieliz Guerrero
 */

#include "VRol.h"
#include "Nodo.h"

VRol::VRol() {

}

VRol::~VRol() {

}

int VRol::menuRol() {
	Limpiar();

	ImprimirEncabezado("\n      S U B - M E N U  R O L E S", "      ==========================");
	ImprimirLineasBlanco(1);
	ImprimirMensaje(" [1] INCLUIR ROL\n");
	ImprimirMensaje(" [2] CONSULTAR ROL\n");
	ImprimirMensaje(" [3] MODIFICAR ROL\n");
	ImprimirMensaje(" [4] ELIMINAR ROL\n");
	ImprimirMensaje(" [5] IMPRIMIR ROLES\n");
	ImprimirMensaje(" [6] VOLVER AL MENU PRINCIPAL\n\n");
	return LeerValidarNro("  SELECCIONE SU OPCION : ", 1, 6);
}

void VRol::imprimirListaRoles(MRol &rol) {
	Limpiar();

	ImprimirEncabezado("\n      LISTADO DE ROLES", "   ======================");
	ImprimirLineasBlanco(1);

	if (rol.Vacia()) {
		ImprimirMensaje("\nNO SE ENCONTRARON ROLES REGISTRADOS\n");
	} else {

		ImprimirStringJustificado("Código", 8);
		ImprimirStringJustificado("Nombre", 20);
		ImprimirStringJustificado("Descripción", 50);
		ImprimirStringJustificado("Censados", 15);
		ImprimirStringJustificado("Precio Carnet", 15);

		ImprimirLineasBlanco(2);

		Nodo<InfoRol> *p = rol.ObtPrimero();
		while (p != NULL) {
			InfoRol info = p->ObtInfo();

			ImprimirNroJustificado(info.codigo, 8);
			ImprimirStringJustificado(info.nombre, 20);
			ImprimirStringJustificado(info.descripcion, 50);
			ImprimirNroJustificado(info.cantCensados, 15);
			ImprimirNroDecimalJustificado(info.precioCarnet, 15);
			ImprimirLineasBlanco(1);

			p = p->ObtDer();
		}
	}
}

void VRol::imprimirRol(InfoRol infoRol) {
	Limpiar();

	ImprimirEncabezado("      INFORMACION DEL ROL", "   ================================");
	ImprimirLineasBlanco(1);

	ImprimirNro("CODIGO: ", infoRol.codigo);
	ImprimirLineasBlanco(1);
	ImprimirString("NOMBRE: ", infoRol.nombre);
	ImprimirLineasBlanco(1);
	ImprimirString("DESCRIPCION: ", infoRol.descripcion);
	ImprimirLineasBlanco(1);
	ImprimirNro("CANTIDAD CENSADOS: ", infoRol.cantCensados);
	ImprimirLineasBlanco(1);
	ImprimirNroDecimal("PRECIO DEL CARNET:  ", infoRol.precioCarnet);
	ImprimirLineasBlanco(1);
}
