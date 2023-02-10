#include "s21_math.h"

/*  возвращает значение e, возведенное в заданную степень */
long double s21_exp(double x) {
  long double add_value = 1, res = 1, num = 0, n = 1;
  if (x == 0.0)
    res = 1;
  else if (x == -S21_INF)
    res = 0;
  else if (x == S21_INF)
    res = S21_INF;
  else if (!(x >= 0) && !(x < 0))
    res = S21_INF;
  else {
    if (x < 0.0)
      num = -x;
    else
      num = x;

    while (s21_fabs(add_value) > EPS_16) {
      add_value *= num / n;
      res += add_value;
      n++;
    }
    if (x < 0.0) res = 1.0 / res;
  }
  return res;
}
