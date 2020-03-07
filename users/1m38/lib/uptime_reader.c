#include <stdio.h>

uint32_t timer_read32(void);

char uptime_str[24] = {};

void set_uptime(void)
{
  const uint32_t uptime_ms = timer_read32();
  const uint32_t uptime_s = uptime_ms / 1000;
  const unsigned int seconds = uptime_s % 60;
  const unsigned int mins = (uptime_s / 60) % 60;
  const unsigned int hours = (uptime_s / 3600) % 60;
  snprintf(uptime_str, sizeof(uptime_str), "Uptime %02d:%02d:%02d", hours, mins, seconds);
}

const char *read_uptime(void)
{
  return uptime_str;
}