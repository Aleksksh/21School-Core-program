#include "s21_math.h"

/*  вычисляет арккосинус */
long double s21_acos(double x) {
  double rez = 0;
  rez = (S21_PI / 2) - s21_asin(x);
  return rez;
}
