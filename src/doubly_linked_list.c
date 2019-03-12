#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *prev;
    struct node_struct *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void destroy();
void insert_front();
void remove_front();
void insert_back();
void remove_back();
void insert_at();
void remove_at();
int size();
void display();

int main()
{
    int choice;

    printf("Doubly Linked List\n");

    do {
        printf("\n[1 INSERT_FRONT] [2 REMOVE_FRONT] [3 INSERT_BACK] [4 REMOVE_BACK] [5 INSERT_AT] [6 REMOVE_AT] [7 SIZE] [0 QUIT]\n");
        printf("Choice > ");
        fflush(stdout);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
        case 0:
            break;
        case 1:
            insert_front();
            break;
        case 2:
            remove_front();
            break;
        case 3:
            insert_back();
            break;
        case 4:
            remove_back();
            break;
        case 5:
            insert_at();
            break;
        case 6:
            remove_at();
            break;
        case 7:
            printf("Size = %d\n", size());
            break;
        default:
            break;
        }

        if (choice) {
            display();
        }
    } while (choice);

    destroy();
    return 0;
}

void destroy()
{
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void insert_front()
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
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
    if (tail == NULL) {
        tail = new_node;
    }
    printf("%d inserted at the front of the list.\n", data);
}

void remove_front()
{
    if (head == NULL) {
        printf("List empty.\n");
    } else {
        Node *temp = head;
        int data = temp->data;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        free(temp);
        printf("%d removed from the front of the list.\n", data);
    }
}

void insert_back()
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
    new_node->prev = tail;
    if (tail != NULL) {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == NULL) {
        head = new_node;
    }
    printf("%d inserted at the back of the list.\n", data);
}

void remove_back()
{
    if (tail == NULL) {
        printf("List empty.\n");
    } else {
        Node *temp = tail;
        int data = temp->data;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        free(temp);
        printf("%d removed from the back of the list.\n", data);
    }
}

void insert_at()
{
    int position;
    printf("Insert at position > ");
    fflush(stdout);
    scanf("%d", &position);
    fflush(stdin);

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

    Node *temp = head;
    Node *previous = NULL;
    int i = 0;
    while (temp != NULL && i < position) {
        previous = temp;
        temp = temp->next;
        i++;
    }

    new_node->prev = previous;
    if (previous == NULL) {
        head = new_node;
    } else {
        previous->next = new_node;
    }

    new_node->next = temp;
    if (temp == NULL) {
        tail = new_node;
    } else {
        temp->prev = new_node;
    }

    printf("%d inserted to the list.\n", data);
}

void remove_at()
{
    if (head == NULL) {
        printf("List empty.\n");
    } else {
        int position;
        printf("Remove at position > ");
        fflush(stdout);
        scanf("%d", &position);
        fflush(stdin);

        Node *temp = head;
        Node *previous = NULL;
        int i = 0;
        while (temp->next != NULL && i < position) {
            previous = temp;
            temp = temp->next;
            i++;
        }

        if (previous == NULL) {
            head = head->next;
        } else {
            previous->next = temp->next;
        }

        if (temp->next == NULL) {
            tail = tail->prev;
        } else {
            temp->next->prev = temp->prev;
        }

        int data = temp->data;
        free(temp);
        printf("%d removed from the list.\n", data);
    }
}

int size()
{
    int n = 0;
    Node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        n++;
    }
    return n;
}

void display()
{
    printf("\n");
    printf("HEAD -> ");
    if (head == NULL) {
        printf("(NULL)");
    } else {
    Node *temp = head;
        while (temp != NULL) {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL) {
                printf(" <-> ");
            }
        }
    }
    printf(" <- TAIL");
    printf("\n");
}
