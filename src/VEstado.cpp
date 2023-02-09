/*
 * VEstado.cpp
 *
 *  Created on: Feb 07, 2023
 *      Author: jsayago77
 */


#include "VEstado.h"

VEstado::VEstado () {

}

VEstado::~VEstado() {

}

int VEstado::menuEstado(){
	Limpiar();

		ImprimirEncabezado("\n      S U B - M E N U  E S T A D O ", "      ==========================");
		ImprimirLineasBlanco(1);
		ImprimirMensaje(" [1] INCLUIR ESTADO\n");
		ImprimirMensaje(" [2] CONSULTAR ESTADO\n");
		ImprimirMensaje(" [3] MODIFICAR ESTADO\n");
		ImprimirMensaje(" [4] ELIMINAR ESTADO\n");
		ImprimirMensaje(" [5] IMPRIMIR ESTADOS\n");
		ImprimirMensaje(" [6] VOLVER AL MENU PRINCIPAL\n\n");
		return LeerValidarNro("  SELECCIONE SU OPCION : ", 1, 6);

}
void VEstado::imprimirListaEstados(MEstado &Estado){ // HAY QUE ESCOGER LA LISTA DE EstadoS DEPENDE DEL ROL
	Limpiar();

		ImprimirEncabezado("\n      LISTADO DE ESTADOS", "   ======================");
		ImprimirLineasBlanco(1);

		if (Estado.Vacia()) {
			ImprimirMensaje("\nNO SE ENCONTRARON ESTADOS REGISTRADAS\n");
		} else {

			ImprimirStringJustificado("Código", 8);
			ImprimirStringJustificado("Nombre", 20);
			ImprimirStringJustificado("Fecha", 20);

			ImprimirLineasBlanco(2);

			Nodo<InfoEstado> *p = Estado.ObtTope(); // HAY QUE APLICAR LA MARCA
			while (p != NULL) {
				InfoEstado info = p->ObtInfo();

				ImprimirNroJustificado(info.codigo, 8);
				ImprimirStringJustificado(info.nombre, 20);
				ImprimirStringJustificado(info.fecha, 20);
				ImprimirLineasBlanco(1);

				p = p->ObtDer();
			}
		}

		ImprimirLineasBlanco(2);

		Pausa();

}
void VEstado::imprimirEstado(InfoEstado infoEstado){
	Limpiar();

		ImprimirEncabezado("      INFORMACION DE ESTADO", "   ================================");
		ImprimirLineasBlanco(1);

		ImprimirNro("CODIGO: ", infoEstado.codigo);
		ImprimirLineasBlanco(2);
		ImprimirString("NOMBRE: ", infoEstado.nombre);
		ImprimirLineasBlanco(2);
		ImprimirString("FECHA: ", infoEstado.fecha);
		ImprimirLineasBlanco(2);

		Pausa();

}
