#include <stdio.h>

// Definimos un tamaño máximo para el heap
#define MAX_SIZE 100

// Arreglo global para almacenar el heap
int heap[MAX_SIZE];
// Variable global para rastrear el tamaño actual del heap
int heapSize = 0;

/**
 * @brief Intercambia dos valores enteros.
 * @param a Puntero al primer entero.
 * @param b Puntero al segundo entero.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief "Re-heapify" hacia arriba (sift-up).
 * Mueve un elemento hacia arriba en el árbol para mantener la propiedad de Max-Heap.
 * Se usa después de una inserción.
 * @param i Índice del elemento a mover hacia arriba.
 */
void reHeapUp(int i) {
    // Mientras el elemento no sea la raíz (i > 0) y sea mayor que su padre
    // (i-1)/2 es el índice del padre
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        // Intercambia el elemento con su padre
        swap(&heap[i], &heap[(i - 1) / 2]);
        // Mueve el índice al del padre para continuar la comprobación hacia arriba
        i = (i - 1) / 2;
    }
}

/**
 * @brief Inserta un nuevo elemento en el heap.
 * @param item El valor entero a insertar.
 */
void insert(int item) {
    if (heapSize >= MAX_SIZE) {
        printf("Error: Heap está lleno. No se pudo insertar %d.\n", item);
        return;
    }

    // 1. Añade el nuevo elemento al final del arreglo
    heap[heapSize] = item;
    int currentIndex = heapSize;
    heapSize++;

    // 2. "Flota" el elemento hacia arriba a su posición correcta
    reHeapUp(currentIndex);
}

/**
 * @brief "Re-heapify" hacia abajo (sift-down).
 * Mueve un elemento hacia abajo en el árbol para mantener la propiedad de Max-Heap.
 * Se usa después de eliminar la raíz.
 * @param i Índice del elemento a mover hacia abajo.
 */
void reHeapDown(int i) {
    int largest = i; // Asume que el nodo actual 'i' es el más grande
    int leftChild = 2 * i + 1;  // Índice del hijo izquierdo
    int rightChild = 2 * i + 2; // Índice del hijo derecho

    // 1. Comprueba si el hijo izquierdo existe y es mayor que el nodo 'largest' actual
    if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    // 2. Comprueba si el hijo derecho existe y es mayor que el nodo 'largest' actual
    if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    // 3. Si el nodo 'i' no es el más grande (es decir, uno de sus hijos es mayor)
    if (largest != i) {
        // Intercambia el nodo 'i' con su hijo más grande
        swap(&heap[i], &heap[largest]);
        // Llama recursivamente a reHeapDown en el subárbol afectado
        // 'largest' ahora contiene el índice donde se movió el valor original de 'i'
        reHeapDown(largest);
    }
}

/**
 * @brief Elimina y devuelve el elemento máximo (la raíz) del heap.
 * @return El valor máximo del heap, o -1 si el heap está vacío.
 */
int removeMax(void) {
    if (heapSize <= 0) {
        printf("Error: Heap está vacío.\n");
        return -1; // Valor de error
    }

    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    // 1. Guarda la raíz (el máximo) para devolverla
    int maxItem = heap[0];

    // 2. Mueve el último elemento del heap a la raíz
    heap[0] = heap[heapSize - 1];
    heapSize--;

    // 3. "Hunde" el nuevo elemento de la raíz a su posición correcta
    reHeapDown(0);

    return maxItem;
}

/**
 * @brief Muestra el contenido del heap (el arreglo).
 */
void showHeap(void) {
    printf("Heap actual (arreglo): [ ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("]\n");
}

/**
 * @brief Muestra la estructura de árbol del heap.
 * Itera a través de todos los nodos padre y muestra sus hijos.
 */
void showHeapStructure(void) {
    printf("Estructura del Heap (Nodo[índice] = valor):\n");
    if (heapSize == 0) {
        printf("  (Heap vacío)\n");
        return;
    }

    // Solo necesitamos iterar hasta el último nodo padre.
    // El último nodo padre está en (heapSize / 2) - 1.
    for (int i = 0; i < (heapSize / 2); i++) {
        printf("  Padre[%d] = %d\n", i, heap[i]);
        
        // Hijo Izquierdo
        int left = 2 * i + 1;
        if (left < heapSize) {
            printf("    -> Hijo Izquierdo[%d] = %d\n", left, heap[left]);
        }

        // Hijo Derecho (puede no existir)
        int right = 2 * i + 2;
        if (right < heapSize) {
            printf("    -> Hijo Derecho[%d] = %d\n", right, heap[right]);
        }
    }
    // ... (El resto de comentarios en esta función fueron eliminados) ...
    
    // Caso especial: si el heap solo tiene un nodo (la raíz),
    // el bucle for (i < heapSize/2) no se ejecutará.
    if (heapSize == 1) {
         printf("  Raíz[%d] = %d (sin hijos)\n", 0, heap[0]);
    }

    printf("----------------------------------------\n");
}

/**
 * @brief Función principal para demostrar la funcionalidad del Max-Heap.
 */
int main() {
    // --- 1. Fase de Inserción ---
    printf("--- FASE DE INSERCIÓN ---\n");
    int itemsToInsert[] = {10, 50, 20, 5, 80, 30, 65};
    int n = sizeof(itemsToInsert) / sizeof(itemsToInsert[0]);

    for (int i = 0; i < n; i++) {
        printf("Insertando %d...\n", itemsToInsert[i]);
        insert(itemsToInsert[i]);
        showHeap();
    }

    printf("\n--- ESTRUCTURA FINAL DEL HEAP (POST-INSERCIÓN) ---\n");
    showHeapStructure();

    // --- 2. Fase de Eliminación ---
    printf("\n--- FASE DE ELIMINACIÓN ---\n");
    int K = 3; // Número de elementos máximos a eliminar
    printf("Eliminando los %d elementos máximos...\n", K);

    for (int i = 0; i < K; i++) {
        int maxVal = removeMax();
        if (maxVal != -1) {
            printf("\nElemento máximo eliminado: %d\n", maxVal);
            showHeap();
        }
    }

    printf("\n--- ESTRUCTURA FINAL DEL HEAP (POST-ELIMINACIÓN) ---\n");
    showHeapStructure();

    return 0;
}
