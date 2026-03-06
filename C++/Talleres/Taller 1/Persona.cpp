#include "Persona.h"
#include <string>

Persona::Persona(){
    edad = 18;

}

Persona::Persona(std::string nombre, std::string apellidos, std::string email, std::string marca, bool habitual, int edad){
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->email = email;
    this->marca = marca;
    this->habitual = habitual;
    this->edad = edad;
}

bool Persona::compra(Automovil a) {
    bool compra = false;
    if (nComprados < 10) {
        comprados[nComprados++] = a;
        compra = true;
    }
    return compra;
    }


    