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

int VPersona::menuPersona(){
	Limpiar();

		ImprimirEncabezado("\n      S U B - M E N U P E R S O N  A S", "      ==========================");
		ImprimirLineasBlanco(1);
		ImprimirMensaje(" [1] INCLUIR PERSONA\n");
		ImprimirMensaje(" [2] CONSULTAR PERSONA\n");
		ImprimirMensaje(" [3] MODIFICAR PERSONA\n");
		ImprimirMensaje(" [4] ELIMINAR PERSONA\n");
		ImprimirMensaje(" [5] IMPRIMIR PERSONAS\n");
		ImprimirMensaje(" [6] VOLVER AL MENU PRINCIPAL\n\n");
		return LeerValidarNro("  SELECCIONE SU OPCION : ", 1, 6);

}
void VPersona::imprimirListaPersonas(MPersona &persona){ // HAY QUE ESCOGER LA LISTA DE PERSONAS DEPENDE DEL ROL
	Limpiar();

		ImprimirEncabezado("\n      LISTADO DE PERSONAS", "   ======================");
		ImprimirLineasBlanco(1);

		if (persona.Vacia()) {
			ImprimirMensaje("\nNO SE ENCONTRARON PERSONAS REGISTRADAS\n");
		} else {

			ImprimirStringJustificado("Código", 8);
			ImprimirStringJustificado("Cedula", 9);
			ImprimirStringJustificado("Nombre", 20);
			ImprimirStringJustificado("Apellido", 20);
			ImprimirStringJustificado("Sexo", 8);
			ImprimirStringJustificado("Tipo Persona", 8);
			ImprimirStringJustificado("Correo", 20);
			ImprimirStringJustificado("Decanato", 20);
			ImprimirStringJustificado("Pila Estatus", 20);

			ImprimirLineasBlanco(2);

			Nodo<InfoPersona> *p = persona.ObtPrimero(); // HAY QUE APLICAR LA MARCA
			while (p != NULL) {
				InfoPersona info = p->ObtInfo();

				ImprimirNroJustificado(info.codigo, 8);
				ImprimirStringJustificado(info.nombre, 20);
				ImprimirStringJustificado(info.apellido, 20);
				ImprimirNroJustificado(info.sexo, 8);
				ImprimirNroJustificado(info.tipoPersona, 8);
				ImprimirStringJustificado(info.correo, 20);
				ImprimirStringJustificado(info.decanato, 20);
				ImprimirStringJustificado(info.pilaEstatus, 20);
				ImprimirLineasBlanco(1);

				p = p->ObtDer();
			}
		}

		ImprimirLineasBlanco(2);

		Pausa();

}
void VPersona::imprimirPersona(InfoPersona infoPersona){
	Limpiar();

		ImprimirEncabezado("      INFORMACION DE LA PERSONA", "   ================================");
		ImprimirLineasBlanco(1);

		ImprimirNro("CODIGO: ", infoPersona.codigo);
		ImprimirLineasBlanco(2);
		ImprimirString("NOMBRE: ", infoPersona.nombre);
		ImprimirLineasBlanco(2);
		ImprimirString("APELLIDO: ", infoPersona.apellido);
		ImprimirLineasBlanco(2);
		ImprimirNro("SEXO: ", infoPersona.sexo);
		ImprimirLineasBlanco(2);
		ImprimirNro("TIPO DE PERSONA: ", infoPersona.tipoPersona);
		ImprimirLineasBlanco(2);
		ImprimirString("CORREO: ", infoPersona.correo);
		ImprimirLineasBlanco(2);
		ImprimirString("DECANATO: ", infoPersona.decanato);
		ImprimirLineasBlanco(2);
		ImprimirString("ESTATUS DE LA PILA: ", infoPersona.pilaEstatus);
		ImprimirLineasBlanco(2);

		Pausa();

}
