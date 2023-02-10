#include "s21_math.h"

/*  вычисляет квадратный корень */
long double s21_sqrt(double x) {
  long double left = 0;
  long double right = (x < 1) ? 1 : x;
  long double middle;
  if (x == S21_INF)
    middle = S21_INF;
  else if (x == -S21_INF)
    middle = S21_NAN;
  else if (x == 0 || x == -0)
    middle = 0;
  else if (x < 0)
    middle = S21_NAN;
  else if (x == 1)
    middle = 1;
  else {
    middle = (left + right) / 2;
    while ((middle - left) > S21_PRECISION) {
      if ((middle * middle) > x)
        right = middle;
      else
        left = middle;
      middle = (left + right) / 2;
    }
  }
  return middle;
}
