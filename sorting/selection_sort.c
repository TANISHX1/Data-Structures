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

void swap(int* array, int idx_1, int idx_2)
    {
    int temp = array[idx_2];
    array[idx_2] = array[idx_1];
    array[idx_1] = temp;
    }

void selection_sort(int* array)
    {
    int minvalue_idx;
    for (int i = 0;i < MAX_SIZE;i++) {
        minvalue_idx = i;
        for (int j = i + 1;j < MAX_SIZE;j++) {
            if (array[j] < array[minvalue_idx]) {
                minvalue_idx = j;
                }
            }
        swap(array, minvalue_idx, i);
        }
    }

void print(int* array)
    {
    for (int i = 0;i < MAX_SIZE;i++) {
        printf("%d\t", array[i]);
        }
    puts("");
    }

int main()
    {
    srand(time(NULL)); 
    int array[MAX_SIZE];
    array_initialize(array);
    puts("\tInitialized Array:");
    print(array);
    selection_sort(array);
    puts("\n\tSorted Array [Selection sort]:");
    print(array);
    }