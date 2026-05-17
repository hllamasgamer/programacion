#include "Vehiculo.h"
using namespace std;

namespace poo {
    Vehiculo::Vehiculo(const string& marca, const string& modelo) 
        : marca(marca), modelo(modelo) {}

    string Vehiculo::getMarca() const { return marca; }
    string Vehiculo::getModelo() const { return modelo; }

    string Vehiculo::obtenerSonido() const {
        return "Sonido genérico de vehículo";
    }
}
