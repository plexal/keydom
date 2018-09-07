#include "../inc/config.h"

FILE * open_file(const char *path)
{
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error");
        exit (EXIT_FAILURE);
    }
    return fp;
}

void close_file(FILE *fp)
{
    if (fclose(fp) != 0) {
        perror("Error");
        exit (EXIT_FAILURE);
    }
}

int read_char(FILE *fp)
{
    int c = fgetc(fp);
    if (ferror(fp) != 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    return c;
}

void print_struct_config(const struct config *cfg)
{
    FILE *logfp = open_writable_file("/tmp/keydom.log");

    fprintf(logfp, "Printing config:\n##########\n");
    for (size_t i = 0; i < cfg->len; i++) {
        fprintf(logfp, "mods: ");
        for (size_t k = 0; k < MAX_MODS; k++) {
            fprintf(logfp, "%d ", cfg->data[i].mods[k]);
        }
        fprintf(logfp, "\ntrig: %d", cfg->data[i].trig);
        fprintf(logfp, "\nout: ");
        for (size_t j = 0; j < MAX_OUT; j++) {
            fprintf(logfp, "%d ", cfg->data[i].out[j]);
        }
        fprintf(logfp, "\nopt: %d", cfg->data[i].opt);
        fprintf(logfp, "\n##########\n");
    }

    close_file(logfp);
}

void print_current(const struct config_data *current)
{
    fprintf(stdout, "mods: ");
    for (size_t i = 0; i < MAX_MODS; i++) {
        fprintf(stdout, "%d ", current->mods[i]);
    }
    fprintf(stdout, "\ntrig: %d\nout: ", current->trig);
    for (size_t i = 0; i < MAX_OUT; i++) {
         fprintf(stdout, "%d ", current->out[i]);
    }
    fprintf(stdout, "\nopt: %d\n##########\n", current->opt);
}

void print_list(struct node *head)
{
    fprintf(stdout, "Printing List:\n##########\n");
    for (struct node *current = head; current != NULL; current = current->next) {
        print_current(&current->data);
    }
}

void reset_current(struct config_data *current)
{
    for (size_t i = 0; i < MAX_MODS; i++) {
        current->mods[i] = 0;
    }
    current->trig = 0;
    for (size_t i = 0; i < MAX_OUT; i++) {
        current->out[i] = 0;
    }
    current->opt = OPT_RELEASE;
}

void read_token(FILE *fp, struct token *tok)
{
    int c;
    size_t i = 0;
    bool comment = false;
    while ((c = read_char(fp)) != EOF) {
        if (comment == true) {
            if (c == '\n') comment = false;
            else continue;
        }
        switch (c) {
            case '#':
                comment = true;
                continue;
            case ':':
                if (i > 0) {
                    tok->string[i] = '\0';
                    tok->delimiter = ':';
                    return;
                }
            case ',':
                if (i > 0) {
                    tok->string[i] = '\0';
                    tok->delimiter = ',';
                    return;
                }
            case ';':
                if (i > 0) {
                    tok->string[i] = '\0';
                    tok->delimiter = ';';
                    return;
                }
            case '}':
                tok->string[i] = '\0';
                tok->delimiter = '}';
                return;
            default :
                if (i < 26 && isalnum(c)) tok->string[i++] = (char) c;
        }
    }
    tok->delimiter = 'X';
}

void set_code(struct config_data *current, __u16 code, int field)
{
    if (code == 0 && field != OPT) return;
    switch (field) {
        case MODS:
            for (size_t i = 0; i < MAX_MODS; i++) {
                if (current->mods[i] == 0) {
                    current->mods[i] = code;
                    return;
                }
            }
        case TRIG:
            current->trig = code;
            return;
        case OUT:
            for (size_t i = 0; i < MAX_OUT; i++) {
                if (current->out[i] == 0) {
                    current->out[i] = code;
                    return;
                }
            }
        case OPT:
            current->opt = code;
            return;
        default :
            return;
    }
}

void push(const struct config_data *current, struct node **head)
{
    struct node *new_node = malloc_and_error_check(sizeof(struct node));
    for (size_t i = 0; i < MAX_MODS; i++) {
        new_node->data.mods[i] = current->mods[i];
    }
    new_node->data.trig = current->trig;
    for (size_t i = 0; i < MAX_OUT; i++) {
        new_node->data.out[i] = current->out[i];
    }
    new_node->data.opt = current->opt;
    new_node->next = *head;
    *head = new_node;
}

void parse_config(const char *path, struct node **head)
{
    FILE *fp = open_file(path);
    struct config_data current = {
        .mods = {0},
        .trig = 0,
        .out = {0},
        .opt = OPT_RELEASE
    };
    int field = NONE;
    __u16 code = 0;
    struct token tok = {
        .string = {'\0'},
        .delimiter = '\0'
    };
    for (tok.delimiter = '\0'; tok.delimiter != 'X'; read_token(fp, &tok)) {
        switch (tok.delimiter) {
            case ':':
                field = translate_field(tok.string);
                continue;
            case ',':
                code = translate_code(tok.string);
                set_code(&current, code, field);
                continue;
            case ';':
                if (field == OPT) code = translate_option(tok.string);
                else code = translate_code(tok.string);
                set_code(&current, code, field);
                continue;
            case '}':
                push(&current, head);
                reset_current(&current);
                continue;
            default :
                continue;;
        }
    }
    close_file(fp);
}

int count_nodes(struct node *head)
{
    int count = 0;
    for (struct node *current = head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

void pop(struct node **head, struct config_data *current)
{
    if (*head == NULL) {
        fprintf(stderr, "Underflow. Aborting.\n");;
        exit(EXIT_FAILURE);
    }
    struct node *next_node = (*head)->next;
    for (size_t i = 0; i < MAX_MODS; i++) {
        current->mods[i] = (*head)->data.mods[i];
    }
    current->trig = (*head)->data.trig;
    for (size_t i = 0; i < MAX_OUT; i++) {
        current->out[i] = (*head)->data.out[i];
    }
    current->opt = (*head)->data.opt;
    free(*head);
    *head = next_node;
}

void convert_list_to_array(struct node **head, struct config *cfg)
{
    struct config_data current;
    cfg->len = count_nodes(*head);
    cfg->data = malloc_and_error_check(sizeof(struct config_data) * cfg->len);
    for (size_t i = 0; i < cfg->len; i++) {
        pop(head, &current);
        for (size_t j = 0; j < MAX_MODS; j++) {
            cfg->data[i].mods[j] = current.mods[j];
        }
        cfg->data[i].trig = current.trig;
        for (size_t j = 0; j < MAX_OUT; j++) {
            cfg->data[i].out[j] = current.out[j];
        }
        cfg->data[i].opt = current.opt;
    }
}

void get_config_data(const char *path, struct config *cfg)
{
    struct node *head = NULL;
    parse_config(path, &head);
    convert_list_to_array(&head, cfg);
    // print_struct_config(cfg);
}
