#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int queue[MAX];
int front = -1, rear = -1;

void insert(int key)
    {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        puts("[Error]_Queue_Overflow__");
        exit(1);
        }
    else if ((rear == -1) || (front == -1)) {
        rear = front = 0;
        queue[rear] = key;
        }
    else if (rear == MAX - 1) {
        rear = 0;
        }
    else {
        queue[++rear] = key;
        }
    }

void delete()
    {
    if (front < 0) {
        puts("[Error]_Queue_Underflow__");
        exit(1);
        }
    else if (front == rear) {
        queue[front] = '\0';
        front = rear = -1;
        }
    else if (front == MAX - 1) {
        queue[front] = '\0';
        front = 0;
        }
    else {
        queue[front++] = '\0';
        }
    }

int main()
    {
    for (int i = 0;i < MAX ;i++) {
        insert((i + 1) * 10);
        }
    // printf("Front [%d] | Rear [%d]\n", front, rear);
        delete();
        delete();
    // printf("Front [%d] | Rear [%d]\n", front, rear);
    for (int i = 0;i < MAX;i++) {
        printf("%d\t", queue[i]);
        }
    }