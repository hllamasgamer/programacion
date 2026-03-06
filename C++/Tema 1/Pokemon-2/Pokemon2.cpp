// Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
public:
    string nombre;  //nombre del pokemon
    double vida;    //vida que tiene el pokemon
    string tipo;    //tipo del pokemon

    Pokemon();  //constructor por defecto
    Pokemon(string nombre, double vida, string tipo);   //constructor con atributos
    ~Pokemon(); //destructor

    void ataca();   //operaciones de ataque
    void ataca(Pokemon *victima);
};

Pokemon::Pokemon() {
    nombre = "Desconocido";
    vida = 0.0;
    tipo = "normal";
    //cout << "Holiiii" << std::endl;  //Nunca jamás en la vida se ponen mensajes en los métodos!!
}

Pokemon::Pokemon(string nombre, double vida, string tipo) {
    this->nombre = nombre;
    this->vida = vida;
    this->tipo = tipo;
    //cout << "Holiiii" << std::endl;  //Nunca jamás en la vida se ponen mensajes en los métodos!!
}

Pokemon::~Pokemon() {
    //cout << "Me mueeeroooo" << endl;    //Nunca jamás en la vida se ponen mensajes en los métodos
}

void Pokemon::ataca() {
    //Al atacar, la vida disminuye un 10%
    vida = vida * 0.9;
}

void Pokemon::ataca(Pokemon *victima) {
    victima->vida = victima->vida * 0.9;
    //cout << "Atacando..." + to_string(victima.vida);
}

int main()
{
    Pokemon pikachu;
    cout << "Nombre Pikachu: " + pikachu.nombre << endl;
    cout << "Vida Pikachu: " + to_string(pikachu.vida) << endl;
    cout << "Tipo Pikachu: " + pikachu.tipo << endl;
    cout << "############################################" << endl;

    pikachu.nombre = "Mi Pikachu";
    pikachu.vida = 12.0;
    pikachu.tipo = "Rayito";
    cout << "Nombre Pikachu: " + pikachu.nombre << endl;
    cout << "Vida Pikachu: " + to_string(pikachu.vida) << endl;
    cout << "Tipo Pikachu: " + pikachu.tipo << endl;
    cout << "############################################" << endl;

    Pokemon pikachu2("Otro Pikachu", 10.0, "Eléctrico");
    cout << "Nombre Pikachu: " + pikachu2.nombre << endl;
    cout << "Vida Pikachu: " + to_string(pikachu2.vida) << endl;
    cout << "Tipo Pikachu: " + pikachu2.tipo << endl;
    cout << "############################################" << endl;

}
