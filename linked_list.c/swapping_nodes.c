#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int node_id;
    int value;
    struct node* next;
    }node;

node* head = NULL;
int count_node = 0;

void insert_node(int value)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("Mem Failed\n");
        return;
        }
    ptr->node_id = ++count_node;
    ptr->value = value;
    ptr->next = head;
    head = ptr;
    }

void print()
    {
    node* pos = head;
    while (pos != NULL) {
        printf("Node [%2d] | Value : %d\n", pos->node_id, pos->value);
        pos = pos->next;
        }
    }

//function to change node_with _id_1 with node_with_id_2
void change_node(int node_id_1, int node_id_2)
    {
    if (head == NULL) {
        puts("List is empty");
        return;
        }
    node* node_1_prev = NULL, * node_1_curr = head;
    node* node_2_prev = NULL, * node_2_curr = head, * temp = NULL;

    //for node 1
    while (node_1_curr != NULL && node_1_curr->node_id != node_id_1) {
        node_1_prev = node_1_curr;
        node_1_curr = node_1_curr->next;
        }

    //for node 2
    while (node_2_curr != NULL && node_2_curr->node_id != node_id_2) {
        node_2_prev = node_2_curr;
        node_2_curr = node_2_curr->next;
        }

    if (!node_1_curr || !node_2_curr) {
        puts("Node not found");
        return;
        }
    temp = node_1_curr->next;
    node_1_curr->next = node_2_curr->next;
    node_2_curr->next = temp;
    if (node_1_prev) {
        node_1_prev->next = node_2_curr;
        }
    else
        {
        head = node_2_curr;
        }
    if (node_2_prev) {
        node_2_prev->next = node_1_curr;
        }
    else
        {
        head = node_1_curr;
        }



    }

int main()
    {
    // works fine for changing any node within the list except neighabour nodes .
    int count = 10;
    for (int i = 0;i < count;i++) {
        insert_node(i * 10 + i);
        }
    print();
    puts(" ");
    change_node(1, 10);
    print();

    }