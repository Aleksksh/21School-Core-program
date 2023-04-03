#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  char const *s = src;
  if (!src && !dest) dest = S21_NULL;
  if (dest == src)
    d = (char *)s;
  else if (d < s) {
    while (n-- > 0) *d++ = *s++;
  } else {
    d += n;
    s += n;
    while (n-- > 0) *--d = *--s;
  }
  return dest;
}
