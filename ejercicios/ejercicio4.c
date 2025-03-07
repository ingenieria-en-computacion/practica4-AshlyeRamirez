#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char nombre[40];
    int edad;
} Estudiante;

int main() {
    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
     Estudiante *lista = (Estudiante *)malloc(size * sizeof(Estudiante));
    
    //Si el arreglo es nulo imprime el mensaje
    if (lista == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf(" %49s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            lista = (Estudiante *)realloc(lista, size * sizeof(Estudiante));
            
            //Verifica nuevamente que si apunta a nulo se imprima el error
            if (lista == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strncpy(lista[count].nombre, nombre, 40);
        lista[count].nombre[39] = '\0'; // Asegurar terminación nula
        lista[count].edad = edad;
        
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", lista[i].nombre, lista[i].edad);
        
    }

    //libera la memoria
    free(lista);
    return 0;
}
