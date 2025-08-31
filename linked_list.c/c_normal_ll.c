// simple circular linked list using recursion 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct node {
    int node_id;
    int key;
    struct node* next;
    }node;

int node_counter = 0;
node* head = NULL;
node* tail_point = NULL;

void new_node(int key, int max_nodes)
    {
    if (max_nodes == 0) {
        tail_point->next = head;
        return;
        }
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        puts("[Error] | Mem allocation failed");
        return;
        }
    if (head == NULL) {
        tail_point = ptr;
        }
    ptr->key = key;
    ptr->node_id = ++node_counter;
    ptr->next = head;
    head = ptr;
    new_node(rand() / 2e5, max_nodes - 1);
    }

void print()
    {
    node* pos = head;
    if (pos != NULL) {
        printf("Node[%2d] | Value :%d\n", pos->node_id, pos->key);
        pos = pos->next;
        }
    while (pos != tail_point->next)
        {
        printf("Node[%2d] | Value :%d\n", pos->node_id, pos->key);
        pos = pos->next;
        }


    }
int main()
    {
    // working of exection time ,is not a part of data structure.
    struct timeval start, end;
    gettimeofday(&start, NULL);

    new_node(10, 10);

    print();
    gettimeofday(&end, NULL);
    long exe_time = (end.tv_sec - start.tv_sec) * 1e6;
    exe_time += (end.tv_usec - start.tv_usec);
    printf("\nTotal Execution time : [ %3d us ] \n", exe_time);
    return 0;
    }