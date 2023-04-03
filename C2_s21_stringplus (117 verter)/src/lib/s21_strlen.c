#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int a = 0;
  while (*str != '\0') {
    a++;
    str++;
  }
  return (a);
}
