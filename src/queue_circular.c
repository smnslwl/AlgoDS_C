#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 4

int queue[MAXQUEUE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    printf("Circular Queue with MAXQUEUE = %d\n", MAXQUEUE);

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

    if ((front == rear + 1) || (front == 0 && rear == MAXQUEUE - 1)) {
        printf("Queue full.\n");
        return;
    } else {
        printf("Number to enqueue > ");
        fflush(stdout);
        scanf("%d", &data);
        fflush(stdin);
        if (rear == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAXQUEUE;
        queue[rear] = data;
        printf("%d enqueued to the queue.\n", data);
    }
}

void dequeue()
{
    int data;

    if (rear == -1) {
        printf("Queue empty.\n");
    } else {
        data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAXQUEUE;
        }
        printf("%d dequeued off the queue.\n", data);
    }
}

void display()
{
    int i;

    printf("\n");

    if (rear == -1) {
        printf("(empty)");
    } else if (front > rear) {
        printf("FRONT -> ");
        for (i = front; i < MAXQUEUE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("<- REAR");
    } else {
        printf("FRONT -> ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("<- REAR");
    }

    printf("\n");
}
