#include "Semanal.h"
#include <cassert>

Semanal::Semanal(int semana, int semanasMes) {
	this->semanaDeMes = semana;
	this->esPrimeraDeMes = semana == 1;
	this->esUltimaDeMes = semana == semanasMes;
}

void Semanal::calculaDias(DiaSemana primerDiaMes, int diasMes) {
	if (this->esPrimeraDeMes) {
		this->diaMesInicio = 1;
		this->primerDia = primerDiaMes;
		this->ultimoDia = domingo;
	}
	else {
		// El primer día del mes.
		int dia = 1;

		// En número de días de la primera semana es: 7 - primerDiaMes.
		// Avanza hasta el lunes de la segunda semana.
		dia += 7 - primerDiaMes;

		// Quedan por avanzar estas semanas: this->semanaDeMes - 2.
		dia += (this->semanaDeMes - 2) * 7;
		this->diaMesInicio = dia;
		this->primerDia = lunes;
		if (this->esUltimaDeMes) {
			this->ultimoDia = (DiaSemana)(diasMes - this->diaMesInicio);
		}
		else {
			this->ultimoDia = domingo;
		}
	}
}
