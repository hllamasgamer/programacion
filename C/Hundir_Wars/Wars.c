#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mostrarMenu() {
    printf("===BIENVENIDO A HUNDIR LA FLOTA versión STAR WARS===\n");
    printf("Por favor, selecciona una opción:\n");
    printf("1. Iniciar Juego\n");
    printf("2. Mejores Puntuaciones (Aún en construccion)\n");
    printf("3. Salir\n");
}
int leerOpcion(){
    printf("Introduce una opción (1-3): \n");
    int opcion;
    int resultado = scanf("%d", &opcion);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (resultado == 1) {
        return opcion;
    } else {
        return -1;
    }
}
void crearTablero(char t[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            t[i][j] = '*'; 
        }
    }
}
void mostrarTablero(char t[12][12]) {
    printf("  ");
    for (int j = 0; j < 12; j++) {
        printf("%2d", j);
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("%2d", i);
        for (int j = 0; j < 12; j++) {
            printf("%2c", t[i][j]);
        }
        printf("\n");
    }
}
void colocarNaveAleatoria(char t[12][12], int size, char symbol) {
int colocada = 0;
int orientacion;
int fila, columna;

while (colocada == 0) {
    orientacion = rand() % 2;
    fila = rand() % 12;
    columna = rand() % 12;

    if (orientacion == 0) { // horizontal
        if (columna + size > 12) {
            continue;
        }
    } else { // vertical
        if (fila + size > 12) {
            continue;
        }
    }

    // aquí vendrá luego la comprobación de casillas libres
    // y la colocación
}
}

void colocarBarcos(char t[12][12]) {

    colocarNaveAleatoria(t, 4, 'C');
    colocarNaveAleatoria(t, 3, 'F');
    colocarNaveAleatoria(t, 3, 'F');
    colocarNaveAleatoria(t, 2, 'T');
    colocarNaveAleatoria(t, 2, 'T');
    colocarNaveAleatoria(t, 2, 'T');

}
void iniciarPartida() {
    printf("Creando el tablero de juego...\n");
    printf("Por favor, presiona Enter para continuar...\n");
    getchar();
    char tableroJugador[12][12];
    char tableroOponente[12][12];
    crearTablero(tableroJugador);
    crearTablero(tableroOponente);
    colocarBarcos(tableroJugador);
    colocarBarcos(tableroOponente);
    printf("Tablero del jugador:\n");
    mostrarTablero(tableroJugador);
    printf("Tablero del oponente:\n");
    mostrarTablero(tableroOponente);
    getchar();
}
void mostrarPuntuaciones() {
    printf("Mostrando mejores puntuaciones (Aún en construcción)...\n");
    getchar();
}
int main(){
    srand(time(NULL));
    int salir = 0;
    while (salir == 0) {
        mostrarMenu();
        int opcion = leerOpcion();

        switch (opcion) {
            case 1:
                iniciarPartida();
                break;
            case 2:
                mostrarPuntuaciones();
                break;
            case 3:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                salir = 1;
                break;
            default:
                printf("Opción no válida. Por favor, intenta de nuevo.\n");
                break;
        }
    }
    return 0;
}