//insert at any point and delete at any point
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FG_BGREEN   "\033[92m"
#define RESET       "\033[0m"

typedef struct node {
    int node_id;
    int key;
    bool inserted;
    struct node* next;
    }node;

node* head = NULL;
int node_counter = 0;

int insert_at_any(int key, int position)
    {
    //doing node_counter +1 ,for the case , when we are inserting the node at end
    if (position > node_counter + 1) {
        puts("inserting pos is greater than max nodes");
        return 1;
        }

    node* node_prev = head;
    node* ptr = (node*)malloc(sizeof(node));
    ptr->node_id = node_counter++;
    ptr->key = key;
    ptr->inserted = true;
    node* pos = head;
    //if list is null
    if (head == NULL) {
        ptr->next = NULL;
        head = ptr;
        return 1;
        }

    //handling the case seperately ,when inserting the node at begin 
    if (position == 1) {
        ptr->next = node_prev;
        head = ptr;
        return 0;
        }

    for (int i = 1;i < position - 1;i++) {
        node_prev = node_prev->next;
        }
    ptr->next = node_prev->next;
    node_prev->next = ptr;
    return 0;
    }

int delete_at_any(int position)
    {
    //if position is more than max
    if (position > node_counter) {
        puts("Deleting the node at position higher then max node");
        return 1;
        }

    node* prev = head;
    node* node_curr = NULL;
    if (!prev) {
        puts("List is Empty");
        return 1;
        }
    //if deleting first node
    if (position == 1) {
        node_curr = prev;
        head = head->next;
        node_curr->next = NULL;
        return 0;
        }
    //to get the prev node of the node that , have to delete
    for (int i = 1;i < position - 1;i++) {
        prev = prev->next;
        }
    node_curr = prev->next;

    //if the node is present b/w the list
    if (node_curr->next != NULL) {
        prev->next = node_curr->next;
        }

    //if the node is present at last
    else {
        prev->next = NULL;
        }
    free(node_curr);
    return 0;
    }

void print()
    {
    node* pos = head;
    while (pos != NULL) {
        if (pos->inserted) {
            printf("%sNode [%2d]  | value: %d %s\n", FG_BGREEN, pos->node_id, pos->key, RESET);
            }
        else {
            printf("Node [%2d]  | value:%d\n", pos->node_id, pos->key);
            }
        pos = pos->next;
        }
    }

void create_list(int key)
    {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->inserted = false;
    ptr->key = key;
    ptr->node_id = node_counter++;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        return;
        }
    node* pos = head;
    while (pos->next != NULL) {
        pos = pos->next;
        }
    pos->next = ptr;
    }

int main()
    {
    int count = 10, new_node_pos = 0, new_node_value = 0, Del_node_pos = 0;
    printf(" list have '%d' nodes [By Defult]\n", count);
    for (int i = 0;i < count;i++) {
        create_list(10 * i);
        }
    print();
    printf("\n");
    printf("Enter the Value & position to enter new node:\t");
    scanf("%d %d", &new_node_value, &new_node_pos);


    //note both insert && delete function returns 0 on success , so, that's why we using bitwise '!' (not)
    if (!insert_at_any(new_node_value, new_node_pos)) {
        print();
        }
    printf("\nEnter position to delete a node :\t");
    scanf("%d", &Del_node_pos);

    if (!delete_at_any(Del_node_pos)) {
        printf("\n\n");
        print();
        }
    }