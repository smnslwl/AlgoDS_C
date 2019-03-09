#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    const char *data;
    struct node_struct *left;
    struct node_struct *right;
} Node;

Node *binary_tree_create(const char *data);
void binary_tree_free(Node *root);
void binary_tree_preorder(Node *root);
void binary_tree_inorder(Node *root);
void binary_tree_postorder(Node *root);
void binary_tree_display(Node *root, int depth);

int main()
{
    Node *root = binary_tree_create("A");
    root->left = binary_tree_create("B");
    root->right = binary_tree_create("C");
    root->left->left = binary_tree_create("D");
    root->left->right = binary_tree_create("E");
    root->right->left = binary_tree_create("F");
    root->right->right = binary_tree_create("G");

    printf("Binary Tree\n\n");

    binary_tree_display(root, 0);
    printf("\n");

    printf("Pre order:  ");
    binary_tree_preorder(root);
    printf("\n");

    printf("In order:   ");
    binary_tree_inorder(root);
    printf("\n");

    printf("Post order: ");
    binary_tree_postorder(root);
    printf("\n");

    binary_tree_free(root);
    return 0;
}

Node *binary_tree_create(const char *data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void binary_tree_free(Node *root)
{
    if (root) {
        binary_tree_free(root->left);
        binary_tree_free(root->right);
        free(root);
    }
}

void binary_tree_preorder(Node *root)
{
    if (root) {
        printf("%s ", root->data);
        binary_tree_preorder(root->left);
        binary_tree_preorder(root->right);
    }
}

void binary_tree_inorder(Node *root)
{
    if (root) {
        binary_tree_inorder(root->left);
        printf("%s ", root->data);
        binary_tree_inorder(root->right);
    }
}

void binary_tree_postorder(Node *root)
{
    if (root) {
        binary_tree_postorder(root->left);
        binary_tree_postorder(root->right);
        printf("%s ", root->data);
    }
}

void binary_tree_display(Node *root, int depth)
{
    if (root) {
        binary_tree_display(root->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%s\n", root->data);
        binary_tree_display(root->right, depth + 1);
    }
}
