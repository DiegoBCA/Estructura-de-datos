#include <stdio.h>
#include <stdlib.h>

// Para una implementación simple, podemos usar un arreglo de punteros a arreglos para simular las listas.
// En un escenario real, se usarían listas enlazadas o estructuras de datos dinámicas.

// Definir el número de vértices
#define V_LIST 4

// Estructura para un nodo de la lista de adyacencia
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Estructura para representar la lista de adyacencia para un vértice
typedef struct AdjList {
    Node* head;
} AdjList;

// Estructura para representar el grafo
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Función para crear un nuevo nodo de lista de adyacencia
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Función para crear un grafo con V vértices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Crear un arreglo de listas de adyacencia. Un AdjList para cada vértice
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));

    // Inicializar cada lista de adyacencia como vacía
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Función para agregar una arista dirigida (src -> dest) al grafo
void addEdge(Graph* graph, int src, int dest) {
    // Agregar el nodo a la lista de src. Es una nueva cabeza de la lista
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Función para imprimir la lista de adyacencia
void printAdjList(Graph* graph) {
    printf("\nLista de Adyacencia (Dirigida):\n");
    char labels[] = {'A', 'B', 'C', 'D'};

    for (int v = 0; v < graph->numVertices; ++v) {
        Node* pCrawl = graph->array[v].head;
        printf("%c: ", labels[v]);
        while (pCrawl) {
            printf("%c -> ", labels[pCrawl->dest]);
            pCrawl = pCrawl->next;
        }
        printf("NULL\n");
    }
}

int main_list() {
    Graph* graph = createGraph(V_LIST);

    // Agregar las aristas dirigidas: (A, B), (A, C), (B, D), (C, B)
    // A=0, B=1, C=2, D=3

    addEdge(graph, 0, 1); // A -> B
    addEdge(graph, 0, 2); // A -> C
    addEdge(graph, 1, 3); // B -> D
    addEdge(graph, 2, 1); // C -> B

    printAdjList(graph);

    // Liberar memoria (importante en C)
    for (int i = 0; i < graph->numVertices; ++i) {
        Node* current = graph->array[i].head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}
