#include "Moto.h"
using namespace std;

namespace poo {
    Moto::Moto(const string& marca, const string& modelo) 
        : Vehiculo(marca, modelo) {}

    string Moto::obtenerSonido() const {
        return "Vroom Vroom (Moto)";
    }
}
