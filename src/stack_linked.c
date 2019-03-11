#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *next;
} Node;

Node *top = NULL;

void push();
void pop();
void display();

int main()
{
    int choice;

    printf("Linked Stack\n");

    do {
        printf("\n[1 PUSH] [2 POP] [0 QUIT]\n");
        printf("Choice > ");
        fflush(stdout);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
        case 0:
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
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

void push()
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
    new_node->next = top;
    top = new_node;
    printf("%d pushed to the stack.\n", data);
}

void pop()
{
    if (top == NULL) {
        printf("List empty.\n");
    } else {
        Node *temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        printf("%d popped off the stack.\n", data);
    }
}

void display()
{
    printf("\n");
    if (top == NULL) {
        printf("(empty)");
    } else {
        printf("TOP -> ");
        Node *temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
