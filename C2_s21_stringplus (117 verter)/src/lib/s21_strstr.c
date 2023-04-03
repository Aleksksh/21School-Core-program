#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *output;
  if (s21_strlen(needle) == 0) {
    output = haystack;
  } else {
    int flag = 0;  // 1 когда встретился совпадающий символ
    const char *copy = needle;
    for (; *haystack && *needle; haystack++) {
      if (*haystack == *needle) {
        if (!flag) {
          output = haystack;
          flag = 1;
        }
        needle++;
      } else {
        needle = copy;
        flag = 0;
      }
    }
    if (*needle) output = S21_NULL;
  }
  return (char *)output;
}
