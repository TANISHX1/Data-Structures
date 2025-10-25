// Insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

void array_initialize(int* array)
    {
    for (int i = 0;i < MAX_SIZE;i++) {
        array[i] = rand() % 100;
        }
    }

void insertion_sort(int* array)
    {
    for (int pass = 1;pass < MAX_SIZE;++pass) {
        int key = array[pass];
        int i = pass - 1;
        while (i>=0 && array[i]>key)
        {
            array[i + 1] = array[i];
            i--;
            }
        array[i + 1] = key;
        }
    }

void print(int* array)
    {
    for (int i = 0;i < MAX_SIZE;i++) {
        printf("%d \t", array[i]);
        }
    puts(" ");
    }

int main()
    {
    srand(time(NULL));
    int array[MAX_SIZE];
    array_initialize(array);
    puts("Initialized Array :");
    print(array);
    insertion_sort(array);
    puts("\n\tSorted Array [Insertion sort] :\n");
    print(array);
    }