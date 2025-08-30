//doublly linked list . insertion at any and delete at any
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#define FG_BRED     "\033[91m"
#define FG_BGREEN   "\033[92m"
#define FG_BYELLOW  "\033[93m"
#define RESET       "\033[0m"

typedef struct node {
    int node_id;
    int key;
    bool valid_insert;
    struct node* next;
    struct node* prev;
    }node;

node* head = NULL;
node* tail = NULL;
int node_counter = 0;

void insert_at_any(int key, bool valid, int position)
    {
    if (position > MAX) {
        puts("[ Error ] position is beyond range");
        return;
        }
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("Mem failed");
        exit(1);
        }
    ptr->node_id = ++node_counter;
    ptr->key = key;
    ptr->valid_insert = true;
    ptr->next = NULL;
    if (!head) {
        ptr->prev = NULL;
        head = ptr;
        tail = ptr;
        }
    else {
        //valid = 1[from forward]  | 0 = [from backward]
        node* pos;
        int i = 1;
        valid ? (pos = head) : (pos = tail);
        if (position == 1) {
            if (valid) {
                ptr->prev = NULL;
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
                return;
                }
            else {
                ptr->prev = pos;
                ptr->next = NULL;
                pos->next = ptr;
                tail = ptr;
                return;
                }
            }
        for (;i < position - 1;i++) {
            valid ? (pos = pos->next) : (pos = pos->prev);
            }
        if (valid) {
            ptr->prev = pos;
            pos->next->prev = ptr;
            (pos->next) ? (ptr->next = pos->next) : (ptr->next = NULL);
            pos->next = ptr;
            }
        else {
            ptr->prev = pos->next;
            ptr->next = pos;
            }
        }
    }

// insert from begin
void initial_list(int key)
    {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("Mem failed");
        exit(1);
        }
    ptr->node_id = ++node_counter;
    ptr->key = key;
    ptr->valid_insert = false;
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
        tail = ptr;
        }
    }


void delete(int del_pos, bool valid)
    {
    // valid = 1,from begning , 0 for end
    if (del_pos > node_counter) {
        puts("Invalid node_delete");
        return;
        }
    node* pos;
    valid ? (pos = head) : (pos = tail);
    node* temp = NULL;
    if (del_pos == 1) {
        if (valid) {
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            return;
            }
        else {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
            return;
            }
        }
    for (int i = 1;i < del_pos - 1;i++) {

        valid ? (pos = pos->next) : (pos = pos->prev);
        }
    if (valid) {
        temp = pos->next;
        pos->next->next != NULL ? (pos->next = pos->next->next, pos->next->prev = pos) : (pos->next = NULL, tail = tail->prev);
        free(temp);
        }
    else {
        temp = pos->prev;
        pos->prev->prev != NULL ? (pos->prev = pos->prev->prev, pos->prev->next = pos) : (head = head->next, pos->prev = NULL);
        free(temp);
        }



    }

void print()
    {
    node* pos = head;
    node* pos_pre = tail;
    puts("\tforward:\n");
    while (pos != NULL) {
        if (!pos->valid_insert) {
            printf("Node [%2d] | Value : %d\n", pos->node_id, pos->key);
            }
        else {
            printf("%sNode [%2d] | Value : %d%s\n", FG_BGREEN, pos->node_id, pos->key, RESET);
            }
        pos = pos->next;
        }
    printf("\n");
    puts("\tBackward:\n");

    while (pos_pre != NULL) {
        if (!pos_pre->valid_insert) {

            printf("Node [%2d] | Value : %d\n", pos_pre->node_id, pos_pre->key);
            }
        else {
            printf("%sNode [%2d] | Value : %d%s\n", FG_BGREEN, pos_pre->node_id, pos_pre->key, RESET);

            }
        pos_pre = pos_pre->prev;
        }
    }

int main()
    {
    bool valid;
    int count = 10;
    for (int i = 0;i < count;i++) {
        initial_list(10 * i);
        }
    
    print();
    insert_at_any(555, 1, 4);
    printf("%s\n\t\tAfter insertation\n%s", FG_BYELLOW, RESET);
    print();

    printf("\n\t\t%sEnter Deletion point  1- forward 0-backward\n\n%s", FG_BYELLOW, RESET);
    scanf("%d", &valid);
    delete(1, valid);
    valid ? puts("\n\tafter Deletion from Beganing\n") : puts("\n\tafter Deletion from End\n");
    print();
    return 0;
    }