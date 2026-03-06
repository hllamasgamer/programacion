// Directiva del preprocesador que evita duplicar el código de la cabecera.
#pragma once

// Clase que almacena una lista de números enteros de longitud variable.
class ListaEnteros {
public:
    // Array de 100 enteros.
    int elementos [100];
    // Longitud de la lista.
    // Los elementos de la lista están en: 
    //      'elementos [0]',···,'elementos [99]'.

    int longitud {0};   //indica dónde tengo que insertar

    // Concatena un elemento al final de la lista.
    void concatena (int valor);

    // Inserta un elemento en la lista en la posición indicada por 'indice'.
    void inserta (int indice, int valor);

    // Extrae el elemento de la lista de la posición indicada. 
    void extrae (int indice); 
    
    // Métodos auxiliares.
    // Desplaza los elementos que están a partir de 'indice' a una posición superior.
    //Abrir hueco
    void desplaza_arriba (int indice);

    // Desplaza los elementos que están a partir de 'indice' a una posición inferior.
    //Reubicar cuando borro
    void desplaza_abajo (int indice); 
};
