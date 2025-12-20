#include<stdio.h>          // Incluye la librería estándar de entrada/salida (printf, scanf, getchar, etc.)


void mostrarMenu() {       
    printf("===BIENVENIDO A HUNDIR LA FLOTA===\n");         // Muestra el título del juego
    printf("Por favor, selecciona una opción:\n");         // Pide al usuario que elija una opción
    printf("1. Iniciar Juego\n");                          // Opción 1: iniciar partida
    printf("2. Mejores Puntuaciones (Aún en construccion)\n"); // Opción 2: futuras puntuaciones
    printf("3. Salir\n");                                  // Opción 3: salir del programa
}

int leerOpcion(){
    printf("Introduce una opción (1-3): \n");              // Muestra mensaje pidiendo la opción
    int opcion;                                            // Variable donde se guarda la opción numérica
    int resultado = scanf("%d", &opcion);                  // Intenta leer un entero; guarda cuántos valores ha leído (0 o 1)
    int c;                                                 // Variable para limpiar el búfer de entrada
    while ((c = getchar()) != '\n' && c != EOF);           // Consume el resto de la línea hasta el salto de línea o EOF
    if (resultado == 1) {                                  // Si scanf ha leído 1 entero correctamente...
        return opcion;                                     // ...devuelve la opción introducida por el usuario
    } else {                                               // Si scanf NO ha leído un número (por ejemplo se metió una letra)
        return -1;                                         // ...devuelve -1 indicando opción inválida
    }
}

void crearTablero(char t[12][12]) {                        // Recibe una matriz 12x12 de caracteres
    for (int i = 0; i < 12; i++) {                         // Recorre las filas (0 a 11)
        for (int j = 0; j < 12; j++) {                     // Recorre las columnas (0 a 11) en cada fila
            t[i][j] = '~';                                 // Asigna el carácter '~' para representar agua en esa casilla
        }
    }
}

void mostrarTablero(char t[12][12]) {                      // Recibe un tablero 12x12 para imprimirlo
    printf("  ");                                          // Imprime dos espacios iniciales para alinear cabecera de columnas
    for (int j = 0; j < 12; j++) {                         // Recorre las columnas para imprimir sus índices (0..11)
        printf("%2d", j);                                  // Imprime el número de columna con ancho 2 (alineado)
    }
    printf("\n");                                          // Salta a la siguiente línea tras la cabecera

    for (int i = 0; i < 12; i++) {                         // Recorre las filas del tablero
        printf("%2d", i);                                  // Imprime el índice de fila con ancho 2
        for (int j = 0; j < 12; j++) {                     // Recorre cada columna de esa fila
            printf("%2c", t[i][j]);                        // Imprime el carácter almacenado en la casilla [i][j] con ancho 2
        }
        printf("\n");                                      // Salta a la siguiente línea al terminar una fila
    }
}

void colocarBarcos(char t[12][12]) {                       // Recibe un tablero 12x12 donde va a colocar barcos
    t[0][0] = 'P';                                         // Portaviones (P) – casilla (0,0)
    t[0][1] = 'P';                                         // Portaviones – casilla (0,1)
    t[0][2] = 'P';                                         // Portaviones – casilla (0,2)
    t[0][3] = 'P';                                         // Portaviones – casilla (0,3)

    t[2][0] = 'C';                                         // Crucero (C) – casilla (2,0)
    t[2][1] = 'C';                                         // Crucero – casilla (2,1)
    t[2][2] = 'C';                                         // Crucero – casilla (2,2)

    t[4][5] = 'C';                                         // Segundo Crucero – casilla (4,5)
    t[5][5] = 'C';                                         // Segundo Crucero – casilla (5,5)
    t[6][5] = 'C';                                         // Segundo Crucero – casilla (6,5)

    t[9][9] = 'T';                                         // Patrullero (T) – casilla (9,9)
    t[9][10] = 'T';                                        // Patrullero – casilla (9,10)

    t[6][0] = 'T';                                         // Segundo patrullero – casilla (6,0)
    t[7][0] = 'T';                                         // Segundo patrullero – casilla (7,0)

    t[11][2] = 'T';                                        // Tercer patrullero – casilla (11,2)
    t[11][3] = 'T';                                        // Tercer patrullero – casilla (11,3)
}

