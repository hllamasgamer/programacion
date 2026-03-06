#include <stdio.h>
#include <stdlib.h>  // Necesario para rand() y srand()
#include <time.h>    // Necesario para time()
#include <stdbool.h> // Necesario para usar 'true' y 'false'

int main() {
    // 1. Inicializar la "semilla" para los números aleatorios. 
    // Esto se hace solo una vez al principio del programa.
    srand(time(NULL)); 
    
    bool jugar_de_nuevo = true;
    char respuesta;

    // Bucle principal para reiniciar el juego
    while (jugar_de_nuevo) {
        
        // Configuración inicial de la partida
        int intentos_restantes = 3;
        int habitacion_actual = 1;
        bool tesoro_encontrado = false;
        
        // Generar un número aleatorio entre 1 y 5 para esconder el tesoro
        int habitacion_tesoro = (rand() % 5) + 1;
        
        // Arreglo para registrar cofres abiertos (0 al 4). Inician en 'false'.
        bool cofres_abiertos[5] = {false, false, false, false, false};

        printf("\n=== ¡Bienvenido a la mazmorra de las 5 habitaciones! ===\n");

        // Bucle de la partida actual
        while (intentos_restantes > 0 && !tesoro_encontrado) {
            printf("\n----------------------------------------\n");
            printf("Estás en la habitacion: %d\n", habitacion_actual);
            printf("Intentos restantes: %d\n", intentos_restantes);
            printf("Elige una accion:\n");
            printf("1. Avanzar\n");
            printf("2. Retroceder\n");
            printf("3. Abrir cofre\n");
            printf("Tu eleccion: ");
            
            int accion;
            scanf("%d", &accion);

            // Lógica de movimiento y acciones
            if (accion == 1) {
                if (habitacion_actual < 5) {
                    habitacion_actual++; // Suma 1 a la habitación
                    printf("-> Avanzas a la siguiente habitacion.\n");
                } else {
                    printf("-> Ya estás en la ultima habitacion, no puedes avanzar mas.\n");
                }
                
            } else if (accion == 2) {
                if (habitacion_actual > 1) {
                    habitacion_actual--; // Resta 1 a la habitación
                    printf("-> Retrocedes a la habitacion anterior.\n");
                } else {
                    printf("-> Estas en la entrada, no puedes retroceder mas.\n");
                }
                
            } else if (accion == 3) {
                // Ajustamos a índice de arreglo (0 a 4)
                int indice_cofre = habitacion_actual - 1;
                
                if (cofres_abiertos[indice_cofre]) {
                    printf("-> Ya abriste este cofre. Está vacio.\n");
                } else {
                    cofres_abiertos[indice_cofre] = true; // Marcamos como abierto
                    
                    if (habitacion_actual == habitacion_tesoro) {
                        printf("-> ¡Felicidades! Has encontrado el TESORO.\n");
                        tesoro_encontrado = true;
                    } else {
                        printf("-> El cofre esta vacio...\n");
                        intentos_restantes--; // Restamos un intento
                    }
                }
                
            } else {
                printf("-> Accion no valida. Intenta de nuevo con 1, 2 o 3.\n");
            }
        }

        // Final de la partida actual
        if (!tesoro_encontrado) {
            printf("\n----------------------------------------\n");
            printf("Te has quedado sin intentos. ¡FIN DEL JUEGO!\n");
            printf("El tesoro estaba en la habitacion: %d\n", habitacion_tesoro);
        }

        // Opción para volver a jugar
        printf("\n¿Quieres jugar de nuevo? (S para si, N para no): ");
        // El espacio antes de %c es un pequeño truco en C para ignorar el "Enter" anterior
        scanf(" %c", &respuesta); 
        
        if (respuesta == 'N' || respuesta == 'n') {
            jugar_de_nuevo = false;
        }
    }

    printf("\n¡Gracias por jugar! Hasta pronto.\n");
    return 0;
}