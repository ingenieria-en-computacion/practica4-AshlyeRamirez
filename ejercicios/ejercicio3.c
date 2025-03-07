#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 2; // Asigna un número pequeño
    int *arr = (int *)malloc(size * sizeof(int)); // reserva memoria con malloc

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese números (ingrese -1 para terminar):\n");

    while (1) {
        scanf("%d", &num);
        if (num == -1) break;//rompe el ciclo

        // Si el arreglo está lleno, aumentar su tamaño con realloc
        if (count >= size) {
            size *= 2;
            int *temp = (int *)realloc(arr, size * sizeof(int));
            if (temp == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                free(arr);
                return 1;
            }
            arr = temp;
        }

        arr[count++] = num;
    }

    // Imprimir la lista ingresada
    printf("La lista ingresada es: ");
    for (int i = 0; i < count; i++) {
        //Imprime la lista
        printf("%d ", arr[i]);
    }
    printf("\n");

    //libera la memoria asignada
    free(arr);
    return 0;

}
