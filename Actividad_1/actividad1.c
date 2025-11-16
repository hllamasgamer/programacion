#include<stdio.h>
#include<string.h>

int main(){

     printf("Hola, como te llamas?\n");
    char nombre[50];
    scanf("%49s", nombre);
    printf("De que pais eres?\n");
    char pais[50];
    scanf("%49s", pais);
    if (strcmp(pais, "Japon") ==0){

        printf("hajimemashite, %s-san\n", nombre);
    }
    else if (strcmp(pais, "Inglaterra") ==0){
        printf("Nice to meet you, %s\n", nombre);
    }
    else {
        printf("Mucho gusto, %s\n", nombre);
    }
    return 0;
}