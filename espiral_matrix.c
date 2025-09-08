#include <stdio.h> //librerias
#include <stdlib.h>//librerias

void spiralOrder(int rows, int cols, int **matrix) { //funcion para recibir las columnas y filas
    int top = 0, bottom = rows - 1; //delimitar  sus posiciones, indice
    int left = 0, right = cols - 1; //delimitar posiciones del recuadro, indice

    while (top <= bottom && left <= right) {
        // De izquierda a derecha en la fila superior
        for (int i = left; i <= right; i++) { //recorrer la matriz eh imprimir los valores
            printf("%d ", matrix[top][i]);
        } //hasta que se acaben los de la fila
        top++; //necesaria para continuar con la siguiente ilera

        // De arriba hacia abajo en la columna derecha
        for (int i = top; i <= bottom; i++) { //recorrer la matriz
            printf("%d ", matrix[i][right]); //imprimir los valores
        } //hasta que se acaben los de la fila
        right--; //necesaria para regresar a la columna anterior

        if (top <= bottom) { 
            // De derecha a izquierda en la fila inferior
            for (int i = right; i >= left; i--) { //recorrer la matriz
                printf("%d ", matrix[bottom][i]); //imprimir cada valor
            } //hasta que se acaben los de la fila
            bottom--; //necesaria para volver una fila arriba
        } 

        if (left <= right) { 
            // De abajo hacia arriba en la columna izquierda
            for (int i = bottom; i >= top; i--) { //recorrer la matriz
                printf("%d ", matrix[i][left]); //imprimir la matriz
            } //hasta que se acaben los valores
            left++;//avanazar una columna a la derecha
        }
    }
}

int main() {
    int rows = 5, cols = 4;

    // Asignar memoria dinámicamente para la matriz
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Inicializar la matriz con valores de ejemplo
    int values[5][4] = {
        {1, 2, 3, 4},
        {14, 15, 16, 5},
        {13, 20, 17, 6},
        {12, 19, 18, 7},
        {11, 10, 9, 8}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[i][j];//guardamos la matriz values en el apuntador matrix
        }
    }

    // Llamar a la función para imprimir en espiral
    spiralOrder(rows, cols, matrix);

    // Liberar la memoria asignada
    for (int i = 0; i < rows; i++) { //recorre la matriz
        free(matrix[i]); //libera cada casilla de la matriz
    }
    free(matrix);

    return 0;
}
