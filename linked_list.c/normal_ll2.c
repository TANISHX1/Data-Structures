//simple linked list with insert_in_begin and delete_from_begin
#include <stdio.h>
#include <stdlib.h>

struct node {
    int node_id;
    int key;
    struct node* next;
    };

struct node* head = NULL;
int node_number = 0;

void insert_at_begin(int key)
    {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        puts("Memory Allocation Failed!");
        exit(1);
        }
    ptr->node_id = node_number++;
    ptr->key = key;
    ptr->next = head;
    head = ptr;
    }

void delete_from_begin()
    {
    if (head == NULL) {
        puts("List is Empty Nothing to delete");
        return;
        }
    struct node* pos = head;
    head = head->next;
    pos->next = NULL;
    printf("\t\tnode [%d] is deleted\n", pos->node_id);
    free(pos);

    }

void print()
    {
    printf("\n");
    struct node* pos = head;
    while (pos != NULL) {
        printf("Node [%3d]  |  Key : %d\n",pos->node_id, pos->key);
        pos = pos->next;
        }
    printf("\n");
    }
int main()
    {
    for (int i = 0;i < 10;i++) {
        insert_at_begin(i*10 + i);
        }
    print();
    for (int i = 0;i < 3;i++) {
        delete_from_begin();
        }
    print();

    }