//simple linked list with insert_at_end and delete_at_end
#include <stdlib.h>
#include <stdio.h>

struct node {
    int node_id;
    int key;
    struct node* next;
    };

struct node* head = NULL;
int node_number = 0;

void insert_at_end(int key)
    {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (!ptr) {
        puts("Failed Memory Allocation ");
        return;
        }
    ptr->key = key;
    ptr->node_id = node_number++;
    ptr->next = NULL;
    if (head == NULL)
        {
        ptr->next = head;
        head = ptr;
        return;
        }
    struct node* pos = head;
    while (pos->next != NULL) {
        pos = pos->next;
        }
    pos->next = ptr;
    }

void delete_at_end()
    {
    //when list is empty
    if (head == NULL) {
        puts("List is Empty , Nothing to delete");
        }
    struct node* pos_current = head;
    struct node* pos_prev = NULL;
    while (pos_current->next != NULL) {
        pos_prev = pos_current;
        pos_current = pos_current->next;
        }
    pos_prev->next = NULL;
    printf("\t\tNode [%2d] deleted successfully\n", pos_current->node_id);
    free(pos_current);

    }

void print()
    {
    printf("\n");
    struct node* pos = head;
    while (pos != NULL) {
        printf("Node [%2d]  |  Key : %d\n", pos->node_id, pos->key);
        pos = pos->next;
        }
    printf("\n");
    }

int main()
    {
    int nodes_to_create;
    printf("Enter number of max nodes :\t");
    scanf("%d", &nodes_to_create);
    for (int i = 0;i < nodes_to_create;i++) {
        insert_at_end(i * 10 + i);
        }
    print();
    for (int i = 0;i < nodes_to_create%5;i++) {
        delete_at_end();
        }
    print();
    return 0;
    }