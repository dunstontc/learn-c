#include <stdio.h>

/* strlen2: return length of string s */
int strlen2(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    printf("%d\n", n);
    return n;
}

int main() {
    char array[100];
    char *ptr;

    strlen2("hello, world"); /* string constant */
    strlen2(array);          /* char array[100]; */
    strlen2(ptr);            /* char *ptr; */

    return 0;
}
