#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    //Ingresar los valores de m,n
    printf("Ingrese el numero de filas (m): ");
    scanf ("%d", &m);
    printf("Solicite el numero de filas (n): ");
    scanf ("%d", &n);

    // Usa calloc para reservar memoria para la matriz
    int *matriz = (int *)calloc(m * n, sizeof(int));

    // Verificar si la memoria asignó correctamente
    if (matriz == NULL) {
        printf("Error: No se pudo asignar  a la memoria.\n");
        return 1;
    }

    // Imprime la matriz inicializada con ceros
    printf("\nMatriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]); // Acceso en formato de matriz
        }
        printf("\n");
    }

    // Permite al usuario modificar algunos valores
    int x, y, valor;
    char continuar;
    do {
        printf("\nIngrese la fila y columna a modificar (ejemplo: 1 1 para la primera celda): ");
        scanf("%d %d", &x, &y);
        
        if (x >= 0 && x < m && y >= 0 && y < n) {
            printf("Ingrese el nuevo valor: ");
            scanf("%d", &valor);
            matriz[x * n + y] = valor; // Actualiza el valor en la matriz
        } else {
            printf("Índice fuera de rango. Intente de nuevo.\n");
        }

        printf("¿Desea modificar otro valor? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Imprime la matriz actualizada
    printf("\nMatriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }

    // Libera la memoria reservada
    free(matriz);

    return 0;
}