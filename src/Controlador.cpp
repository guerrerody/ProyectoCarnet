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

		MPersona p;
		rol.cPersonas = p;

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
	int dec, codigo;

	vr.Limpiar();
	vr.ImprimirEncabezado("      ELIMINAR ROL", "   ================");
	vr.ImprimirLineasBlanco(1);

	codigo = vp.LeerNroDecimal("Código: ");
	Nodo<InfoRol> *ptrRol = mr.BuscarRol(codigo);

	if (ptrRol == NULL) {
		vr.ImprimirMensaje("ROL NO ENCONTRADO\n\n");
		vr.ImprimirLineasBlanco(1);
		vr.Pausa();
	} else {
		vr.ImprimirMensaje("ROL ENCONTRADO\n\n");
		vr.imprimirRol(ptrRol->ObtInfo());
		dec = vr.LeerNroDecimal("Desea eliminar el rol? (1)SI (2)NO: ");
		if(dec == 1){
			InfoRol r;
			mr.EliminarRol(codigo, r);
		}
	}

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
	InfoPersona persona;

	vp.Limpiar();
	vp.ImprimirEncabezado("      INCLUIR PERSONA", "   ================");
	vp.ImprimirLineasBlanco(1);

	persona.cedula = vp.LeerString("Cédula: ");
	if (mp.BuscarPersona(persona.cedula) != NULL) {
		vp.ImprimirMensaje("LA PERSONA YA EXISTE\n\n");
	} else {
		persona.codigo = vp.LeerNroDecimal("Código: ");
		persona.nombre = vp.LeerString("Nombre: ");
		persona.apellido = vp.LeerString("Apellido: ");
		persona.sexo = vp.LeerNroDecimal("Sexo (1)MASCULINO (2)FEMENINO: ");
		persona.correo = vp.LeerString("Correo Electrónico: ");
		persona.decanato = vp.LeerString("Decanato: ");
		persona.tipoPersona = vp.LeerNroDecimal("Código de Rol: ");

		MEstado e;
		persona.pilaEstado = e;

		Nodo<InfoRol> *rol = mr.BuscarRol(persona.tipoPersona);
		while(rol == NULL){
			vp.ImprimirMensaje("EL ROL NO EXISTE, INGRESAR ROL VALIDO\n\n");
			persona.tipoPersona = vp.LeerNroDecimal("Código de Rol: ");
			rol = mr.BuscarRol(persona.tipoPersona);
		};

		rol->ObtInfo().cPersonas.Insertar(persona);

		vp.ImprimirMensaje("\nLA PERSONA SE INCLUYO SATISFACTORIAMENTE\n");
	}
	vp.ImprimirLineasBlanco(1);
	vp.Pausa();
}
void Controlador::consultarPersona(){
	InfoPersona persona;
	Nodo<InfoPersona> *ptrPersona;

	vp.Limpiar();
	vp.ImprimirEncabezado("      CONSULTAR PERSONA", "   ================");
	vp.ImprimirLineasBlanco(1);

	persona.cedula = vp.LeerString("Cédula: ");

	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(persona.cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			rol == NULL;
		};
	}
	if(ptrPersona == NULL){
			vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
			vp.ImprimirLineasBlanco(1);
			vr.Pausa();
		} else {
			vp.imprimirPersona(ptrPersona->ObtInfo());
		}
}

