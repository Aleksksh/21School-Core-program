#include "s21_math.h"

/*  вычисляет арктангенс */
long double s21_atan(double x) {
  double rez = 0;
  if (x == S21_INF) {
    rez = S21_PI / 2.0;
  } else if (x == -0.0) {
    rez = -0.0;
  } else if (x == -S21_INF) {
    rez = -S21_PI / 2.0;
  } else {
    rez = s21_asin((x) / (s21_sqrt(1 + x * x)));
  }
  return rez;
}
