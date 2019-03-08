#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

void bst_free(struct BSTNode *root);
struct BSTNode *bst_minimum(struct BSTNode *root);
struct BSTNode *bst_insert(struct BSTNode *root, int data);
struct BSTNode *bst_remove(struct BSTNode *root, int data);
void bst_inorder(struct BSTNode *root);
void bst_display(struct BSTNode *root, int depth);

int main()
{
    struct BSTNode *root = NULL;
    int choice;
    int data;

    printf("Binary Search Tree\n");

    do {
        printf("\n[1 INSERT] [2 REMOVE] [0 QUIT]\n");
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

void bst_free(struct BSTNode *root)
{
    if (root) {
        bst_free(root->left);
        bst_free(root->right);
        free(root);
    }
}

struct BSTNode *bst_minimum(struct BSTNode *root)
{
    if (root->left) {
        return bst_minimum(root->left);
    } else {
        return root;
    }
}

struct BSTNode *bst_insert(struct BSTNode *root, int data)
{
    if (root == NULL) {
        struct BSTNode *new_node = malloc(sizeof(struct BSTNode));
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

struct BSTNode *bst_remove(struct BSTNode *root, int data)
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
            struct BSTNode *prev_root = root;
            if (root->left && root->right) {
                struct BSTNode *new_root = bst_minimum(root->right);
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

void bst_inorder(struct BSTNode *root)
{
    if (root) {
        bst_inorder(root->left);
        printf("%d ", root->data);
        bst_inorder(root->right);
    }
}

void bst_display(struct BSTNode *root, int depth)
{
    if (root) {
        bst_display(root->left, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%d\n", root->data);
        bst_display(root->right, depth + 1);
    }
}
