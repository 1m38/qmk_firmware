#include <stdio.h>

uint32_t type_count = 0;
char count_str[24] = {};

void count_up(void)
{
  type_count++;
  snprintf(count_str, sizeof(count_str), "Type count: %ld", type_count);
}

const char *read_count(void)
{
  return count_str;
}