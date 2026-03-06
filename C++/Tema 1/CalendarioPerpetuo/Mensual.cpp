#include "Mensual.h"

int Mensual::tablaDiasMes[12] = {
	31, 28, 31, 30, 31, 30,	31, 31, 30, 31, 30, 31 };

Mensual::Mensual(MesAño mes, DiaSemana primerDiaAño, bool bisiesto) {
	this->mes = mes;

	// Almacena, en 'diasMes' de la instancia, el número de días del mes,
	// también si es bisiesto.
	this->diasMes = tablaDiasMes[mes];
	if (bisiesto && mes == febrero) {
		this->diasMes++;
	}

	//
	// Cálculo del día de la semana del primer día de 'mes'.
	// Se calcula a partir del parámetro 'primerDiaAño'.
	//
	// Día de la semana del primer día del año.
	// Es un entero de 0 a 6 (lunes a domingo)
	int dia = primerDiaAño;

	// Avanza los meses desde enero hasta el mes anterior a 'mes'.
	for (int paso = 0; paso < mes; ++paso) {
		// Ávanza los días de que tiene el mes 'paso'.
		dia += tablaDiasMes[paso];
		if (bisiesto && paso == febrero) {
			dia++;
		}
	}

	// En 'dia' se han acumulado muchas semanas.
	// Para quitar las semanas sobrantes se usa el módulo (resto de la división).
	dia = dia % 7;

	// Almacena el día de la semana calculado.
	this->primerDia = (DiaSemana)dia;
}

int Mensual::semanas() {
	// Calcula en cuantas semanas se extiende el mes.
	// Se tiene en cuanta el día de la semana del primer día del mes.
	// P.ej. si la semana empieza en domingo, eso es una semana completa.
	int total = this->primerDia + this->diasMes;

	//
	int semanas = total / 7;

	// Los días de final de mes se tienen en cuenta.
	// P.ej. si el ultimo día del mes es lunes, cuenta una semana más.
	if (total % 7 > 0) {
		semanas++;
	}

	return semanas;
}
