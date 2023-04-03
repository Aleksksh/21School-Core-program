#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *d = dest;
  if (dest && src) {
    while (*src) {
      *dest = *src;
      src++;
      dest++;
    }
    *dest = '\0';
  }
  return d;
}
