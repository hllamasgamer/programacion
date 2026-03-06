// archivo: Mensual.h

#pragma once
#include <string>
#include "DiaSemana.h"
#include "MesAño.h"

// Contiene los datos necesarios para confeccionar el calendario de un mes.
class Mensual {
public:
	// Mes del año cuyo calendario se calcula.
	MesAño mes;
	// Dias que tiene el mes, teniendo en cuenta los años bisiestos.
	int diasMes;
	// Primer día de la semana del mes.
	DiaSemana primerDia;

	// Número de días de cada mes del año, para un año no bisiesto.
	static int tablaDiasMes[12];
	
	// Constructor.
	// 'mes': es el mes del año cuyo calendario se calcula.
	// 'primerDiaAño': día de la semana del primer día del año correspondiente al mes cuyo calendario se calcula.
	// 'bisiesto': indica si el año es bisiesto.
	Mensual(MesAño mes, DiaSemana primerDiaAño, bool bisiesto);
	
	// Número de semanas en las que se extiende el mes.
	// La primera y la ultima semana pueden no tener 7 días, el valor devuelto estará entre 4 y 6 semanas.
	int semanas();
};
