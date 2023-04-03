#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *output = S21_NULL;
  unsigned char *str_tmp = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*str_tmp == (unsigned char)c) {
      output = (void *)str_tmp;
      break;
    } else if (*str_tmp != '\0')
      str_tmp++;
    else
      break;
  }
  return output;
}
