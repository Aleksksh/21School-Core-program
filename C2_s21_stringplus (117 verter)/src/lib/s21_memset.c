#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str) {
    unsigned char *output = (unsigned char *)str;
    while (n-- > 0) {
      *output = (unsigned char)c;
      output++;
    }
  }
  return str;
}
