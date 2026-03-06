// Para implementar la clase 'ListaEnteros' se incluye la cabecera que la define.
#include "ListaEnteros.h"

//int ListaEnteros::concatena (int valor)
void ListaEnteros::concatena (int valor) {
    // Control de errores: si el array está completo, no hace nada.
    if (longitud >= 100) {
        return;
    }
    elementos[longitud] = valor;
    longitud++;

    return;
    //return longitud;
}

void ListaEnteros::inserta (int indice, int valor) {
    // Control de errores: no hace nada en un índice inválido.
    if (indice < 0 || longitud <= indice) {
        return;
    }
    // Control de errores: si el array está completo, no hace nada.
    if (longitud >= 100) {
        return;                        
    }
    // Hay que desplazar los elementos que están a partir de 'indice' para hacer sitio al nuevo elemento.
    desplaza_arriba (indice); 
    elementos [indice] = valor;
    longitud ++;
}

void ListaEnteros::extrae (int indice) {
    // Control de errores: no hace nada en un índice inválido.
    if (indice < 0 || longitud <= indice) {
        return;
    }
    // Hay que desplazar los elementos que están a partir de 'indice'+1 para ocupar el sitio de 'indice'.
    desplaza_abajo (indice + 1); 
    longitud --;

    /*
    int valor;
    valor = elementos [indice];
    desplaza_abajo (indice + 1);
    longitud --;

    return valor;

    */
}

void ListaEnteros::desplaza_arriba (int indice) {
    for (int i = longitud - 1; i >= indice; -- i) {
        elementos [i + 1] = elementos [i]; 
    }
}

void ListaEnteros::desplaza_abajo (int indice) {
    for (int i = indice; i <= longitud - 1; ++ i) {
        elementos [i - 1] = elementos [i]; 
    }
}
