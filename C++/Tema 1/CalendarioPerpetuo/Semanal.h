#pragma once
#include "DiaSemana.h"

// Contiene los datos necesarios para confeccionar el calendario de una semana.
class Semanal {
public:
	// Número de la semana dentro del mes, de 1 a 6.
	// La primera y la última semanas pueden ser incompletas.
	int semanaDeMes;
	// Indica si es la primera semana del mes.
	bool esPrimeraDeMes;
	// indica si es la última semana del mes.
	bool esUltimaDeMes;
	// Número del día del mes, entre 1 y 31, del primer día de la semana.
	int diaMesInicio;
	// Día de la semana del primer día de la semana.
	// Lunes en todas las semanas, excepto (posiblemente) en la primera.
	DiaSemana primerDia;
	// Día de la semana del último día de la semana.
	// Domingo en todas las semanas, excepto (posiblemente) en la última.
	DiaSemana ultimoDia;

	// Constructor.
	// Establece: 'semanaDeMes', 'esPrimeraDeMes' y 'esUltimaDeMes'.
	// 'semana': Número de orden de la semana dentro del mes, de 1 a 6.
	// 'semanasMes': Número de semanas que tiene el mes (4, 5 o 6).
	Semanal(int semana, int semanasMes);
	
	// Calcula los datos de la clase.
	// Debe ser llamado tras el constructor para calcular: 'diaMesInicio', 'primerDia' y 'ultimoDia'.
	void calculaDias(DiaSemana primerDiaMes, int diasMes);
};
