#include <stdio.h>

/**
 * Each variable type can only hold so much.
 * In C when you declare a variable, you're saying
 * "this is how much space I want to allocate and how I want it stored within the stack".
 * The short will overflow its available value, go negative, and continue the cycle.
 * It will never be as big as a long long.
 */
int main(void)
{
    short a = 0;
    long long b = 999999999999;

    while(a < b)
    {
        printf("%d\n", a);
        ++a;
    }

    return 0;
}
