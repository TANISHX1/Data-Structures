#include "header.h"

void infix_to_postfix(char *buf)
{

    int   len = (int)strlen(buf);
    char c;
    for (int i = 0; i < len; i++) {
         c = buf[i];

        //  skip spaces  & \n
        if (c == ' ' || c == '\n')
            continue;

        // digit
        int a = int_compare(c);
        if (a > NOT_FOUND) {
            if (opt_stack_i < 10)
                operand_stack[opt_stack_i++] = a;
            printf("%d",operand_stack[opt_stack_i-1]);
            continue;
        }

        /* is it an operator? */
        int b = operator_compare(c, ZERO);
        if (b > NOT_FOUND) {
            if (optr_stack_i < 10)
                priority_check(b);
            }
    }

    // prints operators lefts at end
    for (; optr_stack_i>=0; ) {
        printf("%c", operator_stack[optr_stack_i--]);
    }
    printf("\n");
}

int main(void)
{
    char *input = calloc(BUFSIZE, 1);
    if (!input) {
        perror("calloc");
        return 1;
    }

    if (!fgets(input, BUFSIZE, stdin)) {
        perror("fgets");
        free(input);
        return 1;
    }

    infix_to_postfix(input);
    free(input);
    return 0;
}