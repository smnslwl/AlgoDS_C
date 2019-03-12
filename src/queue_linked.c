#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *prev;
    struct node_struct *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    printf("Linked Queue\n");

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
    printf("Number to insert > ");
    fflush(stdout);
    scanf("%d", &data);
    fflush(stdin);

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failure.\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = rear;
    if (rear != NULL) {
        rear->next = new_node;
    }
    rear = new_node;
    if (front == NULL) {
        front = new_node;
    }
    printf("%d enqueued to the queue.\n", data);
}

void dequeue()
{
    if (front == NULL) {
        printf("Queue empty.\n");
    } else {
        Node *temp = front;
        int data = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        free(temp);
        printf("%d dequeued off the queue.\n", data);
    }
}

void display()
{
    printf("\n");
    if (front == NULL) {
        printf("(empty)");
    } else {
        printf("FRONT -> ");
        Node *temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("<- REAR");
    }
    printf("\n");
}
