#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Solicita al usuario el valor de n
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    // Usa malloc para reservar memoria para n enteros
    int *arr = (int *)malloc(n * sizeof(int));

     // Verificar si la memoria se asignó correctamente
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1; // Salir del programa con código de error
    }

     // Llena el arreglo con valores ingresados por el usuario
    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
         printf("Valor %d: ", i + 1);
        scanf("%d", &arr[i]);
        
    }

     // Imprime el arreglo
     printf("Los valores ingresados son: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        
    }
    printf("\n");

    // Libera la memoria reservada
    free(arr);

    return 0;
}
