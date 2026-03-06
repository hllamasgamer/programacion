// Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

class Pokemon {
public:
    static int total;   //variable estática
    static std::string informe();

    std::string nombre;  //nombre del pokemon
    double vida;    //vida que tiene el pokemon
    std::string tipo;    //tipo del pokemon
    
    Pokemon();  //constructor por defecto
    Pokemon(std::string nombre, double vida, std::string tipo);   //constructor con atributos
    ~Pokemon();
    
    void ataca();   //operaciones de ataque
    void ataca(Pokemon victima);
};

int Pokemon::total{ 0 };

//int Pokemon::informe() 
std::string Pokemon::informe() {
    //return total;
    return "Total Pokemons creados: " + std::to_string(total);
}

Pokemon::Pokemon() {
    nombre = "Desconocido";
    vida = 0.0;
    tipo = "normal";

    total++;    //Variable estática
    
    //std::cout << "Holiiii";  //Nooo poner mensajes
}

Pokemon::Pokemon(std::string nombre, double vida, std::string tipo) {
    this->nombre = nombre;
    this->vida = vida;
    this->tipo = tipo;
    total++;    //total = total +1;
                //total +=7;
    //std::cout << "Holiiii";  //Nooo poner mensajes
}

Pokemon::~Pokemon() {
    total--;
    //cout << "Me mueeeroooo" << endl;
}

void Pokemon::ataca() {
    //Al atacar, la vida disminuye un 10%
    vida = vida * 0.9;
}

void Pokemon::ataca(Pokemon victima) {
    victima.vida = victima.vida * 0.9;
    //cout << "Atacando..." + to_string(victima.vida);
}

int main()
{
    Pokemon pikachu{"Pikachu", 20.0, "Eléctrico"};
    Pokemon charmander{ "Charmander", 15.0, "Fuego" };
    Pokemon bulbasaur{ "Bulbasaur", 16.0, "Planta" };

    pikachu.ataca();

    //int n;
    //n = Pokemon::informe();
    std::cout << Pokemon::informe();
}
