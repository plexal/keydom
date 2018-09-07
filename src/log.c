#include "../inc/main.h"

void close_file(FILE *fp);

FILE * open_writable_file(const char *path)
{
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Error");
        exit (EXIT_FAILURE);
    }
    return fp;
}

void output_log(const int integer, const char *string)
{
    FILE *fp = open_writable_file("/tmp/keydom.log");

    fprintf(fp, "%d\t%s\n", integer, string);

    close_file(fp);
}
