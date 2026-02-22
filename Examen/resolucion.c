#include <stdio.h>   // Librería estándar para entrada/salida (printf, scanf)
#include <stdlib.h>  // Librería para funciones generales (rand, srand)
#include <time.h>    // Librería para manejar el tiempo (usada para la semilla del aleatorio)

/* Definimos una "Estructura". Es como una ficha técnica que agrupa 
   distintos tipos de datos bajo un mismo nombre (Producto).
*/
typedef struct {
    char nombre[30]; // Cadena de caracteres para el nombre del producto
    float precio;    // Número con decimales para el precio
} Producto;

int main() {
    // --- CONFIGURACIÓN INICIAL ---
    
    // Declaramos e inicializamos el array de 10 productos.
    // Cada par de llaves { "Nombre", precio } representa un elemento de la estructura.
    Producto inventario[10] = {
        {"Leche", 1.20}, {"Pan", 0.85}, {"Huevos", 2.50},
        {"Arroz", 1.10}, {"Cafe", 4.50}, {"Manzanas", 3.20},
        {"Pasta", 0.95}, {"Jabon", 1.80}, {"Aceite", 5.60},
        {"Cereal", 3.00}
    };

    int puntuacionTotal = 0; // Acumulador de aciertos
    char jugarDeNuevo;       // Variable para leer 's' o 'n' al final de la ronda

    /* srand(time(NULL)) establece la "semilla" del generador de números aleatorios.
       Si no ponemos esto, rand() siempre sacaría los mismos productos cada vez
       que abras el programa. Usamos el tiempo actual para que sea siempre distinto.
    */
    srand(time(NULL)); 

    printf("--- BIENVENIDO AL SIMULADOR DE CAJERO ---\n");

    // --- BUCLE PRINCIPAL DE JUEGO ---
    do {
        int indices[3];          // Guardará los 3 números aleatorios elegidos
        float sumaReal = 0;      // Variable para sumar los precios de esos 3 productos
        float estimacionUsuario; // Lo que el usuario cree que vale el total

        printf("\nAdivina el precio total de estos 3 productos:\n");

        // 1. Elegir 3 productos al azar
        for (int i = 0; i < 3; i++) {
            /* rand() % 10 genera un número entre 0 y 9.
               Ese número lo usamos como índice para entrar al array 'inventario'.
            */
            indices[i] = rand() % 10;
            
            // Mostramos el nombre accediendo al índice generado
            printf("- %s\n", inventario[indices[i]].nombre);
            
            // Sumamos el precio de ese producto específico al total real
            sumaReal += inventario[indices[i]].precio;
        }

        // 2. Interacción con el usuario
        printf("\nIntroduce el precio total estimado (ej. 5.45): ");
        
        /* %f es el formato para leer números decimales (float).
           Usamos & para indicar la dirección de memoria donde guardar el dato.
        */
        if (scanf("%f", &estimacionUsuario) != 1) {
            printf("Error: Debes introducir un numero.\n");
            return 1; // Finaliza si el usuario mete algo que no es un número
        }

        // 3. Lógica de comparación
        /* Comparamos la apuesta del usuario con la suma real calculada por el PC.
           Nota: En C, comparar floats con '==' a veces falla por precisión,
           pero para este ejercicio educativo funciona bien.
        */
        if (estimacionUsuario == sumaReal) {
            printf("¡EXACTO! Eres un cajero experto.\n");
            puntuacionTotal++; // Sumamos un punto al contador
        } else {
            // Si falla, mostramos el desglose para que el usuario aprenda los precios
            printf("Error. El precio real era: %.2f\n", sumaReal);
            printf("Desglose:\n");
            for(int j=0; j<3; j++) {
                printf("  > %s: %.2f\n", inventario[indices[j]].nombre, inventario[indices[j]].precio);
            }
        }

        // 4. Control de repetición
        printf("\n¿Quieres jugar otra ronda? (s/n): ");
        /* El espacio antes de %c es CRUCIAL. Sirve para limpiar el "salto de línea" 
           que quedó en el buffer después de que el usuario pulsara Enter en el scanf anterior.
        */
        scanf(" %c", &jugarDeNuevo);

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S'); 
    // El bucle se repite mientras la respuesta sea 's' o 'S'

    // --- FINALIZACIÓN ---
    printf("\n========================================");
    printf("\nSESION FINALIZADA. Aciertos totales: %d", puntuacionTotal);
    printf("\n========================================\n");

    return 0; // El programa termina con éxito
}