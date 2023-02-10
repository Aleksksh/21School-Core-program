#include "s21_math.h"

/*  вычисляет абсолютное значение числа с плавающей точкой */
long double s21_fabs(double x) {
  long double f = 0;
  if (x != x) f = S21_NAN;
  if (x == S21_INF || x == -S21_INF) f = S21_INF;
  if (x == -0) f = 0;
  if (x < 0)
    f = -x;
  else
    f = x;
  return f;
}
