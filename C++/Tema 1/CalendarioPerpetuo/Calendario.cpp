#include <iostream>
#include "Anual.h"
#include "Mensual.h"
#include "Semanal.h"
#include "Calendario.h"

Calendario::Calendario(int año) {
	this->año = año;
}

void Calendario::Imprime() {
	// Se usa una instancia de 'Anual'.
	Anual anual{ this->año };
	// Cabecera del calendario.
	std::cout << "\n";
	std::cout << " "
		<< anual.año << "\n";
	std::cout << "\n";

	//
	// Se imprime el calendario en 4 filas y 3 columnas (de meses).
	int mes = 0;
	for (int bloque_meses = 1; bloque_meses <= 4; ++bloque_meses) {
		// Para las 3 columnas del calendario se usan tres instancias de
		// 'Mensual'.
		// No tenemos arrays ni punteros, no se puede hacer de otra forma.
		Mensual mensual_1{
		(MesAño)(mes), anual.primerDia, anual.esBisiesto };
		Mensual mensual_2{
		(MesAño)(mes + 1), anual.primerDia, anual.esBisiesto };
		Mensual mensual_3{
		(MesAño)(mes + 2), anual.primerDia, anual.esBisiesto };

		//
		Imprime(mensual_1, mensual_2, mensual_3);
		mes += 3;
		std::cout << "\n\n";
	}
}

void Calendario::Imprime(
	Mensual mensual_1, Mensual mensual_2, Mensual mensual_3) {
	// Imprime 3 meses en una sola fila.
	//
	// El máximo de semanas en los tres meses.
	int total_semanas = mensual_1.semanas();

	if (mensual_2.semanas() > total_semanas) {
		total_semanas = mensual_2.semanas();
	}

	if (mensual_3.semanas() > total_semanas) {
		total_semanas = mensual_3.semanas();
	}

	// La cabecera de cada mes.
	std::cout << "\n";
	std::cout << " " << literalMes(mensual_1.mes);
	std::cout << " " << literalMes(mensual_2.mes);
	std::cout << " " << literalMes(mensual_3.mes);
	std::cout << "\n\n";

	// 3 cabeceras para los días.
	for (int indice = 1; indice <= 3; ++indice) {
		std::cout << " Lun Mar Mie Jue Vie Sab Dom ";
	}

	std::cout << "\n";

	for (int indice = 1; indice <= 3; ++indice) {
		std::cout << " --------------------------- ";
	}
	std::cout << "\n";

	// Recorre las semanas, de la primera a la máxima de los 3 meses.
	// Alguna de las semanas pueden quedar en blanco.
	for (int semana = 1; semana <= total_semanas; ++semana) {
		// Una instancia de 'Semanal' para cada columna y cada semana.
		Semanal semanal_1{ semana, mensual_1.semanas() };
		Semanal semanal_2{ semana, mensual_2.semanas() };
		Semanal semanal_3{ semana, mensual_3.semanas() };
		semanal_1.calculaDias(mensual_1.primerDia, mensual_1.diasMes);
		semanal_2.calculaDias(mensual_2.primerDia, mensual_2.diasMes);
		semanal_3.calculaDias(mensual_3.primerDia, mensual_3.diasMes);
		std::cout << "\n";
		std::cout << " ";

		// Imprime semana actual de la primera columna.
		Imprime(semanal_1, mensual_1);
		std::cout << " ";

		// Imprime semana actual de la columna 2.
		Imprime(semanal_2, mensual_2);
		std::cout << " ";

		// Imprime semana actual de la columna 3.
		Imprime(semanal_3, mensual_3);
		std::cout << " ";
	}
}

void Calendario::Imprime(Semanal semanal, Mensual mensual) {
	// Imprime los números de los días de la semana, de lunes a domingo.
	//
	int dia_mes = semanal.diaMesInicio;
	for (int dia_semana = lunes; dia_semana <= domingo; ++dia_semana) {
		if (dia_mes > mensual.diasMes) {
			// Algunos dias se quedan en blanco.
			std::cout << " ";
		}
		else {
			if (dia_semana < semanal.primerDia) {
				// Algunos dias se quedan en blanco.
				std::cout << " ";
			}
			else {
				// Para colocar bien en columna.
				if (dia_mes < 10) {
					std::cout << " ";
				}
				std::cout << dia_mes;
				// Suma 1 al día impreso.
				dia_mes++;
			}
		}
		// Separacion entre días.
		std::cout << " ";
	}
}

std::string Calendario::literalMes(MesAño mes) {
	// El nombre del mes.
	switch (mes) {
	case enero:
		return " Enero ";
	case febrero:
		return " Febrero ";
	case marzo:
		return " Marzo ";
	case abril:
		return " Abril ";
	case mayo:
		return " Mayo ";
	case junio:
		return " Junio ";
	case julio:
		return " Julio ";
	case agosto:
		return " Agosto ";
	case setiembre:
		return "Setiembre";
	case octubre:
		return " Octubre ";
	case noviembre:
		return "Noviembre";
	case diciembre:
		return "Diciembre";
	}
	return "";
}