void Controlador::modificarPersona(){
	InfoPersona persona;
	Nodo<InfoPersona> *ptrPersona;

	vp.Limpiar();
	vp.ImprimirEncabezado("      MODIFICAR PERSONA", "   ================");
	vp.ImprimirLineasBlanco(1);

	persona.cedula = vp.LeerString("Cédula: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(persona.cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			rol == NULL;
		};
	}

	if (ptrPersona == NULL) {
		vp.ImprimirMensaje("LA PERSONA NO EXISTE\n\n");
	} else {
		vp.ImprimirMensaje("PERSONA ENCONTRADA\n\n");
		vp.ImprimirMensaje("DATOS DE PERSONA\n\n");
		vp.imprimirPersona(ptrPersona->ObtInfo());
		vp.ImprimirLineasBlanco(1);
		vp.ImprimirMensaje("INGRESE DATOS A MODIFICAR\n\n");

		persona.codigo = vp.LeerNroDecimal("Código: ");
		persona.nombre = vp.LeerString("Nombre: ");
		persona.apellido = vp.LeerString("Apellido: ");
		persona.sexo = vp.LeerNroDecimal("Sexo (1)MASCULINO (2)FEMENINO: ");
		persona.correo = vp.LeerString("Correo Electrónico: ");
		persona.decanato = vp.LeerString("Decanato: ");
		persona.tipoPersona = vp.LeerNroDecimal("Código de Rol: ");
		Nodo<InfoRol> *auxRol = mr.BuscarRol(persona.tipoPersona);

		while(auxRol == NULL){
			vp.ImprimirMensaje("EL ROL NO EXISTE, INGRESAR ROL VALIDO\n\n");
			persona.tipoPersona = vp.LeerNroDecimal("Código de Rol: ");
			auxRol = mr.BuscarRol(persona.tipoPersona);
		};

		auxRol->ObtInfo().cPersonas.ModificarPersona(persona);

		vp.ImprimirMensaje("\nLA PERSONA SE MODIFICO SATISFACTORIAMENTE\n");
	}

	vr.ImprimirLineasBlanco(1);
	vr.Pausa();
}
void Controlador::eliminarPersona(){
	int dec;
	string cedula;
	Nodo<InfoPersona> *ptrPersona;

	vp.Limpiar();
	vp.ImprimirEncabezado("      ELIMINAR PERSONA", "   ================");
	vp.ImprimirLineasBlanco(1);

	cedula = vp.LeerString("Cédula: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			rol == NULL;
		};
	}

	if (ptrPersona == NULL) {
		vp.ImprimirMensaje("PERSONA NO ENCONTRADA\n\n");
		vp.ImprimirLineasBlanco(1);
		vr.Pausa();
	} else {
		vp.ImprimirMensaje("PERSONA ENCONTRADA\n\n");
		vp.imprimirPersona(ptrPersona->ObtInfo());
		dec = vp.LeerNroDecimal("Desea eliminar persona? (1)SI (2)NO: ");
		if(dec == 1){
			rol->ObtInfo().cPersonas.EliminarPersona(cedula);
		}
	}
}
void Controlador::imprimirPersonas(){
	int codigo;

	codigo = vp.LeerNroDecimal("Seleccionar Rol: ");
	Nodo<InfoRol>* rol = mr.BuscarRol(codigo);

	if(rol != NULL){
		vp.imprimirListaPersonas(rol->ObtInfo().cPersonas);
	} else {
		vp.ImprimirMensaje("EL ROL NO EXISTE\n\n");
	}
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

void Controlador::incluirEstado(){
	InfoEstado estado;
	string cedula;
	Nodo<InfoPersona>* ptrPersona;

	ve.Limpiar();
	ve.ImprimirEncabezado("      INCLUIR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol == NULL;
		};
	}

	estado.codigo = ve.LeerNroDecimal("Código: ");
	if (ptrPersona->ObtInfo().pilaEstado.BuscarEstado(estado.codigo) != NULL) {
		ve.ImprimirMensaje("EL ESTADO YA EXISTE\n\n");
	} else {
		ve.ImprimirMensaje("INGRESAR DATOS DE ESTADO\n\n");
		estado.nombre = ve.LeerString("Nombre: ");
		estado.fecha = ve.LeerString("Fecha: ");

		ptrPersona->ObtInfo().pilaEstado.IncluirEstado(estado);

		ve.ImprimirMensaje("\nEL ESTADO SE INCLUYO SATISFACTORIAMENTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
}
void Controlador::consultarEstado(){
	InfoEstado estado;
	Nodo<InfoPersona> *ptrPersona;
	string cedula;

	ve.Limpiar();
	ve.ImprimirEncabezado("      CONSULTAR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol == NULL;
		};
	}

	estado.codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado>* e = ptrPersona->ObtInfo().pilaEstado.BuscarEstado(estado.codigo);
	if (e->ObtInfo().codigo != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());
	} else {
		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
}
void Controlador::modificarEstado(){
	InfoEstado estado;
	string cedula;
	Nodo<InfoPersona>* ptrPersona;

	ve.Limpiar();
	ve.ImprimirEncabezado("      INCLUIR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol == NULL;
		};
	}

	estado.codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado>* e = ptrPersona->ObtInfo().pilaEstado.BuscarEstado(estado.codigo);
	if (e->ObtInfo().codigo != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());

		ve.ImprimirMensaje("\nINGRESAR DATOS DE ESTADO\n\n");
		estado.nombre = ve.LeerString("Nombre: ");
		estado.fecha = ve.LeerString("Fecha: ");

		ptrPersona->ObtInfo().pilaEstado.IncluirEstado(estado);
		ve.ImprimirMensaje("\nEL ESTADO SE INCLUYO SATISFACTORIAMENTE\n");
	} else {

		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
}
void Controlador::eliminarEstado(){
	int dec, codigo;
	string cedula;
	Nodo<InfoPersona> *ptrPersona;

	ve.Limpiar();
	ve.ImprimirEncabezado("      ELIMINAR ESTADO", "   ================");
	ve.ImprimirLineasBlanco(1);

	cedula = ve.LeerString("Cédula de persona: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			ve.ImprimirMensaje("LA PERSONA EXISTE\n\n");
			rol == NULL;
		};
	}

	codigo = ve.LeerNroDecimal("Código: ");
	Nodo<InfoEstado>* e = ptrPersona->ObtInfo().pilaEstado.BuscarEstado(codigo);
	if (e->ObtInfo().codigo != NULL) {
		ve.ImprimirMensaje("EL ESTADO EXISTE\n\n");
		ve.imprimirEstado(e->ObtInfo());
		dec = ve.LeerNroDecimal("Desea eliminar estado? (1)SI (2)NO: ");
		if(dec == 1){
			ptrPersona->ObtInfo().pilaEstado.EliminarEstado(codigo);
		}
	} else {
		ve.ImprimirMensaje("\nEL ESTADO NO EXISTE\n");
	}
	ve.ImprimirLineasBlanco(1);
	ve.Pausa();
}
void Controlador::imprimirEstados(){
	string cedula;
	Nodo<InfoPersona>* ptrPersona;

	cedula = ve.LeerString("Cedula de Persona: ");
	Nodo<InfoRol>* rol = mr.ObtPrimero();
	while(rol != NULL){
		ptrPersona = rol->ObtInfo().cPersonas.BuscarPersona(cedula);
		if(ptrPersona == NULL)
			rol = rol->ObtDer();
		else {
			rol == NULL;
		};
	}

	if(ptrPersona != NULL){
		ve.imprimirListaEstados(ptrPersona->ObtInfo().pilaEstado);
	} else {
		ve.ImprimirMensaje("LA PERSONA NO EXISTE\n\n");
	}
}