// archivo: ListaPokemon.h

#pragma once
#include "Pokemon.h"

// La lista está en el espacio de nombres de la asignatura.
namespace poo {

    // Clase que almacena una lista de Pokemons de longitud variable.
    // No hay un número máximo de elementos para la lista. 
    // Inicialmente tiene cero elementos.
    class ListaPokemons {
    public:
        // Constructor.
        ListaPokemons();
        // Destructor.
        // Además, elimina los Pokemons contenidos en la lista.
        ~ListaPokemons();

        // Obtiene la longitud de la lista.
        int longitud();
        // Obtiene el elemento cuyo índice se indica.
        Pokemon* getElemento(int indice);
        // Establece el valor del elemento cuyo índice se indica.
        void setElemento(int indice, Pokemon* valor);

        // Concatena un Pokemon al final de la lista.
        void concatena(Pokemon* valor);
        // Inserta un elemento en la lista en la posición indicada 
        // por 'indice'.
        void inserta(int indice, Pokemon* valor);
        // Extrae el elemento de la lista de la posición indicada. 
        void extrae(int indice);
    private:
        // Longitud del array 'elementos'.
        int capacidad;
        // Array de 'capacidad' Pokemons.
        // Se trata de un array de punteros a Pokemon.
        // El primer * es por ser puntero, el segundo * es por ser array.
        // Es un puntero que se usa como si fuera un array.
        Pokemon** elementos;
        // Longitud de la lista.
        // Los elementos de la lista están en: 
        //      'elementos [0]',···,'elementos [longtd-1]'.
        int longtd;

        // Amplia la capacidad de la lista cuando es necesario.
        void amplia_capacidad();
        // Desplaza los elementos que están a partir de 'indice' a una posición superior.
        void desplaza_arriba(int indice);
        // Desplaza los elementos que están a partir de 'indice' a una posición inferior.
        void desplaza_abajo(int indice);
    };

    inline int ListaPokemons::longitud() {
        return longtd;
    }

    inline Pokemon* ListaPokemons::getElemento(int indice) {
        return elementos[indice];
    }

    inline void ListaPokemons::setElemento(int indice, Pokemon* valor) {
        elementos[indice] = valor;
    }

}
