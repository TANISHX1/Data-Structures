#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_ELEMENT 5

void swap(int* array, int s1, int s2)
    {
    int temp = array[s2];
    array[s2] = array[s1];
    array[s1] = temp;
    }

void array_initialize(int* array)
    {
    for (int i = 0;i < MAX_ELEMENT;i++) {
        array[i] = rand() % 100;
        }
    }

void bubble_sort(int* array)
    {
    for (int pass = 1;pass <= MAX_ELEMENT - 1;pass++) {
        bool flag = 1;
        for (int i = 0;i < MAX_ELEMENT  - pass;i++) {
            if (array[i] > array[i + 1]) {
                swap(array, i, i + 1);
                flag = 0;
                }
            }
        if (flag) {
            break;
            }
        }
    }

void print(int* array)
    {
    for (int i = 0;i < MAX_ELEMENT;i++) {
        printf("%d\t", array[i]);
        }
    puts(" ");
    }

int main()
    {
    int array[MAX_ELEMENT];
    srand(time(NULL));
    array_initialize(array);
    puts("\tInitial Array:");
    print(array);
    bubble_sort(array);
    puts("\n\tArray after sorting:");
    print(array);
    }