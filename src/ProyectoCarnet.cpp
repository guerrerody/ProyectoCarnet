//============================================================================
// Name        : ProyectoCarnet.cpp
// Author      : Dorieliz Guerrero
//============================================================================

#include "Controlador.h"

int main() {

	int opc;
	Controlador c;
	VGeneral vg;
	do {
		vg.Limpiar();
		vg.ImprimirEncabezado("\n      M E N U  P R I N C I P A L\n", "    ==============================");
		vg.ImprimirMensaje("[1] GESTIÓN DE ROLES\n");
		vg.ImprimirMensaje("[2] GESTIÓN DE PERSONAS\n");
		vg.ImprimirMensaje("[3] GESTIÓN DE ESTADO\n");
		vg.ImprimirMensaje("[4] FINALIZAR\n\n");
		opc = vg.LeerValidarNro("  SELECCIONE SU OPCION : ", 1, 3);
		switch (opc) {
		case 1:
			c.gestionRoles();
			break;
		case 2:
			c.gestionPersonas();
			break;
		/*case 3:
			c.gestionEstado();
			break;*/
		}
	} while (opc != 4);
	return 0;
}
