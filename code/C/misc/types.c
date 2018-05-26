#include <stdio.h>

void print_types(void)
{
    printf("size of integer : %zu \n",   sizeof(int));
    printf("Size of double : %zu \n",    sizeof(double));
    printf("size of short : %zu \n",     sizeof(short));
    printf("Size of long : %zu \n",      sizeof(long));
    printf("size of long long : %zu \n", sizeof(long long));
}

int main(void)
{
    print_types();
    return 0;
}