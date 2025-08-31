
//AP == arithmetic operation 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define BOLD        "\033[1m"
#define RESET       "\033[0m"
#define ITALIC      "\033[3m"
#define FG_BLACK    "\033[30m"
#define FG_RED      "\033[31m"
#define FG_GREEN    "\033[32m"
#define FG_YELLOW   "\033[33m"
#define FG_BLUE     "\033[34m"
#define FG_MAGENTA  "\033[35m"
#define FG_CYAN     "\033[36m"
#define FG_WHITE    "\033[37m"

int main()
    {
    int count = 20;
    srand(time(NULL));
    unsigned int  array[count];

    //assigning values to the array elements
    for (int i = 0;i < count;i++) {
        array[i] = rand() % (int)4e5;
        }
    unsigned int* ptr = array;
    //AP-1 ptr increment
    printf("%sAP-1%s\n\n", BOLD, RESET);
    for (int i = 0;i < count;i++)
        {
        printf("%s%-15p  %s", FG_CYAN, ptr++ ,RESET);
        }
    unsigned int* last_element = ptr;
    printf("\n\n");
    
    //ptr to array
    ptr = array;

    //AP-2 ptr addition
    printf("%sAP-2%s\n\n", BOLD, RESET);

    for (int i = 0;i < count;i++) {
        printf("%s%-15p %s ",FG_CYAN, ptr + i , RESET);
        }
    printf("\n\n");

    //AP-3 ptr subtraction
    printf("%sAP-3%s\n", BOLD, RESET);

    printf("\nArray size : %d\n\n", last_element - ptr);

    //AP-4 ptr compression 
    printf("%sAP-4%s\n\n", BOLD, RESET);

    short int random = rand() % count;
    unsigned int* random_find = &array[random];
    for (int i = 0;i < count; i++) {
        if (ptr + i == random_find) {
            printf("%s Element found [%p]  | value is %d %s \n\n", FG_MAGENTA, random_find, *(ptr + i), RESET);
            break;
            }
        }

    //AP-5.1 less than or greater than
    printf("%sAP-5.1%s\n", BOLD, RESET);

    for (int i = 0;i < count; i++) {
        if (ptr + i > random_find) {
            printf("%sElements has address greater [%p]  |  Element address : %p  |  Element value :%d %s\n", FG_GREEN, random_find, ptr + i, *(ptr + i), RESET);
            }
        }
    // sleep(1);
    printf("\nEnd\n");

    }