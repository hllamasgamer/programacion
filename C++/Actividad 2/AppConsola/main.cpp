#include <iostream>
#include "Vehiculo.h"
#include "Coche.h"
#include "Moto.h"
#include "Tratamiento.h"
#include "Camion.h"

using namespace std;

int main() {
    using namespace poo;

    Tratamiento t;

    // Usando clases de la biblioteca
    cout << "--- Usando Coche (Biblioteca) ---" << endl;
    Vehiculo* coche = new Coche("Toyota", "Yaris Cross");
    t.mostrarDetalles(coche);
    delete coche;

    cout << "\n--- Usando Moto (Biblioteca) ---" << endl;
    Vehiculo* moto = new Moto("Honda", "CBR");
    t.mostrarDetalles(moto);
    delete moto;

    // Usando clase extendida en el proyecto de consola
    cout << "\n--- Usando Camion (Extendido en Consola) ---" << endl;
    Vehiculo* camion = new Camion("Volvo", "FH16");
    t.mostrarDetalles(camion);
    delete camion;

    cout << "\nPresione Enter para salir..." << endl;
    cin.get();

    return 0;
}
