#include "Tratamiento.h"
#include <iostream>
using namespace std;

namespace poo {
    void Tratamiento::mostrarDetalles(Vehiculo* v) const {
        if (v) {
            cout << "Vehiculo: " << v->getMarca() << " " << v->getModelo() << endl;
            cout << "Sonido: " << v->obtenerSonido() << endl;
        }
    }
}
