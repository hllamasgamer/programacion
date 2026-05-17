#include "Coche.h"
using namespace std;

namespace poo {
    Coche::Coche(const string& marca, const string& modelo) 
        : Vehiculo(marca, modelo) {}

    string Coche::obtenerSonido() const {
        return "Broom Broom (Coche)";
    }
}
