#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ListaPokemons.h"

using namespace std;
using namespace poo;

// Función para parsear una línea y crear un objeto Pokemon (Abstracción)
Pokemon* procesarLinea(const string& linea) {
    istringstream ss(linea);
    string campo;
    Pokemon* p = new Pokemon();

    // Extracción campo a campo según el orden del CSV 
    getline(ss, campo, ','); p->setNumber(stoi(campo));
    getline(ss, campo, ','); p->setCode(stoi(campo));
    getline(ss, campo, ','); p->setSerial(stoi(campo));
    getline(ss, campo, ','); p->setName(campo);
    getline(ss, campo, ','); p->setType1(campo);
    getline(ss, campo, ','); p->setType2(campo);
    getline(ss, campo, ','); p->setColor(campo);
    getline(ss, campo, ','); p->setAbility1(campo);
    getline(ss, campo, ','); p->setAbility2(campo);
    getline(ss, campo, ','); p->setAbilityHidden(campo);
    getline(ss, campo, ','); p->setGeneration(stoi(campo));
    getline(ss, campo, ','); p->setLegendary(stoi(campo));
    getline(ss, campo, ','); p->setMegaEvolution(stoi(campo));
    getline(ss, campo, ','); p->setHeight(stof(campo));
    getline(ss, campo, ','); p->setWeight(stof(campo));
    getline(ss, campo, ','); p->setHp(stoi(campo));
    getline(ss, campo, ','); p->setAtk(stoi(campo));
    getline(ss, campo, ','); p->setDef(stoi(campo));
    getline(ss, campo, ','); p->setSpAtk(stoi(campo));
    getline(ss, campo, ','); p->setSpDef(stoi(campo));
    getline(ss, campo, ','); p->setSpd(stoi(campo));
    getline(ss, campo, ','); p->setTotal(stoi(campo));

    return p;
}

// Función para guardar la lista en un archivo nuevo
void guardarArchivo(ListaPokemons& lista, const string& nombreArchivo) {
    ofstream salida(nombreArchivo);
    if (!salida.is_open()) return;

    // Cabecera idéntica al original 
    salida << "NUMBER,CODE,SERIAL,NAME,TYPE1,TYPE2,COLOR,ABILITY1,ABILITY2,ABILITY HIDDEN,GENERATION,LEGENDARY,MEGA_EVOLUTION,HEIGHT,WEIGHT,HP,ATK,DEF,SP_ATK,SP_DEF,SPD,TOTAL" << endl;

    for (int i = 0; i < lista.longitud(); ++i) {
        Pokemon* p = lista.getElemento(i);
        salida << p->getNumber() << "," << p->getCode() << "," << p->getSerial() << ","
            << p->getName() << "," << p->getType1() << "," << p->getType2() << ","
            << p->getColor() << "," << p->getAbility1() << "," << p->getAbility2() << ","
            << p->getAbilityHidden() << "," << p->getGeneration() << ","
            << p->getLegendary() << "," << p->getMegaEvolution() << ","
            << p->getHeight() << "," << p->getWeight() << "," << p->getHp() << ","
            << p->getAtk() << "," << p->getDef() << "," << p->getSpAtk() << ","
            << p->getSpDef() << "," << p->getSpd() << "," << p->getTotal() << "\n";
    }
    salida.close();
}

int main() {
    ifstream archivo("pokemon_correcto.csv");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    ListaPokemons lista;
    string linea;

    // Saltar la cabecera
    getline(archivo, linea);

    // Lectura línea a línea 
    while (getline(archivo, linea) && !linea.empty()) {
        try {
            Pokemon* p = procesarLinea(linea);
            lista.concatena(p);
        }
        catch (...) {
            // Control de errores básico si una línea está corrupta
            continue;
        }
    }
    archivo.close();

    // Proceso inverso: Escritura 
    guardarArchivo(lista, "pokemon_actividad1.csv");

    cout << "Archivo 'pokemon_actividad1.csv' generado con éxito." << endl;
    cout << "Usa 'comp pokemon_correcto.csv pokemon_actividad1.csv' para verificar." << endl;

    return 0;
}