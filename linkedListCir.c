#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} CircularLinkedList;

// Prototipos
CircularLinkedList* createList();
void addFront(CircularLinkedList* list, int data);
void addEnd(CircularLinkedList* list, int data);
void addAtPosition(CircularLinkedList* list, int data, int pos);
void removeFront(CircularLinkedList* list);
void removeEnd(CircularLinkedList* list);
void removeAtPosition(CircularLinkedList* list, int pos);
bool search(CircularLinkedList* list, int data);
void traverse(CircularLinkedList* list);
int getSize(CircularLinkedList* list);
bool isEmpty(CircularLinkedList* list);
void clear(CircularLinkedList* list);
void display(CircularLinkedList* list);
int getFront(CircularLinkedList* list);
int getRear(CircularLinkedList* list);

// Crear lista
CircularLinkedList* createList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->front = NULL;
    list->rear = NULL;
    list->size = 0;
    return list;
}

// Agregar al frente
void addFront(CircularLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (list->front == NULL) {
        newNode->next = newNode;
        list->front = list->rear = newNode;
    } else {
        newNode->next = list->front;
        list->rear->next = newNode;
        list->front = newNode;
    }
    list->size++;
}

// Agregar al final
void addEnd(CircularLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (list->front == NULL) {
        newNode->next = newNode;
        list->front = list->rear = newNode;
    } else {
        newNode->next = list->front;
        list->rear->next = newNode;
        list->rear = newNode;
    }
    list->size++;
}

// Agregar en posición
void addAtPosition(CircularLinkedList* list, int data, int pos) {
    if (pos < 0 || pos > list->size) return;
    if (pos == 0) {
        addFront(list, data);
    } else if (pos == list->size) {
        addEnd(list, data);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        Node* temp = list->front;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        list->size++;
    }
}

// Eliminar del frente
void removeFront(CircularLinkedList* list) {
    if (list->front == NULL) return;
    Node* temp = list->front;
    if (list->front == list->rear) {
        list->front = list->rear = NULL;
    } else {
        list->front = list->front->next;
        list->rear->next = list->front;
    }
    free(temp);
    list->size--;
}

// Eliminar del final
void removeEnd(CircularLinkedList* list) {
    if (list->front == NULL) return;
    Node* temp = list->front;
    if (list->front == list->rear) {
        list->front = list->rear = NULL;
        free(temp);
    } else {
        while (temp->next != list->rear) temp = temp->next;
        free(list->rear);
        list->rear = temp;
        list->rear->next = list->front;
    }
    list->size--;
}

// Eliminar en posición
void removeAtPosition(CircularLinkedList* list, int pos) {
    if (pos < 0 || pos >= list->size) return;
    if (pos == 0) {
        removeFront(list);
    } else if (pos == list->size - 1) {
        removeEnd(list);
    } else {
        Node* temp = list->front;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        list->size--;
    }
}

// Buscar
bool search(CircularLinkedList* list, int data) {
    if (list->front == NULL) return false;
    Node* temp = list->front;
    do {
        if (temp->data == data) return true;
        temp = temp->next;
    } while (temp != list->front);
    return false;
}

// Recorrer
void traverse(CircularLinkedList* list) {
    if (list->front == NULL) return;
    Node* temp = list->front;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->front);
    printf("(front)\n");
}

// Tamaño
int getSize(CircularLinkedList* list) {
    return list->size;
}

// ¿Está vacía?
bool isEmpty(CircularLinkedList* list) {
    return list->size == 0;
}

// Limpiar
void clear(CircularLinkedList* list) {
    while (!isEmpty(list)) {
        removeFront(list);
    }
}

// Mostrar
void display(CircularLinkedList* list) {
    printf("Lista: ");
    traverse(list);
    printf("Tamaño: %d\n", getSize(list));
}

// Obtener front
int getFront(CircularLinkedList* list) {
    return list->front ? list->front->data : -1;
}

// Obtener rear
int getRear(CircularLinkedList* list) {
    return list->rear ? list->rear->data : -1;
}

// Programa de prueba
int main() {
    CircularLinkedList* list = createList();
    int choice, value, pos;

    do {
        printf("\n--- Menú Lista Circular ---\n");
        printf("1. Agregar al frente\n2. Agregar al final\n3. Agregar en posición\n");
        printf("4. Eliminar del frente\n5. Eliminar del final\n6. Eliminar en posición\n");
        printf("7. Buscar\n8. Mostrar\n9. Obtener front\n10. Obtener rear\n");
        printf("11. Limpiar\n12. Salir\n");
        printf("Opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Valor: "); scanf("%d", &value);
                addFront(list, value); break;
            case 2:
                printf("Valor: "); scanf("%d", &value);
                addEnd(list, value); break;
            case 3:
                printf("Valor y posición: "); scanf("%d %d", &value, &pos);
                addAtPosition(list, value, pos); break;
            case 4:
                removeFront(list); break;
            case 5:
                removeEnd(list); break;
            case 6:
                printf("Posición: "); scanf("%d", &pos);
                removeAtPosition(list, pos); break;
            case 7:
                printf("Valor a buscar: "); scanf("%d", &value);
                printf(search(list, value) ? "Encontrado\n" : "No encontrado\n"); break;
            case 8:
                display(list); break;
            case 9:
                printf("Front: %d\n", getFront(list)); break;
            case 10:
                printf("Rear: %d\n", getRear(list)); break;
            case 11:
                clear(list); break;
            case 12:
                printf("Saliendo...\n"); break;
            default:
                printf("Opción inválida\n");
        }
    } while (choice != 12);

    clear(list);
    free(list);
    return 0;
}