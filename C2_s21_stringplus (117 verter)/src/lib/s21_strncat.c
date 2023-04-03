#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *d = dest;
  s21_size_t lengh = n > s21_strlen(src) ? s21_strlen(src) : n;
  while (*dest) dest++;
  while (lengh--) *dest++ = *src++;
  *dest = '\0';
  return d;
}
