#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 4

int queue[MAXQUEUE];
int front = 0;
int rear = 0;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    printf("Array-based Queue with MAXQUEUE = %d\n", MAXQUEUE);

    do {
        printf("\n[1 ENQUEUE] [2 DEQUEUE] [0 QUIT]\n");
        printf("Choice > ");
        fflush(stdout);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
        case 0:
            break;
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        default:
            break;
        }

        if (choice) {
            display();
        }
    } while (choice);

    return 0;
}

void enqueue()
{
    int data;

    if (rear == MAXQUEUE) {
        printf("Queue full.\n");
        return;
    } else {
        printf("Number to enqueue > ");
        fflush(stdout);
        scanf("%d", &data);
        fflush(stdin);
        rear++;
        queue[rear - 1] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

void dequeue()
{
    int data;

    if (front == rear) {
        printf("Queue empty.\n");
    } else {
        front++;
        data = queue[front - 1];
        printf("%d dequeued off the queue.\n", data);
    }
}

void display()
{
    int i;

    printf("\n");

    if (front == rear) {
        printf("(empty)");
    } else {
        printf("FRONT -> ");
        for (i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("<- REAR");
    }

    printf("\n");
}
