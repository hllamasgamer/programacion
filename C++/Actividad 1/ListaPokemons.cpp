// archivo: principal.cpp

#include "ListaPokemons.h"

poo::ListaPokemons::ListaPokemons() {
    capacidad = 0;
    // cuando la capacidad es 0, elementos puede ser nulo (no siempre).
    elementos = nullptr;
    // siempre será: longtd <= capacidad
    longtd = 0;
}

poo::ListaPokemons::~ListaPokemons() {
    // Si la lista no está vacía se libera la memoria usada.
    // No usar 'capacidad', podría ser 0.
    if (elementos != nullptr) {
        // En el destructor se liberan los recursos usados.
        // Primero se liberan los Pokemons
        for (int i = 0; i < longtd; ++i) {
            Pokemon* p = elementos[i];
            delete p;
        }
        delete[] elementos;
    }
}

void poo::ListaPokemons::concatena(Pokemon* valor) {
    // Si el array interno está completo, hay que ampliarlo.
    if (longtd == capacidad) {
        amplia_capacidad();
    }
    // Ahora, el array interno no está completo.
    elementos[longtd] = valor;
    longtd++;
}

void poo::ListaPokemons::inserta(int indice, Pokemon* valor) {
    // Control de errores: no hace nada en un índice inválido.
    if (indice < 0 || longtd <= indice) {
        return;
    }
    // Control de errores: si el array está completo, no hace nada.
    if (longtd == capacidad) {
        amplia_capacidad();
    }
    // Hay que desplazar los elementos que están a partir de 'indice'
    // para hacer sitio al nuevo elemento.
    desplaza_arriba(indice);
    elementos[indice] = valor;
    longtd++;
}

void poo::ListaPokemons::extrae(int indice) {
    // Control de errores: no hace nada en un índice inválido.
    if (indice < 0 || longtd <= indice) {
        return;
    }
    // Hay que desplazar los elementos que están a partir de 'indice'+1
    // para ocupar el sitio de 'indice'.
    desplaza_abajo(indice + 1);
    longtd--;
}

void poo::ListaPokemons::amplia_capacidad() {
    // ¿Cual es la nueva capacidad? Al menos 10.
    int nueva_capacd = 10;
    if (capacidad > 0) {
        // Simplemente, duplica la capacidad.
        nueva_capacd = capacidad * 2;
    }
    // Nuevo array de elementos para sustituir al anterior.
    Pokemon** nuevos_elemts = new Pokemon * [nueva_capacd];
    // Los elementos actuales se copian en el nuevo array.
    for (int indice = 0; indice < longtd; ++indice) {
        nuevos_elemts[indice] = elementos[indice];
    }
    // Se elimina el array antiguo.
    delete[] elementos;
    // Se establecen los elementos nuevos.
    capacidad = nueva_capacd;
    elementos = nuevos_elemts;
}

void poo::ListaPokemons::desplaza_arriba(int indice) {
    for (int i = longtd - 1; i >= indice; --i) {
        elementos[i + 1] = elementos[i];
    }
}

void poo::ListaPokemons::desplaza_abajo(int indice) {
    for (int i = indice; i <= longtd - 1; ++i) {
        elementos[i - 1] = elementos[i];
    }
}
