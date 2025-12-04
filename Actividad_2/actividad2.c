#include<stdio.h>

void mostrarMenu() {
    printf("===BIENVENIDO A HUNDIR LA FLOTA===\n");
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
            t[i][j] = '~'; 
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
void colocarBarcos(char t[12][12]) {
    t[0][0] = 'P'; 
    t[0][1] = 'P'; 
    t[0][2] = 'P'; 
    t[0][3] = 'P';
    t[2][0] = 'C';
    t[2][1] = 'C';
    t[2][2] = 'C';
    t[4][5] = 'C';
    t[5][5] = 'C';
    t[6][5] = 'C';
    t[9][9] = 'T';
    t[9][10] = 'T';
    t[6][0] = 'T';
    t[7][0] = 'T';
    t[11][2] = 'T';
    t[11][3] = 'T';
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