
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND  -10
#define BUFSIZE  35
#define ZERO     0

int   operand_stack[10] = { 0 };
char  operator_stack[10] = { 0 };
int   opt_stack_i = 0;
int   optr_stack_i = 0;

// int comarision
int int_compare(char buf)
    {
    const char digs[] = "0123456789";
    // we are finding buf in digs 
    char* p = strchr(digs, buf);
    // logic : location of char found - base address 
    return p ? (int)(p - digs) : NOT_FOUND;
    }

int operator_compare(char c, int valid)
    {
    const char ops[] = " +-*/";  /* ops[1]='+', ops[2]='-', etc. */
    size_t n = strlen(ops);

    if (valid > 0) {
        if ((size_t)valid < n)
            return ops[valid];
        else
            return NOT_FOUND;
        }

    /* find c in ops[1..n-1] */
    for (int i = 1; i < (int)n; i++) {
        if (c == ops[i])
            return i;
        }
    return NOT_FOUND;
    }

int priority_no(int p_no)
    {
    if (p_no >= 1 && p_no <= 2) { return 1; }
    else if (p_no >= 3 && p_no <= 4) { return 2; }
    return EXIT_FAILURE;
    }

int priority_check( int p_no)
    {
    if (!optr_stack_i) {
        operator_stack[optr_stack_i++] = (char)operator_compare(0, p_no);
        return EXIT_SUCCESS;
        }
    int top_optr_p_ = priority_no(operator_compare(operator_stack[optr_stack_i - 1], ZERO));
    int loading_optr_p_no = priority_no(p_no);

    if (top_optr_p_ >= loading_optr_p_no)
        {
        printf("%c", operator_stack[optr_stack_i-1]);
        operator_stack[optr_stack_i-1] =(char) operator_compare(0,p_no);
        }
    else if (top_optr_p_ < loading_optr_p_no) {
        operator_stack[optr_stack_i++] =(char) operator_compare(0, p_no);
        }

    return EXIT_FAILURE;
    }

int reverse(int num)  /* you had this but never used it… */
    {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
        }
    return rev;
    }

