
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char custom_line_1_str[24];

const char *custom_line_1(void) {
    snprintf(custom_line_1_str, sizeof(custom_line_1_str), "Be Grateful.");

  return custom_line_1_str;
}
