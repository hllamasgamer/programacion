#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estructura para organizar mejor los datos
typedef struct {
    char nombre[30];
    float precio;
} Producto;

int main() {
    // 1. Array de 10 productos y sus precios
    Producto inventario[10] = {
        {"Leche", 1.20}, {"Pan", 0.85}, {"Huevos", 2.50},
        {"Arroz", 1.10}, {"Cafe", 4.50}, {"Manzanas", 3.20},
        {"Pasta", 0.95}, {"Jabon", 1.80}, {"Aceite", 5.60},
        {"Cereal", 3.00}
    };

    int puntuacionTotal = 0;
    char jugarDeNuevo;
    srand(time(NULL)); // Semilla para aleatorios

    printf("--- BIENVENIDO AL SIMULADOR DE CAJERO ---\n");

    do {
        int indices[3];
        float sumaReal = 0;
        float estimacionUsuario;

        printf("\nAdivina el precio total de estos 3 productos:\n");

        // 2. Seleccionar 3 productos aleatorios por ronda
        for (int i = 0; i < 3; i++) {
            indices[i] = rand() % 10;
            // 3. Se muestran nombres, no precios
            printf("- %s\n", inventario[indices[i]].nombre);
            sumaReal += inventario[indices[i]].precio;
        }

        // 4. El usuario introduce su apuesta
        printf("\nIntroduce el precio total estimado: ");
        scanf("%f", &estimacionUsuario);

        // 5. Comparar resultados (usamos un margen pequeño por los decimales)
        // Si quieres que sea exacto, quita el margen de error
        if (estimacionUsuario == sumaReal) {
            printf("¡EXACTO! Eres un cajero experto.\n");
            puntuacionTotal++;
        } else {
            // 6. En caso de fallo, mostrar precios reales
            printf("Error. El precio real era: %.2f\n", sumaReal);
            printf("Desglose: %s (%.2f) + %s (%.2f) + %s (%.2f)\n",
                   inventario[indices[0]].nombre, inventario[indices[0]].precio,
                   inventario[indices[1]].nombre, inventario[indices[1]].precio,
                   inventario[indices[2]].nombre, inventario[indices[2]].precio);
        }

        // 7. Opción de varias rondas
        printf("\n¿Quieres otra ronda? (s/n): ");
        scanf(" %c", &jugarDeNuevo);

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    // 8. Mostrar puntuación final
    printf("\n--- SESION FINALIZADA ---");
    printf("\nPuntuacion total: %d aciertos.\n", puntuacionTotal);

    return 0;
}