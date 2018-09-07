#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <stdbool.h>

#define MAX_MODS 5
#define MAX_OUT (5+1)*2

enum {
    RELEASE = 0,
    PRESS = 1,
    REPEAT = 2
};

enum {
    OPT_RELEASE = 0,
    OPT_SINGLE = 1,
    OPT_REPEAT = 2
};

struct config_data {
    __u16 mods[MAX_MODS];
    __u16 trig;
    __u16 out[MAX_OUT];
    int opt;
};

struct config {
    int len;
    struct config_data *data;
};

struct buffer {
    __u16 code;
    bool used;
};

void get_config_data(const char *path, struct config *cfg);

void process(struct input_event *event, struct buffer buf[MAX_MODS],
              struct buffer *prev, const struct config *cfg);

void *malloc_and_error_check(const size_t size);
void *calloc_and_error_check(const size_t nitems, const size_t size);

FILE * open_writable_file(const char *path);
void output_log(const int integer, const char *string);
