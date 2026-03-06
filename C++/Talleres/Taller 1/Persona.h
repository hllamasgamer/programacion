#pragma once
#include "Automovil.h"



class Persona {
public:
    std::string nombre;
    std::string apellidos;
    std::string email;
    std::string marca;
    bool habitual;
    int edad;
    Automovil comprados [10];
    int nComprados { 0 };
    

    Persona();
    Persona(std::string nombre, std::string apellidos, std::string email, std::string marca, bool habitual, int edad);

    
    bool compra(Automovil a);
};