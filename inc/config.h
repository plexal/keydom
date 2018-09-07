#include "./main.h"
#include <string.h>
#include <ctype.h>

enum {
    NONE = 0,
    MODS,
    TRIG,
    OUT,
    OPT
};

struct node {
    struct config_data data;
    struct node *next;
};

struct token {
    char string[26];
    char delimiter;
};

int translate_field(const char string[26]);
int translate_option(const char string[26]);
__u16 translate_code(const char string[26]);
