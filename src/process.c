#include "../inc/process.h"

bool is_advanced_key(const __u16 code)
{
    switch (code) {
        case 0: return true;
        // case 14: return true; // backspace
        // case 15: return true; // tab
        // case 28: return true; // enter
        case 29: return true;
        case 42: return true;
        case 54: return true;
        case 56: return true;
        case 97: return true;
        case 100: return true;
        case 125: return true;
        case 126: return true;
        default :
            if (code < 255) return false;
            return true;
    }
}

void cache(const __u16 code, struct buffer buf[MAX_MODS])
{
    for (int i = 0; i < MAX_MODS; i++) {
        if (buf[i].code == 0) {
            buf[i].code = code;
            buf[i].used = false;
            return;
        }
    }
}

bool clear(const __u16 code, struct buffer buf[MAX_MODS])
{
    for (int i = 0; i < MAX_MODS; i++) {
        if (buf[i].code == code) {
            buf[i].code = 0;
            return buf[i].used;
        }
    }
    return true;
}

bool do_mods_match_buf(const __u16 mods[MAX_MODS],
                          const struct buffer buf[MAX_MODS])
{
    int mul1 = 1, mul2 = 1, sum1 = 0, sum2 = 0;
    for (int i = 0; i < MAX_MODS; i++) {
        mul1 *= mods[i];
        sum1 += mods[i];
        mul2 *= buf[i].code;
        sum2 += buf[i].code;
    }
    if (mul1 == mul2 && sum1 == sum2) return true;
    return false;
}

bool does_value_match_opt(const int opt, const __s32 value)
{
    switch (value) {
        case PRESS:
            if (opt == OPT_SINGLE || opt == OPT_REPEAT) return true;
            return false;
        case REPEAT:
            if (opt == OPT_REPEAT) return true;
            return false;
        case RELEASE:
            if (opt == OPT_RELEASE) return true;
            return false;
        default :
            return false;
    }
}

int check_for_remap_match(const struct input_event *event,
                          const struct buffer buf[MAX_MODS], const  struct buffer *prev,
                          const struct config *cfg)
{
    for (int i = 0; i < cfg->len; i++) {
        if (do_mods_match_buf(cfg->data[i].mods, buf) == true
            && does_value_match_opt(cfg->data[i].opt, event->value) == true
            && prev->code == cfg->data[i].trig
            && prev->code == event->code) return i;
    }
    return -1;
}

void write_remap_output(const __u16 out[MAX_OUT])
{
    struct input_event event;
    event.type = EV_KEY;
    event.value = PRESS;
    for (int i = 0; i < MAX_OUT; i++) {
        if (out[i] != 0) {
            event.code = out[i];
            write_event(&event);
        }
    }
    event.value = RELEASE;
    for (int i = (MAX_OUT-1); i >= 0 ; i--) {
        if (out[i] != 0) {
            event.code = out[i];
            write_event(&event);
        }
    }
}

bool is_buf_empty(const struct buffer buf[MAX_MODS])
{
    for (int i = 0; i < MAX_MODS; i++) {
        if (buf[i].code != 0) return false;
    }
    return true;
}

void write_prev(const struct buffer *prev)
{
    if (prev->used == true) return;
    struct input_event event;
    event.type = EV_KEY;
    event.code = prev->code;
    event.value = PRESS;
    write_event(&event);
    event.value = RELEASE;
    write_event(&event);
}

void write_released(struct input_event *event)
{
    event->value = PRESS;
    write_event(event);
    event->value = RELEASE;
    write_event(event);
}

void set_used(struct buffer buf[MAX_MODS])
{
    for (int i = 0; i < MAX_MODS; i++) {
        buf[i].used = true;
    }
}

void process(struct input_event *event, struct buffer buf[MAX_MODS],
              struct buffer *prev, const struct config *cfg)
{
    if (is_advanced_key(event->code) == true) {
        write_event(event);
        return;
    }

    int index = -1;
    bool used;
    switch (event->value) {
        case PRESS:
            prev->code = event->code;
            prev->used = false;
            index = check_for_remap_match(event, buf, prev, cfg);
            if (index != -1) {
                write_remap_output(cfg->data[index].out);
                set_used(buf);
                prev->used = true;
            } else cache(event->code, buf);
            return;
        case REPEAT:
            if (prev->used == false) return;
            index = check_for_remap_match(event, buf, prev, cfg);
            if (index != -1) {
                write_remap_output(cfg->data[index].out);
                set_used(buf);
            }
            return;
        case RELEASE:
            used = clear(event->code, buf);
            index = check_for_remap_match(event, buf, prev, cfg);
            if (index != -1) {
                write_remap_output(cfg->data[index].out);
                set_used(buf);
            } else if (used == false) write_released(event);
            return;
        default :
            return;
    }
}
