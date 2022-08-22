
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char custom_line_3_str[24];

const char *custom_line_3(void) {
    snprintf(custom_line_3_str, sizeof(custom_line_3_str), "It's Possible.");

  return custom_line_3_str;
}
