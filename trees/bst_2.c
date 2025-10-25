// binary search tree insertion and deletion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
    {
    int node_id;
    int value;
    struct node* left;
    struct node* right;
    }node;

node* head = NULL;
int count = 0;

node* create_node(int value)
    {
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) {
        perror("Mem allocation Failed");
        exit(1);
        }
    new_node->node_id = ++count;
    new_node->value = value;
    new_node->left = new_node->right = NULL;

    return new_node;
    }
node* insert(node* root, int value)
    {
    if (!root) {
        return create_node(value);
        }
    else if (root->value > value) {
        root->left = insert(root->left, value);
        }
    else if (root->value < value) {
        root->right = insert(root->right, value);
        }
    return root;
    }

node* find(node* root)
    {
    node* l_node = root;
    while (l_node->left != NULL) {
        l_node = l_node->left;
        }
    return l_node;
    }

node* delete_node(node* root, int value)
    {
    if (!root) {
        return root;
        }
    if (value < root->value) {
        root->left = delete_node(root->left, value);
        }
    else if (value > root->value) {
        root->right = delete_node(root->right, value);
        }
    else {
        //  case 1: no child , 1 child
        node* temp = NULL;
        if (!root->left) {
            temp = root->right;
        }
        else if (!root->right) {
            temp =root->left;
            }
        if (temp) {
            free(root);
            return temp;
            }

        else {
            node* successsor = find(root->right);
            root->value = successsor->value;
            root->right = delete_node(root->right, successsor->value);
            }
        }
    return root;
    }


void print(node* root)
    {
    if (!root) {
        return;
        }
    print(root->left);
    printf("Node [%d] | value : %d\n", root->node_id, root->value);
    print(root->right);

    }

int main()
    {
    srand(time(NULL));
    for (int i = 0;i < 5;i++) {
        head = insert(head, (i + 1) * 10);
        }
    print(head);
    delete_node(head, 20);
    puts("---------------------------------------------------------------");
    print(head);
    }