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

	/*
	rol.codigo = vr.LeerNro("Código del Rol: ");
	if (mr.BuscarRol(rol.codigo) != NULL) {
		vr.ImprimirMensaje("EL ROL YA EXISTE\n\n");
	} else {
		rol.nombre = vr.LeerString("Nombre: ");
		rol.descripcion = vr.LeerString("Descripción: ");
		rol.precioCarnet = vr.LeerNroDecimal("Precio Carnet: ");

		mr.IncluirRol(rol);

		vr.ImprimirMensaje("\nEL ROL SE INCLUYO SATISFACTORIAMENTE\n");
	}
	*/


	InfoRol newRol1;
	newRol1.codigo = 123;
	newRol1.nombre = "ADMIN";
	newRol1.descripcion = "Administracion";
	newRol1.precioCarnet = 12.00;
	mr.IncluirRol(newRol1);
	InfoRol newRol2;
	newRol2.codigo = 321;
	newRol2.nombre = "USER";
	newRol2.descripcion = "Usuario";
	newRol2.precioCarnet = 10.00;
	mr.IncluirRol(newRol2);
	vr.ImprimirMensaje("\nSE INCLUYEROS 2 ROLES DE PRUEBA (123 Y 321)\n");


	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::consultarRol() {
	InfoRol rol;

	vr.Limpiar();
	vr.ImprimirEncabezado("      CONSULTAR ROL", "     ================");
	vr.ImprimirLineasBlanco(1);

	rol.codigo = vr.LeerNro("Código del Rol: ");
	Nodo<InfoRol> *ptrRol = mr.BuscarRol(rol.codigo);

	if (ptrRol == NULL) {
		vr.ImprimirMensaje("ROL NO ENCONTRADO\n\n");
	} else {
		vr.imprimirRol(ptrRol->ObtInfo());
	}
	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::modificarRol() {
	InfoRol rol;

	vr.Limpiar();
	vr.ImprimirEncabezado("      MODIFICAR ROL", "     ===============");
	vr.ImprimirLineasBlanco(1);

	rol.codigo = vr.LeerNro("Código del Rol: ");
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
	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::eliminarRol() {
	vr.Limpiar();
	vr.ImprimirEncabezado("      ELIMINAR ROL", "     ==============");
	vr.ImprimirLineasBlanco(1);

	int codigo = vp.LeerNro("Código del Rol: ");
	Nodo<InfoRol> *ptrRol = mr.BuscarRol(codigo);

	if (ptrRol == NULL) {
		vr.ImprimirMensaje("ROL NO ENCONTRADO\n\n");
	} else {
		vr.imprimirRol(ptrRol->ObtInfo());
		if (vr.LeerValidarNro("Está seguro de eliminar el rol? (1)SI (2)NO: ", 1, 2) == 1) {
			InfoRol r;
			if (mr.EliminarRol(codigo, r)) {
				vr.ImprimirMensaje("ROL ELIMINADO SATISFACTORIAMENTE\n\n");
			}
		}
	}
	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
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

void Controlador::incluirPersona() {
	vp.Limpiar();
	vp.ImprimirEncabezado("      INCLUIR PERSONA", "      ===============");
	vp.ImprimirLineasBlanco(1);

	InfoPersona persona;
	persona.cedula = vp.LeerString("Cédula: ");
	if (mp.BuscarPersona(persona.cedula, persona)) {
		vp.ImprimirMensaje("LA PERSONA YA EXISTE\n\n");
	} else {
		persona.nombre = vp.LeerString("Nombre: ");
		persona.apellido = vp.LeerString("Apellido: ");
		persona.sexo = vp.LeerNro("Sexo (1)MASCULINO (2)FEMENINO: ");
		persona.correo = vp.LeerString("Correo Electrónico: ");
		persona.decanato = vp.LeerString("Decanato: ");

		do {
			int codRol = vp.LeerNro("Código de Rol: ");
			Nodo<InfoRol> *pRol = mr.BuscarRol(codRol);
			if (pRol != NULL) {
				pRol->ObtInfo().cPersonas->Insertar(persona);
				vp.ImprimirMensaje("\nLA PERSONA SE INCLUYO SATISFACTORIAMENTE\n");
				break;
			}
			vp.ImprimirMensaje("EL ROL NO EXISTE, INGRESAR ROL VALIDO\n\n");
		} while(true);
	}

	vp.ImprimirLineasBlanco(1);
	vp.Pausa();
}

void Controlador::consultarPersona() {
	vp.Limpiar();
	vp.ImprimirEncabezado("      CONSULTAR PERSONA", "      =================");
	vp.ImprimirLineasBlanco(1);

	string cedula = vp.LeerString("Cédula: ");
	Nodo<InfoRol> *pRol = mr.ObtPrimero();
	while (pRol != NULL) {
		InfoPersona personaBuscar;
		MPersona *personas = pRol->ObtInfo().cPersonas;
		if (personas->BuscarPersona(cedula, personaBuscar)) {
			vp.imprimirPersona(pRol->ObtInfo().nombre, personaBuscar);
			break;
		}
		pRol = pRol->ObtDer();
	}
	if (pRol == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
	}

	vp.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::modificarPersona() {
	vp.Limpiar();
	vp.ImprimirEncabezado("      MODIFICAR PERSONA", "      =================");
	vp.ImprimirLineasBlanco(1);

	InfoPersona persona;
	persona.cedula = vp.LeerString("Cédula: ");
	Nodo<InfoRol> *pRol = mr.ObtPrimero();
	while (pRol != NULL) {
		InfoPersona personaBuscar;
		MPersona *personas = pRol->ObtInfo().cPersonas;
		if (personas->BuscarPersona(persona.cedula, personaBuscar)) {
			vp.imprimirPersona(pRol->ObtInfo().nombre, personaBuscar);
			vp.ImprimirLineasBlanco(1);
			vp.ImprimirMensaje("INGRESE DATOS A MODIFICAR\n\n");

			persona.nombre = vp.LeerString("Nombre: ");
			persona.apellido = vp.LeerString("Apellido: ");
			persona.sexo = vp.LeerNroDecimal("Sexo (1)MASCULINO (2)FEMENINO: ");
			persona.correo = vp.LeerString("Correo Electrónico: ");
			persona.decanato = vp.LeerString("Decanato: ");

			personas->ModificarPersona(persona);

			vp.ImprimirMensaje("\nLA PERSONA SE MODIFICO SATISFACTORIAMENTE\n");

			break;
		}
		pRol = pRol->ObtDer();
	}
	if (pRol == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
	}

	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::eliminarPersona() {
	vp.Limpiar();
	vp.ImprimirEncabezado("      ELIMINAR PERSONA", "      ================");
	vp.ImprimirLineasBlanco(1);

	string cedula = vp.LeerString("Cédula: ");
	Nodo<InfoRol> *pRol = mr.ObtPrimero();
	while (pRol != NULL) {
		InfoPersona personaBuscar;
		MPersona *personas = pRol->ObtInfo().cPersonas;
		if (personas->BuscarPersona(cedula, personaBuscar)) {
			vp.imprimirPersona(pRol->ObtInfo().nombre, personaBuscar);
			if (vp.LeerValidarNro("Está seguro de eliminar la Persona? (1)SI (2)NO: ", 1, 2) == 1) {
				InfoPersona p;
				if (personas->EliminarPersona(cedula, p)) {
					vr.ImprimirMensaje("PERSONA ELIMINADA SATISFACTORIAMENTE\n\n");
				}
			}
			break;
		}
		pRol = pRol->ObtDer();
	}
	if (pRol == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
	}

	vp.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::imprimirPersonas() {
	int codigo = vp.LeerNro("Código del Rol: ");
	Nodo<InfoRol> *rol = mr.BuscarRol(codigo);

	if (rol != NULL) {
		MPersona *personas = rol->ObtInfo().cPersonas;
		vp.imprimirListaPersonas(rol->ObtInfo().nombre, *personas);
	} else {
		vp.ImprimirMensaje("EL ROL NO EXISTE\n\n");
	}
	vp.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::gestionEstados() {
	int opc;
	do {
		opc = ve.menuEstado();
		switch (opc) {
		case 1:
			incluirEstado();
			break;
		case 2:
			consultarEstado();
			break;
		case 3:
			modificarEstado();
			break;
		case 4:
			eliminarEstado();
			break;
		case 5:
			imprimirEstados();
			break;
		}
	} while (opc != 6);
}

void Controlador::incluirEstado() {
	vp.Limpiar();
	ve.ImprimirEncabezado("      INCLUIR ESTADO", "     ================");
	vp.ImprimirLineasBlanco(1);

	InfoEstado estado;
	string cedula = ve.LeerString("Cédula de Persona: ");
	Nodo<InfoRol> *pRol = mr.ObtPrimero();
	while (pRol != NULL) {
		InfoPersona personaBuscar;
		MPersona *personas = pRol->ObtInfo().cPersonas;
		if (personas->BuscarPersona(cedula, personaBuscar)) {
			vp.imprimirPersona(pRol->ObtInfo().nombre, personaBuscar);
			vp.ImprimirLineasBlanco(1);
			vp.ImprimirMensaje("INGRESE DATOS DEL ESTADO\n\n");

			estado.codigo = ve.LeerNro("Código del Estado: ");
			if (personaBuscar.pilaEstado->BuscarEstado(estado.codigo) != NULL) {
				ve.ImprimirMensaje("EL ESTADO YA EXISTE\n\n");
			} else {
				estado.nombre = ve.LeerString("Nombre: ");
				estado.fecha = ve.LeerString("Fecha: ");

				personaBuscar.pilaEstado->IncluirEstado(estado);
				personas->ModificarPersona(personaBuscar);

				ve.ImprimirMensaje("\nEL ESTADO SE INCLUYO SATISFACTORIAMENTE\n");
			}
			break;
		}
		pRol = pRol->ObtDer();
	}
	if (pRol == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
	}

	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}

void Controlador::consultarEstado() {
	/*
	InfoEstado estado;
	InfoPersona personaBuscar;
	string cedula;

	ve.Limpiar();
	ve.ImprimirEncabezado("      CONSULTAR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");

	Nodo<InfoRol> *rol = mr.ObtPrimero();
	while (rol != NULL) {
		bool resp = rol->ObtInfo().cPersonas.BuscarPersona(cedula, personaBuscar);
		if(resp == false){
			rol = rol->ObtDer();
		} else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol = NULL;
		}
	}

	estado.codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado> *e = personaBuscar.pilaEstado.BuscarEstado(estado.codigo);
	if (e != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());
	} else {
		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
	*/
}

void Controlador::modificarEstado() {
	/*
	InfoEstado estado;
	string cedula;
	InfoPersona personaBuscar;

	ve.Limpiar();
	ve.ImprimirEncabezado("      MODIFICAR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	Nodo<InfoRol> *rol = mr.ObtPrimero();
	while (rol != NULL) {
		bool resp = rol->ObtInfo().cPersonas.BuscarPersona(cedula, personaBuscar);
		if(resp == false){
			rol = rol->ObtDer();
		} else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol = NULL;
		}
	}

	estado.codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado> *e = personaBuscar.pilaEstado.BuscarEstado(estado.codigo);
	if (e != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());

		ve.ImprimirMensaje("\nINGRESAR DATOS DE ESTADO\n\n");
		estado.nombre = ve.LeerString("Nombre: ");
		estado.fecha = ve.LeerString("Fecha: ");

		personaBuscar.pilaEstado.IncluirEstado(estado);
		rol->ObtInfo().cPersonas.ModificarPersona(personaBuscar);

		ve.ImprimirMensaje("\nEL ESTADO SE INCLUYO SATISFACTORIAMENTE\n");
	} else {

		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
	*/
}

void Controlador::eliminarEstado() {
	/*
	int dec, codigo;
	string cedula;
	InfoPersona personaBuscar;

	ve.Limpiar();
	ve.ImprimirEncabezado("      ELIMINAR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");
	Nodo<InfoRol> *rol = mr.ObtPrimero();
	while (rol != NULL) {
		bool resp = rol->ObtInfo().cPersonas.BuscarPersona(cedula, personaBuscar);
		if(resp == false){
			rol = rol->ObtDer();
		} else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol = NULL;
		}
	}


	codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado> *e = personaBuscar.pilaEstado.BuscarEstado(codigo);
	if (e != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());
		dec = ve.LeerNroDecimal("Desea eliminar estado? (1)SI (2)NO: ");
		if (dec == 1) {
			personaBuscar.pilaEstado.EliminarEstado(codigo);
			rol->ObtInfo().cPersonas.ModificarPersona(personaBuscar);
		}
	} else {
		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
	*/
}

void Controlador::imprimirEstados() {
	string cedula = ve.LeerString("Cédula de Persona: ");
	Nodo<InfoRol> *pRol = mr.ObtPrimero();
	while (pRol != NULL) {
		InfoPersona personaBuscar;
		MPersona *personas = pRol->ObtInfo().cPersonas;
		if (personas->BuscarPersona(cedula, personaBuscar)) {
			vp.imprimirPersona(pRol->ObtInfo().nombre, personaBuscar);
			vp.ImprimirLineasBlanco(1);

			MEstado *estados = personaBuscar.pilaEstado;
			ve.imprimirListaEstados(*estados);

			break;
		}
		pRol = pRol->ObtDer();
	}
	if (pRol == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
	}

	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}
