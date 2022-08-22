
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char custom_line_2_str[24];

const char *custom_line_2(void) {
    snprintf(custom_line_2_str, sizeof(custom_line_2_str), "Work Hard.");

  return custom_line_2_str;
}
