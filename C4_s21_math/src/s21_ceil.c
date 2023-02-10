#include "s21_math.h"

/*  возвращает ближайшее целое число, не меньшее заданного значения */
long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (!(x >= 0) && !(x < 0))
    result = S21_NAN;
  else if (x == S21_INF)
    result = S21_INF;
  else if (x == -S21_INF)
    result = -S21_INF;
  else if (s21_fabs(x) > 0. && x != result)
    if (x > 0.) result += 1;

  return result;
}
