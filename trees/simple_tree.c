// implementation of binary tree [ tree creation  , transversing( inorder)] 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// data structure of a tree nodes
typedef struct tree_node
    {
    int key;
    int node_id;
    struct tree_node* left_node;
    struct tree_node* right_node;
    } tree_node;

// root node
tree_node* tree_root = NULL;
int node_counter = 0;
bool root_node_creation = true;

// creates new node
tree_node* create_node(int key)
    {
    tree_node* node = (tree_node*)malloc(sizeof(tree_node));
    if (!node) {
        fprintf(stderr, "[ Error ] | Memory_allocation_failed_for_node__");
        return NULL;
        }
    node->key = key;
    node->node_id = ++node_counter;
    node->left_node = NULL;
    node->right_node = NULL;
    return node;
    }

// transverse to left_side  till reaches last node 
tree_node* insert_left_node(tree_node* parent, int key)
    {
    if (parent == NULL)return NULL;
    parent->left_node = create_node(key);
    return parent->left_node;
    }

// trasverse till reaches last right node
tree_node* insert_right_node(tree_node* parent, int key)
    {
    if (parent == NULL) return NULL;
    parent->right_node = create_node(key);
    return parent->right_node;
    }

void create_tree( int n,tree_node* node , int height , int current_height)
    {
    if (current_height >= height) {
        return;
        }
        tree_node* left_node = insert_left_node(node, n * 11);
        tree_node* right_node = insert_right_node(left_node, n * 12);
     n += 1;
     create_tree(n, left_node, height, current_height + 1);
     create_tree(n, right_node, height, current_height + 1);
        
    }

void print_tree(tree_node*pos)
    {
        if (pos == NULL)
        {
            return;
        }
        print_tree(pos->left_node);
        printf("POS [%d] | Value : %d \n", pos->node_id, pos->key);
        print_tree(pos->right_node);
    }

int main()
    {
    tree_root = create_node(0);
    create_tree(10,tree_root,3,0);
    print_tree(tree_root);
    printf("done\n");
    }