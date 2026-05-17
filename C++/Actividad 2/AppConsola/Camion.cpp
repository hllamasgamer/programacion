#include "Camion.h"
using namespace std;

namespace poo {
    Camion::Camion(const string& marca, const string& modelo) 
        : Vehiculo(marca, modelo) {}

    string Camion::obtenerSonido() const {
        return "HONK HONK (Camion)";
    }
}
