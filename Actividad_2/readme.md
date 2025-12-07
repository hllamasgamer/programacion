# Hundir la Flota – Actividad 2 (Programación en C)

Este proyecto implementa una versión inicial del juego *Hundir la Flota* 
El programa muestra un menú, permite iniciar una partida, la cual crea los tableros de ambos jugadores (jugador y oponente), coloca las naves en posiciones fijas y muestra los tableros por pantalla.

## Funcionalidad principal
- Menú con opciones: Iniciar juego, ver puntuaciones (en construcción) y salir.
- Creación de dos tableros de 12×12 utilizando matrices bidimensionales.
- Inicialización de los tableros con el carácter `~` (agua).
- Colocación de naves en posiciones fijas.
- Visualización completa del tablero del jugador y del oponente.

## Compilación y ejecución
Windows:
gcc actividad2.c -o actividad2.exe
.\actividad2.exe

Mac:
cc actividad2.c .o actividad2
./actividad2
