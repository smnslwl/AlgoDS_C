#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 4

int stack[MAXSTACK];
int top = 0;

void push();
void pop();
void display();

int main()
{
    int choice;

    printf("Array-based Stack with MAXSTACK = %d\n", MAXSTACK);

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

    if (top == MAXSTACK) {
        printf("Stack overflow.\n");
        return;
    } else {
        printf("Number to push > ");
        fflush(stdout);
        scanf("%d", &data);
        fflush(stdin);
        top++;
        stack[top - 1] = data;
        printf("%d pushed to the stack.\n", data);
    }
}

void pop()
{
    int data;

    if (top == 0) {
        printf("Stack underflow.\n");
    } else {
        data = stack[top - 1];
        top--;
        printf("%d popped off the stack.\n", data);
    }
}

void display()
{
    int i;

    printf("\n");

    if (top == 0) {
        printf("(empty)");
    } else {
        printf("TOP -> ");
        for (i = top; i > 0; i--) {
            printf("%d ", stack[i - 1]);
        }
    }

    printf("\n");
}
