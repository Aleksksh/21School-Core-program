/*#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res;
  if (n == 0)
    res = 0;
  else {
    for (; n && *str1 && *str1 == *str2;) {
      str1++;
      str2++;
      n--;
    }
    res = *str1 - *str2;
  }
  return res;
}*/
#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  unsigned char a, b;
  while (n) {
    a = *str1++;
    b = *str2++;
    if (a != b) return a - b;
    if (!a) break;
    n--;
  }
  return 0;
}