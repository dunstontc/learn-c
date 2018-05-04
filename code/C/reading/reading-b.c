// https://www.cs.bu.edu/teaching/c/file-io/intro/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char *mode = "r";
    char *filename[13] = "./hello.txt";


    fp = fopen(filename, mode);

    if (fp == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(1);
    }

    // ofp = fopen(outputFilename, "w");

    return 0;
}

