/*#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res;
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  while (*s1 == *s2 && n-- > 0) {
    if (*s1 == '\0' || *s2 == '\0')
      break;
    else {
      s1++;
      s2++;
    }
  }
  if (n == 0)
    res = 0;
  else {
    res = *s1 - *s2;
  }
  return res;
}*/
#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1, *s2;
  int res = 0;
  s1 = str1, s2 = str2;
  for (; n--; s1++, s2++) {
    if (*s1 != *s2) {
      res = (*s1 - *s2);
      break;
    }
  }
  return res;
}