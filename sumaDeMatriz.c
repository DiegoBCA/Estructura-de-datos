#include <stdio.h>
#include <stdlib.h>

int main (){
    int rows, cols; //incializar las filas y columnas

    printf("escribe el numero de filas y columnas \n");
    scanf("%d %d", &rows, &cols); // input de las filas y columnas

    int *A = (int *)malloc((size_t)rows * (size_t)cols * sizeof(int));//incilaizar la matriz A como apuntador
    int *B = (int *)malloc((size_t)rows * (size_t)cols * sizeof(int));//inicializar la matriz B como apuntador
    int *C = (int *)malloc((size_t)rows * (size_t)cols * sizeof(int));//incializar la matriz C como apuntador

    printf("escribe la matriz A: \n"); //escribe la matriz A
    for(int i = 0; i < rows; i++){ //recorrer las filas
        for(int j = 0; j < cols; j++){ //recorrer las columnas
            scanf("%d", &A[i*cols + j]); //almacenar el dato por filas y columnas
        }
    }
        printf("\n");

    printf("escribe la matriz B: \n");//escribe la matriz B
    for(int i = 0; i < rows; i++){ //recorrer las filas
        for(int j = 0; j < cols; j++){ //recorrer las columnas
            scanf("%d", &B[i*cols + j]);//almacenar el dato por filas y columnas
        }
        printf("\n");
    }
    printf("la matriz C es: \n"); //imprime la matriz C
    for(int i = 0; i < rows; i++){ //recorrer las filas
        for(int j = 0; j < cols; j++){ //recorrer las columnas
            C[i*cols + j] = A[i*cols + j] + B[i*cols + j]; //sumar la matriz A y la B por dato
            printf("%d ", C[i*cols + j]); //imprime la matriz C
        }
printf("\n ");
        }
        free(A);
        free(B);
        free(C);
        return 0;
    
}
