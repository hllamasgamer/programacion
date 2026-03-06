#include <iostream>
// Para usar la clase 'ListaEnteros' se incluye la cabecera que la define.
#include "ListaEnteros.h"

int main () {
    // Crea una instancia de la lista de números enteros.
    // La lista tiene capacidad para 100 enteros.
    ListaEnteros lista {};

    // Bucle que lee la lista de números.
    bool termina = false;
    while (! termina) {
        int numero;
        // Lee un número de la entrada por consola y lo deja en 'numero'.
        // Para terminar la entrada de números pulsar 'Ctrl+D' (o 'Ctrl+Z') y luego 'Intro'.
        std::cin >> numero;
        if (! std::cin) {
            termina = true;
        } else {
            // Concatena el número leído a la lista. Incrementa 'longitud'.
            lista.concatena (numero);
            // Si se han leído ya 100 números, no seguir, no entran en la lista.
            if (lista.longitud == 100) {
                termina = true;                                                         
            }       
        } 
    } 

    // Se escriben los números leídos.
    std::cout << "\n";   
    for (int indice = 0; indice < lista.longitud; ++ indice) {  //indice++
        // Escribe el número y salta de línea.
        std::cout << lista.elementos [indice] << "\n";   
    }
}
