/*
 * InfoRol.h
 *
 *  Created on: 28 nov. 2022
 *      Author: guerrerody
 */

#ifndef INFOROL_H_
#define INFOROL_H_

#include <iostream>
#include <string>
using namespace std;

struct InfoRol {
	string codigo;
	string nombre;
	string descripcion;
	float precioCarnet;
	int cantCensados = 0;
};

#endif /* INFOROL_H_ */
