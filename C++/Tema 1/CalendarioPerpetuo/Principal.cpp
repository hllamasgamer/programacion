/***********************************************************/
// Ejercicio 1.6
/***********************************************************/
/*
#include <iostream>
#include "Anual.h"
int main () {
	std::cout << "Escriba un año: ";
	int año;
	std::cin >> año;
	Anual anual {año};
	std::cout << "primer dia del año " << anual.primerDia << "\n";
}
*/

/***********************************************************/
// Ejercicio 1.10
/***********************************************************/
/*
#include <iostream>
#include "DiaSemana.h"
#include "MesAño.h"
#include "Anual.h"
#include "Mensual.h"
int main () {
	std::cout << "Escriba un año: ";
	int año;
	std::cin >> año;
	Anual anual {año};
	std::cout << "Escriba un mes: ";
	int mes;
	std::cin >> mes;
	Mensual mensual {
	(MesAño) (mes - 1), anual.primerDia, anual.esBisiesto};
	std::cout << "primer dia del mes " << mensual.primerDia << "\n";
}
*/

/***********************************************************/
// Ejercicio 1.14
/***********************************************************/
/*
#include <iostream>
#include "DiaSemana.h"
#include "MesAño.h"
#include "Anual.h"
#include "Mensual.h"
#include "Semanal.h"
int main () {
	std::cout << "Escriba un año: ";
	int año;
	std::cin >> año;
	Anual anual {año};
	std::cout << "Escriba un mes: ";
	int mes;
	std::cin >> mes;
	Mensual mensual {
	(MesAño) (mes - 1), anual.primerDia, anual.esBisiesto};
	std::cout << "Escriba una semana: ";
	int semana;
	std::cin >> semana;
	Semanal semanal {semana, mensual.semanas ()};
	semanal.calculaDias (mensual.primerDia, mensual.diasMes);
	//
	std::cout << "esPrimeraDeMes " << semanal.esPrimeraDeMes << "\n";
	std::cout << "esUltimaDeMes " << semanal.esUltimaDeMes << "\n";
	std::cout << "diaMesInicio " << semanal.diaMesInicio << "\n";
	std::cout << "primerDia " << semanal.primerDia << "\n";
	std::cout << "ultimoDia " << semanal.ultimoDia << "\n";
}
*/

/***********************************************************/
#include <iostream>
#include "Calendario.h"
int main() {
	std::cout << "Escriba un año: ";
	int año;
	std::cin >> año;
	Calendario calendario{ año };
	calendario.Imprime();
}
