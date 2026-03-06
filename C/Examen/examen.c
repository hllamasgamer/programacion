#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definir numero productos
#define NUM_PROD 10


// Estructura para almacenar Productos y Precios
struct Productos{
    char products[20];
    int precios;
};

// Lista de productos y Precios
struct Productos productos[NUM_PROD] = {
    {"Leche", 1},
    {"Pan", 1},
    {"Sal", 1},
    {"Harina", 2},
    {"Carne", 5},
    {"Pescado", 5},
    {"Huevos", 3},
    {"Lavavajillas", 4},
    {"Servilletas", 1},
    {"Ambientador", 2}
};

// Funcion Jugar
void Jugar() {
    int valor_total; // Se almacena la respuesta del jugador

    srand(time(NULL));

    
        int indice = rand () % NUM_PROD;
        struct Productos elegidos = productos [indice];
        

        printf("Adivina el precio de estos 3 productos:\n%s\n", elegidos.products);
        scanf("%d", &valor_total);
        if (valor_total == 10) {
            printf("Enhorabuena, has acertado el precio!");
        }
        else {
            printf("Lo siento, no has acertado el precio...");
        }
};

int main () {
    printf("Bienvenido al Juego del Supermercado\n");
    Jugar();
    return 0;
}
// A la hora de comparar el precio, puse algo al azar, en este momoento estoy bloqueado y no se por donde seguir. Gracias por su tiempo