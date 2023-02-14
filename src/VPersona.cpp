/*
 * VPersona.cpp
 *
 *  Created on: Jan 29, 2023
 *      Author: guerrerody
 */


#include "VPersona.h"

VPersona::VPersona () {

}

VPersona::~VPersona() {

}

int VPersona::menuPersona() {
	Limpiar();

	ImprimirEncabezado("\n      S U B - M E N U P E R S O N A S", "      ===============================");
	ImprimirLineasBlanco(1);
	ImprimirMensaje(" [1] INCLUIR PERSONA\n");
	ImprimirMensaje(" [2] CONSULTAR PERSONA\n");
	ImprimirMensaje(" [3] MODIFICAR PERSONA\n");
	ImprimirMensaje(" [4] ELIMINAR PERSONA\n");
	ImprimirMensaje(" [5] IMPRIMIR PERSONAS\n");
	ImprimirMensaje(" [6] VOLVER AL MENU PRINCIPAL\n\n");
	return LeerValidarNro("  SELECCIONE SU OPCION : ", 1, 6);
}

void VPersona::imprimirListaPersonas(string rol, MPersona &personas) {
	Limpiar();

	ImprimirEncabezado("      LISTADO DE PERSONAS", "     ======================");
	ImprimirLineasBlanco(1);

	ImprimirString("Rol: ", rol);
	ImprimirLineasBlanco(2);

	if (personas.Vacia()) {
		ImprimirMensaje("\nNO SE ENCONTRARON PERSONAS REGISTRADAS\n");
	} else {

		ImprimirStringJustificado("Cedula", 10);
		ImprimirStringJustificado("Nombre", 20);
		ImprimirStringJustificado("Apellido", 20);
		ImprimirStringJustificado("Sexo (1=M 2=F)", 20);
		ImprimirStringJustificado("Correo", 20);
		ImprimirStringJustificado("Decanato", 20);
		ImprimirStringJustificado("Estatus Carnet", 20);

		ImprimirLineasBlanco(2);

		InfoPersona marca;
		personas.Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			InfoPersona info;
			personas.Remover(info);
			if (info.cedula.empty()) {
				finCola = true;
			} else {
				ImprimirStringJustificado(info.cedula, 10);
				ImprimirStringJustificado(info.nombre, 20);
				ImprimirStringJustificado(info.apellido, 20);
				ImprimirNroJustificado(info.sexo, 20);
				ImprimirStringJustificado(info.correo, 20);
				ImprimirStringJustificado(info.decanato, 20);
				MEstado *estado = info.pilaEstado;
				ImprimirStringJustificado(estado->Vacia() ? "<NINGUNO>" : estado->ObtTope()->ObtInfo().nombre, 20);
				ImprimirLineasBlanco(1);

				personas.Insertar(info);
			}
		}
	}
}

void VPersona::imprimirPersona(string rol, InfoPersona infoPersona) {
	Limpiar();

	ImprimirEncabezado("      INFORMACION DE LA PERSONA", "   ===============================");
	ImprimirLineasBlanco(1);

	ImprimirString("ROL: ", rol);
	ImprimirLineasBlanco(1);
	ImprimirString("CEDULA: ", infoPersona.cedula);
	ImprimirLineasBlanco(1);
	ImprimirString("NOMBRE: ", infoPersona.nombre);
	ImprimirLineasBlanco(1);
	ImprimirString("APELLIDO: ", infoPersona.apellido);
	ImprimirLineasBlanco(1);
	ImprimirNro("SEXO (1=M 2=F): ", infoPersona.sexo);
	ImprimirLineasBlanco(1);
	ImprimirString("CORREO: ", infoPersona.correo);
	ImprimirLineasBlanco(1);
	ImprimirString("DECANATO: ", infoPersona.decanato);
	ImprimirLineasBlanco(1);
	MEstado *estado = infoPersona.pilaEstado;
	ImprimirString("ESTATUS CARNET: ", estado->Vacia() ? "<NINGUNO>" : estado->ObtTope()->ObtInfo().nombre);
	ImprimirLineasBlanco(1);
}
