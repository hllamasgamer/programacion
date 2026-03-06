// Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

class Pokemon {
public:
    std::string nombre;  //nombre del pokemon
    double vida;    //vida que tiene el pokemon
    std::string tipo;    //tipo del pokemon

    void ataca();   //operaciones de ataque
    void ataca(Pokemon enemigo);
};

void Pokemon::ataca() {
    //Al atacar, la vida disminuye un 10%
    vida = vida * 0.9;
}

void Pokemon::ataca(Pokemon enemigo) {
    //Al atacar, la vida disminuye un 10%
    enemigo.vida = enemigo.vida * 0.9;
    //std::cout << "Atacando..." + std::to_string(enemigo.vida) << std::endl;
}

int main()
{
    Pokemon p;
    Pokemon charmander;
    Pokemon bulbasaur;
    
    p.nombre = "Pikachu";
    p.vida = 100;
    charmander.vida = p.vida;

    p.ataca();
    charmander.ataca();

    std::cout << "Vida Pikachu: " + std::to_string(p.vida) << std::endl;
    std::cout << "Vida Charmander: " + std::to_string(charmander.vida) << std::endl;
    
    std::cout << "Pickachu ataca a Charmander" << std::endl;
    p.ataca(charmander);
    std::cout << "Vida Pikachu: " + std::to_string(p.vida) << std::endl;
    std::cout << "Vida Charmander: " + std::to_string(charmander.vida) << std::endl;

}
