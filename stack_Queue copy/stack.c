#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

int stack[MAX_STACK];
int stack_ptr = -1;

void push(int key)
    {
    if (stack_ptr == MAX_STACK ) {
        puts("[Error] | Stackover flow");
        exit(1);
        }
    stack[++stack_ptr] = key;
    }
void pop()
    {
    if (stack_ptr < 0) {
        puts("[Error] | Stackunder Flow");
        exit(1);
        }
    stack[stack_ptr--] = '\0';
    }

int main()
    {
    for (int i = 0;i < MAX_STACK;i++) {
        push((i + 1) * 8);
        }
    for (int i = 0;i <= stack_ptr;i++) {
        printf("Stack[%d] | value : %d\n", stack_ptr - i, stack[stack_ptr - i]);
        }
    for (int i = 0;i < 5;i++) {

        pop();
        }
    printf("\n\n");
    for (int i = 0;i <= stack_ptr;i++) {
        printf("Stack[%d] | value : %d\n", stack_ptr - i, stack[stack_ptr - i]);
        }
    }