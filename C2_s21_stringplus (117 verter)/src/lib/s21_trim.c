#include "../s21_string.h"

//  Возвращает новую строку, в которой удаляются все начальные и конечные
//   вхождения набора заданных символов (trim_chars) из данной строки (src).
//   В случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
  char *copy = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL && s21_strlen(trim_chars) > 0) {
    s21_size_t count = s21_strspn(src, trim_chars);
    for (; count; count--, src++) {
    }
    const char *p = src;  //  save pointer to the first non trim char
    for (; *src; src++, count++) {
    }  //  reaching end of src
    if (count) {
      int flag = 1;  //  flag is down when reaching the first non trim char
      const char *trimcopy = trim_chars;
      while (flag) {
        int fflag = 0;  //  flag is when found any trim char in an iteration
        src--;
        for (; *trim_chars; trim_chars++) {
          if (*src == *trim_chars) {
            fflag = 1;
            count--;
            trim_chars = trimcopy;
            break;
          }
        }
        if (!fflag) flag = 0;
      }
    }
    char *output = (char *)malloc(sizeof(char) * (1 + count));
    copy = output;
    if (output != S21_NULL) {
      for (; count; count--, p++, output++) *output = *p;
      *output = '\0';
    }
  } else if (src != S21_NULL &&
             (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0)) {
    copy = s21_trim(src, " ");
  }
  return copy;
}