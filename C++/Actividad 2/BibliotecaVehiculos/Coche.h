#ifndef COCHE_H
#define COCHE_H

#include "Vehiculo.h"
using namespace std;

namespace poo {
    class Coche : public Vehiculo {
    public:
        Coche(const string& marca, const string& modelo);
        string obtenerSonido() const override;
    };
}

#endif
