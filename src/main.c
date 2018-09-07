#include "../inc/main.h"

int read_event(struct input_event *event)
{
    return fread(event, sizeof(struct input_event), 1, stdin) == 1;
}

void write_event(const struct input_event *event)
{
    if (fwrite(event, sizeof(struct input_event), 1, stdout) != 1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    struct input_event event;

    struct buffer buf[MAX_MODS] = {0};
    struct buffer prev = {
        .code = 0,
        .used = false
    };
    struct config cfg = {
        .len = 0,
        .data = NULL
    };
    get_config_data("/etc/keydom/keydom.conf", &cfg);

    // Each I/O operation should be performed as soon as possible.
    setvbuf(stdin, NULL, _IONBF, BUFSIZ);
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    while (read_event(&event)) {
        if (event.type != EV_KEY) write_event(&event);
        else process(&event, buf, &prev, &cfg);
    }
    free(cfg.data);
}
