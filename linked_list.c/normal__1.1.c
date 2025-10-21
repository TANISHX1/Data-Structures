// simple linked list using recursion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node {
    char* name;
    int node_id;
    struct node* next;
    }node;

int counter_node = 0;
node* head = NULL;

node* createnode(char* name)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("mem allocation failed");
        exit(1);
        }
    ptr->name = strdup(name);
    ptr->node_id = ++counter_node;
    ptr->next = NULL;
    return ptr;
    }

node* insert(node* ptr, char* name)
    {
    if (!ptr) {
        ptr = createnode(name);
        return ptr;
        }
    else {
        ptr->next = insert(ptr->next, name);
        return ptr;
        }
    }

void free_node(node* node__)
    {
    free(node__->name);
    free(node__);
    }

void print_ll(int free_node_)
    {
    node* ptr = head;
    if (!ptr) {
        puts("List is Empty");
        exit(1);
        }
    while (ptr->next != NULL) {
        printf("Node[%3d] | %s\n", ptr->node_id, ptr->name);
        if (free_node_) {
            free_node(ptr);
            }
        ptr = ptr->next;
        }
    }

int main()
    {
    int max_nodes;
    printf("Enter Max_nodes:\t");
    scanf("%d", &max_nodes);
    // head = insert(NULL, "Tanish");
    for (int i = 0;i < max_nodes;i++) {
        head = insert(head, "yash");
        }
    print_ll(0);
    return 0;
    }