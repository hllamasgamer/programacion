#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

namespace poo {
    class Vehiculo {
    private:
        string marca;
        string modelo;

    public:
        Vehiculo(const string& marca, const string& modelo);
        virtual ~Vehiculo() = default;

        string getMarca() const;
        string getModelo() const;

        virtual string obtenerSonido() const;
    };
}

#endif
