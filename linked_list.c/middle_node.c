// printd the mibble node of the list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
    {
    int node_id;
    int key;
    struct node* next;
    }node;
node* head = NULL;
int node_counter = 0;

void insert_node(int key)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("Mem failed");
        return;
        }
    ptr->node_id = ++node_counter;
    ptr->key = key;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        }
    else {
        node* pos = head;
        while (pos->next != NULL) {
            pos = pos->next;
            }
        pos->next = ptr;
        }
    }
int main()
    {
    int count = 0;
    printf("Enter Max nodes:\t");
    scanf("%d", &count);
    for (int i = 0;i < count;i++) {
        insert_node(10 * i);
        }
    int node_print = 0;
    node_counter % 2 ? (node_print = (node_counter + 1) / 2) : (node_print = node_counter / 2);
    node* pos = head;
    while (pos != NULL) {
        if (pos->node_id == node_print) {
            break;
            }
        pos = pos->next;
        }
    printf("Middle node is Node[%2d]  | Value of node %d\n", pos->node_id, pos->key);
    return 0;
    }