void iniciarPartida() {
    printf("Creando el tablero de juego...\n");            // Mensaje informativo: comienza la creación de tableros
    printf("Por favor, presiona Enter para continuar...\n");// Pide al usuario que pulse Enter para seguir
    getchar();                                             // Espera a que el usuario pulse Enter (consumiendo ese '\n')

    char tableroJugador[12][12];                           // Declara el tablero del jugador (matriz 12x12)
    char tableroOponente[12][12];                          // Declara el tablero del oponente (otra matriz 12x12)

    crearTablero(tableroJugador);                          // Inicializa el tablero del jugador con '~'
    crearTablero(tableroOponente);                         // Inicializa el tablero del oponente con '~'

    colocarBarcos(tableroJugador);                         // Coloca barcos fijos en el tablero del jugador
    colocarBarcos(tableroOponente);                        // Coloca los mismos barcos fijos en el tablero del oponente

    printf("Tablero del jugador:\n");                      // Cabecera antes de mostrar el tablero del jugador
    mostrarTablero(tableroJugador);                        // Muestra el tablero del jugador (con barcos visibles)

    printf("Tablero del oponente:\n");                     // Cabecera antes de mostrar el tablero del oponente
    mostrarTablero(tableroOponente);                       // Muestra el tablero del oponente

    getchar();                                             // Espera a que el usuario pulse Enter antes de volver al menú
}

void mostrarPuntuaciones() {
    printf("Mostrando mejores puntuaciones (Aún en construcción)...\n"); // Mensaje de módulo no implementado
    getchar();                                             // Pausa para que el usuario lea el mensaje
}

int main(){
    int salir = 0;                                         // Variable de control del bucle principal (0 = seguir, 1 = salir)

    while (salir == 0) {                                   // Bucle principal del programa: se repite hasta que salir sea 1
        mostrarMenu();                                     // Muestra el menú de opciones
        int opcion = leerOpcion();                         // Lee la opción del usuario y la guarda en 'opcion'

        switch (opcion) {                                  // Selecciona el camino según la opción elegida
            case 1:                                        // Si el usuario elige 1
                iniciarPartida();                          // Llama al módulo JUGAR (crea y muestra los tableros)
                break;                                     // Vuelve al while (menú)
            case 2:                                        // Si el usuario elige 2
                mostrarPuntuaciones();                     // Muestra el mensaje de puntuaciones en construcción
                break;                                     // Vuelve al while (menú)
            case 3:                                        // Si el usuario elige 3
                printf("Saliendo del programa. ¡Hasta luego!\n");// Despedida del programa
                salir = 1;                                 // Cambia la variable para salir del bucle
                break;                                     // Sale del switch, y el while ya no se repetirá
            default:                                       // Para cualquier otra entrada (incluyendo -1 de leerOpcion)
                printf("Opción no válida. Por favor, intenta de nuevo.\n"); // Mensaje de error
                break;                                     // Vuelve al menú
        }
    }
    return 0;                                              // Devuelve 0 indicando que el programa termina correctamente
}
/*
===========================================================
            RESUMEN DE FUNCIONES DEL PROGRAMA
===========================================================

- mostrarMenu()
  Muestra por pantalla las opciones del menú principal.

- leerOpcion()
  Lee la opción del usuario, valida si es número y limpia el búfer.
  Devuelve la opción o -1 si la entrada es inválida.

- crearTablero()
  Inicializa una matriz 12x12 asignando '~' en todas sus posiciones.

- mostrarTablero()
  Imprime un tablero 12x12 con índices de filas y columnas.

- colocarBarcos()
  Coloca barcos en posiciones fijas dentro del tablero.
  Usa 'P', 'C' y 'T' según el tipo de barco.

- iniciarPartida()
  Crea los tableros del jugador y del oponente, inicializa sus
  casillas, coloca barcos y muestra ambos tableros en pantalla.

- mostrarPuntuaciones()
  Función placeholder que muestra un mensaje indicando que
  aún no está implementada.

- main()
  Controla el flujo del programa mediante un bucle que muestra
  el menú, lee la opción del usuario y llama al módulo 
  correspondiente.
===========================================================
*/
