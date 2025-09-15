#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int queue[MAX];
int front = -1, rear = -1;

void insert(int key)
    {
    if (rear == MAX - 1) {
        puts("[Error]__Queue_overflow__");
        exit(1);
        }
    else if (rear == -1) {
        front = rear = 0;
        queue[rear] = key;
        return;
        }
    else {
        queue[++rear] = key;
        }
    }

void delete()
    {
    if (front < 0) {
        puts("[Error]__Queue_Underflow__");
        exit(1);
        }
    else if (front == rear) {
        queue[rear] = '\0';
        front = rear = -1;
        }
    else {
        queue[front++] = '\0';
        }
    }

int main()
    {
    for (int i = 0;i < MAX;i++) {
        insert((i + 1) * 10);
        }

    // for (int i = 0;i < MAX;i++) {
    //     delete();
    //     }
    for (int i = 0;i < MAX;i++) {
        printf("%d\t", queue[i]);
        }
    }


