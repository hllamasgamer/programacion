#include "Anual.h"

int Anual::añoReferencia{ 2022 };

DiaSemana Anual::primerDiaReferencia{ sabado };

Anual::Anual(int año) {
	this->año = año;
	this->esBisiesto = bisiesto(año);
	this->primerDia = primerDiaAño(año);
}

bool Anual::bisiesto(int año) {
	// Un año es bisiesto si es divisible por 4,
	// excepto si es divisible por 100, que no lo es,
	// excepto si es divisible por 400, que si lo es.
	bool bisiesto = false;
	if (año % 4 == 0) {
		bisiesto = true;
	}
	if (año % 100 == 0) {
		bisiesto = false;
	}
	if (año % 400 == 0) {
		bisiesto = true;
	}
	return bisiesto;
}

DiaSemana Anual::primerDiaAño(int año) {
	// Calculo del día de la semana del primer día de 'año'.
	// Se calcula a partir de 'añoReferencia' y 'primerDiaReferencia'.
	//
	// Día de la semana del primer día del año de referencia.
	// Es un entero de 0 a 6 (lunes a domingo)
	int dia = primerDiaReferencia;
	if (añoReferencia <= año) {
		// Hay que avanzar los años desde 'añoReferencia' hasta el año
		// anterior a parámetro 'año'.
		// Se busca el primer día del año.
		for (int paso = añoReferencia; paso < año; ++paso) {
			// Cada año de avance suma 365 o 366 días.
			dia += 365;
			if (bisiesto(paso)) {
				dia++;
			}
		}
	}
	else {
		// Hay que retroceder los años desde el año anterior a
		// 'añoReferencia' hasta el año del parámetro 'año'.
		// Se busca el primer día del año.
		for (int paso = añoReferencia - 1; paso >= año; --paso) {
			// Cada año de retroceso resta 365 o 366 días.
			dia -= 365;
			if (bisiesto(paso)) {
				dia--;
			}
		}
	}
	
	// En 'dia' se han acumulado muchas semanas, en avance (positivo)
	// o en retroceso (negativo).
	// Para quitar las semanas sobrantes se usa el módulo (resto de la
	// división).
	dia = dia % 7;
	
	// Puede seguir siendo negativo, debe estar de 0 a 6.
	if (dia < 0) {
		dia += 7;
	}
	
	// Solo falta devolver el día de la semana calculado.
	return (DiaSemana)dia;
}
