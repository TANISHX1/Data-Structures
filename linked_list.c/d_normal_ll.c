//doublly linked list . insertion at end and delete from forward && backward
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int node_id;
    int key;
    struct node* next;
    struct node* prev;
    }node;

node* head = NULL;
int node_counter = 0;

void insert_at_bgn(int key)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("Mem failed");
        exit(1);
        }
    ptr->node_id = ++node_counter;
    ptr->key = key;
    ptr->next = NULL;
    if (!head) {
        ptr->prev = NULL;
        head = ptr;
        }
    else {
        node* pos = head;
        while (pos->next != NULL) {
            pos = pos->next;
            }
        ptr->prev = pos;
        pos->next = ptr;
        }
    }
void delete(int to_del , bool valid)
    {
    // valid = 1,from begning , 0 for end
    node* pos = head;
    node* temp = NULL;
    for (int i = 0;i < to_del;i++) {
        if (valid) {
            pos = head;
            head = head->next;
            head->prev = NULL;
            free(pos);
            }
        else {
            pos = head;
            while (pos->next != NULL)
            {
                pos = pos->next;
            }
            pos->prev->next = NULL;
            temp = pos;
            free(temp);
            }
        }
        

    }

void print()
    {
    node* pos = head;
    node* pos_pre = NULL;
    puts("\tforward:\n");
    while (pos != NULL) {
        printf("Node [%2d] | Value : %d\n", pos->node_id, pos->key);
        pos_pre = pos;
        pos = pos->next;
        }
    printf("\n");
    puts("\tBackward:\n");

    while (pos_pre != NULL) {
        printf("Node [%2d] | Value : %d\n", pos_pre->node_id, pos_pre->key);
        pos_pre =pos_pre->prev;
        }
    }

int main()
    {
    bool valid;
    int count = 10;
    for (int i = 0;i < count;i++) {
        insert_at_bgn(10 * i);
        }
    // puts("Done");
    print();
    puts("\n\t\tEnter Deletion point  1- forward 0-backward\n");
    scanf("%d", &valid);
    delete(2, valid);
   valid? puts("\n\tafter Deletion from Beganing\n"):puts("\n\tafter Deletion from Beganing\n");
    print();

    }