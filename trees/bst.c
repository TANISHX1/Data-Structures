// simple binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int node_id;
    struct node* left_node;
    struct node* right_node;
    }node;

// global variables
node* root_ = NULL;
int counter = 0;

struct node* node_create(int data)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        fprintf(stderr, "[ error ] | Mem alloc Failed\n");
        return NULL;
        }
    ptr->key = data;
    ptr->node_id = ++counter;
    ptr->left_node = ptr->right_node = NULL;
    return ptr;
    }


node* insert(node* root, int value)
    {
    if (!root) {
        return node_create(value);
        }
    else {
        if (value < root->key) {
            root->left_node = insert(root->left_node, value);
            }
        else if (value > root->key) {
            root->right_node = insert(root->right_node, value);
            }
        }
    return root;
    }

void print(node* root, int option)
    {
    if (option > 3 || option < 1) {
        puts("[ Error] | print ( enter option for 1-3)");
        return;
        }
    if (!root) {
        return;
        }
    switch (option)
        {
        case 1:
            // for inorder transversing
        {
        print(root->left_node, 1);
        printf("Root[%2d] | Value : %d \n", root->node_id, root->key);
        print(root->right_node, 1);
        }
        break;
        case 2:
            // for postorder transversing 
        {
        printf("Root[%2d] | Value : %d \n", root->node_id, root->key);
        print(root->left_node, 2);
        print(root->right_node, 2);
        break;
        }
        case 3:
            // for preorder transversing
        {
        print(root->left_node, 3);
        print(root->right_node, 3);
        printf("Root[%2d] | Value : %d \n", root->node_id, root->key);
        break;
        }

        default:
            break;
        }

    }
int main()
    {
    root_ = insert(root_, (1) * 10);
    for (int i = 0;i < 10;i++) {
        root_ = insert(root_, (i + 1) * 10);
        }
    print(root_, 1);
    puts("done");
    return 0;
    }