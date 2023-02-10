#include "s21_math.h"

/*  вычисляет тангенс */
long double s21_tan(double x) {
  long double tangens = s21_cos(x);
  tangens = (tangens != 0.0) ? (s21_sin(x) / tangens) : S21_NAN;
  return tangens;
}
