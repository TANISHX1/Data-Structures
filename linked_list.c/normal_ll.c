//simple linked list 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* next;
    };

int main()
    {
    struct node* head = NULL;
    for (int i = 0;i < 10;i++) {
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->key = i * 10;
        ptr->next = head;
        head = ptr;
        }
    struct node* pos = head;
    struct node* temp = NULL;
    while (pos != NULL) {
        printf("NODE VALUE: %d\n", pos->key);
        temp = pos;
        pos = pos->next;
        free(temp);
        }
    puts("Main:Complete");
    return 0;
    }