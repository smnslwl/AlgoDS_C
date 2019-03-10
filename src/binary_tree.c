#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    const char *data;
    struct node_struct *left;
    struct node_struct *right;
} Node;

Node *create(const char *data);
void destroy(Node *root);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void display(Node *root, int depth);

int main()
{
    Node *root = create("A");
    root->left = create("B");
    root->right = create("C");
    root->left->left = create("D");
    root->left->right = create("E");
    root->right->left = create("F");
    root->right->right = create("G");

    printf("Binary Tree\n\n");

    display(root, 0);
    printf("\n");

    printf("Pre order:  ");
    preorder(root);
    printf("\n");

    printf("In order:   ");
    inorder(root);
    printf("\n");

    printf("Post order: ");
    postorder(root);
    printf("\n");

    destroy(root);
    return 0;
}

Node *create(const char *data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void destroy(Node *root)
{
    if (root) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void preorder(Node *root)
{
    if (root) {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root) {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->data);
    }
}

void display(Node *root, int depth)
{
    if (root) {
        display(root->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%s\n", root->data);
        display(root->right, depth + 1);
    }
}
