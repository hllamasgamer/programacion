#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"
using namespace std;

namespace poo {
    class Camion : public Vehiculo {
    public:
        Camion(const string& marca, const string& modelo);
        string obtenerSonido() const override;
    };
}

#endif
