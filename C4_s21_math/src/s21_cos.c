#include "s21_math.h"

/*  вычисляет косинус */
long double s21_cos(double x) {
  long double cosinus;
  cosinus = s21_sin((S21_PI / 2) - x);
  return cosinus;
}
