#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 5


int main(){
 int queue[QUEUESIZE];
 int front=-1;
 int rear=-1;
 char opcion;
 int elemento;

    while (1) {
        // Muestra el contenido de la cola
        printf("Contenido de la cola: ");
        if (front == -1 || front > rear) {
            printf("esta vacia.");
        } else {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n\n");

        printf("Escribe E para agregar un valor\n");
        printf("Escribe D para eliminar el elemento frontal de al cola\n");
        printf("Escribe Q para terminar el programa\n ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'E':
            case 'e':
                // Enqueue
                if (rear == QUEUESIZE - 1) {
                    printf("La cola esta llena\n");
                } else {
                    printf("Escribe el valor para la cola");
                    scanf("%d", &elemento);
                    if (front == -1) {
                        front = 0;
                    }
                    rear++;
                    queue[rear] = elemento;
                    printf("%d\n", elemento);
                }
                break;
            case 'D':
            case 'd':
                // Dequeue
                if (front == -1 || front > rear) {
                    printf("Esta vacia\n");
                } else {
                    elemento = queue[front];
                    front++;
                    printf(" %d\n", elemento);
                    if (front > rear) {
                        front = -1;
                        rear = -1;
                    }
                }
                break;
            case 'Q':
            case 'q':
                printf("exit\n");
                return 0;
            default:
                printf("Escribe solo la letra E,D o Q\n");
                break;
        }
        // Muestra el contenido de la cola después de cada operación
        printf("Current queue content: ");
        if (front == -1 || front > rear) {
            printf("The queue is empty.\n\n");
        } else {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n\n");
        }
    }

    return 0;
}
