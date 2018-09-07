#include "../src/translate.c"
#include "../src/alloc.c"

void set_cfg_manually(struct config *cfg)
{
    cfg->len = 34;
    cfg->data = calloc_and_error_check(cfg->len, sizeof(struct config_data));

    cfg->data[0].mods[0] = 57; // space
    cfg->data[0].mods[1] = 33; // F
    cfg->data[0].trig = 35; // H
    cfg->data[0].out[0] = 125; // meta
    cfg->data[0].out[1] = 35; // H
    cfg->data[0].opt = OPT_RELEASE;

    cfg->data[1].mods[0] = 57; // space
    cfg->data[1].mods[1] = 33; // F
    cfg->data[1].trig = 36; // J
    cfg->data[1].out[0] = 125; // meta
    cfg->data[1].out[1] = 36; // J
    cfg->data[1].opt = OPT_RELEASE;

    cfg->data[2].mods[0] = 57; // space
    cfg->data[2].mods[1] = 33; // F
    cfg->data[2].trig = 37; // K
    cfg->data[2].out[0] = 125; // meta
    cfg->data[2].out[1] = 37; // K
    cfg->data[2].opt = OPT_RELEASE;

    cfg->data[3].mods[0] = 57; // space
    cfg->data[3].mods[1] = 33; // F
    cfg->data[3].trig = 38; // L
    cfg->data[3].out[0] = 125; // meta
    cfg->data[3].out[1] = 38; // L
    cfg->data[3].opt = OPT_RELEASE;

    cfg->data[4].mods[0] = 57; // space
    cfg->data[4].mods[1] = 36; // J
    cfg->data[4].trig = 2; // num1
    cfg->data[4].out[0] = 125; // meta
    cfg->data[4].out[1] = 2; // num1
    cfg->data[4].opt = OPT_RELEASE;

    cfg->data[5].mods[0] = 57; // space
    cfg->data[5].mods[1] = 36; // J
    cfg->data[5].trig = 3; // num2
    cfg->data[5].out[0] = 125; // meta
    cfg->data[5].out[1] = 3; // num2
    cfg->data[5].opt = OPT_RELEASE;

    cfg->data[6].mods[0] = 57; // space
    cfg->data[6].mods[1] = 36; // J
    cfg->data[6].trig = 4; // num3
    cfg->data[6].out[0] = 125; // meta
    cfg->data[6].out[1] = 4; // num3
    cfg->data[6].opt = OPT_RELEASE;

    cfg->data[7].mods[0] = 57; // space
    cfg->data[7].mods[1] = 36; // J
    cfg->data[7].trig = 5; // num4
    cfg->data[7].out[0] = 125; // meta
    cfg->data[7].out[1] = 5; // num4
    cfg->data[7].opt = OPT_RELEASE;

    cfg->data[8].mods[0] = 57; // space
    cfg->data[8].mods[1] = 36; // J
    cfg->data[8].trig = 6; // num5
    cfg->data[8].out[0] = 125; // meta
    cfg->data[8].out[1] = 6; // num5
    cfg->data[8].opt = OPT_RELEASE;

    cfg->data[9].mods[0] = 57; // space
    cfg->data[9].mods[1] = 36; // J
    cfg->data[9].trig = 7; // num6
    cfg->data[9].out[0] = 125; // meta
    cfg->data[9].out[1] = 7; // num6
    cfg->data[9].opt = OPT_RELEASE;

    cfg->data[10].mods[0] = 57; //space
    cfg->data[10].mods[1] = 33; // F
    cfg->data[10].trig = 22; // U
    cfg->data[10].out[0] = 104; // Page-Up
    cfg->data[10].opt = OPT_RELEASE;

    cfg->data[11].mods[0] = 57; //space
    cfg->data[11].mods[1] = 33; // F
    cfg->data[11].trig = 49; // N
    cfg->data[11].out[0] = 109; // Page-Down
    cfg->data[11].opt = OPT_RELEASE;

    cfg->data[12].mods[0] = 57; //space
    cfg->data[12].mods[1] = 33; // F
    cfg->data[12].trig = 21; // Y
    cfg->data[13].out[0] = 29; // control
    cfg->data[12].out[1] = 110; // insert
    cfg->data[12].opt = OPT_RELEASE;

    cfg->data[13].mods[0] = 57; //space
    cfg->data[13].mods[1] = 33; // F
    cfg->data[13].trig = 25; // P
    cfg->data[13].out[0] = 54; // shift
    cfg->data[13].out[1] = 110; // insert
    cfg->data[13].opt = OPT_RELEASE;

    cfg->data[14].mods[0] = 57; //space
    cfg->data[14].mods[1] = 36; // J
    cfg->data[14].trig = 16; // Q
    cfg->data[14].out[0] = 125; // meta
    cfg->data[14].out[1] = 17; // W
    cfg->data[14].opt = OPT_RELEASE;

    cfg->data[15].mods[0] = 57; //space
    cfg->data[15].mods[1] = 24; // Letter O
    cfg->data[15].trig = 20; // T
    cfg->data[15].out[0] = 125; // meta
    cfg->data[15].out[1] = 29; // control
    cfg->data[15].out[2] = 56; // alt
    cfg->data[15].out[3] = 54; // shift
    cfg->data[15].out[4] = 20; // T
    cfg->data[15].opt = OPT_RELEASE;

    cfg->data[16].mods[0] = 57; //space
    cfg->data[16].mods[1] = 24; // Letter O
    cfg->data[16].trig = 18; // E
    cfg->data[16].out[0] = 125; // meta
    cfg->data[16].out[1] = 29; // control
    cfg->data[16].out[2] = 56; // alt
    cfg->data[16].out[3] = 54; // shift
    cfg->data[16].out[4] = 18; // E
    cfg->data[16].opt = OPT_RELEASE;

    cfg->data[17].mods[0] = 57; //space
    cfg->data[17].mods[1] = 24; // Letter O
    cfg->data[17].trig = 33; // F
    cfg->data[17].out[0] = 125; // meta
    cfg->data[17].out[1] = 29; // control
    cfg->data[17].out[2] = 56; // alt
    cfg->data[17].out[3] = 54; // shift
    cfg->data[17].out[4] = 33; // F
    cfg->data[17].opt = OPT_RELEASE;

    cfg->data[18].mods[0] = 57; //space
    cfg->data[18].mods[1] = 24; // Letter O
    cfg->data[18].trig = 19; // R
    cfg->data[18].out[0] = 125; // meta
    cfg->data[18].out[1] = 29; // control
    cfg->data[18].out[2] = 56; // alt
    cfg->data[18].out[3] = 54; // shift
    cfg->data[18].out[4] = 19; // R
    cfg->data[18].opt = OPT_RELEASE;

    cfg->data[19].mods[0] = 57; //space
    cfg->data[19].mods[1] = 24; // Letter O
    cfg->data[19].trig = 48; // B
    cfg->data[19].out[0] = 125; // meta
    cfg->data[19].out[1] = 29; // control
    cfg->data[19].out[2] = 56; // alt
    cfg->data[19].out[3] = 54; // shift
    cfg->data[19].out[4] = 48; // B
    cfg->data[19].opt = OPT_RELEASE;

    cfg->data[20].trig = 58; // capslock
    cfg->data[20].out[0] = 1; // escape
    cfg->data[20].opt = OPT_RELEASE;

    cfg->data[21].mods[0] = 57; // space
    cfg->data[21].mods[1] = 36; // J
    cfg->data[21].mods[2] = 37; // K
    cfg->data[21].trig = 2; // num1
    cfg->data[21].out[0] = 125; // meta
    cfg->data[21].out[1] = 54; // shift
    cfg->data[21].out[2] = 2; // num1
    cfg->data[21].opt = OPT_RELEASE;

    cfg->data[22].mods[0] = 57; // space
    cfg->data[22].mods[1] = 36; // J
    cfg->data[22].mods[2] = 37; // K
    cfg->data[22].trig = 3; // num2
    cfg->data[22].out[0] = 125; // meta
    cfg->data[22].out[1] = 54; // shift
    cfg->data[22].out[2] = 3; // num2
    cfg->data[22].opt = OPT_RELEASE;

    cfg->data[23].mods[0] = 57; // space
    cfg->data[23].mods[1] = 36; // J
    cfg->data[23].mods[2] = 37; // K
    cfg->data[23].trig = 4; // num3
    cfg->data[23].out[0] = 125; // meta
    cfg->data[23].out[1] = 54; // shift
    cfg->data[23].out[2] = 4; // num3
    cfg->data[23].opt = OPT_RELEASE;

    cfg->data[24].mods[0] = 57; // space
    cfg->data[24].mods[1] = 36; // J
    cfg->data[24].mods[2] = 37; // K
    cfg->data[24].trig = 5; // num4
    cfg->data[24].out[0] = 125; // meta
    cfg->data[24].out[1] = 54; // shift
    cfg->data[24].out[2] = 5; // num4
    cfg->data[24].opt = OPT_RELEASE;

    cfg->data[25].mods[0] = 57; // space
    cfg->data[25].mods[1] = 36; // J
    cfg->data[25].mods[2] = 37; // K
    cfg->data[25].trig = 6; // num5
    cfg->data[25].out[0] = 125; // meta
    cfg->data[25].out[1] = 54; // shift
    cfg->data[25].out[2] = 6; // num5
    cfg->data[25].opt = OPT_RELEASE;

    cfg->data[26].mods[0] = 57; // space
    cfg->data[26].mods[1] = 36; // J
    cfg->data[26].mods[2] = 37; // K
    cfg->data[26].trig = 7; // num6
    cfg->data[26].out[0] = 125; // meta
    cfg->data[26].out[1] = 54; // shif21
    cfg->data[26].out[2] = 7; // num6
    cfg->data[26].opt = OPT_RELEASE;

    cfg->data[27].trig = 14; // backspace
    cfg->data[27].out[0] = 14; // backspace
    cfg->data[27].opt = OPT_REPEAT;

    cfg->data[28].trig = 15; // tab
    cfg->data[28].out[0] = 15; // tab
    cfg->data[28].opt = OPT_REPEAT;

    cfg->data[29].trig = 28; // enter
    cfg->data[29].out[0] = 28; // enter
    cfg->data[29].opt = OPT_REPEAT;

    cfg->data[30].trig = 103; // arrow up
    cfg->data[30].out[0] = 103; // arrow up
    cfg->data[30].opt = OPT_REPEAT;

    cfg->data[31].trig = 105; // arrow left
    cfg->data[31].out[0] = 105; // arrow left
    cfg->data[31].opt = OPT_REPEAT;

    cfg->data[32].trig = 106; // arrow right
    cfg->data[32].out[0] = 106; // arrow right
    cfg->data[32].opt = OPT_REPEAT;

    cfg->data[33].trig = 108; // arrow down
    cfg->data[33].out[0] = 108; // arrow down
    cfg->data[33].opt = OPT_REPEAT;
}

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
    fprintf(stdout, "Printing config:\n##########\n");
    for (size_t i = 0; i < cfg->len; i++) {
        fprintf(stdout, "mods: ");
        for (size_t k = 0; k < MAX_MODS; k++) {
            fprintf(stdout, "%d ", cfg->data[i].mods[k]);
        }
        fprintf(stdout, "\ntrig: %d", cfg->data[i].trig);
        fprintf(stdout, "\nout: ");
        for (size_t j = 0; j < MAX_OUT; j++) {
            fprintf(stdout, "%d ", cfg->data[i].out[j]);
        }
        fprintf(stdout, "\nopt: %d", cfg->data[i].opt);
        fprintf(stdout, "\n##########\n");
    }
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
                // print_current(&current);
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
    // print_list(head);
    convert_list_to_array(&head, cfg);
    // print_struct_config(cfg);
}

int main()
{
    struct config cfg = {
        .len = 0,
        .data = NULL
    };
    get_config_data("/etc/keydom/keydom.conf", &cfg);
}
