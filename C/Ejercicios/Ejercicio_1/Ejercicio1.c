#include<stdio.h>

int main() {
    float numero1, numero2, numero3;

    printf("Ingrese el primer numero: ");
    scanf("%f", &numero1);
    printf("Ingrese el segundo numero: ");
    scanf ("%f", &numero2);
    printf("Ingrese el tercer numero: ");
    scanf ("%f", &numero3);
    float suma = numero1 + numero2 + numero3; // Siempre tiene que ir detras de leer los numeros, sino no lo hace bien //
    float promedio = suma/3;
    printf("El promedio es: %.2f\n", promedio);
    printf("Presione Enter para salir...");
    getchar();
    getchar();
    return 0;

}