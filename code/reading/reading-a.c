#include <stdio.h>
#include <stdlib.h>

int main()
{
    // This is a waste of memory. Just messing around with strings.
    char mode[1] = "r";
    char filename[12] = "./hello.txt";

    // For files you want to read or write, you need a file pointer
    FILE *fp;

    fp = fopen(filename, mode);

    return 0;
}
