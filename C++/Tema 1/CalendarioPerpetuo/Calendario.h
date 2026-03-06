#pragma once
#include "Mensual.h"
#include "Semanal.h"

// Imprime en la consola el calendario de un año.
class Calendario {
public:
	// El año cuyo calendario se imprime.
	int año;

	// Constructor. Establece el año del calendario.
	Calendario(int año);

	// Imprime el calendario.
	void Imprime();

	// Metodos auxiliares.
	void Imprime(
		Mensual mensual_1, Mensual mensual_2, Mensual mensual_3);

	void Imprime(Semanal semanal, Mensual mensual);

	std::string literalMes(MesAño mes);
};
