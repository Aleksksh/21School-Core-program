#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *s = S21_NULL;
  while (*str) {
    if (*str == (char)c) {
      s = str;
      break;
    }
    str++;
  }
  if (*str == (char)c) s = str;
  return (char *)s;
}
