#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"
using namespace std;

namespace poo {
    class Moto : public Vehiculo {
    public:
        Moto(const string& marca, const string& modelo);
        string obtenerSonido() const override;
    };
}

#endif
