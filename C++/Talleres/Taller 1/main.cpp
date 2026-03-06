#include <iostream>

#include "Persona.h"
#include "Automovil.h"

int main () {
    Persona p1("Hugo", "Llamas", "hugo.llamas@example.com", "Toyota", true, 25);
    Automovil a1;

    a1.tipo = "Coche";
    a1.marca = "Toyota";
    a1.modelo = "Yaris Cross";
    a1.plazas = 5;
    a1.electrico = false;
    a1.color = "Verde";
    a1.precio = 32000.0;

    bool exito;
    //comprar(p1, a1);
    exito = p1.compra(a1);
    std::cout<< p1.nombre + " ha comprado? " << exito;

    //Dar mensajes mas explicativos
    //Comprar mas vehiculos
    //mostrar las matriculas de los coches comprados

};