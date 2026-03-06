#pragma once

#include "DiaSemana.h"

// Contiene los datos necesarios para confeccionar el calendario de un año.
class Anual {
public:
	// Año cuyo calendario se calcula.
	int año;
	// Indica si el año es bisiesto.
	bool esBisiesto;
	// Día de la semana del primer día del año.
	DiaSemana primerDia;

	// Datos usados para los cálculos.
	// Es una año concreto de referencia.
	static int añoReferencia;
	// Primer día de la semana del año de referencia.
	static DiaSemana primerDiaReferencia;
	
	// Constructor. Toma como parámetro el año cuyo calendario se confecciona.
	Anual(int año);
	
	// Indica si el año es bisiesto.
	static bool bisiesto(int año);
	
	// Calcula el primer dia de la semana del primer día del año indicado.
	static DiaSemana primerDiaAño(int año);
};
