#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *left;
    struct node_struct *right;
} Node;

void bst_free(Node *root);
Node *bst_minimum(Node *root);
Node *bst_insert(Node *root, int data);
Node *bst_remove(Node *root, int data);
int bst_size(Node *root);
void bst_display(Node *root, int depth);

int main()
{
    Node *root = NULL;
    int choice;
    int data;

    printf("Binary Search Tree\n");

    do {
        printf("\n[1 INSERT] [2 REMOVE] [3 SIZE] [0 QUIT]\n");
        printf("Choice > ");
        fflush(stdout);
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Number to insert > ");
            fflush(stdout);
            scanf("%d", &data);
            fflush(stdin);
            root = bst_insert(root, data);
            break;
        case 2:
            printf("Number to remove > ");
            fflush(stdout);
            scanf("%d", &data);
            fflush(stdin);
            root = bst_remove(root, data);
            break;
        case 3:
            printf("Size = %d\n", bst_size(root));
            break;
        default:
            break;
        }

        if (choice) {
            printf("\n");
            if (root == NULL) {
                printf("(empty)\n");
            } else {
                bst_display(root, 0);
            }
        }
    } while (choice);

    bst_free(root);
    return 0;
}

void bst_free(Node *root)
{
    if (root) {
        bst_free(root->left);
        bst_free(root->right);
        free(root);
    }
}

Node *bst_minimum(Node *root)
{
    if (root != NULL && root->left != NULL) {
        return bst_minimum(root->left);
    } else {
        return root;
    }
}

Node *bst_insert(Node *root, int data)
{
    if (root == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else {
        if (data < root->data) {
            root->left = bst_insert(root->left, data);
        } else if (data > root->data) {
            root->right = bst_insert(root->right, data);
        } else {
            printf("%d already exists in the Binary Search Tree.\n", data);
        }
        return root;
    }
}

Node *bst_remove(Node *root, int data)
{
    if (root == NULL) {
        printf("%d does not exist in the Binary Search Tree.\n", data);
        return NULL;
    } else {
        if (data < root->data) {
            root->left = bst_remove(root->left, data);
        } else if (data > root->data) {
            root->right = bst_remove(root->right, data);
        } else {
            Node *prev_root = root;
            if (root->left && root->right) {
                Node *new_root = bst_minimum(root->right);
                root->data = new_root->data;
                root->right = bst_remove(root->right, new_root->data);
            } else {
                if (root->left) {
                    root = root->left;
                } else if (root->right) {
                    root = root->right;
                } else {
                    root = NULL;
                }
                free(prev_root);
            }
        }
        return root;
    }
}

int bst_size(Node *root)
{
    if (root == NULL) {
        return 0;
    } else {
        return 1 + bst_size(root->left) + bst_size(root->right);
    }
}

void bst_display(Node *root, int depth)
{
    if (root != NULL) {
        bst_display(root->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%d\n", root->data);
        bst_display(root->right, depth + 1);
    }
}
